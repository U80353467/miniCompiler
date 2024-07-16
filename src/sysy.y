%{
#include "ast.hpp"
#include <stdio.h>
void yyerror(const char *s);
extern int yylex(void);
extern FILE* yyin;
extern int yyparse(void);
extern int yylineno;
extern char* yytext;
#ifdef YYSTYPE
#undef YYSTYPE
#endif
#define YYSTYPE ast::ASTNode*

ast::ASTNode *root;

void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    fprintf(stderr, "  Text: %s\n", yytext);
    exit(-1);
}

%}

%token INT VOID IF ELSE WHILE RETURN
%token ADD SUB MUL DIV MOD LT GT LE GE EQ NE AND OR NOT
%token IDENT INTCONST
%token LBRACE RBRACE LBRACKET RBRACKET LPAREN RPAREN SEMI COMMA ASSIGN
%nonassoc THEN
%nonassoc ELSE

%start Program

%%
Program      : CompUnit { $$ = new ast::Program(); $$->addChild($1); root = $$;}
             ;

CompUnit     : Decl { $$ = new ast::CompUnit(); $$->addChild($1); }
             | FuncDef  { $$ = new ast::CompUnit(); $$->addChild($1); }
             | CompUnit Decl    { $$ = new ast::CompUnit(); $$->addChild($1); $$->addChild($2); }
             | CompUnit FuncDef { $$ = new ast::CompUnit(); $$->addChild($1); $$->addChild($2); }
             ;

Decl         : VarDecl  { $$ = $1; }
                ;

VarDecl      : INT VarDefList SEMI    { $$ = new ast::VarDecl(); $$->appendValue("int"); $$->addChild($2);}
                ;

VarDefList   : VarDef   { $$ = new ast::VarDefList(); $$->addChild($1); }
                | VarDefList COMMA VarDef   { $$ = $1; $$->addChild($3); }
                ;

VarDef       : IDENT    { $$ = new ast::VarDef(); $$->appendValue($1->getValue()); }
                | IDENT ASSIGN InitVal  { $$ = new ast::VarDef(); $$->appendValue($1->getValue()); $$->addChild($3); }
                | IDENT ArraySizeList  { $$ = new ast::VarDef(); $$->appendValue($1->getValue()); $$->addChild($2); }
                | IDENT ArraySizeList ASSIGN InitVal   { $$ = new ast::VarDef(); $$->appendValue($1->getValue()); $$->addChild($2); $$->addChild($4); }
                ;

ArraySizeList   : LBRACKET INTCONST RBRACKET { $$ = new ast::ArraySizeList(); $$->appendValue("[" + $2->getValue() + "]"); }
                | ArraySizeList LBRACKET INTCONST RBRACKET { $$ = $1; $$->appendValue("[" + $3->getValue() + "]"); }
                ;

InitVal      : Exp  { $$ = new ast::InitVal(); $$->addChild($1); }
                | LBRACE RBRACE { $$ = new ast::InitVal(); }
                | LBRACE InitValList RBRACE { $$ = new ast::InitVal(); $$->addChild($2); }
                ;

InitValList  : InitVal  { $$ = new ast::InitValList(); $$->addChild($1); }
                | InitValList COMMA InitVal { $$ = $1; $$->addChild($3); }
                ;

FuncDef      : INT IDENT LPAREN FuncFParams RPAREN Block   { $$ = new ast::FuncDef(); $$->appendValue("int"); $$->appendValue($2->getValue()); $$->addChild($4); $$->addChild($6); }
                | VOID IDENT LPAREN FuncFParams RPAREN Block  { $$ = new ast::FuncDef(); $$->appendValue("void"); $$->appendValue($2->getValue()); $$->addChild($4); $$->addChild($6); }
                | INT IDENT LPAREN RPAREN Block    { $$ = new ast::FuncDef(); $$->appendValue("int"); $$->appendValue($2->getValue()); $$->addChild($5); }
                | VOID IDENT LPAREN RPAREN Block   { $$ = new ast::FuncDef(); $$->appendValue("void"); $$->appendValue($2->getValue()); $$->addChild($5); }
                ;

FuncFParams  : FuncFParam   { $$ = new ast::FuncFParams(); $$->addChild($1); }
                | FuncFParams COMMA FuncFParam  { $$ = $1; $$->addChild($3); }
                ;

FuncFParam   : INT IDENT  { $$ = new ast::FuncFParam(); $$->appendValue("int"); $$->appendValue($2->getValue()); }
                | INT IDENT LBRACKET RBRACKET { $$ = new ast::FuncFParam(); $$->appendValue("int"); $$->appendValue($2->getValue()); $$->appendValue("[]"); }
                | INT IDENT LBRACKET RBRACKET ArraySizeList  { $$ = new ast::FuncFParam(); $$->appendValue("int"); $$->appendValue($2->getValue()); $$->appendValue("[]"); $$->addChild($5); }
                ;

Block        : LBRACE BlockItemList RBRACE  { $$ = new ast::Block(); $$->addChild($2); }
                ;

BlockItemList: BlockItem    { $$ = new ast::BlockItemList(); $$->addChild($1); }
                | BlockItemList BlockItem   { $$ = $1; $$->addChild($2); }
                ;

BlockItem    : Decl     { $$ = new ast::BlockItem(); $$->addChild($1); }
                | Stmt   { $$ = new ast::BlockItem(); $$->addChild($1); }
                ;

