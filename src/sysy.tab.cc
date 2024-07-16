/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/sysy.y"

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

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: compiler <filename>\n");
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    yyin = inputFile;
    yyparse();
    root->print(std::cout, 0);
    fclose(inputFile);

    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    fprintf(stderr, "  Text: %s\n", yytext);
    exit(-1);
}


#line 115 "src/sysy.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sysy.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_VOID = 4,                       /* VOID  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_ADD = 9,                        /* ADD  */
  YYSYMBOL_SUB = 10,                       /* SUB  */
  YYSYMBOL_MUL = 11,                       /* MUL  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_MOD = 13,                       /* MOD  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_IDENT = 23,                     /* IDENT  */
  YYSYMBOL_INTCONST = 24,                  /* INTCONST  */
  YYSYMBOL_LBRACE = 25,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 26,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 27,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 28,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_SEMI = 31,                      /* SEMI  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 33,                    /* ASSIGN  */
  YYSYMBOL_THEN = 34,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_Program = 36,                   /* Program  */
  YYSYMBOL_CompUnit = 37,                  /* CompUnit  */
  YYSYMBOL_Decl = 38,                      /* Decl  */
  YYSYMBOL_VarDecl = 39,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 40,                /* VarDefList  */
  YYSYMBOL_VarDef = 41,                    /* VarDef  */
  YYSYMBOL_ArraySizeList = 42,             /* ArraySizeList  */
  YYSYMBOL_InitVal = 43,                   /* InitVal  */
  YYSYMBOL_InitValList = 44,               /* InitValList  */
  YYSYMBOL_FuncDef = 45,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 46,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 47,                /* FuncFParam  */
  YYSYMBOL_Block = 48,                     /* Block  */
  YYSYMBOL_BlockItemList = 49,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 50,                 /* BlockItem  */
  YYSYMBOL_Stmt = 51,                      /* Stmt  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Cond = 53,                      /* Cond  */
  YYSYMBOL_LVal = 54,                      /* LVal  */
  YYSYMBOL_ArrayExpList = 55,              /* ArrayExpList  */
  YYSYMBOL_PrimaryExp = 56,                /* PrimaryExp  */
  YYSYMBOL_Number = 57,                    /* Number  */
  YYSYMBOL_UnaryExp = 58,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 59,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 60,               /* FuncRParams  */
  YYSYMBOL_MulExp = 61,                    /* MulExp  */
  YYSYMBOL_AddExp = 62,                    /* AddExp  */
  YYSYMBOL_RelExp = 63,                    /* RelExp  */
  YYSYMBOL_EqExp = 64,                     /* EqExp  */
  YYSYMBOL_LAndExp = 65,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 66                     /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    56,    57,    58,    59,    62,    65,    68,
      69,    72,    73,    74,    75,    78,    79,    82,    83,    84,
      87,    88,    91,    92,    93,    94,    97,    98,   101,   102,
     103,   106,   109,   110,   113,   114,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   128,   131,   134,   135,   138,
     139,   141,   142,   143,   146,   149,   150,   151,   152,   155,
     156,   157,   160,   161,   164,   165,   166,   167,   170,   171,
     172,   175,   176,   177,   178,   179,   182,   183,   184,   187,
     188,   191,   192
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "VOID", "IF",
  "ELSE", "WHILE", "RETURN", "ADD", "SUB", "MUL", "DIV", "MOD", "LT", "GT",
  "LE", "GE", "EQ", "NE", "AND", "OR", "NOT", "IDENT", "INTCONST",
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "SEMI",
  "COMMA", "ASSIGN", "THEN", "$accept", "Program", "CompUnit", "Decl",
  "VarDecl", "VarDefList", "VarDef", "ArraySizeList", "InitVal",
  "InitValList", "FuncDef", "FuncFParams", "FuncFParam", "Block",
  "BlockItemList", "BlockItem", "Stmt", "Exp", "Cond", "LVal",
  "ArrayExpList", "PrimaryExp", "Number", "UnaryExp", "UnaryOp",
  "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,    72,  -127,  -127,   163,    83,   -31,  -127,
     182,   166,   135,   -21,  -127,   110,  -126,   -13,    84,   -51,
    -127,  -127,  -127,    31,  -127,  -127,    58,   -96,    12,    57,
      55,  -127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,    78,     6,     9,    10,    18,    34,    60,
       7,    25,    26,    79,    80,    81,    82,    83,   117,    36,
      57,    37,    38,    39,    40,    90,    41,    42,   119,   120,
     121,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CompUnit  */
