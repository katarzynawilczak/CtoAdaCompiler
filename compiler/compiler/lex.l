%option noyywrap
%{
    #include "grammar.tab.h"
    #include "SyntaxTree/Includes.hpp"
%}

main			int[ \r\t\v\f]main
name        	[a-zA-Z]([0-9]*[a-zA-Z]*)*
comment_line	\/\/.*
comment_block	\/\*[!?.,\*='";:{}()\[\]_\+\-1-9a-zA-Z \n\t\v\f]*\*\/
whitespace  	[ \r\t\v\f]
linefeed    	\n


%%
"."						{return DOT;}
";"						{return SEMICOLON;}
"{"                     {return LEFT_CURLY_BRACKET;}
"}"                     {return RIGHT_CURLY_BRACKET;}
"("						{return LEFT_ROUND_BRACKET;}
")"						{return RIGHT_ROUND_BRACKET;}
"<"						{return LEFT_ANGLE_BRACKET;}
">"						{return RIGHT_ANGLE_BRACKET;}
"#include"				{return INCLUDE;}
"int"					{return INT;}
"char"					{return CHAR;}
"double"				{return DOUBLE;}
"float"					{return FLOAT;}
{main}					{return MAIN;}
{name}                  {return NAME;}
{comment_line}
{comment_block}
{whitespace}			
{linefeed}              ++yylineno;
%%
