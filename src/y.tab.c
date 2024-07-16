
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sysy.y"

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



/* Line 189 of yacc.c  */
#line 98 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 208 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    17,    21,
      23,    27,    29,    33,    36,    41,    45,    50,    52,    55,
      59,    61,    65,    72,    79,    85,    91,    93,    97,   100,
     105,   111,   115,   117,   120,   122,   124,   129,   132,   134,
     136,   142,   150,   156,   159,   163,   165,   167,   169,   172,
     176,   181,   185,   187,   189,   191,   193,   198,   202,   205,
     207,   209,   211,   213,   217,   219,   223,   227,   231,   233,
     237,   241,   243,   247,   251,   255,   259,   261,   265,   269,
     271,   275,   277
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    38,    -1,    45,    -1,    37,
      38,    -1,    37,    45,    -1,    39,    -1,     3,    40,    31,
      -1,    41,    -1,    40,    32,    41,    -1,    23,    -1,    23,
      33,    43,    -1,    23,    42,    -1,    23,    42,    33,    43,
      -1,    27,    24,    28,    -1,    42,    27,    24,    28,    -1,
      52,    -1,    25,    26,    -1,    25,    44,    26,    -1,    43,
      -1,    44,    32,    43,    -1,     3,    23,    29,    46,    30,
      48,    -1,     4,    23,    29,    46,    30,    48,    -1,     3,
      23,    29,    30,    48,    -1,     4,    23,    29,    30,    48,
      -1,    47,    -1,    46,    32,    47,    -1,     3,    23,    -1,
       3,    23,    27,    28,    -1,     3,    23,    27,    28,    42,
      -1,    25,    49,    26,    -1,    50,    -1,    49,    50,    -1,
      38,    -1,    51,    -1,    54,    33,    52,    31,    -1,    52,
      31,    -1,    31,    -1,    48,    -1,     5,    29,    53,    30,
      51,    -1,     5,    29,    53,    30,    51,     6,    51,    -1,
       7,    29,    53,    30,    51,    -1,     8,    31,    -1,     8,
      52,    31,    -1,    62,    -1,    66,    -1,    23,    -1,    23,
      55,    -1,    27,    52,    28,    -1,    55,    27,    52,    28,
      -1,    29,    52,    30,    -1,    54,    -1,    57,    -1,    24,
      -1,    56,    -1,    23,    29,    60,    30,    -1,    23,    29,
      30,    -1,    59,    58,    -1,     9,    -1,    10,    -1,    22,
      -1,    52,    -1,    60,    32,    52,    -1,    58,    -1,    61,
      11,    58,    -1,    61,    12,    58,    -1,    61,    13,    58,
      -1,    61,    -1,    62,     9,    61,    -1,    62,    10,    61,
      -1,    62,    -1,    63,    14,    62,    -1,    63,    15,    62,
      -1,    63,    16,    62,    -1,    63,    17,    62,    -1,    63,
      -1,    64,    18,    63,    -1,    64,    19,    63,    -1,    64,
      -1,    65,    20,    64,    -1,    65,    -1,    66,    21,    65,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    38,    39,    40,    41,    44,    47,    50,
      51,    54,    55,    56,    57,    60,    61,    64,    65,    66,
      69,    70,    73,    74,    75,    76,    79,    80,    83,    84,
      85,    88,    91,    92,    95,    96,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   110,   113,   116,   117,   120,
     121,   123,   124,   125,   128,   131,   132,   133,   134,   137,
     138,   139,   142,   143,   146,   147,   148,   149,   152,   153,
     154,   157,   158,   159,   160,   161,   164,   165,   166,   169,
     170,   173,   174
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "IF", "ELSE", "WHILE",
  "RETURN", "ADD", "SUB", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE",
  "EQ", "NE", "AND", "OR", "NOT", "IDENT", "INTCONST", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "SEMI", "COMMA", "ASSIGN",
  "THEN", "$accept", "Program", "CompUnit", "Decl", "VarDecl",
  "VarDefList", "VarDef", "ArraySizeList", "InitVal", "InitValList",
  "FuncDef", "FuncFParams", "FuncFParam", "Block", "BlockItemList",
  "BlockItem", "Stmt", "Exp", "Cond", "LVal", "ArrayExpList", "PrimaryExp",
  "Number", "UnaryExp", "UnaryOp", "FuncRParams", "MulExp", "AddExp",
  "RelExp", "EqExp", "LAndExp", "LOrExp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    37,    38,    39,    40,
      40,    41,    41,    41,    41,    42,    42,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    46,    46,    47,    47,
      47,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    53,    54,    54,    55,
      55,    56,    56,    56,    57,    58,    58,    58,    58,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    62,    62,
      62,    63,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     1,     3,     1,
       3,     1,     3,     2,     4,     3,     4,     1,     2,     3,
       1,     3,     6,     6,     5,     5,     1,     3,     2,     4,
       5,     3,     1,     2,     1,     1,     4,     2,     1,     1,
       5,     7,     5,     2,     3,     1,     1,     1,     2,     3,
       4,     3,     1,     1,     1,     1,     4,     3,     2,     1,
       1,     1,     1,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     7,     4,    11,     0,
       9,     0,     1,     5,     6,     0,     0,     0,    13,     8,
       0,     0,     0,     0,     0,     0,    26,    59,    60,    61,
      47,    54,     0,     0,    12,    17,    52,    55,    53,    64,
       0,    68,    45,     0,     0,    11,    10,     0,     0,    15,
      28,     0,    24,     0,     0,     0,     0,    48,    18,    20,
       0,     0,    58,     0,     0,     0,     0,     0,     0,    14,
      25,     0,     0,     0,     0,     0,     0,    38,    34,    39,
       0,    32,    35,     0,    52,    22,    27,     0,    57,    62,
       0,     0,    19,     0,    51,    65,    66,    67,    69,    70,
      16,    23,    29,     0,     0,    43,     0,    31,    33,    37,
       0,    49,    56,     0,     0,    21,    30,     0,    71,    76,
      79,    81,    46,     0,    44,     0,    63,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    40,
      72,    73,    74,    75,    77,    78,    80,    82,    42,     0,
      41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    78,     6,     9,    10,    18,    34,    60,
       7,    25,    26,    79,    80,    81,    82,    83,   117,    36,
      57,    37,    38,    39,    40,    90,    41,    42,   119,   120,
     121,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -127
