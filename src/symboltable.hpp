#pragma once
#include "ast.hpp"
#include <cstring>
#include <iostream>
#include <vector>

namespace symboltable {

class VariableRenameHelper {
public:
    bool isGlobal = true;
    VariableRenameHelper();
    std::string getNewValueName();
    std::string getNewReferenceName();
    std::string getNewGlobalValueName();
    std::string getNewGlobalReferenceName();
private:
    int valueCount;
    int referenceCount;
    int globalValueCount;
    int globalReferenceCount;
};

struct symbol
{
    std::string name;
    std::string type;
    std::string extra;
    ast::ASTNode *extraNode;
    std::string irName;
    symbol(std::string name, std::string type) : name(name), type(type) { }
    symbol(std::string name, std::string type, std::string extra, ast::ASTNode* node) : name(name), type(type), extra(extra), extraNode(node) { }
};

class SymbolTable {
public:
    SymbolTable();
    std::vector<symbol> scope;
    VariableRenameHelper variableRenameHelper;
    void enterScope(std::string name);
    void exitScope();
    symbol findSymbolInScope(std::string name);
    symbol findSymbol(std::string name);
    symbol findNearestFunction();
    void sematicError(std::string name);
    std::string checkType(ast::ASTNode *node);
    int checkArrayInitList(std::string arrayName, std::vector<int> dimensions, ast::ASTNode *node, int pre_accumulator, int extra);
    void analyze(ast::ASTNode *node);
};

}
