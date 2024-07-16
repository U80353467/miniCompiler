#include <iostream>
#include <fstream>
#include "ast.hpp"
#include "irgenerator.hpp"

//#define LAB4 4

/*
中间代码的定义如下：

类型	格式	说明
数据流指令	x = #k	将常量k加载到x中
x = y	将y的值存放到x中
x = y binop z	将y和z的双目运算结果存放到x中
x = y binop #k	将y和常量k的双目运算结果存放到x中
x = unop y	将y的单目运算结果存放到x中
x = *y	将y所指向的值存放到x中
*x = y	将y的值存放到x指向的位置中
控制流指令	LABEL l:	定义标签l
GOTO L	无条件跳转到L处
IF x relop y GOTO L	如果x和y的运算结果满足op的关系，则跳转到L处
函数相关指令	FUNCTION f:	定义函数f
x = CALL f	调用函数f，并将返回值存放到x中
CALL f	调用函数f，但不保存返回值
PARAM x	函数参数声明
ARG x	将x作为参数传递给函数
RETURN x	退出当前函数并返回x的值
RETURN	退出当前函数并返回void的值
DEC x #k	声明k个字节的空间，并将首地址存放到x中
全局变量相关指令	GLOBAL x:	定一个全局变量 x
x = &label	将全局变量 label 的地址存放到 x 中
.WORD #k	向当前位置直接存放一个大小为 4 字节的整数 k
我们支持的 binop 双目运算，relop 关系运算和 unop 单目运算如下表所示：

双目运算符	说明	关系运算符	说明	单目运算符	说明
+	加法	>	大于	+	正
-	减法	>=	大于等于	-	取负
*	乘法	<	小于		
/	除法	<=	小于等于		
%	模	!=	不等于		
==	等于	
*/
namespace irgenerator {
    bool startsWith(const std::string& str, const std::string& s0) {
        return str.substr(0, s0.length()) == s0;
    }

    ast::ASTNode* findEffectiveNode(ast::ASTNode* node) {
        while (node->getChildren().size() > 0 && node->getValueVector().size() == 1) {
            node = node->getChildren()[0];
        }
        return node;
    }

    ast::ASTNode* findStmtNode(ast::ASTNode* node) {
        while (node->getChildren().size() > 0 && node->getValueType() != "Stmt") {
            node = node->getChildren()[0];
        }
        return node;
    }

    IRGenerator::IRGenerator() = default;

    IRGenerator::IRGenerator(std::string IRoutputFileName) {
        IRoutputFile.open(IRoutputFileName);
    }

    std::string IRGenerator::getNewTempName() {
        return "__tmp" + std::to_string(tempCount++);
    }

    std::string IRGenerator::getNewLabelName() {
        return "_l_lab" + std::to_string(labelCount++);
    }

    void IRGenerator::writeToFile(std::string content) {
        IRoutputFile << content;
    }

    void IRGenerator::closeFile() {
        IRoutputFile.close();
    }

