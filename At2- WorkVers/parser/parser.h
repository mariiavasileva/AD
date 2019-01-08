/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_HOME_MIKE_DESKTOP_AT2_WORKVERS_PARSER_PARSER_H_INCLUDED
# define YY_YY_HOME_MIKE_DESKTOP_AT2_WORKVERS_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SQRT = 258,
    EXP = 259,
    LOG = 260,
    SIN = 261,
    COS = 262,
    TAN = 263,
    ASIN = 264,
    ACOS = 265,
    ATAN = 266,
    ABS = 267,
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    DIVIDE = 271,
    POWER = 272,
    EQ = 273,
    identifier = 274,
    number = 275,
    LT = 276,
    GT = 277,
    LE = 278,
    GE = 279,
    NE = 280,
    UMINUS = 281,
    UPLUS = 282
  };
#endif
/* Tokens.  */
#define SQRT 258
#define EXP 259
#define LOG 260
#define SIN 261
#define COS 262
#define TAN 263
#define ASIN 264
#define ACOS 265
#define ATAN 266
#define ABS 267
#define PLUS 268
#define MINUS 269
#define TIMES 270
#define DIVIDE 271
#define POWER 272
#define EQ 273
#define identifier 274
#define number 275
#define LT 276
#define GT 277
#define LE 278
#define GE 279
#define NE 280
#define UMINUS 281
#define UPLUS 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "/home/mike/Desktop/At2- WorkVers/parser/parser.y" /* yacc.c:1909  */

	int                         ival;
	float                       fval;
	char*                       sval;
    node*                       nval;

#line 115 "/home/mike/Desktop/At2- WorkVers/parser/parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_MIKE_DESKTOP_AT2_WORKVERS_PARSER_PARSER_H_INCLUDED  */
