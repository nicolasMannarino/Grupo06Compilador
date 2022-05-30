
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
#include <string.h>
#include "y.tab.h"
#include "TablaSimbolos.h"
#include "Arbol.h"

extern FILE* yyin;

void reiniciarPunteros();
void operacionTake(float valor);

FILE* archTS;
FILE *pArbol;
FILE *pIntermedia;

t_NodoArbol* Ptr;
t_NodoArbol* Sptr;
t_NodoArbol* Aptr;
t_NodoArbol* Eptr;
t_NodoArbol* Tptr;
t_NodoArbol* Optr;
t_NodoArbol* Fptr;
t_NodoArbol* Lptr;
t_NodoArbol* Wptr;
t_NodoArbol* Rptr;
t_NodoArbol* ILptr;
t_NodoArbol* ASptr;
t_NodoArbol* IFptr;
t_NodoArbol* WHptr;
t_NodoArbol* ESTptr;
t_NodoArbol* SENptr;
t_NodoArbol* DECptr;
t_NodoArbol* LDECptr;
t_NodoArbol* VSptr;
t_NodoArbol* SGptr;
t_NodoArbol* LIDptr;
t_NodoArbol* TPptr;
t_NodoArbol* Vptr;
t_NodoArbol* CFptr;
t_NodoArbol* SFptr;
t_NodoArbol* SVptr;
t_NodoArbol* FDptr;
t_NodoArbol* FIptr;
t_NodoArbol* CONDptr;
t_NodoArbol* CONDFptr;
t_NodoArbol* AUXptr;
t_NodoArbol* CONDWptr;
t_NodoArbol* SENWHILEptr;
t_NodoArbol* SENIFptr;
t_NodoArbol* TAKEptr;

int nroTake;
int controlTake;
float nroResultadoTake; 
char* signoTake;
char nroCadenaTake[10];



/* Line 189 of yacc.c  */
#line 135 "Sintactico.tab.c"

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
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 62 "Sintactico.y"

	char* strVal; 



