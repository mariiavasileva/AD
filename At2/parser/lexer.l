%{
#include <iostream>
#define YY_DECL extern "C" int yylex()
#include "../model.h"
#include "parser.h"
int line_num = 1;
%}

%option noyywrap
%x COMMENT

%%
"//".*\n	 		  	{ ++line_num; }
"/*"            		{ BEGIN(COMMENT); }
<COMMENT>"*/" 			{ BEGIN(INITIAL); }
<COMMENT>\n    			{ ++line_num; }
<COMMENT>.    			;

"#define"               { ++line_num; }

"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return TIMES; }
"/"                     { return DIVIDE; }
"^"                     { return POWER; }

"="                     { return EQ; }

abs                     { return ABS; }
sqrt              	    { return SQRT; }
exp              	    { return EXP; }
log              	    { return LOG; }
sin              	    { return SIN; }
cos              	    { return COS; }
tan              	    { return TAN; }
asin              	    { return ASIN; }
acos              	    { return ACOS; }
atan              	    { return ATAN; }

[0-9]+          	                { yylval.sval = strdup(yytext); return number; }
[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?	{ yylval.sval = strdup(yytext); return number; }
[a-zA-Z_][a-zA-Z0-9_]*              { yylval.sval = strdup(yytext); return identifier; }

[\[\]\(\):;,\{\}@]	    { return yytext[0]; }

\n                      { ++line_num; }
[ \t]+				    ;

%%