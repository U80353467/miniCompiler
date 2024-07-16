#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace ast {
    class ASTNode {
    public:
        ASTNode();
        ASTNode(const ASTNode &node);
        virtual void print(std::ostream &os, size_t indent) const;
        void addChild(ASTNode *node);
        void appendValue(std::string val);
        std::string getValue() const;
        std::string getValueType() const;
        std::vector<std::string>& getValueVector();
        void setValue(int index, std::string val);
        std::vector<ASTNode*>& getChildren();
        void clearChildren();
        std::string irName;
    protected:
        std::vector<std::string> value;
    private:
        std::vector<ASTNode*> children;
    };

    class Program : public ASTNode {
    public:
        Program();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class CompUnit : public ASTNode {
    public:
        CompUnit();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class Decl : public ASTNode {
    public:
        Decl();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class VarDecl : public ASTNode {
    public:
        VarDecl();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class VarDefList : public ASTNode {
    public:
        VarDefList();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class VarDef : public ASTNode {
    public:
        VarDef();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class ArraySizeList : public ASTNode {
    public:
        ArraySizeList();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class InitValList : public ASTNode {
    public:
        InitValList();
        //void print(std::ostream &os, size_t indent = 0) const override;
    }; 

    class InitVal : public ASTNode {
    public:
        InitVal();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class FuncDef : public ASTNode {
    public:
        FuncDef();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class FuncFParams : public ASTNode {
    public:
        FuncFParams();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class FuncFParam : public ASTNode {
    public:
        FuncFParam();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class Block : public ASTNode {
    public:
        Block();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class BlockItemList : public ASTNode {
    public:
        BlockItemList();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class BlockItem : public ASTNode {
    public:
        BlockItem();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class Stmt : public ASTNode {
    public:
        Stmt();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };
    
    class Exp : public ASTNode {
    public:
        Exp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class Cond : public ASTNode {
    public:
        Cond();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class LVal : public ASTNode {
    public:
        LVal();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class ArrayExpList : public ASTNode {
    public:
        ArrayExpList();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class PrimaryExp : public ASTNode {
    public:
        PrimaryExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class Number : public ASTNode {
    public:
        Number();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class UnaryExp : public ASTNode {
    public:
        UnaryExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };
    
    class UnaryOp : public ASTNode {
    public:
        UnaryOp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class FuncRParams : public ASTNode {
    public:
        FuncRParams();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class MulExp : public ASTNode {
    public:
        MulExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class AddExp : public ASTNode {
    public:
        AddExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class RelExp : public ASTNode {
    public:
        RelExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class EqExp : public ASTNode {
    public:
        EqExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class LAndExp : public ASTNode {
    public:
        LAndExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class LOrExp : public ASTNode {
    public:
        LOrExp();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

    class Assist : public ASTNode {
    public:
        Assist();
        //void print(std::ostream &os, size_t indent = 0) const override;
    };

}