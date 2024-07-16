#include "ast.hpp"

namespace ast{
    static std::vector<int> list;
    ASTNode::ASTNode() = default;
    ASTNode::ASTNode(const ASTNode &node) = default;
    void ASTNode::print(std::ostream &os, size_t indent = 0) const{
        int last_indent = 0;
        for (auto i : list) {
            os << std::string(i - last_indent, ' ') << "|";
            last_indent = i;
        }
        if (indent == last_indent) {
            os << "-" << getValue() << std::endl;
        } else {
            os << std::string(indent - last_indent, ' ') << "|-" << getValue() << std::endl;
        }
        for (auto child : children) {
            if (children.size() > 1) {
                if (child == children.front()) {
                    list.push_back(indent + 2);
                } else if (child == children.back()) {
                    list.pop_back();
                }
            }
            child->print(os, indent + 2);
        }
    }

    void ASTNode::addChild(ASTNode *node) {
        children.push_back(node);
    }

    void ASTNode::appendValue(std::string val) {
        value.push_back(val);
    }

    std::string ASTNode::getValue() const{
        std::string valueAll = "";
        for (auto i : value) {
            valueAll += i + " ";
        }
        return valueAll;
    }

    std::string ASTNode::getValueType() const{
        return value[0];
    }

    std::vector<std::string>& ASTNode::getValueVector(){
        return value;
    }

    void ASTNode::setValue(int index, std::string val) {
        value[index] = val;
    }

    std::vector<ASTNode*>& ASTNode::getChildren(){
        return children;
    }

    void ASTNode::clearChildren() {
        children.clear();
    }

    Program::Program() {
        value.push_back("Program");
    }

    CompUnit::CompUnit() {
        value.push_back("CompUnit");
    }

    Decl::Decl() {
        value.push_back("Decl");
    }

    VarDecl::VarDecl() {
        value.push_back("VarDecl");
    }

    VarDefList::VarDefList() {
        value.push_back("VarDefList");
    }

    VarDef::VarDef() {
        value.push_back("VarDef");
    }

    ArraySizeList::ArraySizeList() {
        value.push_back("ArraySizeList");
    }

    InitValList::InitValList() {
        value.push_back("InitValList");
    }

    InitVal::InitVal() {
        value.push_back("InitVal");
    }

    FuncDef::FuncDef() {
        value.push_back("FuncDef");
    }

    FuncFParams::FuncFParams() {
        value.push_back("FuncFParams");
    }

    FuncFParam::FuncFParam() {
        value.push_back("FuncFParam");
    }

    Block::Block() {
        value.push_back("Block");
    }

    BlockItemList::BlockItemList() {
        value.push_back("BlockItemList");
    }

    BlockItem::BlockItem() {
        value.push_back("BlockItem");
    }

    Stmt::Stmt() {
        value.push_back("Stmt");
    }

    Exp::Exp() {
        value.push_back("Exp");
    }

    Cond::Cond() {
        value.push_back("Cond");
    }
    
    LVal::LVal() {
        value.push_back("LVal");
    }

    ArrayExpList::ArrayExpList() {
        value.push_back("ArrayExpList");
    }

    PrimaryExp::PrimaryExp() {
        value.push_back("PrimaryExp");
    }

    Number::Number() {
        value.push_back("Number");
    }

    UnaryExp::UnaryExp() {
        value.push_back("UnaryExp");
    }

    UnaryOp::UnaryOp() {
        value.push_back("UnaryOp");
    }

    FuncRParams::FuncRParams() {
        value.push_back("FuncRParams");
    }

    MulExp::MulExp() {
        value.push_back("MulExp");
    }

    AddExp::AddExp() {
        value.push_back("AddExp");
    }

    RelExp::RelExp() {
        value.push_back("RelExp");
    }

    EqExp::EqExp() {
        value.push_back("EqExp");
    }

    LAndExp::LAndExp() {
        value.push_back("LAndExp");
    }

    LOrExp::LOrExp() {
        value.push_back("LOrExp");
    }

    Assist::Assist() {
        value.push_back("Assist");
    }
}