#line 53 "src/sysy.y"
                        { yyval = new ast::Program(); yyval->addChild(yyvsp[0]); root = yyval;}
#line 1279 "src/sysy.tab.cc"
    break;

  case 3: /* CompUnit: Decl  */
#line 56 "src/sysy.y"
                    { yyval = new ast::CompUnit(); yyval->addChild(yyvsp[0]); }
#line 1285 "src/sysy.tab.cc"
    break;

  case 4: /* CompUnit: FuncDef  */
#line 57 "src/sysy.y"
                        { yyval = new ast::CompUnit(); yyval->addChild(yyvsp[0]); }
#line 1291 "src/sysy.tab.cc"
    break;

  case 5: /* CompUnit: CompUnit Decl  */
#line 58 "src/sysy.y"
                                { yyval = new ast::CompUnit(); yyval->addChild(yyvsp[0]); }
#line 1297 "src/sysy.tab.cc"
    break;

  case 6: /* CompUnit: CompUnit FuncDef  */
#line 59 "src/sysy.y"
                                { yyval = new ast::CompUnit(); yyval->addChild(yyvsp[0]); }
#line 1303 "src/sysy.tab.cc"
    break;

  case 7: /* Decl: VarDecl  */
#line 62 "src/sysy.y"
                        { yyval = new ast::Decl(); yyval->addChild(yyvsp[0]); }
#line 1309 "src/sysy.tab.cc"
    break;

  case 8: /* VarDecl: INT VarDefList SEMI  */
#line 65 "src/sysy.y"
                                      { yyval = new ast::VarDecl(); yyval->appendValue("int"); yyval->addChild(yyvsp[-1]);}
#line 1315 "src/sysy.tab.cc"
    break;

  case 9: /* VarDefList: VarDef  */
#line 68 "src/sysy.y"
                        { yyval = new ast::VarDefList(); yyval->addChild(yyvsp[0]); }
#line 1321 "src/sysy.tab.cc"
    break;

  case 10: /* VarDefList: VarDefList COMMA VarDef  */
#line 69 "src/sysy.y"
                                            { yyval = yyvsp[-2]; yyval->addChild(yyvsp[0]); }
#line 1327 "src/sysy.tab.cc"
    break;

  case 11: /* VarDef: IDENT  */
#line 72 "src/sysy.y"
                        { yyval = new ast::VarDef(); yyval->appendValue(yyvsp[0]->getValue()); }
#line 1333 "src/sysy.tab.cc"
    break;

  case 12: /* VarDef: IDENT ASSIGN InitVal  */
#line 73 "src/sysy.y"
                                        { yyval = new ast::VarDef(); yyval->appendValue(yyvsp[-2]->getValue()); yyval->addChild(yyvsp[0]); }
#line 1339 "src/sysy.tab.cc"
    break;

  case 13: /* VarDef: IDENT ArraySizeList  */
#line 74 "src/sysy.y"
                                       { yyval = new ast::VarDef(); yyval->appendValue(yyvsp[-1]->getValue()); yyval->addChild(yyvsp[0]); }
#line 1345 "src/sysy.tab.cc"
    break;

  case 14: /* VarDef: IDENT ArraySizeList ASSIGN InitVal  */
#line 75 "src/sysy.y"
                                                       { yyval = new ast::VarDef(); yyval->appendValue(yyvsp[-3]->getValue()); yyval->addChild(yyvsp[-2]); yyval->addChild(yyvsp[0]); }
#line 1351 "src/sysy.tab.cc"
    break;

  case 15: /* ArraySizeList: LBRACKET INTCONST RBRACKET  */
#line 78 "src/sysy.y"
                                             { yyval = new ast::ArraySizeList(); yyval->appendValue("[" + yyvsp[-1]->getValue() + "]"); }
#line 1357 "src/sysy.tab.cc"
    break;

  case 16: /* ArraySizeList: ArraySizeList LBRACKET INTCONST RBRACKET  */
#line 79 "src/sysy.y"
                                                           { yyval = yyvsp[-3]; yyval->appendValue("[" + yyvsp[-1]->getValue() + "]"); }
#line 1363 "src/sysy.tab.cc"
    break;

  case 17: /* InitVal: Exp  */
#line 82 "src/sysy.y"
                    { yyval = new ast::InitVal(); yyval->addChild(yyvsp[0]); }
#line 1369 "src/sysy.tab.cc"
    break;

  case 18: /* InitVal: LBRACE RBRACE  */