    void IRGenerator::translateExp(ast::ASTNode *node, std::string place) {
        while (node->getValueType() == "Exp") {
            node = node->getChildren()[0];
        }
        std::string expType = node->getValueType();
        if (expType == "Number") {
            std::string value = node->getValueVector()[1];

            instructions.push_back({ "li", place, value, "" });
            writeToFile(place + " = #" + value + "\n");
        } else if (expType == "LVal") {
            // Lval on the right side
            std::string name = node->getValueVector()[1];
            if (node->getChildren().size() > 0 && node->getChildren()[0]->getValueType() == "ArrayExpList") {
                // array
                std::vector<int> lowDimensionProduct;
                for (int i = 2; i < node->getValueVector().size(); ++i) {
                    if (!isdigit(node->getValueVector()[i][0])) {
                        lowDimensionProduct.insert(lowDimensionProduct.begin(), 1);
                        continue;
                    }
                    lowDimensionProduct.push_back(std::stoi(node->getValueVector()[i]));
                }
                lowDimensionProduct.push_back(1);
                for (int i = lowDimensionProduct.size() - 2; i >= 0; --i) {
                    lowDimensionProduct[i] *= lowDimensionProduct[i + 1];
                }
                std::string arrayIndex = getNewTempName();
                std::string placeIndex = getNewTempName();

                if (startsWith(name, "__global")) {
                    instructions.push_back({ "la", arrayIndex, name, "" });
                    writeToFile(arrayIndex + " = &" + name + "\n");
                } else {
                    instructions.push_back({ "mv", arrayIndex, name, "" });
                    writeToFile(arrayIndex + " = " + name + "\n");
                }
                
                instructions.push_back({ "mv", placeIndex, "zero", "" });
                writeToFile(placeIndex + " = #0\n");
                ast::ASTNode* arrayExpList = node->getChildren()[0];

                int varibleDimension = node->getValueVector().size() - 2;
                varibleDimension -= arrayExpList->getChildren().size();

                for (int i = 0; i < arrayExpList->getChildren().size(); ++i) {
                    std::string singleIndex = getNewTempName();
                    translateExp(arrayExpList->getChildren()[i], singleIndex);
                    instructions.push_back({ "muli", singleIndex, singleIndex, std::to_string(lowDimensionProduct[i + 1]) });
                    writeToFile(singleIndex + " = " + singleIndex + " * #" + std::to_string(lowDimensionProduct[i + 1]) + "\n");
                    instructions.push_back({ "add", placeIndex, placeIndex, singleIndex });
                    writeToFile(placeIndex + " = " + placeIndex + " + " + singleIndex + "\n");
                }
                instructions.push_back({ "muli", placeIndex, placeIndex, "4" });
                writeToFile(placeIndex + " = " + placeIndex + " * #4\n");
                instructions.push_back({ "add", arrayIndex, arrayIndex, placeIndex });
                writeToFile(arrayIndex + " = " + arrayIndex + " + " + placeIndex + "\n");

                if (varibleDimension == 0) {
                    instructions.push_back({ "lw", place, arrayIndex, "0" });
                    writeToFile(place + " = " + "*" + arrayIndex + "\n");
                } else {
                    instructions.push_back({ "mv", place, arrayIndex, "" });
                    writeToFile(place + " = " + arrayIndex + "\n");
                }
            } else {
                if (startsWith(name, "__global")) {
                    instructions.push_back({ "la", place, name, "" });
                    writeToFile(place + " = &" + name + "\n");
                    if (startsWith(name.substr(8), "_val")) {
                        instructions.push_back({ "lw", place, place, "0" });
                        writeToFile(place + " = *" + place + "\n");
                    }
                } else {
                    instructions.push_back({ "mv", place, name, "" });
                    writeToFile(place + " = " + name + "\n");
                }
            }
        } else if (expType == "AddExp" || expType == "MulExp") {
            std::string binop = node->getValueVector()[1];
            std::string place1 = getNewTempName();
            std::string place2 = getNewTempName();
            translateExp(node->getChildren()[0], place1);
            translateExp(node->getChildren()[1], place2);
            std::string binopL = binop;
            if (binopL == "+") {
                binopL = "add";
            } else if (binopL == "-") {
                binopL = "sub";
            } else if (binopL == "*") {
                binopL = "mul";
            } else if (binopL == "/") {
                binopL = "div";
            } else if (binopL == "%") {
                binopL = "rem";
            }
            instructions.push_back({ binopL, place, place1, place2 });
            writeToFile(place + " = " + place1 + " " + binop + " " + place2 + "\n");
        } else if (expType == "UnaryExp" && node->getValueVector().size() == 1) {
            // + -
            std::string unaryop = node->getChildren()[0]->getValueVector()[1];
            std::string place1 = getNewTempName();
            std::string place2 = getNewTempName();
            translateExp(node->getChildren()[1], place1);
            // instructions.push_back({ "li", place2, "0", "" });
            writeToFile(place2 + " = #0" + "\n");
            std::string unaryopL = unaryop;
            if (unaryopL == "+") {
                unaryopL = "add";
            } else if (unaryopL == "-") {
                unaryopL = "sub";
            }
            instructions.push_back({ unaryopL, place, "zero", place1 });
            writeToFile(place + " = " + place2 + " " + unaryop + " " + place1 + "\n");
        } else if (expType == "UnaryExp" && node->getValueVector().size() > 2) {
            // call function
            std::string name = node->getValueVector()[1];
            std::string type = node->getValueVector()[2];
            ast::ASTNode* funcRParams = nullptr;
            if (node->getChildren().size() > 0) {
                funcRParams = node->getChildren()[0];
            }
            if (funcRParams != nullptr) {
                for (auto param : funcRParams->getChildren()) {
                    std::string placeParam = getNewTempName();
                    translateExp(param, placeParam);
                    instructions.push_back({ "arg", placeParam, "", "" });
                    writeToFile("ARG " + placeParam + "\n");
                }
            }
            if (type == "void") {
                instructions.push_back({ "call", "", name, "" });
                writeToFile("CALL " + name + "\n");
            } else {
                instructions.push_back({ "call", place, name, "" });
                writeToFile(place + " = CALL " + name + "\n");
            }
        }
    }