Stmt         : LVal ASSIGN Exp SEMI     { $$ = new ast::Stmt(); $$->appendValue("="); $$->addChild($1); $$->addChild($3); }
                | Exp SEMI  { $$ = new ast::Stmt(); $$->addChild($1); }
                | SEMI  { $$ = new ast::Stmt(); }
                | Block { $$ = new ast::Stmt(); $$->addChild($1); }
                | IF LPAREN Cond RPAREN Stmt %prec THEN    { $$ = new ast::Stmt(); $$->appendValue("if"); $$->addChild($3); $$->addChild($5); $5->appendValue("labelTrue"); }
                | IF LPAREN Cond RPAREN Stmt ELSE Stmt  { $$ = new ast::Stmt(); $$->appendValue("if"); $$->addChild($3); $$->addChild($5); $5->appendValue("labelTrue"); $$->addChild($7); $7->appendValue("labelFalse"); }
                | WHILE LPAREN Cond RPAREN Stmt { $$ = new ast::Stmt(); $$->appendValue("while"); $$->addChild($3); $$->addChild($5); $5->appendValue("labelBegin"); }
                | RETURN SEMI   { $$ = new ast::Stmt(); $$->appendValue("return"); }
                | RETURN Exp SEMI   { $$ = new ast::Stmt(); $$->appendValue("return"); $$->addChild($2); }
                ;

Exp          : AddExp   { $$ = new ast::Exp(); $$->addChild($1); }
                ;

Cond         : LOrExp   { $$ = new ast::Cond(); $$->addChild($1); }
                ;

LVal         : IDENT    { $$ = new ast::LVal(); $$->appendValue($1->getValue()); }
                | IDENT ArrayExpList   { $$ = new ast::LVal(); $$->appendValue($1->getValue()); $$->addChild($2); }
                ;

ArrayExpList     : LBRACKET Exp RBRACKET { $$ = new ast::ArrayExpList(); $$->addChild($2); }
                | ArrayExpList LBRACKET Exp RBRACKET { $$ = $1; $$->addChild($3); }

PrimaryExp   : LPAREN Exp RPAREN    { $$ = $2; }
                | LVal  { $$ = $1; }
                | Number    { $$ = $1; }
                ;

Number       : INTCONST { $$ = new ast::Number(); $$->appendValue($1->getValue()); }
                ;

UnaryExp     : PrimaryExp   { $$ = $1; }
                | IDENT LPAREN FuncRParams RPAREN   { $$ = new ast::UnaryExp(); $$->appendValue($1->getValue()); $$->addChild($3); }
                | IDENT LPAREN RPAREN   { $$ = new ast::UnaryExp(); $$->appendValue($1->getValue()); }
                | UnaryOp UnaryExp  { $$ = new ast::UnaryExp(); $$->addChild($1); $$->addChild($2); }
                ;

UnaryOp      : ADD  { $$ = new ast::UnaryOp(); $$->appendValue("+"); }
                | SUB   { $$ = new ast::UnaryOp(); $$->appendValue("-"); }
                | NOT   { $$ = new ast::UnaryOp(); $$->appendValue("!"); }
                ;

FuncRParams  : Exp  { $$ = new ast::FuncRParams(); $$->addChild($1); }
                | FuncRParams COMMA Exp { $$ = $1; $$->addChild($3); }
                ;

MulExp       : UnaryExp { $$ = $1; }
                | MulExp MUL UnaryExp   { $$ = new ast::MulExp(); $$->addChild($1); $$->appendValue("*"); $$->addChild($3); }
                | MulExp DIV UnaryExp   { $$ = new ast::MulExp(); $$->addChild($1); $$->appendValue("/"); $$->addChild($3); }
                | MulExp MOD UnaryExp   { $$ = new ast::MulExp(); $$->addChild($1); $$->appendValue("%"); $$->addChild($3); }
                ;

AddExp       : MulExp   { $$ = $1; }
                | AddExp ADD MulExp     { $$ = new ast::AddExp(); $$->addChild($1); $$->appendValue("+"); $$->addChild($3); }
                | AddExp SUB MulExp     { $$ = new ast::AddExp(); $$->addChild($1); $$->appendValue("-"); $$->addChild($3); }
                ;

RelExp       : AddExp   { $$ = $1; }
                | RelExp LT AddExp  { $$ = new ast::RelExp(); $$->addChild($1); $$->appendValue("<"); $$->addChild($3); }
                | RelExp GT AddExp  { $$ = new ast::RelExp(); $$->addChild($1); $$->appendValue(">"); $$->addChild($3); }
                | RelExp LE AddExp  { $$ = new ast::RelExp(); $$->addChild($1); $$->appendValue("<="); $$->addChild($3); }
                | RelExp GE AddExp  { $$ = new ast::RelExp(); $$->addChild($1); $$->appendValue(">="); $$->addChild($3); }
                ;

EqExp        : RelExp   { $$ = $1; }
                | EqExp EQ RelExp   { $$ = new ast::EqExp(); $$->addChild($1); $$->appendValue("=="); $$->addChild($3); }
                | EqExp NE RelExp   { $$ = new ast::EqExp(); $$->addChild($1); $$->appendValue("!="); $$->addChild($3); }
                ;

LAndExp      : EqExp    { $$ = $1; }
                | LAndExp AND EqExp { $$ = new ast::LAndExp(); $$->addChild($1); $$->appendValue("&&"); $$->addChild($3); }
                ;

LOrExp       : LAndExp  { $$ = $1; }
                | LOrExp OR LAndExp { $$ = new ast::LOrExp(); $$->addChild($1); $$->appendValue("||"); $$->addChild($3); }
                ;

%%