#line 83 "src/sysy.y"
                                { yyval = new ast::InitVal(); }
#line 1375 "src/sysy.tab.cc"
    break;

  case 19: /* InitVal: LBRACE InitValList RBRACE  */
#line 84 "src/sysy.y"
                                            { yyval = new ast::InitVal(); yyval->addChild(yyvsp[-1]); }
#line 1381 "src/sysy.tab.cc"
    break;

  case 20: /* InitValList: InitVal  */
#line 87 "src/sysy.y"
                        { yyval = new ast::InitValList(); yyval->addChild(yyvsp[0]); }
#line 1387 "src/sysy.tab.cc"
    break;

  case 21: /* InitValList: InitValList COMMA InitVal  */
#line 88 "src/sysy.y"
                                            { yyval = yyvsp[-2]; yyval->addChild(yyvsp[0]); }
#line 1393 "src/sysy.tab.cc"
    break;

  case 22: /* FuncDef: INT IDENT LPAREN FuncFParams RPAREN Block  */
#line 91 "src/sysy.y"
                                                           { yyval = new ast::FuncDef(); yyval->appendValue("int"); yyval->appendValue(yyvsp[-4]->getValue()); yyval->addChild(yyvsp[-2]); yyval->addChild(yyvsp[0]); }
#line 1399 "src/sysy.tab.cc"
    break;

  case 23: /* FuncDef: VOID IDENT LPAREN FuncFParams RPAREN Block  */
#line 92 "src/sysy.y"
                                                              { yyval = new ast::FuncDef(); yyval->appendValue("void"); yyval->appendValue(yyvsp[-4]->getValue()); yyval->addChild(yyvsp[-2]); yyval->addChild(yyvsp[0]); }
#line 1405 "src/sysy.tab.cc"
    break;

  case 24: /* FuncDef: INT IDENT LPAREN RPAREN Block  */
#line 93 "src/sysy.y"
                                                   { yyval = new ast::FuncDef(); yyval->appendValue("int"); yyval->appendValue(yyvsp[-3]->getValue()); yyval->addChild(yyvsp[0]); }
#line 1411 "src/sysy.tab.cc"
    break;

  case 25: /* FuncDef: VOID IDENT LPAREN RPAREN Block  */
#line 94 "src/sysy.y"
                                                   { yyval = new ast::FuncDef(); yyval->appendValue("void"); yyval->appendValue(yyvsp[-3]->getValue()); yyval->addChild(yyvsp[0]); }
#line 1417 "src/sysy.tab.cc"
    break;

  case 26: /* FuncFParams: FuncFParam  */
#line 97 "src/sysy.y"
                            { yyval = new ast::FuncFParams(); yyval->addChild(yyvsp[0]); }
#line 1423 "src/sysy.tab.cc"
    break;

  case 27: /* FuncFParams: FuncFParams COMMA FuncFParam  */
#line 98 "src/sysy.y"
                                                { yyval = yyvsp[-2]; yyval->addChild(yyvsp[0]); }
#line 1429 "src/sysy.tab.cc"
    break;

  case 28: /* FuncFParam: INT IDENT  */
#line 101 "src/sysy.y"
                          { yyval = new ast::FuncFParam(); yyval->appendValue("int"); yyval->appendValue(yyvsp[0]->getValue()); }
#line 1435 "src/sysy.tab.cc"
    break;

  case 29: /* FuncFParam: INT IDENT LBRACKET RBRACKET  */
#line 102 "src/sysy.y"
                                              { yyval = new ast::FuncFParam(); yyval->appendValue("int"); yyval->appendValue(yyvsp[-2]->getValue()); yyval->appendValue("[]"); }
#line 1441 "src/sysy.tab.cc"
    break;

  case 30: /* FuncFParam: INT IDENT LBRACKET RBRACKET ArraySizeList  */
#line 103 "src/sysy.y"
                                                             { yyval = new ast::FuncFParam(); yyval->appendValue("int"); yyval->appendValue(yyvsp[-3]->getValue()); yyval->appendValue("[]"); yyval->addChild(yyvsp[0]); }
#line 1447 "src/sysy.tab.cc"
    break;

  case 31: /* Block: LBRACE BlockItemList RBRACE  */
#line 106 "src/sysy.y"
                                            { yyval = new ast::Block(); yyval->addChild(yyvsp[-1]); }
#line 1453 "src/sysy.tab.cc"
    break;

  case 32: /* BlockItemList: BlockItem  */