static const yytype_int16 yypact[] =
{
       2,    -1,    25,    56,     2,  -127,  -127,  -127,   -17,    60,
    -127,    -4,  -127,  -127,  -127,    40,    11,    36,   -18,  -127,
      51,    14,    65,    76,   101,    -2,  -127,  -127,  -127,  -127,
      28,  -127,   141,   149,  -127,  -127,  -127,  -127,  -127,  -127,
     149,    95,   107,    77,    36,    -9,  -127,   101,    49,  -127,
     108,    80,  -127,   101,   134,   149,   132,   112,  -127,  -127,
      -5,   117,  -127,   149,   149,   149,   149,   149,   120,  -127,
    -127,   101,   121,    51,   123,   124,   109,  -127,  -127,  -127,
      44,  -127,  -127,   126,   127,  -127,  -127,   140,  -127,  -127,
      52,   149,  -127,    36,  -127,  -127,  -127,  -127,    95,    95,
    -127,  -127,   142,   149,   149,  -127,   143,  -127,  -127,  -127,
     149,  -127,  -127,   149,   147,  -127,   150,   146,   107,   106,
     125,   159,   160,   152,  -127,   153,  -127,  -127,   105,   149,
     149,   149,   149,   149,   149,   149,   149,   105,  -127,   174,
     107,   107,   107,   107,   106,   106,   125,   159,  -127,   105,
    -127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,    72,  -127,  -127,   163,    83,   -31,  -127,
     182,   166,   135,   -21,  -127,   110,  -126,   -13,    84,   -51,
    -127,  -127,  -127,    31,  -127,  -127,    58,   -96,    12,    57,
      55,  -127
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      84,    59,   139,    52,    35,     1,     2,   118,   118,    43,
      15,   148,    16,    69,    23,    44,    17,    23,    15,    35,
      61,    92,     8,   150,    17,    21,    70,    93,    53,    84,
      54,    35,    85,   140,   141,   142,   143,   118,   118,   118,
     118,    24,    87,    89,    47,    27,    28,    73,    11,    74,
     101,    75,    76,    27,    28,    55,    12,    56,    29,    30,
      31,    32,   115,   106,    22,    33,    29,    30,    31,    51,
     107,    62,     5,    33,    45,    77,    13,    84,   114,    71,
      35,    54,   112,    73,   113,    74,    84,    75,    76,    27,
      28,    19,    20,    49,    95,    96,    97,   125,    84,    50,
     126,    68,    29,    30,    31,    51,    63,    64,    65,    33,
      74,    77,    75,    76,    27,    28,    66,    67,    27,    28,
     129,   130,   131,   132,    98,    99,    51,    29,    30,    31,
      51,    29,    30,    31,    33,    72,    77,    23,    33,    91,
     105,    27,    28,   133,   134,   144,   145,    94,   100,   102,
      27,    28,   103,   104,    29,    30,    31,   109,    27,    28,
     110,    33,    88,    29,    30,    31,    32,    58,   111,    15,
      33,    29,    30,    31,   124,   127,   128,    43,    33,   135,
     149,   136,   137,    46,   138,   116,    14,    48,   123,    86,
     108,   147,   146
};