    void IRGenerator::translateCond(ast::ASTNode *node, std::string labelTrue, std::string labelFalse) {
        if (node->getValueType() == "Cond") {
            node = node->getChildren()[0];
        }
        std::string condType = node->getValueType();
        if (condType == "RelExp" || condType == "EqExp") {
            std::string relop = node->getValueVector()[1];
            std::string place1 = getNewTempName();
            std::string place2 = getNewTempName();
            translateExp(node->getChildren()[0], place1);
            translateExp(node->getChildren()[1], place2);
            std::string relopL = relop;
            if (relopL == "==") {
                relopL = "beq";
            } else if (relopL == "!=") {
                relopL = "bne";
            } else if (relopL == ">") {
                relopL = "bgt";
            } else if (relopL == "<") {
                relopL = "blt";
            } else if (relopL == ">=") {
                relopL = "bge";
            } else if (relopL == "<=") {
                relopL = "ble";
            }
            instructions.push_back({ relopL, place1, place2, labelTrue });
            writeToFile("IF " + place1 + " " + relop + " " + place2 + " GOTO " + labelTrue + "\n");
            instructions.push_back({ "j", labelFalse, "", "" });
            writeToFile("GOTO " + labelFalse + "\n");
        } else if (condType == "LAndExp") {
            std::string labelMid = getNewLabelName();
            translateCond(node->getChildren()[0], labelMid, labelFalse);
            instructions.push_back({ "LABEL", labelMid, "", "" });
            writeToFile("LABEL " + labelMid + ":\n");
            translateCond(node->getChildren()[1], labelTrue, labelFalse);
        } else if (condType == "LOrExp") {
            std::string labelMid = getNewLabelName();
            translateCond(node->getChildren()[0], labelTrue, labelMid);
            instructions.push_back({ "LABEL", labelMid, "", "" });
            writeToFile("LABEL " + labelMid + ":\n");
            translateCond(node->getChildren()[1], labelTrue, labelFalse);
        } else if (condType == "UnaryExp") {
            if (node->getValueVector().size() > 1) {
                // function call
                std::string place1 = getNewTempName();
                std::string place2 = getNewTempName();
                translateExp(node, place1);
                // instructions.push_back({ "li", place2, "0", "" });
                writeToFile(place2 + " = #0\n");
                instructions.push_back({ "bne", place1, "zero", labelTrue });
                writeToFile("IF " + place1 + " != " + place2 + " GOTO " + labelTrue + "\n");
                instructions.push_back({ "j", labelFalse, "", "" });
                writeToFile("GOTO " + labelFalse + "\n");
            } else {
                // !exp
                std::string unaryop = node->getChildren()[0]->getValueVector()[1];
                if (unaryop == "!") {
                    translateCond(node->getChildren()[1], labelFalse, labelTrue);
                } else {
                    // + -
                    std::string place1 = getNewTempName();
                    std::string place2 = getNewTempName();
                    translateExp(node->getChildren()[1], place1);
                    // instructions.push_back({ "li", place2, "0", "" });
                    writeToFile(place2 + " = #0\n");
                    if (unaryop == "-") {
                        instructions.push_back({ "sub", place1, "zero", place1 });
                        writeToFile(place1 + " = " + place2 + " - " + place1 + "\n");
                    } else {
                        instructions.push_back({ "add", place1, "zero", place1 });
                        writeToFile(place1 + " = " + place2 + " + " + place1 + "\n");
                    }
                    instructions.push_back({ "bne", place1, "zero", labelTrue });
                    writeToFile("IF " + place1 + " != " + place2 + " GOTO " + labelTrue + "\n");
                    instructions.push_back({ "j", labelFalse, "", "" });
                    writeToFile("GOTO " + labelFalse + "\n");
                }
            }
        } else {
            std::string place1 = getNewTempName();
            std::string place2 = getNewTempName();
            // node->print(std::cout, 0);
            translateExp(node, place1);
            // instructions.push_back({ "li", place2, "0", "" });
            writeToFile(place2 + " = #0\n");
            instructions.push_back({ "bne", place1, "zero", labelTrue });
            writeToFile("IF " + place1 + " != " + place2 + " GOTO " + labelTrue + "\n");
            instructions.push_back({ "j", labelFalse, "", "" });
            writeToFile("GOTO " + labelFalse + "\n");
        }
    }