/* Line 214 of yacc.c  */
#line 224 "Sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 236 "Sintactico.tab.c"

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

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
       0,     0,     3,     5,     7,    10,    13,    15,    17,    21,
      26,    30,    34,    36,    38,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    62,    65,    67,    69,    75,    85,
      88,    90,    92,    94,    98,   104,   108,   114,   117,   122,
     126,   128,   132,   136,   140,   144,   148,   152,   155,   157,
     159,   161,   165,   169,   178,   179,   191,   193,   195,   197,
     199,   203,   205,   207,   210,   212,   215,   219,   221,   225,
     229,   231,   235,   239,   241,   243,   246,   248,   251,   253,
     257,   259,   262,   265,   267,   269,   272,   274,   276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    51,    -1,    51,    52,    -1,
      51,    56,    -1,    56,    -1,    52,    -1,    11,    53,    12,
      -1,    53,    54,    40,    55,    -1,    54,    40,    55,    -1,
      54,    38,    41,    -1,    41,    -1,    16,    -1,    17,    -1,
      15,    -1,    57,    -1,    60,    -1,    68,    -1,    79,    -1,
      70,    -1,    80,    -1,    69,    -1,     3,    59,    34,    58,
      35,    -1,    58,    56,    -1,    56,    -1,    64,    -1,     4,
      64,    34,    62,    35,    -1,     4,    64,    34,    62,    35,
       5,    34,    63,    35,    -1,    61,    56,    -1,    56,    -1,
      61,    -1,    61,    -1,    64,    29,    65,    -1,    32,    64,
      29,    65,    33,    -1,    64,    30,    65,    -1,    32,    64,
      30,    65,    33,    -1,    31,    64,    -1,    32,    31,    65,
      33,    -1,    32,    65,    33,    -1,    65,    -1,    67,    25,
      66,    -1,    67,    24,    66,    -1,    67,    28,    66,    -1,
      67,    27,    66,    -1,    67,    26,    66,    -1,    67,    23,
      66,    -1,    31,    81,    -1,    69,    -1,    81,    -1,    81,
      -1,    41,    22,    76,    -1,    41,    22,    44,    -1,    13,
      32,    41,    39,    36,    75,    37,    33,    -1,    -1,    14,
      32,    72,    39,    42,    71,    39,    36,    73,    37,    33,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    73,
      39,    74,    -1,    74,    -1,    42,    -1,    19,    42,    -1,
      43,    -1,    19,    43,    -1,    75,    39,    76,    -1,    76,
      -1,    76,    18,    77,    -1,    76,    19,    77,    -1,    77,
      -1,    77,    21,    78,    -1,    77,    20,    78,    -1,    78,
      -1,    42,    -1,    19,    42,    -1,    43,    -1,    19,    43,
      -1,    41,    -1,    32,    76,    33,    -1,    70,    -1,     6,
      81,    -1,     7,    41,    -1,    41,    -1,    42,    -1,    19,
      42,    -1,    44,    -1,    43,    -1,    19,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   129,   132,   133,   134,   135,   138,   141,
     142,   145,   146,   149,   150,   151,   154,   155,   156,   157,
     158,   159,   160,   163,   166,   167,   169,   172,   173,   176,
     177,   180,   183,   186,   187,   189,   190,   192,   193,   194,
     195,   198,   199,   200,   201,   202,   203,   204,   205,   208,
     211,   214,   215,   218,   221,   221,   230,   231,   232,   233,
     236,   237,   240,   241,   242,   243,   246,   247,   250,   251,
     252,   255,   256,   257,   260,   261,   262,   263,   264,   265,
     266,   269,   272,   275,   276,   277,   278,   279,   280
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
  "CTE_STRING", "COMENT", "whitespace", "linefeed", "$accept",
  "programaFinal", "programa", "sentencia", "declaracion",
  "listaDeclaraciones", "listaID", "tipoDato", "estructura", "while",
  "sentenciaWhile", "condicionWhile", "if", "sentenciaIf", "sentenciaV",
  "sentenciaF", "condicionFinal", "condicion", "factorDer", "factorIzq",
  "asign", "inlist", "take", "$@1", "signo", "valores", "valor",
  "listaExpresiones", "expresion", "termino", "operando", "write", "read",
  "factor", 0
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
       0,    48,    49,    50,    51,    51,    51,    51,    52,    53,
      53,    54,    54,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    57,    58,    58,    59,    60,    60,    61,
      61,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    68,    68,    69,    71,    70,    72,    72,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    81,    81,    81,    81,    81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     3,     4,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     1,     1,     5,     9,     2,
       1,     1,     1,     3,     5,     3,     5,     2,     4,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     3,     3,     8,     0,    11,     1,     1,     1,     1,
       3,     1,     1,     2,     1,     2,     3,     1,     3,     3,
       1,     3,     3,     1,     1,     2,     1,     2,     1,     3,
       1,     2,     2,     1,     1,     2,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     7,     6,    16,    17,    18,    22,    20,    19,
      21,     0,     0,     0,    83,    84,    87,    86,     0,    26,
      40,     0,    48,    50,     0,    81,    82,    12,     0,     0,
       0,     0,     0,     1,     4,     5,    85,    88,    37,    50,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,    56,    57,
      58,    59,     0,     0,     0,    78,    74,    76,    52,    80,
      51,    70,    73,    40,     0,     0,    39,    25,     0,     0,
      33,    35,    46,    49,    42,    41,    45,    44,    43,    30,
      31,     0,     0,    11,    15,    13,    14,    10,     0,     0,
      75,    77,     0,     0,     0,     0,     0,    38,    33,    35,
      23,    24,    47,    29,    27,     9,     0,    54,    79,    68,
      69,    72,    71,    34,    36,     0,     0,    67,     0,     0,
       0,     0,     0,    32,     0,    53,    66,     0,    28,     0,
      62,    64,     0,    61,    63,    65,     0,     0,    55,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    38,    39,   107,    99,    14,
      88,    28,    15,   100,   101,   144,    48,    30,    92,    31,
      16,    32,    18,   138,    72,   152,   153,   136,    80,    81,
      82,    19,    20,    33
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
       2,    73,    73,    87,   -27,   -19,    19,    37,    51,    82,
     -71,     2,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -24,    73,    80,   -71,   -71,   -71,   -71,    60,    90,
     -71,   123,   -71,   -71,    11,   -71,   -71,   -71,    -5,    57,
      44,   151,   113,   -71,   -71,   -71,   -71,   -71,    90,   129,
      73,   104,    65,    77,    94,    94,    87,    87,    87,    87,
      87,    87,    77,   -71,   102,    62,    93,   135,   -71,   -71,
     -71,   -71,   139,    -4,    18,   -71,   -71,   -71,   -71,   -71,
      28,   132,   -71,   108,    94,    94,   -71,   -71,    17,    87,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
      77,    91,    93,   -71,   -71,   -71,   -71,   -71,   145,   140,
     -71,   -71,     9,    18,    18,    18,    18,   -71,   150,   152,
     -71,   -71,   -71,   -71,   179,   -71,    18,   -71,   -71,   132,
     132,   -71,   -71,   -71,   -71,   153,    33,    28,   147,    77,
     155,    18,   154,    77,   156,   -71,    28,   -17,   -71,   118,
     -71,   -71,   136,   -71,   -71,   -71,   159,   -17,   -71,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   -71,   178,   -71,   157,    92,     1,   -71,
     -71,   -71,   -71,    54,   -71,   -71,    32,    -6,   107,   -71,
     -71,     0,   -39,   -71,   -71,   -71,    39,   -71,   -70,    63,
      64,   -71,   -71,     7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      17,    13,   149,    79,   112,     1,     2,    63,     3,     4,
      35,    17,    45,     5,    36,     6,     7,    52,    46,    47,
       1,     2,    37,     3,     4,   150,   151,   113,   114,    49,
       6,     7,     7,    29,    34,    79,    37,    73,   110,   111,
      54,    55,   128,     8,    83,    62,   113,   114,    90,    91,
      74,    40,   120,    17,    87,    51,   137,    49,     8,    75,
      76,    77,    17,    93,    93,    93,    93,    93,    93,    41,
     140,   146,   141,    42,    79,    79,    79,    79,   118,   119,
       1,     2,    43,     3,     4,    67,     6,    79,    17,   121,
       6,     7,    21,     6,    53,    65,   122,    66,    86,    21,
      17,   123,    79,   103,    22,    23,    21,     6,   104,   105,
     106,    50,    23,    21,    24,    25,    26,    27,     8,    54,
      55,    24,    25,    26,    27,    89,   124,     7,    24,    25,
      26,    27,    73,    84,    85,    24,    25,    26,    27,    17,
      65,   117,   102,    17,   123,    74,    56,    57,    58,    59,
      60,    61,   115,   116,    75,    76,    77,    78,   -47,   -47,
     154,   155,   -47,   -47,    94,    95,    96,    97,    98,    68,
      69,    70,    71,   156,   108,   157,   129,   130,   109,   131,
     132,   126,   127,   133,   135,   134,   142,   139,   145,    44,
     147,   148,   158,   143,   125,    64,   159
};

