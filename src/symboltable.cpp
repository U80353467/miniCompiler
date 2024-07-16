#include "symboltable.hpp"
#include <string>
#include <vector>
#include <algorithm>

namespace symboltable {

ast::ASTNode* tempNode = nullptr;

VariableRenameHelper::VariableRenameHelper() : valueCount(0), referenceCount(0), globalValueCount(0), globalReferenceCount(0) { }

std::string VariableRenameHelper::getNewValueName()
{
    if (isGlobal) {
        return getNewGlobalValueName();
    }
    return "__val" + std::to_string(valueCount++);
}

std::string VariableRenameHelper::getNewReferenceName()
{
    if (isGlobal) {
        return getNewGlobalReferenceName();
    }
    return "__ref" + std::to_string(referenceCount++);
}

std::string VariableRenameHelper::getNewGlobalValueName()
{
    return "__global_val" + std::to_string(globalValueCount++);
}

std::string VariableRenameHelper::getNewGlobalReferenceName()
{
    return "__global_ref" + std::to_string(globalReferenceCount++);
}

SymbolTable::SymbolTable()
{
    scope.push_back(symbol("$global", "$scope"));
}

void SymbolTable::enterScope(std::string name)
{
    scope.push_back(symbol(name, "$scope"));
}

void SymbolTable::exitScope()
{
    while (scope.back().type != "$scope")
    {
        scope.pop_back();
    }
    scope.pop_back();
}

symbol SymbolTable::findSymbolInScope(std::string name)
{
    // std::cout << "findSymbolInScope: " << name << std::endl;
    for (auto it = scope.end() - 1; it != scope.begin(); --it)
    {
        // std::cout << it->type << " " << it->name << std::endl;
        if (it->type == "$scope")
        {
            break;
        }
        if (it->name == name)
        {
            return *it;
        }
    }
    return symbol("", "");
}

symbol SymbolTable::findSymbol(std::string name)
{
    for (auto it = scope.end() - 1; it != scope.begin(); --it)
    {
        if (it->name == name)
        {
            return *it;
        }
    }
    return symbol("", "");
}

symbol SymbolTable::findNearestFunction()
{
    for (auto it = scope.end() - 1; it != scope.begin(); --it)
    {
        if (it->extra == "function")
        {
            return *it;
        }
    }
    return symbol("", "");
}

void SymbolTable::sematicError(std::string name)
{
    std::cout << "Semantic error: " << name << std::endl;
    exit(-1);
}

bool shouldCheckType(ast::ASTNode *node)
{
    bool isExp = node->getValueType() == "AddExp" || node->getValueType() == "MulExp" || node->getValueType() == "RelExp" || node->getValueType() == "EqExp" || node->getValueType() == "LAndExp" || node->getValueType() == "LOrExp";
    bool isAssign = node->getValueType() == "Stmt";
    return (isExp && node->getValueVector().size() > 1) || (isAssign && node->getValueVector().size() > 1 && node->getValueVector()[1] == "=");
}

std::string SymbolTable::checkType(ast::ASTNode *node)
{
    if (node->getValueType() == "LVal")
    {
        // Left value
        std::string name = node->getValueVector()[1];
        symboltable::symbol sym = findSymbol(name);
        std::string type = sym.type;
        if (type == "")
        {
            sematicError("Variable " + name + " not declared");
        }
        node->setValue(1, sym.irName);

        int variableDimension = 0;
        if (sym.extra == "array") {
            variableDimension = sym.extraNode->getValueVector().size() - 1;
            for (int i = 1; i < sym.extraNode->getValueVector().size(); ++i) {
                std::string dim = sym.extraNode->getValueVector()[i];
                node->appendValue(dim.substr(1, dim.size() - 3));
            }
        }

        if (node->getChildren().size() > 0 && node->getChildren()[0]->getValueType() == "ArrayExpList") {
            ast::ASTNode* arrayExpList = node->getChildren()[0];

            for (auto child : arrayExpList->getChildren()) {
                std::string expType = checkType(child);
                if (expType != "int") {
                    sematicError("Array index must be of type int but got " + expType + " instead.");
                }
            }
            int exp_dimension = arrayExpList->getChildren().size();
            int dimension = variableDimension - exp_dimension;
            // std::cout << "Variable " << name << " has " << variableDimension << " dimensions but got " << variableDimension + dimension << " instead." << std::endl;
            if (dimension > 0) {
                type += "(*)";
                for (int i = 1; i < dimension; ++i) {
                    type += sym.extraNode->getValueVector()[i + exp_dimension + 1];
                }
                return type;
            } else if (dimension == 0) {
                return type;
            } else if (dimension < 0) {
                sematicError("Variable " + name + " has only" + std::to_string(variableDimension) + " dimensions but got " + std::to_string(exp_dimension) + "times reference.");
            }
        }
        if (variableDimension > 0) {
            type += "(*)";
            for (int i = 1; i < variableDimension; ++i) {
                type += sym.extraNode->getValueVector()[i + 1];
            }
        }
        return type;
    }
    else if (node->getValueType() == "UnaryExp" && node->getValueVector().size() > 1)
    {
        std::string name = node->getValueVector()[1];
        // std::cout << name << "is being checked\n";
        ast::ASTNode* funcRParams = nullptr;
        if (node->getChildren().size() > 0) {
            funcRParams = node->getChildren()[0];
        }
        if (funcRParams == nullptr) {
            funcRParams = new ast::FuncRParams();
        }
        if (name == "write ")
        {
            if (funcRParams->getChildren().size() == 1) {
                std::string paramType = checkType(funcRParams->getChildren()[0]);
                if (paramType != "int")
                {
                    sematicError("Function write  expected 1 parameter of type int but got " + paramType + " instead.");
                }

                node->appendValue("void");
                
                return "void";
            }
            sematicError("Function read  or write  expected 1 parameter of type int.");
        }
        if (name == "read ")
        {
            if (funcRParams->getChildren().size() == 0) {

                node->appendValue("int");

                return "int";
            }
            sematicError("Function read  expected 0 parameter.");
        }
        symboltable::symbol sym = findSymbol(name);
        std::string type = sym.type;
        ast::ASTNode* funcFParams = sym.extraNode;
        if (type == "")
        {
            sematicError("Function " + name + " not declared");
        }
        if (funcRParams->getChildren().size() != funcFParams->getChildren().size())
        {
            sematicError("Function " + name + " expected " + std::to_string(funcFParams->getChildren().size()) + " parameters but got " + std::to_string(funcRParams->getChildren().size()) + " instead.");
        }
        for (int i = 0; i < funcRParams->getChildren().size(); i++)
        {
            std::string paramType = checkType(funcRParams->getChildren()[i]);
            ast::ASTNode* funcFParam = funcFParams->getChildren()[i];
            std::string expectedType = funcFParam->getValueVector()[1];
            if (funcFParam->getValueVector().size() > 3 && funcFParam->getValueVector()[3] == "[]") {
                int dimension = 0;
                expectedType += "(*)";
                if (funcFParam->getChildren().size() > 0 && funcFParam->getChildren()[0]->getValueType() == "ArraySizeList") {
                    // funcFParam->print(std::cout, 0);
                    ast::ASTNode* arraySizeList = funcFParam->getChildren()[0];
                    dimension += arraySizeList->getValueVector().size() - 1;
                    for (int i = 1; i < dimension; ++i) {
                        expectedType += arraySizeList->getValueVector()[i];
                    }
                }
            }
            if (paramType != expectedType)
            {
                sematicError("Function " + name + " parameters type mismatch. Expected " + expectedType + " but got " + paramType + " instead.");
            }
        }

        node->appendValue(type);

        return type;
    }
    else if (node->getValueType() == "Number")
    {
        return "int";
    }
    // std::cout<< node->getValueType() << std::endl;
    // std::flush(std::cout);
    if (node->getChildren()[0]->getValueType() == "UnaryOp") {
        return checkType(node->getChildren()[1]);
    }
    std::string leftType = checkType(node->getChildren()[0]);
    if (shouldCheckType(node)) {
        std::string rightType = checkType(node->getChildren()[1]);
        if (leftType.length() > 4) {
            sematicError("Cannot assign to an array.");
        }
        if (leftType != rightType)
        {
            sematicError("Operator " + node->getValueVector()[1] + " type mismatch. Expected " + leftType + " but got " + rightType + " instead.");
        }
    }
    return leftType;
}

int SymbolTable::checkArrayInitList(std::string arrayName, std::vector<int> dimensions, ast::ASTNode *node, int pre_accumulator = 0, int extra = 0)
{
    // std::cout << "checkArrayInitList: " << std::endl;
    // node->print(std::cout, 0);
    int totalsize = 1;
    for (int i = 0; i < dimensions.size(); ++i) {
        totalsize *= dimensions[i];
        // std::cout << dimensions[i] << std::endl;
    }
    int accumulator = 0;
    int unitsize = 0;
    int align = -1;
    for (int i = 0; i < node->getChildren().size(); ++i) {
        ast::ASTNode* child = node->getChildren()[i];
        if (child->getChildren()[0]->getValueType() == "Exp") {
            // scan all non-list elements
            unitsize = 0;
            while (i < node->getChildren().size()) {
                child = node->getChildren()[i];
                if (child->getChildren()[0]->getValueType() != "Exp") {
                    break;
                }
                
                ast::ASTNode* exp = child->getChildren()[0];
                std::string type = checkType(exp);
                if (type != "int") {
                    sematicError("Array " + arrayName + " init list has wrong type. Expected int but got " + type + " instead.");
                }
                int expId = accumulator + pre_accumulator;
                child->getChildren()[0]->appendValue(std::to_string(expId));
                tempNode->addChild(child->getChildren()[0]);

                accumulator++;
                unitsize++;
                i++;
            }
            // std::cout << "1 " << accumulator << " " << totalsize << std::endl;
            // child->getChildren()[0]->print(std::cout, 0);
            if (accumulator > totalsize) {
                sematicError("Array " + arrayName + " init with too many elements.");
            }
            // if followed by list, the number of elements should be aligned with the first dimension
            if (i != node->getChildren().size() && unitsize % dimensions[0] != 0) {
                sematicError("Array " + arrayName + " init list has wrong alignment.");
            }
            if (i == node->getChildren().size()) {
                break;
            }
            i--;
        } else {
            // scan list elements
            if (align == -1) {
                // did not align yet, it means the first list elements
                unitsize = checkArrayInitList(arrayName, dimensions, child->getChildren()[0], pre_accumulator + accumulator, 1);
            } else {
                // current list should check alignment
                unitsize = checkArrayInitList(arrayName, std::vector<int>(dimensions.begin(), dimensions.begin() + align), child->getChildren()[0], pre_accumulator + accumulator);
            }
            accumulator += unitsize;
            // std::cout << "2 " << accumulator << " " << totalsize << std::endl;
            // child->getChildren()[0]->print(std::cout, 0);
            if (accumulator > totalsize) {
                sematicError("Array " + arrayName + " init with too many elements.");
            }
        }
        int cp_accumulator = accumulator;
        align = 0;
        for (auto dim : dimensions) {
            if (cp_accumulator % dim == 0) {
                cp_accumulator /= dim;
                align++;
            } else {
                break;
            }
        }
        // std::cout << "3 " << align << " " << accumulator << std::endl;
    }
    if (extra == 0) {
        // if aligned
        return totalsize;
    } else {
        // if did not align yet
        int group_size = 1;
        for (auto dim : dimensions) {
            group_size *= dim;
            if (group_size >= accumulator) {
                return group_size;
            }
        }
    }
    return accumulator;
}

void SymbolTable::analyze(ast::ASTNode *node)
{
    if (node->getValueType() == "Block") {
        bool isFunctionBlock = scope.back().extra == "function";
        enterScope("$Block");
        symboltable::symbol sym = symbol("", "");
        if (isFunctionBlock) {
            sym = findNearestFunction();
            if (sym.name != "") {
                variableRenameHelper.isGlobal = false;
            }
        }
        // std::cout << "Function " << sym.name << " scope\n";
        // function parameters add to scope
        if (sym.name != "") {
            ast::ASTNode* funcFParams = sym.extraNode;
            for (auto child : funcFParams->getChildren()) {
                std::string name = child->getValueVector()[2];
                std::string type = child->getValueVector()[1];
                if (child->getValueVector().size() > 3 && child->getValueVector()[3] == "[]") {
                    ast::ASTNode* arraySizeList = (child->getChildren().size() > 0) ? child->getChildren()[0] : new ast::ArraySizeList();
                    arraySizeList->appendValue("[]");
                    scope.push_back(symbol(name, type, "array", arraySizeList));
                    scope.back().irName = "__" + name;
                    child->setValue(2, scope.back().irName);
                } else {
                    scope.push_back(symbol(name, type));
                    scope.back().irName = "__" + name;
                    child->setValue(2, scope.back().irName);
                }
            }
        }
        for (auto child : node->getChildren()) {
            analyze(child);
        }
        if (isFunctionBlock) {
            variableRenameHelper.isGlobal = true;
        }
        exitScope();
    } else if (node->getValueType() == "VarDecl") {
        // variable declaration
        ast::ASTNode* varDefList = node->getChildren()[0];
        std::string type = node->getValueVector()[1];
        for (auto child : varDefList->getChildren()) {
            std::string name = child->getValueVector()[1];
            if (findSymbolInScope(name).type != "") {
                sematicError("Variable " + name + " already declared");
            }
            // array
            if (child->getChildren().size() > 0 && child->getChildren()[0]->getValueType() == "ArraySizeList") {
                ast::ASTNode* arraySizeList = child->getChildren()[0];

                scope.push_back(symbol(name, type, "array", arraySizeList));
                scope.back().irName = variableRenameHelper.getNewReferenceName();
                child->setValue(1, scope.back().irName);

                // check array init
                if (child->getChildren().size() > 1) {
                    ast::ASTNode* initVal = child->getChildren()[1];
                    std::vector<int> dimensions;
                    for (int i = 1; i < arraySizeList->getValueVector().size(); ++i) {
                        std::string dim = arraySizeList->getValueVector()[i];
                        dimensions.push_back(std::stoi(dim.substr(1, dim.size() - 3)));
                    }
                    std::reverse(dimensions.begin(), dimensions.end());
                    if (initVal->getChildren().size() > 0) {
                        ast::ASTNode* initValList = initVal->getChildren()[0];
                        tempNode = new ast::Assist();
                        if (initValList->getValueType() == "Exp") {
                            if ((dimensions.size() == 1 && dimensions[0] == 1) == false) {
                                sematicError("Array " + name + " init list has wrong alignment.");
                            }
                            int expId = 0;
                            initValList->appendValue(std::to_string(expId));
                            tempNode->addChild(initValList);
                        } else {
                            if (initValList->getChildren().size() > 0) {
                                // initValList->print(std::cout, 0);
                                // std::cout << name << std::endl;
                                checkArrayInitList(name, dimensions, initValList);
                            }
                        }
                        initVal->clearChildren();
                        initVal->addChild(tempNode);
                    }
                }
            } else {
                scope.push_back(symbol(name, type));
                scope.back().irName = variableRenameHelper.getNewValueName();
                child->setValue(1, scope.back().irName);

                if (child->getChildren().size() > 0 && child->getChildren()[0]->getValueType() == "InitVal") {
                    ast::ASTNode* initVal = child->getChildren()[0];
                    if (initVal->getChildren().size() > 0 && initVal->getChildren()[0]->getValueType() == "InitValList") {
                        sematicError("Cannot initialize non-array variable " + name + " with array init list.");
                    } else if (initVal->getChildren().size() > 0 && initVal->getChildren()[0]->getValueType() == "Exp") {
                       std::string right_type = checkType(initVal->getChildren()[0]);
                       if (type != right_type) {
                           sematicError("Variable " + name + " type mismatch. Expected " + type + " but got " + right_type + " instead.");
                       }
                    }
                }
            }
        }
    } else if (node->getValueType() == "FuncDef") {
        // function declaration
        std::string name = node->getValueVector()[2];
        if (findSymbolInScope(name).type != "") {
            sematicError("Function " + name + " already declared");
        }
        ast::ASTNode* funcFParams = nullptr;
        if (node->getChildren()[0]->getValueType() == "FuncFParams") {
            funcFParams = node->getChildren()[0];
        }
        if (funcFParams == nullptr) {
            funcFParams = new ast::FuncFParams();
        }
        scope.push_back(symbol(name, node->getValueVector()[1], "function", funcFParams));
        for (auto child : node->getChildren()) {
            analyze(child);
        }
    } else if (node->getValueType() == "Stmt" && node->getValueVector().size() > 1 && node->getValueVector()[1] == "return") {
        std::string type = (node->getChildren().size() > 0) ? checkType(node->getChildren()[0]) : "void";
        symboltable::symbol sym = findNearestFunction();
        std::string functype = sym.type;
        if (type != functype)
        {
            sematicError("Return type mismatch. Function " + sym.name + " Expected " + functype + " but got " + type + " instead.");
        }
    } else if (shouldCheckType(node) || (node->getValueType() == "UnaryExp" && node->getValueVector().size() > 1) || node->getValueType() == "Number" || node->getValueType() == "LVal") {
        checkType(node);
    } else {
        for (auto child : node->getChildren()) {
            analyze(child);
        }
    }

}

}