    void IRGenerator::translateStmt(ast::ASTNode *node) {
        if (node->getValueType() == "Stmt") { 
            if (node->getValueVector().size() > 1) {
                std::string stmtType = node->getValueVector()[1];
                if (stmtType == "return") {
                    std::string type = (node->getChildren().size() > 0) ? "int" : "void";
                    if (type == "int") {
                        std::string place = getNewTempName();
                        translateExp(node->getChildren()[0], place);
                        instructions.push_back({ "return", place, "", "" });
                        writeToFile("RETURN " + place + "\n");
                    } else {
                        instructions.push_back({ "return", "", "", "" });
                        writeToFile("RETURN\n");
                    }
                } else if (stmtType == "=") {
                    ast::ASTNode* lval = node->getChildren()[0];
                    ast::ASTNode* exp = node->getChildren()[1];
                    std::string name = lval->getValueVector()[1];
                    if (lval->getChildren().size() > 0 && lval->getChildren()[0]->getValueType() == "ArrayExpList") {
                        // array
                        std::vector<int> lowDimensionProduct;
                        for (int i = 2; i < lval->getValueVector().size(); ++i) {
                            // std::cout << lval->getValueVector()[i] << std::endl;
                            if (!isdigit(lval->getValueVector()[i][0])) {
                                lowDimensionProduct.insert(lowDimensionProduct.begin(), 1);
                                continue;
                            }
                            lowDimensionProduct.push_back(std::stoi(lval->getValueVector()[i]));
                        }
                        lowDimensionProduct.push_back(1);
                        for (int i = lowDimensionProduct.size() - 2; i >= 0; --i) {
                            lowDimensionProduct[i] *= lowDimensionProduct[i + 1];
                        }
                        std::string arrayIndex = getNewTempName();
                        std::string placeIndex = getNewTempName();

                        if (startsWith(name, "__global")) {
                            instructions.push_back({ "la", arrayIndex, name, "" });
                            writeToFile(arrayIndex + " = &" + name + "\n");
                        } else {
                            instructions.push_back({ "mv", arrayIndex, name, "" });
                            writeToFile(arrayIndex + " = " + name + "\n");
                        }
                        
                        instructions.push_back({ "mv", placeIndex, "zero", "" });
                        writeToFile(placeIndex + " = #0\n");
                        ast::ASTNode* arrayExpList = lval->getChildren()[0];
                        for (int i = 0; i < arrayExpList->getChildren().size(); ++i) {
                            std::string singleIndex = getNewTempName();
                            translateExp(arrayExpList->getChildren()[i], singleIndex);
                            instructions.push_back({ "muli", singleIndex, singleIndex, std::to_string(lowDimensionProduct[i + 1]) });
                            writeToFile(singleIndex + " = " + singleIndex + " * #" + std::to_string(lowDimensionProduct[i + 1]) + "\n");
                            instructions.push_back({ "add", placeIndex, placeIndex, singleIndex });
                            writeToFile(placeIndex + " = " + placeIndex + " + " + singleIndex + "\n");
                        }
                        instructions.push_back({ "muli", placeIndex, placeIndex, "4" });
                        writeToFile(placeIndex + " = " + placeIndex + " * #4\n");
                        instructions.push_back({ "add", arrayIndex, arrayIndex, placeIndex });
                        writeToFile(arrayIndex + " = " + arrayIndex + " + " + placeIndex + "\n");
                        std::string placeExp = getNewTempName();
                        translateExp(exp, placeExp);
                        instructions.push_back({ "sw", placeExp, arrayIndex, "0" });
                        writeToFile("*" + arrayIndex + " = " + placeExp + "\n");
                    } else {
                        if (startsWith(name, "__global")) {
                            std::string place = getNewTempName();
                            instructions.push_back({ "la", place, name, "" });
                            writeToFile(place + " = &" + name + "\n");
                            std::string placeExp = getNewTempName();
                            translateExp(exp, placeExp);
                            instructions.push_back({ "sw", placeExp, place, "0" });
                            writeToFile("*" + place + " = " + placeExp + "\n");
                        } else {
                            translateExp(exp, name);
                        }
                    }
                } else if (stmtType == "if") {
                    std::string labelTrue = getNewLabelName();
                    std::string labelFalse = getNewLabelName();
                    std::string labelEnd = getNewLabelName();
                    translateCond(node->getChildren()[0], labelTrue, labelFalse);
                    instructions.push_back({ "LABEL", labelTrue, "", "" });
                    writeToFile("LABEL " + labelTrue + ":\n");
                    if (node->getChildren().size() > 1) translateStmt(node->getChildren()[1]);
                    instructions.push_back({ "j", labelEnd, "", "" });
                    writeToFile("GOTO " + labelEnd + "\n");
                    instructions.push_back({ "LABEL", labelFalse, "", "" });
                    writeToFile("LABEL " + labelFalse + ":\n");
                    if (node->getChildren().size() > 2) translateStmt(node->getChildren()[2]);
                    instructions.push_back({ "LABEL", labelEnd, "", "" });
                    writeToFile("LABEL " + labelEnd + ":\n");
                } else if (stmtType == "while") {
                    std::string labelBegin = getNewLabelName();
                    std::string labelTrue = getNewLabelName();
                    std::string labelFalse = getNewLabelName();
                    instructions.push_back({ "LABEL", labelBegin, "", "" });
                    writeToFile("LABEL " + labelBegin + ":\n");
                    translateCond(node->getChildren()[0], labelTrue, labelFalse);
                    instructions.push_back({ "LABEL", labelTrue, "", "" });
                    writeToFile("LABEL " + labelTrue + ":\n");
                    if (node->getChildren().size() > 1) translateStmt(node->getChildren()[1]);
                    instructions.push_back({ "j", labelBegin, "", "" });
                    writeToFile("GOTO " + labelBegin + "\n");
                    instructions.push_back({ "LABEL", labelFalse, "", "" });
                    writeToFile("LABEL " + labelFalse + ":\n");
                } else {
                    for (auto child : node->getChildren()) {
                        translate(child);
                    }
                }
            } else if (node->getChildren().size() > 0 && node->getChildren()[0]->getValueType() == "Exp") {
                std::string tempplace = getNewTempName();
                translateExp(node->getChildren()[0], tempplace);
            } else {
                for (auto child : node->getChildren()) {
                    translate(child);
                }
            }
        }
    }

