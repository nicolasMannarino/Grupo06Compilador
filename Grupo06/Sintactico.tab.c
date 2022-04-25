
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
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "TablaSimbolos.h"

extern FILE* yyin;
FILE* archTS;



/* Line 189 of yacc.c  */
#line 85 "Sintactico.tab.c"

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
     WHILE = 258,
     IF = 259,
     ELSE = 260,
     WRITE = 261,
     READ = 262,
     AND = 263,
     OR = 264,
     NOT = 265,
     DECVAR = 266,
     ENDDEC = 267,
     INLIST = 268,
     TAKE = 269,
     FLOAT = 270,
     STRING = 271,
     INT = 272,
     OP_MAS = 273,
     OP_REST = 274,
     OP_MULT = 275,
     OP_DIV = 276,
     OP_ASIG = 277,
     COMP_DIST = 278,
     COMP_MAY = 279,
     COMP_MEN = 280,
     COMP_IGUAL = 281,
     COMP_MAYOI = 282,
     COMP_MENOI = 283,
     COND_AND = 284,
     COND_OR = 285,
     COND_NOT = 286,
     P_A = 287,
     P_C = 288,
     LL_A = 289,
     LL_C = 290,
     C_A = 291,
     C_C = 292,
     COMA = 293,
     PYC = 294,
     DP = 295,
     ID = 296,
     CTE_INT = 297,
     CTE_FLOAT = 298,
     CTE_STRING = 299,
     COMENT = 300,
     whitespace = 301,
     linefeed = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 174 "Sintactico.tab.c"

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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    13,    17,    22,    26,
      30,    32,    34,    36,    38,    40,    42,    44,    46,    48,
      50,    52,    58,    64,    74,    78,    84,    90,    94,   100,
     106,   109,   114,   118,   120,   124,   128,   132,   136,   140,
     144,   147,   151,   160,   171,   173,   175,   177,   179,   183,
     185,   187,   190,   192,   195,   197,   201,   203,   207,   209,
     211,   215,   217,   219,   222,   224,   227,   229,   231,   235,
     237,   239,   241,   243,   246,   249,   251,   253,   256,   258,
     260
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    51,    50,    -1,    55,    50,
      -1,    55,    -1,    11,    52,    12,    -1,    53,    40,    54,
      52,    -1,    53,    40,    54,    -1,    53,    38,    41,    -1,
      41,    -1,    16,    -1,    17,    -1,    15,    -1,    56,    -1,
      57,    -1,    60,    -1,    72,    -1,    62,    -1,    73,    -1,
      61,    -1,     3,    58,    34,    50,    35,    -1,     4,    58,
      34,    50,    35,    -1,     4,    58,    34,    50,    35,     5,
      34,    50,    35,    -1,    58,    29,    59,    -1,    32,    58,
      29,    59,    33,    -1,    32,    58,    29,    58,    33,    -1,
      58,    30,    59,    -1,    32,    58,    30,    59,    33,    -1,
      32,    58,    30,    58,    33,    -1,    31,    58,    -1,    32,
      31,    59,    33,    -1,    32,    59,    33,    -1,    59,    -1,
      74,    25,    74,    -1,    74,    24,    74,    -1,    74,    28,
      74,    -1,    74,    27,    74,    -1,    74,    26,    74,    -1,
      74,    23,    74,    -1,    31,    74,    -1,    41,    22,    67,
      -1,    13,    32,    41,    39,    36,    66,    37,    33,    -1,
      14,    32,    63,    39,    42,    39,    36,    64,    37,    33,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    65,
      39,    64,    -1,    65,    -1,    42,    -1,    19,    42,    -1,
      43,    -1,    19,    43,    -1,    41,    -1,    67,    39,    66,
      -1,    67,    -1,    67,    70,    68,    -1,    68,    -1,    60,
      -1,    68,    71,    69,    -1,    69,    -1,    42,    -1,    19,
      42,    -1,    43,    -1,    19,    43,    -1,    44,    -1,    41,
      -1,    32,    67,    33,    -1,    18,    -1,    19,    -1,    21,
      -1,    20,    -1,     6,    74,    -1,     7,    41,    -1,    41,
      -1,    42,    -1,    19,    42,    -1,    44,    -1,    43,    -1,
      19,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    73,    74,    75,    78,    81,    82,    85,
      86,    89,    90,    91,    94,    95,    96,    97,    98,    99,
     100,   103,   106,   107,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   122,   123,   124,   125,   126,   127,
     128,   131,   134,   137,   140,   141,   142,   143,   146,   147,
     150,   151,   152,   153,   154,   157,   158,   161,   162,   163,
     166,   167,   170,   171,   172,   173,   174,   175,   176,   179,
     180,   183,   184,   187,   190,   193,   194,   195,   196,   197,
     198
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "IF", "ELSE", "WRITE", "READ",
  "AND", "OR", "NOT", "DECVAR", "ENDDEC", "INLIST", "TAKE", "FLOAT",
  "STRING", "INT", "OP_MAS", "OP_REST", "OP_MULT", "OP_DIV", "OP_ASIG",
  "COMP_DIST", "COMP_MAY", "COMP_MEN", "COMP_IGUAL", "COMP_MAYOI",
  "COMP_MENOI", "COND_AND", "COND_OR", "COND_NOT", "P_A", "P_C", "LL_A",
  "LL_C", "C_A", "C_C", "COMA", "PYC", "DP", "ID", "CTE_INT", "CTE_FLOAT",
  "CTE_STRING", "COMENT", "whitespace", "linefeed", "$accept", "programa",
  "sentencia", "declaracion", "listaDeclaraciones", "listaID", "tipoDato",
  "estructura", "while", "if", "condicionFinal", "condicion", "asign",
  "inlist", "take", "signo", "valores", "valor", "listaExpresiones",
  "expresion", "termino", "operando", "sumayresta", "multydiv", "write",
  "read", "factor", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    62,    63,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    73,    74,    74,    74,    74,    74,
      74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     3,     4,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     9,     3,     5,     5,     3,     5,     5,
       2,     4,     3,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     8,    10,     1,     1,     1,     1,     3,     1,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       3,     1,     1,     2,     1,     2,     1,     1,     3,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     1,     1,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     5,    14,    15,    16,    20,    18,    17,    19,
       0,     0,     0,    75,    76,    79,    78,     0,    33,     0,
       0,    73,    74,    10,     0,     0,     0,     0,     0,     1,
       3,     4,    77,    80,    30,    40,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,    44,    45,    46,    47,     0,     0,     0,
      67,    62,    64,    66,    59,    41,    58,    61,    33,     0,
       0,    32,     0,    24,    27,     0,    39,    35,    34,    38,
      37,    36,     0,     9,    13,    11,    12,     8,     0,     0,
      63,    65,     0,    69,    70,     0,    72,    71,     0,    31,
       0,    24,     0,    27,    40,    21,    22,     7,     0,     0,
      68,    67,    57,    60,    26,    25,    29,    28,     0,     0,
      56,     0,     0,     0,     0,     0,     0,    42,    55,     0,
      54,    50,    52,     0,    49,    23,    51,    53,     0,     0,
      43,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    34,    35,    97,    12,    13,    14,
      44,    28,    15,    16,    17,    67,   143,   144,   129,   130,
      76,    77,   105,   108,    18,    19,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -37
