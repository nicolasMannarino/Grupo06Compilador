
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
/* Tokens.  */
#define WHILE 258
#define IF 259
#define ELSE 260
#define WRITE 261
#define READ 262
#define AND 263
#define OR 264
#define NOT 265
#define DECVAR 266
#define ENDDEC 267
#define INLIST 268
#define TAKE 269
#define FLOAT 270
#define STRING 271
#define INT 272
#define OP_MAS 273
#define OP_REST 274
#define OP_MULT 275
#define OP_DIV 276
#define OP_ASIG 277
#define COMP_DIST 278
#define COMP_MAY 279
#define COMP_MEN 280
#define COMP_IGUAL 281
#define COMP_MAYOI 282
#define COMP_MENOI 283
#define COND_AND 284
#define COND_OR 285
#define COND_NOT 286
#define P_A 287
#define P_C 288
#define LL_A 289
#define LL_C 290
#define C_A 291
#define C_C 292
#define COMA 293
#define PYC 294
#define DP 295
#define ID 296
#define CTE_INT 297
#define CTE_FLOAT 298
#define CTE_STRING 299
#define COMENT 300
#define whitespace 301
#define linefeed 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


