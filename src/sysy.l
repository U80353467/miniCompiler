%option noinput
%option nounput
%option noyywrap
%option yylineno

%{
#include "ast.hpp"

#ifdef YYSTYPE
#undef YYSTYPE
#endif
#define YYSTYPE ast::ASTNode*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "y.tab.h"

%}

digit       [0-9]
OCT_digit   [0-7]
HEX_digit   [0-9a-fA-F]
letter [_A-za-z]
blank [ \t\n]
identifier [_a-zA-Z][_a-zA-Z0-9]*
singleLineComment "//".*
multipleLineComment "/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"

%%
{singleLineComment} { }
{multipleLineComment} { }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"return"        { return RETURN; }
"int"           { return INT; }
"void"          { return VOID; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"("             { return LPAREN; }
")"             { return RPAREN; }
","             { return COMMA; }
";"             { return SEMI; }
"="             { return ASSIGN; }
{identifier} { yylval = new ast::ASTNode(); yylval->appendValue(strdup(yytext)); return IDENT; }
(0{OCT_digit}+)|(0[xX]{HEX_digit}+)|({digit}+)      { yylval = new ast::ASTNode(); yylval->appendValue(strdup(yytext)); return INTCONST; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }
"+"             { return ADD; }
"-"             { return SUB; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }
{blank}         { }
.               { printf("ERROR(%s)\n", yytext); }

%%