#line 109 "src/sysy.y"
                            { yyval = new ast::BlockItemList(); yyval->addChild(yyvsp[0]); }
#line 1459 "src/sysy.tab.cc"
    break;

  case 33: /* BlockItemList: BlockItemList BlockItem  */
#line 110 "src/sysy.y"
                                            { yyval = yyvsp[-1]; yyval->addChild(yyvsp[0]); }
#line 1465 "src/sysy.tab.cc"
    break;

  case 34: /* BlockItem: Decl  */
#line 113 "src/sysy.y"
                        { yyval = new ast::BlockItem(); yyval->addChild(yyvsp[0]); }
#line 1471 "src/sysy.tab.cc"
    break;

  case 35: /* BlockItem: Stmt  */
#line 114 "src/sysy.y"
                         { yyval = new ast::BlockItem(); yyval->addChild(yyvsp[0]); }
#line 1477 "src/sysy.tab.cc"
    break;

  case 36: /* Stmt: LVal ASSIGN Exp SEMI  */
#line 117 "src/sysy.y"
                                        { yyval = new ast::Stmt(); yyval->addChild(yyvsp[-3]); yyval->addChild(yyvsp[-1]); }
#line 1483 "src/sysy.tab.cc"
    break;

  case 37: /* Stmt: Exp SEMI  */
#line 118 "src/sysy.y"
                            { yyval = new ast::Stmt(); yyval->addChild(yyvsp[-1]); }
#line 1489 "src/sysy.tab.cc"
    break;

  case 38: /* Stmt: SEMI  */
#line 119 "src/sysy.y"
                        { yyval = new ast::Stmt(); }
#line 1495 "src/sysy.tab.cc"
    break;

  case 39: /* Stmt: Block  */
#line 120 "src/sysy.y"
                        { yyval = new ast::Stmt(); yyval->addChild(yyvsp[0]); }
#line 1501 "src/sysy.tab.cc"
    break;

  case 40: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 121 "src/sysy.y"
                                                           { yyval = new ast::Stmt(); yyval->appendValue("if"); yyval->addChild(yyvsp[-2]); yyval->addChild(yyvsp[0]); }
#line 1507 "src/sysy.tab.cc"
    break;

  case 41: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 122 "src/sysy.y"
                                                        { yyval = new ast::Stmt(); yyval->appendValue("if"); yyval->addChild(yyvsp[-4]); yyval->addChild(yyvsp[-2]); yyval->addChild(yyvsp[0]); }
#line 1513 "src/sysy.tab.cc"
    break;

  case 42: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 123 "src/sysy.y"
                                                { yyval = new ast::Stmt(); yyval->appendValue("while"); yyval->addChild(yyvsp[-2]); yyval->addChild(yyvsp[0]); }
#line 1519 "src/sysy.tab.cc"
    break;

  case 43: /* Stmt: RETURN SEMI  */
#line 124 "src/sysy.y"
                                { yyval = new ast::Stmt(); yyval->appendValue("return"); }
#line 1525 "src/sysy.tab.cc"
    break;

  case 44: /* Stmt: RETURN Exp SEMI  */
#line 125 "src/sysy.y"
                                    { yyval = new ast::Stmt(); yyval->appendValue("return"); yyval->addChild(yyvsp[-1]); }
#line 1531 "src/sysy.tab.cc"
    break;

  case 45: /* Exp: AddExp  */
#line 128 "src/sysy.y"
                        { yyval = new ast::Exp(); yyval->addChild(yyvsp[0]); }
#line 1537 "src/sysy.tab.cc"
    break;

  case 46: /* Cond: LOrExp  */
#line 131 "src/sysy.y"
                        { yyval = new ast::Cond(); yyval->addChild(yyvsp[0]); }
#line 1543 "src/sysy.tab.cc"
    break;

  case 47: /* LVal: IDENT  */
#line 134 "src/sysy.y"
                        { yyval = new ast::LVal(); yyval->appendValue(yyvsp[0]->getValue()); }
#line 1549 "src/sysy.tab.cc"
    break;

  case 48: /* LVal: IDENT ArrayExpList  */
#line 135 "src/sysy.y"
                                       { yyval = new ast::LVal(); yyval->appendValue(yyvsp[-1]->getValue()); yyval->addChild(yyvsp[0]); }
#line 1555 "src/sysy.tab.cc"
    break;

  case 49: /* ArrayExpList: LBRACKET Exp RBRACKET  */
