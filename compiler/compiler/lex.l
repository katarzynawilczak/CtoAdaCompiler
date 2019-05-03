%option noyywrap
%{
    #include "grammar.tab.h"
    #include "SyntaxTree/Includes.hpp"
%}

name        [a-zA-Z]([0-9]*[a-zA-Z]*)*
whitespace  [ \r\t\v\f]
linefeed    \n

%%
{name}                  {return NAME;}
":"                     {return COLON;}
";"						{return SEMICOLON;}
"->"                    {return RIGHT_ARROW;}
"{"                     {return LEFT_BRACE;}
"}"                     {return RIGHT_BRACE;}
{whitespace}
{linefeed}              ++yylineno;
%%
