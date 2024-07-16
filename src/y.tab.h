
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     VOID = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     RETURN = 263,
     ADD = 264,
     SUB = 265,
     MUL = 266,
     DIV = 267,
     MOD = 268,
     LT = 269,
     GT = 270,
     LE = 271,
     GE = 272,
     EQ = 273,
     NE = 274,
     AND = 275,
     OR = 276,
     NOT = 277,
     IDENT = 278,
     INTCONST = 279,
     LBRACE = 280,
     RBRACE = 281,
     LBRACKET = 282,
     RBRACKET = 283,
     LPAREN = 284,
     RPAREN = 285,
     SEMI = 286,
     COMMA = 287,
     ASSIGN = 288,
     THEN = 289
   };
#endif
/* Tokens.  */
#define INT 258
#define VOID 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define RETURN 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define LT 269
#define GT 270
#define LE 271
#define GE 272
#define EQ 273
#define NE 274
#define AND 275
#define OR 276
#define NOT 277
#define IDENT 278
#define INTCONST 279
#define LBRACE 280
#define RBRACE 281
#define LBRACKET 282
#define RBRACKET 283
#define LPAREN 284
#define RPAREN 285
#define SEMI 286
#define COMMA 287
#define ASSIGN 288
#define THEN 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