#line 138 "src/sysy.y"
                                         { yyval = new ast::ArrayExpList(); yyval->addChild(yyvsp[-1]); }
#line 1561 "src/sysy.tab.cc"
    break;

  case 50: /* ArrayExpList: ArrayExpList LBRACKET Exp RBRACKET  */
#line 139 "src/sysy.y"
                                                     { yyval = yyvsp[-3]; yyval->addChild(yyvsp[-1]); }
#line 1567 "src/sysy.tab.cc"
    break;

  case 51: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 141 "src/sysy.y"
                                    { yyval = new ast::PrimaryExp(); yyval->addChild(yyvsp[-1]); }
#line 1573 "src/sysy.tab.cc"
    break;

  case 52: /* PrimaryExp: LVal  */
#line 142 "src/sysy.y"
                        { yyval = new ast::PrimaryExp(); yyval->addChild(yyvsp[0]); }
#line 1579 "src/sysy.tab.cc"
    break;

  case 53: /* PrimaryExp: Number  */
#line 143 "src/sysy.y"
                            { yyval = new ast::PrimaryExp(); yyval->addChild(yyvsp[0]); }
#line 1585 "src/sysy.tab.cc"
    break;

  case 54: /* Number: INTCONST  */
#line 146 "src/sysy.y"
                        { yyval = new ast::Number(); yyval->appendValue(yyvsp[0]->getValue()); }
#line 1591 "src/sysy.tab.cc"
    break;

  case 55: /* UnaryExp: PrimaryExp  */
#line 149 "src/sysy.y"
                            { yyval = new ast::UnaryExp(); yyval->addChild(yyvsp[0]); }
#line 1597 "src/sysy.tab.cc"
    break;

  case 56: /* UnaryExp: IDENT LPAREN FuncRParams RPAREN  */
#line 150 "src/sysy.y"
                                                    { yyval = new ast::UnaryExp(); yyval->appendValue(yyvsp[-3]->getValue()); yyval->addChild(yyvsp[-1]); }
#line 1603 "src/sysy.tab.cc"
    break;

  case 57: /* UnaryExp: IDENT LPAREN RPAREN  */
#line 151 "src/sysy.y"
                                        { yyval = new ast::UnaryExp(); yyval->appendValue(yyvsp[-2]->getValue()); }
#line 1609 "src/sysy.tab.cc"
    break;

  case 58: /* UnaryExp: UnaryOp UnaryExp  */
#line 152 "src/sysy.y"
                                    { yyval = new ast::UnaryExp(); yyval->addChild(yyvsp[-1]); yyval->addChild(yyvsp[0]); }
#line 1615 "src/sysy.tab.cc"
    break;

  case 59: /* UnaryOp: ADD  */
#line 155 "src/sysy.y"
                    { yyval = new ast::UnaryOp(); yyval->appendValue("+"); }
#line 1621 "src/sysy.tab.cc"
    break;

  case 60: /* UnaryOp: SUB  */
#line 156 "src/sysy.y"
                        { yyval = new ast::UnaryOp(); yyval->appendValue("-"); }
#line 1627 "src/sysy.tab.cc"
    break;

  case 61: /* UnaryOp: NOT  */
#line 157 "src/sysy.y"
                        { yyval = new ast::UnaryOp(); yyval->appendValue("!"); }
#line 1633 "src/sysy.tab.cc"
    break;

  case 62: /* FuncRParams: Exp  */
#line 160 "src/sysy.y"
                    { yyval = new ast::FuncRParams(); yyval->addChild(yyvsp[0]); }
#line 1639 "src/sysy.tab.cc"
    break;

  case 63: /* FuncRParams: FuncRParams COMMA Exp  */
#line 161 "src/sysy.y"
                                        { yyval = yyvsp[-2]; yyval->addChild(yyvsp[0]); }
#line 1645 "src/sysy.tab.cc"
    break;

  case 64: /* MulExp: UnaryExp  */
#line 164 "src/sysy.y"
                        { yyval = new ast::MulExp(); yyval->addChild(yyvsp[0]);}
#line 1651 "src/sysy.tab.cc"
    break;

  case 65: /* MulExp: MulExp MUL UnaryExp  */
#line 165 "src/sysy.y"
                                        { yyval = new ast::MulExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("*"); yyval->addChild(yyvsp[0]); }
#line 1657 "src/sysy.tab.cc"
    break;

  case 66: /* MulExp: MulExp DIV UnaryExp  */
