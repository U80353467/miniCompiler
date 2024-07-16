#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
#include "ast.hpp"

namespace irgenerator {
    struct instructionNode {
        std::string opcode;
        std::string arg1;
        std::string arg2;
        std::string arg3;
    };
    class IRGenerator {
    public:
        IRGenerator();
        IRGenerator(std::string IRoutputFile);
        std::string getNewTempName();
        std::string getNewLabelName();
        void translateExp(ast::ASTNode *node, std::string place);
        void translateStmt(ast::ASTNode *node);
        void translateCond(ast::ASTNode *node, std::string labelTrue, std::string labelFalse);
        void translateGlobal(ast::ASTNode *node);
        void translate(ast::ASTNode *node);
        void writeToFile(std::string content);
        void closeFile();
        std::list<instructionNode> instructions;
    private:
        std::ofstream IRoutputFile;
        int tempCount = 0;
        int labelCount = 0;
    };
}