static const yytype_int16 yypact[] =
{
       8,    31,    31,    81,   -35,   -28,   -14,    14,    19,    76,
     -37,     8,     8,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -17,    31,    46,   -37,   -37,   -37,   -37,    37,   -37,    82,
      67,   -37,   -37,   -37,    52,    -4,    58,   115,    51,   -37,
     -37,   -37,   -37,   -37,     9,    82,    31,    39,    84,     1,
       1,     8,    81,    81,    81,    81,    81,    81,     8,   -37,
      79,    64,    92,   -37,   -37,   -37,   -37,   100,    60,    51,
      19,   -37,   -37,   -37,   -37,    93,    98,   -37,   107,    31,
      31,   -37,    81,   -37,   -37,   106,   -37,   -37,   -37,   -37,
     -37,   -37,   108,   -37,   -37,   -37,   -37,   -28,   109,   102,
     -37,   -37,    -9,   -37,   -37,    72,   -37,   -37,    72,   -37,
      97,   113,    99,   114,   -37,   -37,   137,   -37,    51,   110,
     -37,   -37,    98,   -37,   -37,   -37,   -37,   -37,   116,   111,
      -2,   117,     8,   118,    51,    10,   119,   -37,   -37,    95,
     -37,   -37,   -37,   120,   121,   -37,   -37,   -37,   122,    10,
     -37,   -37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -11,   -37,    55,   -37,   -37,   -37,   -37,   -37,
       6,   -19,   -36,   -37,   -37,   -37,     7,   -37,    24,   -34,
      54,    53,   -37,   -37,   -37,   -37,     2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      40,    41,    74,    48,    75,    31,    32,    27,    30,   103,
     104,     1,     2,    33,     3,     4,   103,   104,    36,     5,
      20,     6,     7,    45,   120,    42,    43,    78,    47,   139,
      83,    84,    82,    74,    60,   102,    61,   134,    49,    50,
      85,    38,    23,    24,    25,    26,    37,    92,    45,     8,
      20,   140,   141,   142,    86,    87,    88,    89,    90,    91,
     111,   113,    21,    22,    59,    20,    49,    50,    79,    80,
      68,    51,    23,    24,    25,    26,    39,    46,    22,    94,
      95,    96,    74,    69,   114,   110,   112,    23,    24,    25,
      26,    68,    70,    71,    72,    73,    49,    50,    74,    62,
      20,    58,   100,   101,    69,    52,    53,    54,    55,    56,
      57,   103,   104,   121,    71,    72,    73,    81,   106,   107,
      93,   136,    23,    24,    25,    26,    49,    50,    49,    50,
     124,    98,   126,    63,    64,    65,    66,   146,   147,    99,
     109,   115,   128,   116,   119,   118,   125,   127,   133,   131,
     132,   137,   117,   135,   145,   150,   151,   148,   138,   122,
     149,   123
};