    void IRGenerator::translateGlobal(ast::ASTNode *node) {
        while(node->getValueType() != "Number") {
            node = node->getChildren()[0];
        }
        instructions.push_back({ "WORD", node->getValueVector()[1], "", "" });
        writeToFile(".WORD #" + node->getValueVector()[1] + "\n");
    }

    void IRGenerator::translate(ast::ASTNode *node) {
        if (node->getValueType() == "VarDecl") {
            // variable declaration
            ast::ASTNode* varDefList = node->getChildren()[0];
            std::string type = node->getValueVector()[1];
            for (auto child : varDefList->getChildren()) {
                std::string name = child->getValueVector()[1];
                // array
                if (child->getChildren().size() > 0 && child->getChildren()[0]->getValueType() == "ArraySizeList") {
                    ast::ASTNode* arraySizeList = child->getChildren()[0];
                    int totalsize = 1;
                    for (int i = 1; i < arraySizeList->getValueVector().size(); ++i) {
                        std::string dim = arraySizeList->getValueVector()[i];
                        totalsize *= std::stoi(dim.substr(1, dim.size() - 3));
                    }
                    if (startsWith(name, "__global")) {
                        instructions.push_back({ "GLOBAL", name, "", "" });
                        writeToFile("GLOBAL " + name + ":\n");
                    } else {
                        instructions.push_back({ "DEC", name, std::to_string(totalsize * 4), "" });
                        writeToFile("DEC " + name + " #" + std::to_string(totalsize * 4) + "\n");
                    }
                    // check array init
                    if (child->getChildren().size() > 1 && child->getChildren()[1]->getValueType() == "InitVal") {
                        ast::ASTNode* initVal = child->getChildren()[1];
                        if (initVal->getChildren().size() > 0) {
                            // non-empty init value
                            ast::ASTNode* assist = initVal->getChildren()[0];
                            int preExpId = -1;
                            if (startsWith(name, "__global")) {
                                for (auto exp : assist->getChildren()) {
                                    int expId = std::stoi(exp->getValueVector()[1]);
                                    if (expId != preExpId + 1) {
                                        for (int i = preExpId + 1; i < expId; ++i) {
                                            instructions.push_back({ "WORD", "0", "", "" });
                                            writeToFile(".WORD #0\n");
                                        }
                                    }
                                    translateGlobal(exp);
                                    preExpId = expId;
                                }
                                if (preExpId < totalsize - 1) {
                                    for (int i = preExpId + 1; i < totalsize; ++i) {
                                        instructions.push_back({ "WORD", "0", "", "" });
                                        writeToFile(".WORD #0\n");
                                    }
                                }
                            } else {
                                std::string arrayIndex = getNewTempName();
                                std::string placeExp = getNewTempName();
                                instructions.push_back({ "mv", arrayIndex, name, "" });
                                writeToFile(arrayIndex + " = " + name + "\n");
                                for (auto exp : assist->getChildren()) {
                                    int expId = std::stoi(exp->getValueVector()[1]);
                                    if (expId != preExpId + 1) {
                                        for (int i = preExpId + 1; i < expId; ++i) {
                                            // instructions.push_back({ "li", placeExp, "0", "" });
                                            writeToFile(placeExp + " = #0\n");
                                            instructions.push_back({ "sw", "zero", arrayIndex, "0" });
                                            writeToFile("*" + arrayIndex + " = " + placeExp + "\n");
                                            instructions.push_back({ "addi", arrayIndex, arrayIndex, "4" });
                                            writeToFile(arrayIndex + " = " + arrayIndex + " + #4\n");
                                        }
                                    }
                                    translateExp(exp->getChildren()[0], placeExp);
                                    instructions.push_back({ "sw", placeExp, arrayIndex, "0" });
                                    writeToFile("*" + arrayIndex + " = " + placeExp + "\n");
                                    instructions.push_back({ "addi", arrayIndex, arrayIndex, "4" });
                                    writeToFile(arrayIndex + " = " + arrayIndex + " + #4\n");
                                    preExpId = expId;
                                }
                                if (preExpId < totalsize - 1) {
                                    for (int i = preExpId + 1; i < totalsize; ++i) {
                                        // instructions.push_back({ "li", placeExp, "0", "" });
                                        writeToFile(placeExp + " = #0\n");
                                        instructions.push_back({ "sw", "zero", arrayIndex, "0" });
                                        writeToFile("*" + arrayIndex + " = " + placeExp + "\n");
                                        instructions.push_back({ "addi", arrayIndex, arrayIndex, "4" });
                                        writeToFile(arrayIndex + " = " + arrayIndex + " + #4\n");
                                    }
                                }
                            }
                        } else {
                            // empty init value, assign all elements to 0
                            if (startsWith(name, "__global")) {
                                for (int i = 0; i < totalsize; ++i) {
                                    instructions.push_back({ "WORD", "0", "", "" });
                                    writeToFile(".WORD #0\n");
                                }
                            } else {
                                std::string arrayIndex = getNewTempName();
                                std::string placeExp = getNewTempName();
                                instructions.push_back({ "mv", arrayIndex, name, "" });
                                writeToFile(arrayIndex + " = " + name + "\n");
                                for (int i = 0; i < totalsize; ++i) {
                                    // instructions.push_back({ "li", placeExp, "0", "" });
                                    writeToFile(placeExp + " = #0\n");
                                    instructions.push_back({ "sw", "zero", arrayIndex, "0" });
                                    writeToFile("*" + arrayIndex + " = " + placeExp + "\n");
                                    instructions.push_back({ "addi", arrayIndex, arrayIndex, "4" });
                                    writeToFile(arrayIndex + " = " + arrayIndex + " + #4\n");
                                }
                            }
                        }
                    } else {
                        if (startsWith(name, "__global")) {
                            for (int i = 0; i < totalsize; ++i) {
                                instructions.push_back({ "WORD", "0", "", "" });
                                writeToFile(".WORD #0\n");
                            }
                        }
                    }
                } else {
                    if (child->getChildren().size() > 0 && child->getChildren()[0]->getValueType() == "InitVal") {
                        // has init value
                        ast::ASTNode* initVal = child->getChildren()[0];
                        if (startsWith(name, "__global")) {
                            instructions.push_back({ "GLOBAL", name, "", "" });
                            writeToFile("GLOBAL " + name + ":\n");
                            translateGlobal(initVal);
                        } else {
                            translateExp(initVal->getChildren()[0], name);
                        }
                        
                    } else {
                        // no init value
                        if (startsWith(name, "__global")) {
                            // init with 0
                            instructions.push_back({ "GLOBAL", name, "", "" });
                            instructions.push_back({ "WORD", "0", "", "" });
                            writeToFile("GLOBAL " + name + ":\n .WORD #0\n");
                        }
                    }
                }
            }
        } else if (node->getValueType() == "FuncDef") {
            // function declaration
            std::string name = node->getValueVector()[2];
            ast::ASTNode* funcFParams = nullptr;
            if (node->getChildren()[0]->getValueType() == "FuncFParams") {
                funcFParams = node->getChildren()[0];
            }
            instructions.push_back({ "FUNCTION", name, "", "" });
            writeToFile("FUNCTION " + name + ":\n");
            if (funcFParams != nullptr) {
                for (auto param : funcFParams->getChildren()) {
                    instructions.push_back({ "PARAM", param->getValueVector()[2], "", "" });
                    writeToFile("PARAM " + param->getValueVector()[2] + "\n");
                }
            }
            for (auto child : node->getChildren()) {
                translate(child);
            }
        } else if (node->getValueType() == "Stmt") {
            translateStmt(node);
        } else {
            for (auto child : node->getChildren()) {
                translate(child);
            }
        }
    }
}