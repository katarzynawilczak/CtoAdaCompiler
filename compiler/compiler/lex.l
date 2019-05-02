%option noyywrap
%{
    #include "grammar.tab.h"
%}

name        [a-zA-Z]([0-9]*[a-zA-Z]*)*
whitespace  [ \r\t\v\f]
linefeed    \n

%%
{name}                  {printf("Lex: name\n"); return NAME;}
":"                     {printf("Lex: :\n"); return COLON;}
"->"                    {printf("Lex: ->\n"); return RIGHT_ARROW;}
"{"                     {printf("Lex: {\n"); return LEFT_BRACE;}
"}"                     {printf("Lex: }\n"); return RIGHT_BRACE;}
{whitespace}
{linefeed}              ++yylineno;
%%

#include <stdio.h>