static const yytype_uint8 yycheck[] =
{
      11,    12,    38,    22,    38,     3,    41,     1,     2,    18,
      19,     3,     4,    41,     6,     7,    18,    19,    32,    11,
      19,    13,    14,    21,    33,    42,    43,    46,    22,    19,
      49,    50,    31,    69,    38,    69,    40,    39,    29,    30,
      51,    22,    41,    42,    43,    44,    32,    58,    46,    41,
      19,    41,    42,    43,    52,    53,    54,    55,    56,    57,
      79,    80,    31,    32,    12,    19,    29,    30,    29,    30,
      19,    34,    41,    42,    43,    44,     0,    31,    32,    15,
      16,    17,   118,    32,    82,    79,    80,    41,    42,    43,
      44,    19,    41,    42,    43,    44,    29,    30,   134,    41,
      19,    34,    42,    43,    32,    23,    24,    25,    26,    27,
      28,    18,    19,    41,    42,    43,    44,    33,    20,    21,
      41,   132,    41,    42,    43,    44,    29,    30,    29,    30,
      33,    39,    33,    18,    19,    20,    21,    42,    43,    39,
      33,    35,     5,    35,    42,    36,    33,    33,    37,    39,
      34,    33,    97,    36,    35,    33,   149,    37,   134,   105,
      39,   108
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,    11,    13,    14,    41,    49,
      50,    51,    55,    56,    57,    60,    61,    62,    72,    73,
      19,    31,    32,    41,    42,    43,    44,    58,    59,    74,
      58,    74,    41,    41,    52,    53,    32,    32,    22,     0,
      50,    50,    42,    43,    58,    74,    31,    58,    59,    29,
      30,    34,    23,    24,    25,    26,    27,    28,    34,    12,
      38,    40,    41,    18,    19,    20,    21,    63,    19,    32,
      41,    42,    43,    44,    60,    67,    68,    69,    59,    29,
      30,    33,    31,    59,    59,    50,    74,    74,    74,    74,
      74,    74,    50,    41,    15,    16,    17,    54,    39,    39,
      42,    43,    67,    18,    19,    70,    20,    21,    71,    33,
      58,    59,    58,    59,    74,    35,    35,    52,    36,    42,
      33,    41,    68,    69,    33,    33,    33,    33,     5,    66,
      67,    39,    34,    37,    39,    36,    50,    33,    66,    19,
      41,    42,    43,    64,    65,    35,    42,    43,    37,    39,
      33,    64
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
#line 70 "Sintactico.y"
    {printf(" FIN\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 73 "Sintactico.y"
    {printf("   declaracion sentencia es SENTENCIA\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 74 "Sintactico.y"
    {printf("   sentencia estructura es SENTENCIA\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 75 "Sintactico.y"
    {printf("   estructura es SENTENCIA\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 78 "Sintactico.y"
    {printf("   DECVAR ListadoDeDeclaraciones ENDDEC es DECLARACION\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 81 "Sintactico.y"
    {printf("   ListaDeID : TipoDeDato ListadoDeDeclaraciones es LISTADECLARACIONES\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 82 "Sintactico.y"
    {printf("   ListaDeID : TipoDeDato es LISTADECLARACIONES\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 85 "Sintactico.y"
    {printf("   listaID , ID es LISTAID\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 86 "Sintactico.y"
    {printf("   ID es LISTAID\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 89 "Sintactico.y"
    {printf("   STRING es TIPODATO\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 90 "Sintactico.y"
    {printf("   INT es TIPODATO\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 91 "Sintactico.y"
    {printf("   FLOAT es TIPODATO\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 94 "Sintactico.y"
    {printf("   WHILE es ESTRUCTURA\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 95 "Sintactico.y"
    {printf("   IF es ESTRUCTURA\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 96 "Sintactico.y"
    {printf("   ASIGN es ESTRUCTURA\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 97 "Sintactico.y"
    {printf("   WRITE es ESTRUCTURA\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 98 "Sintactico.y"
    {printf("   TAKE es ESTRUCTURA\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 99 "Sintactico.y"
    {printf("   READ es ESTRUCTURA\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 100 "Sintactico.y"
    {printf("   INLIST es ESTRUCTURA\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 103 "Sintactico.y"
    {printf("   WHILE condicionFinal { sentencia } es WHILE\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 106 "Sintactico.y"
    {printf("   IF condicionFinal { sentencia } es IF\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 107 "Sintactico.y"
    {printf("   IF condicionFinal { sentencia } es ELSE { sentencia }\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 110 "Sintactico.y"
    {printf("   condicionFinal && condicion es CONDICIONFINAL\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 111 "Sintactico.y"
    {printf("   ( condicionFinal && condicion ) es CONDICIONFINAL\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 112 "Sintactico.y"
    {printf("   ( condicionFinal && condicionFinal ) es CONDICIONFINAL\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 113 "Sintactico.y"
    {printf("   condicionFinal || condicion es CONDICIONFINAL\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 114 "Sintactico.y"
    {printf("   ( condicionFinal || condicion ) es CONDICIONFINAL\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 115 "Sintactico.y"
    {printf("   ( condicionFinal || condicionFinal ) es CONDICIONFINAL\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 116 "Sintactico.y"
    {printf("   ! condicionFinal es CONDICIONFINAL\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 117 "Sintactico.y"
    {printf("   ( ! condicionFinal ) es CONDICIONFINAL\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 118 "Sintactico.y"
    {printf("   ( condicion ) es CONDICIONFINAL\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 119 "Sintactico.y"
    {printf("   condicion es CONDICIONFINAL\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 122 "Sintactico.y"
    {printf("   factor < factor es CONDICION\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 123 "Sintactico.y"
    {printf("   factor > factor es CONDICION\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 124 "Sintactico.y"
    {printf("   factor <= factor es CONDICION\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 125 "Sintactico.y"
    {printf("   factor >= factor es CONDICION\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 126 "Sintactico.y"
    {printf("   factor == factor es CONDICION\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 127 "Sintactico.y"
    {printf("   factor != factor es CONDICION\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 128 "Sintactico.y"
    {printf("   ! factor es CONDICION\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 131 "Sintactico.y"
    {printf("   ID = expresion es ASIGN\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 134 "Sintactico.y"
    {printf("   INLISTA ( ID ; [ ListaDeExpresiones ] ) es INLIST\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 137 "Sintactico.y"
    {printf("   TAKE ( signo ; CTE_INT ; [ valores ] ) es TAKE\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 140 "Sintactico.y"
    {printf("   + es SIGNO\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {printf("   - es SIGNO\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    {printf("   * es SIGNO\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 143 "Sintactico.y"
    {printf("   / es SIGNO\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 146 "Sintactico.y"
    {printf("   valor ; valores es VALORES\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 147 "Sintactico.y"
    {printf("   valor es VALORES\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 150 "Sintactico.y"
    {printf("   CTE_INT es VALOR\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 151 "Sintactico.y"
    {printf("   - CTE_INT es VALOR\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 152 "Sintactico.y"
    {printf("   CTE_FLOAT es VALOR\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 153 "Sintactico.y"
    {printf("   - CTE_FLOAT es VALOR\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {printf("   ID es VALOR\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 157 "Sintactico.y"
    {printf("   expresion ; listaDeExpresiones es LISTAEXPRESIONES\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 158 "Sintactico.y"
    {printf("   expresion es LISTAEXPRESIONES\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 161 "Sintactico.y"
    {printf("   expresion sumayresta termino es EXPRESION\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    {printf("   termino es EXPRESION\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 163 "Sintactico.y"
    {printf("   asign es EXPRESION\n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 166 "Sintactico.y"
    {printf("   termino multydiv operando es TERMINO\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 167 "Sintactico.y"
    {printf("   operando es TERMINO\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 170 "Sintactico.y"
    {printf("   CTE_INT es OPERANDO\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 171 "Sintactico.y"
    {printf("   - CTE_INT es OPERANDO\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 172 "Sintactico.y"
    {printf("   CTE_FLOAT es OPERANDO\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 173 "Sintactico.y"
    {printf("   - CTE_FLOAT es OPERANDO\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 174 "Sintactico.y"
    {printf("   CTE_STRING es OPERANDO\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 175 "Sintactico.y"
    {printf("   ID es OPERANDO\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 176 "Sintactico.y"
    {printf("   ( expresion ) es OPERANDO\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 179 "Sintactico.y"
    {printf("   + es SUMAYRESTA\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {printf("   - es SUMAYRESTA\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 183 "Sintactico.y"
    {printf("   / es MULTYDIV\n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 184 "Sintactico.y"
    {printf("   * es MULTYDIV\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 187 "Sintactico.y"
    {printf("   WRITE factor es WRITE\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 190 "Sintactico.y"
    {printf("   READ ID es READ\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 193 "Sintactico.y"
    {printf("   ID es FACTOR\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 194 "Sintactico.y"
    {printf("   CTE_INT es FACTOR\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 195 "Sintactico.y"
    {printf("   - CTE_INT es FACTOR\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 196 "Sintactico.y"
    {printf("   CTE_STRING es FACTOR\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 197 "Sintactico.y"
    {printf("   CTE_FLOAT es FACTOR\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 198 "Sintactico.y"
    {printf("   - CTE_FLOAT es FACTOR\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2062 "Sintactico.tab.c"
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
#line 201 "Sintactico.y"



int main(int argc, char* argv[])
{
    archTS = fopen("ts.txt","w");

    if((yyin = fopen(argv[1],"rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo %s\n", argv[1]);
    }

    yyparse();

    generarArchivo();
    printf("\nCOMPILACION EXITOSA!\n");
    fclose(yyin);
    
    return 0;
}