static const yytype_uint8 yycheck[] =
{
      51,    32,   128,    24,    17,     3,     4,   103,   104,    27,
      27,   137,    29,    44,     3,    33,    33,     3,    27,    32,
      33,    26,    23,   149,    33,    29,    47,    32,    30,    80,
      32,    44,    53,   129,   130,   131,   132,   133,   134,   135,
     136,    30,    55,    56,    30,     9,    10,     3,    23,     5,
      71,     7,     8,     9,    10,    27,     0,    29,    22,    23,
      24,    25,    93,    76,    24,    29,    22,    23,    24,    25,
      26,    40,     0,    29,    23,    31,     4,   128,    91,    30,
      93,    32,    30,     3,    32,     5,   137,     7,     8,     9,
      10,    31,    32,    28,    63,    64,    65,   110,   149,    23,
     113,    24,    22,    23,    24,    25,    11,    12,    13,    29,
       5,    31,     7,     8,     9,    10,     9,    10,     9,    10,
      14,    15,    16,    17,    66,    67,    25,    22,    23,    24,
      25,    22,    23,    24,    29,    27,    31,     3,    29,    27,
      31,     9,    10,    18,    19,   133,   134,    30,    28,    28,
       9,    10,    29,    29,    22,    23,    24,    31,     9,    10,
      33,    29,    30,    22,    23,    24,    25,    26,    28,    27,
      29,    22,    23,    24,    31,    28,    30,    27,    29,    20,
       6,    21,    30,    20,    31,   102,     4,    21,   104,    54,
      80,   136,   135
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    36,    37,    38,    39,    45,    23,    40,
      41,    23,     0,    38,    45,    27,    29,    33,    42,    31,
      32,    29,    24,     3,    30,    46,    47,     9,    10,    22,
      23,    24,    25,    29,    43,    52,    54,    56,    57,    58,
      59,    61,    62,    27,    33,    23,    41,    30,    46,    28,
      23,    25,    48,    30,    32,    27,    29,    55,    26,    43,
      44,    52,    58,    11,    12,    13,     9,    10,    24,    43,
      48,    30,    27,     3,     5,     7,     8,    31,    38,    48,
      49,    50,    51,    52,    54,    48,    47,    52,    30,    52,
      60,    27,    26,    32,    30,    58,    58,    58,    61,    61,
      28,    48,    28,    29,    29,    31,    52,    26,    50,    31,
      33,    28,    30,    32,    52,    43,    42,    53,    62,    63,
      64,    65,    66,    53,    31,    52,    52,    28,    30,    14,
      15,    16,    17,    18,    19,    20,    21,    30,    31,    51,
      62,    62,    62,    62,    63,    63,    64,    65,    51,     6,
      51
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 35 "sysy.y"
    { (yyval) = new ast::Program(); (yyval)->addChild((yyvsp[(1) - (1)])); root = (yyval);}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 38 "sysy.y"
    { (yyval) = new ast::CompUnit(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 39 "sysy.y"
    { (yyval) = new ast::CompUnit(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 40 "sysy.y"
    { (yyval) = new ast::CompUnit(); (yyval)->addChild((yyvsp[(1) - (2)])); (yyval)->addChild((yyvsp[(2) - (2)])); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 41 "sysy.y"
    { (yyval) = new ast::CompUnit(); (yyval)->addChild((yyvsp[(1) - (2)])); (yyval)->addChild((yyvsp[(2) - (2)])); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 44 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 47 "sysy.y"
    { (yyval) = new ast::VarDecl(); (yyval)->appendValue("int"); (yyval)->addChild((yyvsp[(2) - (3)]));}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 50 "sysy.y"
    { (yyval) = new ast::VarDefList(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 51 "sysy.y"
    { (yyval) = (yyvsp[(1) - (3)]); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 54 "sysy.y"
    { (yyval) = new ast::VarDef(); (yyval)->appendValue((yyvsp[(1) - (1)])->getValue()); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 55 "sysy.y"
    { (yyval) = new ast::VarDef(); (yyval)->appendValue((yyvsp[(1) - (3)])->getValue()); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 56 "sysy.y"
    { (yyval) = new ast::VarDef(); (yyval)->appendValue((yyvsp[(1) - (2)])->getValue()); (yyval)->addChild((yyvsp[(2) - (2)])); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 57 "sysy.y"
    { (yyval) = new ast::VarDef(); (yyval)->appendValue((yyvsp[(1) - (4)])->getValue()); (yyval)->addChild((yyvsp[(2) - (4)])); (yyval)->addChild((yyvsp[(4) - (4)])); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 60 "sysy.y"
    { (yyval) = new ast::ArraySizeList(); (yyval)->appendValue("[" + (yyvsp[(2) - (3)])->getValue() + "]"); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 61 "sysy.y"
    { (yyval) = (yyvsp[(1) - (4)]); (yyval)->appendValue("[" + (yyvsp[(3) - (4)])->getValue() + "]"); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 64 "sysy.y"
    { (yyval) = new ast::InitVal(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 65 "sysy.y"
    { (yyval) = new ast::InitVal(); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 66 "sysy.y"
    { (yyval) = new ast::InitVal(); (yyval)->addChild((yyvsp[(2) - (3)])); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 69 "sysy.y"
    { (yyval) = new ast::InitValList(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 70 "sysy.y"
    { (yyval) = (yyvsp[(1) - (3)]); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 73 "sysy.y"
    { (yyval) = new ast::FuncDef(); (yyval)->appendValue("int"); (yyval)->appendValue((yyvsp[(2) - (6)])->getValue()); (yyval)->addChild((yyvsp[(4) - (6)])); (yyval)->addChild((yyvsp[(6) - (6)])); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 74 "sysy.y"
    { (yyval) = new ast::FuncDef(); (yyval)->appendValue("void"); (yyval)->appendValue((yyvsp[(2) - (6)])->getValue()); (yyval)->addChild((yyvsp[(4) - (6)])); (yyval)->addChild((yyvsp[(6) - (6)])); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 75 "sysy.y"
    { (yyval) = new ast::FuncDef(); (yyval)->appendValue("int"); (yyval)->appendValue((yyvsp[(2) - (5)])->getValue()); (yyval)->addChild((yyvsp[(5) - (5)])); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 76 "sysy.y"
    { (yyval) = new ast::FuncDef(); (yyval)->appendValue("void"); (yyval)->appendValue((yyvsp[(2) - (5)])->getValue()); (yyval)->addChild((yyvsp[(5) - (5)])); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 79 "sysy.y"
    { (yyval) = new ast::FuncFParams(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 80 "sysy.y"
    { (yyval) = (yyvsp[(1) - (3)]); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 83 "sysy.y"
    { (yyval) = new ast::FuncFParam(); (yyval)->appendValue("int"); (yyval)->appendValue((yyvsp[(2) - (2)])->getValue()); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 84 "sysy.y"
    { (yyval) = new ast::FuncFParam(); (yyval)->appendValue("int"); (yyval)->appendValue((yyvsp[(2) - (4)])->getValue()); (yyval)->appendValue("[]"); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 85 "sysy.y"
    { (yyval) = new ast::FuncFParam(); (yyval)->appendValue("int"); (yyval)->appendValue((yyvsp[(2) - (5)])->getValue()); (yyval)->appendValue("[]"); (yyval)->addChild((yyvsp[(5) - (5)])); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 88 "sysy.y"
    { (yyval) = new ast::Block(); (yyval)->addChild((yyvsp[(2) - (3)])); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 91 "sysy.y"
    { (yyval) = new ast::BlockItemList(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 92 "sysy.y"
    { (yyval) = (yyvsp[(1) - (2)]); (yyval)->addChild((yyvsp[(2) - (2)])); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 95 "sysy.y"
    { (yyval) = new ast::BlockItem(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 96 "sysy.y"
    { (yyval) = new ast::BlockItem(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 99 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->appendValue("="); (yyval)->addChild((yyvsp[(1) - (4)])); (yyval)->addChild((yyvsp[(3) - (4)])); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 100 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->addChild((yyvsp[(1) - (2)])); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 101 "sysy.y"
    { (yyval) = new ast::Stmt(); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 102 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 103 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->appendValue("if"); (yyval)->addChild((yyvsp[(3) - (5)])); (yyval)->addChild((yyvsp[(5) - (5)])); (yyvsp[(5) - (5)])->appendValue("labelTrue"); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 104 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->appendValue("if"); (yyval)->addChild((yyvsp[(3) - (7)])); (yyval)->addChild((yyvsp[(5) - (7)])); (yyvsp[(5) - (7)])->appendValue("labelTrue"); (yyval)->addChild((yyvsp[(7) - (7)])); (yyvsp[(7) - (7)])->appendValue("labelFalse"); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 105 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->appendValue("while"); (yyval)->addChild((yyvsp[(3) - (5)])); (yyval)->addChild((yyvsp[(5) - (5)])); (yyvsp[(5) - (5)])->appendValue("labelBegin"); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 106 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->appendValue("return"); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 107 "sysy.y"
    { (yyval) = new ast::Stmt(); (yyval)->appendValue("return"); (yyval)->addChild((yyvsp[(2) - (3)])); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 110 "sysy.y"
    { (yyval) = new ast::Exp(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 113 "sysy.y"
    { (yyval) = new ast::Cond(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 116 "sysy.y"
    { (yyval) = new ast::LVal(); (yyval)->appendValue((yyvsp[(1) - (1)])->getValue()); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 117 "sysy.y"
    { (yyval) = new ast::LVal(); (yyval)->appendValue((yyvsp[(1) - (2)])->getValue()); (yyval)->addChild((yyvsp[(2) - (2)])); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 120 "sysy.y"
    { (yyval) = new ast::ArrayExpList(); (yyval)->addChild((yyvsp[(2) - (3)])); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 121 "sysy.y"
    { (yyval) = (yyvsp[(1) - (4)]); (yyval)->addChild((yyvsp[(3) - (4)])); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 123 "sysy.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 124 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 125 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 128 "sysy.y"
    { (yyval) = new ast::Number(); (yyval)->appendValue((yyvsp[(1) - (1)])->getValue()); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 131 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 132 "sysy.y"
    { (yyval) = new ast::UnaryExp(); (yyval)->appendValue((yyvsp[(1) - (4)])->getValue()); (yyval)->addChild((yyvsp[(3) - (4)])); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 133 "sysy.y"
    { (yyval) = new ast::UnaryExp(); (yyval)->appendValue((yyvsp[(1) - (3)])->getValue()); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 134 "sysy.y"
    { (yyval) = new ast::UnaryExp(); (yyval)->addChild((yyvsp[(1) - (2)])); (yyval)->addChild((yyvsp[(2) - (2)])); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 137 "sysy.y"
    { (yyval) = new ast::UnaryOp(); (yyval)->appendValue("+"); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 138 "sysy.y"
    { (yyval) = new ast::UnaryOp(); (yyval)->appendValue("-"); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 139 "sysy.y"
    { (yyval) = new ast::UnaryOp(); (yyval)->appendValue("!"); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 142 "sysy.y"
    { (yyval) = new ast::FuncRParams(); (yyval)->addChild((yyvsp[(1) - (1)])); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 143 "sysy.y"
    { (yyval) = (yyvsp[(1) - (3)]); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 146 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 147 "sysy.y"
    { (yyval) = new ast::MulExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("*"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 148 "sysy.y"
    { (yyval) = new ast::MulExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("/"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 149 "sysy.y"
    { (yyval) = new ast::MulExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("%"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 152 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 153 "sysy.y"
    { (yyval) = new ast::AddExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("+"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 154 "sysy.y"
    { (yyval) = new ast::AddExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("-"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 157 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 158 "sysy.y"
    { (yyval) = new ast::RelExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("<"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 159 "sysy.y"
    { (yyval) = new ast::RelExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue(">"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 160 "sysy.y"
    { (yyval) = new ast::RelExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("<="); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 161 "sysy.y"
    { (yyval) = new ast::RelExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue(">="); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 164 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 165 "sysy.y"
    { (yyval) = new ast::EqExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("=="); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 166 "sysy.y"
    { (yyval) = new ast::EqExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("!="); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 169 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 170 "sysy.y"
    { (yyval) = new ast::LAndExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("&&"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 173 "sysy.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 174 "sysy.y"
    { (yyval) = new ast::LOrExp(); (yyval)->addChild((yyvsp[(1) - (3)])); (yyval)->appendValue("||"); (yyval)->addChild((yyvsp[(3) - (3)])); }
    break;



/* Line 1455 of yacc.c  */
#line 2115 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 177 "sysy.y"


