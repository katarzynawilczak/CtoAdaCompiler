%option noyywrap
%{
    #include "grammar.tab.h"
    #include "SyntaxTree/Includes.hpp"
%}

name        [a-zA-Z]([0-9]*[a-zA-Z]*)*
int			int
main		main
whitespace  [ \r\t\v\f]
linefeed    \n

%%
{int}					{return INT;}
{main}					{return MAIN;}
{name}                  {return NAME;}
":"                     {return COLON;}
";"						{return SEMICOLON;}
"->"                    {return RIGHT_ARROW;}
"{"                     {return LEFT_CURLY_BRACKET;}
"}"                     {return RIGHT_CURLY_BRACKET;}
"("						{return LEFT_ROUND_BRACKET;}
")"						{return RIGHT_ROUND_BRACKET;}
{whitespace}
{linefeed}              ++yylineno;
%%
