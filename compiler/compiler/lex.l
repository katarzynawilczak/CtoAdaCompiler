%option noyywrap
%{
    #include "grammar.tab.h"
    #include "SyntaxTree/Includes.hpp"
    #include <iostream>
%}

quote			\"
star			\*
name        	[a-zA-Z]([0-9]*[a-zA-Z]*)*
string			{name}*
comment_line	\/\/.*
comment_block	\/{star}[!?.,\*='";:{}()\[\]_\+\-1-9a-zA-Z \n\t\v\f]*{star}\/
whitespace  	[ \r\t\v\f]
linefeed    	\n


%%
"."						{return DOT;}
","						{return COMMA;}
";"						{return SEMICOLON;}
"="						{return EQUALS;}
{quote}					{return QUOTE;}
"{"                     {return LEFT_CURLY_BRACKET;}
"}"                     {return RIGHT_CURLY_BRACKET;}
"("						{return LEFT_ROUND_BRACKET;}
")"						{return RIGHT_ROUND_BRACKET;}
"<"						{return LEFT_ANGLE_BRACKET;}
">"						{return RIGHT_ANGLE_BRACKET;}
"#include"				{return INCLUDE;}
"printf"				{return PRINTF;}
"int"					{return INT_TYPE;}
"char"					{return CHAR_TYPE;}
"double"				{return DOUBLE_TYPE;}
"float"					{return FLOAT_TYPE;}
{name}                  {return NAME;}
{string}				{return STRING;}
{comment_line}			{std::cout<<"Comment line ignored\n";}
{comment_block}			{std::cout<<"Comment block ignored\n";}
{whitespace}			
{linefeed}              ++yylineno;
%%