#line 166 "src/sysy.y"
                                        { yyval = new ast::MulExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("/"); yyval->addChild(yyvsp[0]); }
#line 1663 "src/sysy.tab.cc"
    break;

  case 67: /* MulExp: MulExp MOD UnaryExp  */
#line 167 "src/sysy.y"
                                        { yyval = new ast::MulExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("%"); yyval->addChild(yyvsp[0]); }
#line 1669 "src/sysy.tab.cc"
    break;

  case 68: /* AddExp: MulExp  */
#line 170 "src/sysy.y"
                        { yyval = new ast::AddExp(); yyval->addChild(yyvsp[0]); }
#line 1675 "src/sysy.tab.cc"
    break;

  case 69: /* AddExp: AddExp ADD MulExp  */
#line 171 "src/sysy.y"
                                        { yyval = new ast::AddExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("+"); yyval->addChild(yyvsp[0]); }
#line 1681 "src/sysy.tab.cc"
    break;

  case 70: /* AddExp: AddExp SUB MulExp  */
#line 172 "src/sysy.y"
                                        { yyval = new ast::AddExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("-"); yyval->addChild(yyvsp[0]); }
#line 1687 "src/sysy.tab.cc"
    break;

  case 71: /* RelExp: AddExp  */
#line 175 "src/sysy.y"
                        { yyval = new ast::RelExp(); yyval->addChild(yyvsp[0]); }
#line 1693 "src/sysy.tab.cc"
    break;

  case 72: /* RelExp: RelExp LT AddExp  */
#line 176 "src/sysy.y"
                                    { yyval = new ast::RelExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("<"); yyval->addChild(yyvsp[0]); }
#line 1699 "src/sysy.tab.cc"
    break;

  case 73: /* RelExp: RelExp GT AddExp  */
#line 177 "src/sysy.y"
                                    { yyval = new ast::RelExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue(">"); yyval->addChild(yyvsp[0]); }
#line 1705 "src/sysy.tab.cc"
    break;

  case 74: /* RelExp: RelExp LE AddExp  */
#line 178 "src/sysy.y"
                                    { yyval = new ast::RelExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("<="); yyval->addChild(yyvsp[0]); }
#line 1711 "src/sysy.tab.cc"
    break;

  case 75: /* RelExp: RelExp GE AddExp  */
#line 179 "src/sysy.y"
                                    { yyval = new ast::RelExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue(">="); yyval->addChild(yyvsp[0]); }
#line 1717 "src/sysy.tab.cc"
    break;

  case 76: /* EqExp: RelExp  */
#line 182 "src/sysy.y"
                        { yyval = new ast::EqExp(); yyval->addChild(yyvsp[0]); }
#line 1723 "src/sysy.tab.cc"
    break;

  case 77: /* EqExp: EqExp EQ RelExp  */
#line 183 "src/sysy.y"
                                    { yyval = new ast::EqExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("=="); yyval->addChild(yyvsp[0]); }
#line 1729 "src/sysy.tab.cc"
    break;

  case 78: /* EqExp: EqExp NE RelExp  */
#line 184 "src/sysy.y"
                                    { yyval = new ast::EqExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("!="); yyval->addChild(yyvsp[0]); }
#line 1735 "src/sysy.tab.cc"
    break;

  case 79: /* LAndExp: EqExp  */
#line 187 "src/sysy.y"
                        { yyval = new ast::LAndExp(); yyval->addChild(yyvsp[0]); }
#line 1741 "src/sysy.tab.cc"
    break;

  case 80: /* LAndExp: LAndExp AND EqExp  */
#line 188 "src/sysy.y"
                                    { yyval = new ast::LAndExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("&&"); yyval->addChild(yyvsp[0]); }
#line 1747 "src/sysy.tab.cc"
    break;

  case 81: /* LOrExp: LAndExp  */
#line 191 "src/sysy.y"
                        { yyval = new ast::LOrExp(); yyval->addChild(yyvsp[0]); }
#line 1753 "src/sysy.tab.cc"
    break;

  case 82: /* LOrExp: LOrExp OR LAndExp  */
#line 192 "src/sysy.y"
                                    { yyval = new ast::LOrExp(); yyval->addChild(yyvsp[-2]); yyval->appendValue("||"); yyval->addChild(yyvsp[0]); }
#line 1759 "src/sysy.tab.cc"
    break;


#line 1763 "src/sysy.tab.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 195 "src/sysy.y"
