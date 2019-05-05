%option noyywrap
%{
    #include "grammar.tab.h"
    #include "SyntaxTree/Includes.hpp"
%}

main		int[ \r\t\v\f]main
name        [a-zA-Z]([0-9]*[a-zA-Z]*)*
type		int
comment		[//][!?.'",1-9a-zA-Z \t]*
whitespace  [ \r\t\v\f]
linefeed    \n


%%
"."						{return DOT;}
":"                     {return COLON;}
";"						{return SEMICOLON;}
"->"                    {return RIGHT_ARROW;}
"{"                     {return LEFT_CURLY_BRACKET;}
"}"                     {return RIGHT_CURLY_BRACKET;}
"("						{return LEFT_ROUND_BRACKET;}
")"						{return RIGHT_ROUND_BRACKET;}
"<"						{return LEFT_ANGLE_BRACKET;}
">"						{return RIGHT_ANGLE_BRACKET;}
"#include"				{return INCLUDE;}
{main}					{return MAIN;}
{name}                  {return NAME;}
{comment}				
{whitespace}			
{linefeed}              ++yylineno;
%%