static const yytype_uint8 yycheck[] =
{
       0,     0,    19,    42,    74,     3,     4,    12,     6,     7,
       3,    11,    11,    11,    41,    13,    14,    23,    42,    43,
       3,     4,    41,     6,     7,    42,    43,    18,    19,    22,
      13,    14,    14,     1,     2,    74,    41,    19,    42,    43,
      29,    30,    33,    41,    50,    34,    18,    19,    54,    55,
      32,    32,    35,    53,    53,    23,   126,    50,    41,    41,
      42,    43,    62,    56,    57,    58,    59,    60,    61,    32,
      37,   141,    39,    22,   113,   114,   115,   116,    84,    85,
       3,     4,     0,     6,     7,    41,    13,   126,    88,    88,
      13,    14,    19,    13,    34,    38,    89,    40,    33,    19,
     100,   100,   141,    41,    31,    32,    19,    13,    15,    16,
      17,    31,    32,    19,    41,    42,    43,    44,    41,    29,
      30,    41,    42,    43,    44,    31,    35,    14,    41,    42,
      43,    44,    19,    29,    30,    41,    42,    43,    44,   139,
      38,    33,    40,   143,   143,    32,    23,    24,    25,    26,
      27,    28,    20,    21,    41,    42,    43,    44,    29,    30,
      42,    43,    33,    34,    57,    58,    59,    60,    61,    18,
      19,    20,    21,    37,    39,    39,   113,   114,    39,   115,
     116,    36,    42,    33,     5,    33,    39,    34,    33,    11,
      36,    35,    33,   139,   102,    38,   157
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,    11,    13,    14,    41,    49,
      50,    51,    52,    56,    57,    60,    68,    69,    70,    79,
      80,    19,    31,    32,    41,    42,    43,    44,    59,    64,
      65,    67,    69,    81,    64,    81,    41,    41,    53,    54,
      32,    32,    22,     0,    52,    56,    42,    43,    64,    81,
      31,    64,    65,    34,    29,    30,    23,    24,    25,    26,
      27,    28,    34,    12,    54,    38,    40,    41,    18,    19,
      20,    21,    72,    19,    32,    41,    42,    43,    44,    70,
      76,    77,    78,    65,    29,    30,    33,    56,    58,    31,
      65,    65,    66,    81,    66,    66,    66,    66,    66,    56,
      61,    62,    40,    41,    15,    16,    17,    55,    39,    39,
      42,    43,    76,    18,    19,    20,    21,    33,    65,    65,
      35,    56,    81,    56,    35,    55,    36,    42,    33,    77,
      77,    78,    78,    33,    33,     5,    75,    76,    71,    34,
      37,    39,    39,    61,    63,    33,    76,    36,    35,    19,
      42,    43,    73,    74,    42,    43,    37,    39,    33,    74
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
#line 126 "Sintactico.y"
    {mostrarArbolDeIzqADer(&Ptr,pArbol);InOrden(&Ptr, pIntermedia);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 129 "Sintactico.y"
    {Ptr = SENptr; printf(" FIN\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 132 "Sintactico.y"
    {SENptr = crearNodo("S",SENptr,DECptr);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 133 "Sintactico.y"
    {SENptr = crearNodo("S",SENptr,ESTptr);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 134 "Sintactico.y"
    {SENptr = ESTptr;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 135 "Sintactico.y"
    {SENptr = DECptr;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 138 "Sintactico.y"
    {DECptr = LDECptr;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {AUXptr = crearNodo(":",LIDptr,TPptr);LDECptr = crearNodo("LISTADEC",AUXptr,LDECptr);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    {LDECptr = crearNodo(":",LIDptr,TPptr);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 145 "Sintactico.y"
    {LIDptr = crearNodo(",",LIDptr,crearHoja((yyvsp[(3) - (3)].strVal)));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 146 "Sintactico.y"
    {LIDptr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 149 "Sintactico.y"
    {TPptr = crearHoja("STRING");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 150 "Sintactico.y"
    {TPptr = crearHoja("INT");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 151 "Sintactico.y"
    {TPptr = crearHoja("FLOAT");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {ESTptr = WHptr;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 155 "Sintactico.y"
    {ESTptr = IFptr;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 156 "Sintactico.y"
    {ESTptr = ASptr;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 157 "Sintactico.y"
    {ESTptr = Wptr;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 158 "Sintactico.y"
    {ESTptr = Tptr;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 159 "Sintactico.y"
    {ESTptr = Rptr;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 160 "Sintactico.y"
    {ESTptr = ILptr;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 163 "Sintactico.y"
    {WHptr = crearNodo("WHILE", CONDWptr, SENWHILEptr);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 166 "Sintactico.y"
    {SENWHILEptr = crearNodo("S",SENWHILEptr,ESTptr);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 167 "Sintactico.y"
    {SENWHILEptr = ESTptr;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 169 "Sintactico.y"
    {CONDWptr = CONDFptr;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 172 "Sintactico.y"
    {IFptr = crearNodo("IF", CONDFptr, SVptr);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 173 "Sintactico.y"
    {IFptr = crearNodo("IF", CONDFptr, crearNodo("CUERPO",SVptr,SFptr));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 176 "Sintactico.y"
    {SENIFptr = crearNodo("S",SENIFptr,ESTptr);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 177 "Sintactico.y"
    {SENIFptr = ESTptr;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {SVptr = SENIFptr;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 183 "Sintactico.y"
    {SFptr = SENIFptr;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 186 "Sintactico.y"
    {CONDFptr = crearNodo("AND",CONDFptr,CONDptr);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 187 "Sintactico.y"
    {CONDFptr = crearNodo("AND",CONDFptr,CONDptr);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 189 "Sintactico.y"
    {CONDFptr = crearNodo("OR",CONDFptr,CONDptr);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 190 "Sintactico.y"
    {CONDFptr = crearNodo("OR",CONDFptr,CONDptr);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 192 "Sintactico.y"
    {;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 193 "Sintactico.y"
    {CONDFptr = CONDptr;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 194 "Sintactico.y"
    {CONDFptr = CONDptr;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 195 "Sintactico.y"
    {CONDFptr = CONDptr;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 198 "Sintactico.y"
    {CONDptr = crearNodo("<",  FIptr, FDptr);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 199 "Sintactico.y"
    {CONDptr = crearNodo(">",  FIptr, FDptr);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 200 "Sintactico.y"
    {CONDptr = crearNodo("<=", FIptr, FDptr);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 201 "Sintactico.y"
    {CONDptr = crearNodo(">=", FIptr, FDptr);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 202 "Sintactico.y"
    {CONDptr = crearNodo("==", FIptr, FDptr);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 203 "Sintactico.y"
    {CONDptr = crearNodo("!=", FIptr, FDptr);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 204 "Sintactico.y"
    {CONDptr = Fptr;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 205 "Sintactico.y"
    {CONDptr = ILptr;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 208 "Sintactico.y"
    {FDptr = Fptr;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 211 "Sintactico.y"
    {FIptr = Fptr;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 214 "Sintactico.y"
    {ASptr = crearNodo("=", crearHoja((yyvsp[(1) - (3)].strVal)),Eptr);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 215 "Sintactico.y"
    {ASptr = crearNodo("=", crearHoja((yyvsp[(1) - (3)].strVal)), crearHoja((yyvsp[(3) - (3)].strVal)));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 218 "Sintactico.y"
    {ILptr = crearNodo("INLIST",crearHoja((yyvsp[(3) - (8)].strVal)),Lptr);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 221 "Sintactico.y"
    {controlTake=0; nroTake = atoi((yyvsp[(5) - (5)].strVal)); nroResultadoTake = 0;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 221 "Sintactico.y"
    {if(controlTake < nroTake){
                                                                                                                                yyerror();
                                                                                                                            }
                                                                                                                            else{
                                                                                                                                sprintf(nroCadenaTake,"%f",nroResultadoTake );
                                                                                                                                TAKEptr = crearHoja(nroCadenaTake);
                                                                                                                            };}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 230 "Sintactico.y"
    {signoTake = "+";;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 231 "Sintactico.y"
    {signoTake = "-";;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 232 "Sintactico.y"
    {signoTake = "*";;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 233 "Sintactico.y"
    {signoTake = "/";;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 236 "Sintactico.y"
    {;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 237 "Sintactico.y"
    {;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 240 "Sintactico.y"
    {if(controlTake < nroTake){operacionTake(atof((yyvsp[(1) - (1)].strVal)));controlTake++;};;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 241 "Sintactico.y"
    {if(controlTake < nroTake){operacionTake(atof((yyvsp[(2) - (2)].strVal)));controlTake++;};;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 242 "Sintactico.y"
    {if(controlTake < nroTake){operacionTake(atof((yyvsp[(1) - (1)].strVal)));controlTake++;};;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 243 "Sintactico.y"
    {if(controlTake < nroTake){operacionTake(atof((yyvsp[(2) - (2)].strVal)));controlTake++;};;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 246 "Sintactico.y"
    {Lptr = crearNodo(";",Lptr,Eptr);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 247 "Sintactico.y"
    {Lptr = Eptr;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 250 "Sintactico.y"
    {Eptr = crearNodo("+",Eptr,Tptr);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 251 "Sintactico.y"
    {Eptr = crearNodo("-",Eptr,Tptr);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 252 "Sintactico.y"
    {Eptr = Tptr;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 255 "Sintactico.y"
    {Tptr = crearNodo("/",Tptr,Optr);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 256 "Sintactico.y"
    {Tptr = crearNodo("*",Tptr,Optr);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 257 "Sintactico.y"
    {Tptr = Optr;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 260 "Sintactico.y"
    {Optr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 261 "Sintactico.y"
    {Optr = crearHoja((yyvsp[(2) - (2)].strVal));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 262 "Sintactico.y"
    {Optr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 263 "Sintactico.y"
    {Optr = crearHoja((yyvsp[(2) - (2)].strVal));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 264 "Sintactico.y"
    {Optr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 265 "Sintactico.y"
    {;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 266 "Sintactico.y"
    {Optr = TAKEptr;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 269 "Sintactico.y"
    {Wptr = crearNodo("W",crearHoja("WRITE"),Fptr);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 272 "Sintactico.y"
    {Rptr = crearNodo("R",crearHoja("READ"),crearHoja((yyvsp[(2) - (2)].strVal)));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 275 "Sintactico.y"
    {Fptr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 276 "Sintactico.y"
    {Fptr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 277 "Sintactico.y"
    {Fptr = crearHoja((yyvsp[(2) - (2)].strVal));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 278 "Sintactico.y"
    {Fptr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 279 "Sintactico.y"
    {Fptr = crearHoja((yyvsp[(1) - (1)].strVal));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 280 "Sintactico.y"
    {Fptr = crearHoja((yyvsp[(2) - (2)].strVal));;}
    break;



/* Line 1455 of yacc.c  */
#line 2197 "Sintactico.tab.c"
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
#line 283 "Sintactico.y"



int main(int argc, char* argv[])
{
    archTS = fopen("ts.txt","w");
    if((pIntermedia = fopen("Intermedia.txt", "wt")) == NULL)
	{
        printf("\nNo se puede abrir el archivo %s\n", "Intermedia.txt");
    }

    if((yyin = fopen(argv[1],"rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo %s\n", argv[1]);
    }

    yyparse();

    generarArchivo();
    printf("\nCOMPILACION EXITOSA!\n");
    reiniciarPunteros();
    fclose(pIntermedia);
    fclose(yyin);
    
    return 0;
}

void reiniciarPunteros(){
Ptr = NULL;
Sptr = NULL;
Aptr = NULL;
Eptr = NULL;
Tptr = NULL;
Optr = NULL;
Fptr = NULL;
Lptr = NULL;
Wptr = NULL;
Rptr = NULL;
ILptr = NULL;
ASptr = NULL;
IFptr = NULL;
WHptr = NULL;
ESTptr = NULL;
SENptr = NULL;
DECptr = NULL;
LDECptr = NULL;
VSptr = NULL;
SGptr = NULL;
LIDptr = NULL;
TPptr = NULL;
Vptr = NULL;
CFptr = NULL;
SFptr = NULL;
SVptr = NULL;
FDptr = NULL;
FIptr = NULL;
CONDptr = NULL;
CONDFptr = NULL;
AUXptr = NULL;
CONDWptr = NULL;
SENWHILEptr = NULL;
SENIFptr = NULL;
TAKEptr = NULL;
																						
}

void operacionTake(float valor){
    if(strcmp(signoTake,"+") == 0){
        nroResultadoTake += valor;
    }
    else
        if(strcmp(signoTake,"-") == 0){
            if(controlTake == 0){
                nroResultadoTake=valor;
            }
            else{
                nroResultadoTake -= valor;
            }
        }
        else
            if(strcmp(signoTake,"/") == 0){
                if(controlTake == 0){
                    nroResultadoTake=valor;
                }
                else{
                    nroResultadoTake /= valor;
                }
            }
            else
                if(strcmp(signoTake,"*") == 0){
                    if(controlTake == 0){
                        nroResultadoTake=valor;
                    }
                    else{
                        nroResultadoTake *= valor;
                    }
                }
}
