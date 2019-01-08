%{
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <cmath>
#include "../model.h"

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_num;

void yyerror(const char *s);
%}

%union
{
	int                         ival;
	float                       fval;
	char*                       sval;
    node*                       nval;
}

// terminals

%token SQRT EXP LOG SIN COS TAN ASIN ACOS ATAN ABS
%token PLUS MINUS TIMES DIVIDE POWER
%token EQ

%token <sval> identifier
%token <sval> number

%left EQ LT GT LE GE NE
%left PLUS MINUS
%left TIMES DIVIDE
%precedence UMINUS UPLUS
%right POWER

%type<nval> expr

// to compile
//bison -d -o pdrhparser.c pdrhparser.y && flex -o pdrhlexer.c pdrhlexer.l && g++ -O2 -std=c++11 `/home/fedor/dreal3/build/release/bin/capd-config --cflags` pdrhparser.h pdrhparser.c pdrhlexer.c ../../model.cpp -lfl `/home/fedor/dreal3/build/release/bin/capd-config --libs` -o pdrh && ./pdrh ../../test/parser/test1.pdrh

%%
fun_list:
	fun_list fun { ; }
	| fun { ; }

fun:
    identifier EQ expr ';' {
                                push_var($1);
                                push_fun($1, $3);
                           }

expr:
    identifier                  {
                                    push_var($1);
                                    $$ = push_node($1, {});
                                }
    | number                    {
                                    $$ = push_node($1, {});
                                }
    | MINUS expr %prec UMINUS   {
                                    $$ = push_node("-", { $2 });
                                }
    | PLUS expr %prec UPLUS     {
                                    $$ = $2;
                                }
    | expr MINUS expr           {
                                    $$ = push_node("-", { $1, $3 });
                                }
    | expr PLUS expr            {
                                    $$ = push_node("+", { $1, $3 });
                                }
    | expr TIMES expr           {
                                    $$ = push_node("*", { $1, $3 });
                                }
    | expr DIVIDE expr          {
                                    $$ = push_node("/", { $1, $3 });
                                }
    | expr POWER expr           {
                                    $$ = push_node("^", { $1, $3 });
                                }
    | ABS '(' expr ')'          {
                                    $$ = push_node("abs", { $3 });
                                }
    | SQRT '(' expr ')'         {
                                    $$ = push_node("^", { $3, push_node("0.5", {}) });
                                }
    | EXP '(' expr ')'          {
                                    $$ = push_node("exp", { $3 });
                                }
    | LOG '(' expr ')'          {
                                    $$ = push_node("log", { $3 });
                                }
    | SIN '(' expr ')'          {
                                    $$ = push_node("sin", { $3 });
                                }
    | COS '(' expr ')'          {
                                    $$ = push_node("cos", { $3 });
                                }
    | TAN '(' expr ')'          {
                                    $$ = push_node("tan", { $3 });
                                }
    | ASIN '(' expr ')'         {
                                    $$ = push_node("asin", { $3 });
                                }
    | ACOS '(' expr ')'         {
                                    $$ = push_node("acos", { $3 });
                                }
    | ATAN '(' expr ')'         {
                                    $$ = push_node("atan", { $3 });
                                }
    | '(' expr ')'              {
                                    $$ = $2;
                                }
    ;

%%

void yyerror(const char *s) {
	std::cerr << "line " << line_num << ": " << s << std::endl;
	exit(EXIT_FAILURE);
}
