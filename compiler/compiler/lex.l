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
number			[0-9]*
comment_line	\/\/.*
comment_block	\/{star}[!?.,\*=<>'";:{}()\[\]_\+\-0-9a-zA-Z \n\t\v\f]*{star}\/
whitespace  	[ \r\t\v\f]
linefeed    	\n


%%
"."						{return DOT;}
","						{return COMMA;}
":"						{return COLON;}
";"						{return SEMICOLON;}
"="						{return EQUALS;}
"+"						{return PLUS;}
"-"						{return MINUS;}
"*"						{return MULTIPLY;}
"/"						{return DIVIDE;}
{quote}					{return QUOTE;}
"{"                     {return LEFT_CURLY_BRACKET;}
"}"                     {return RIGHT_CURLY_BRACKET;}
"("						{return LEFT_ROUND_BRACKET;}
")"						{return RIGHT_ROUND_BRACKET;}
"<"						{return LEFT_ANGLE_BRACKET;}
">"						{return RIGHT_ANGLE_BRACKET;}
">="					{return GREATER_EQUAL;}
"<="					{return LESS_EQUAL;}
"=="					{return EQUAL_EQUAL;}
"!="					{return NOT_EQUAL;}
"&&"					{return AND;}
"||"					{return OR;}
"true"					{return TRUE_STR;}
"false"					{return FALSE_STR;}
"#include"				{return INCLUDE;}
"printf"				{return PRINTF;}
"int"					{return INT_TYPE;}
"char"					{return CHAR_TYPE;}
"double"				{return DOUBLE_TYPE;}
"float"					{return FLOAT_TYPE;}
"bool"					{return BOOL_TYPE;}
"void"					{return VOID_TYPE;}
"return"				{return RETURN;}
"while"					{return WHILE;}
"do"					{return DO;}
"for"					{return FOR;}
"if"					{return IF;}
"else"					{return ELSE;}
"switch"				{return SWITCH;}
"case"					{return CASE;}
"break"					{return BREAK;}
"default"				{return DEFAULT;}
{name}                  {return NAME;}
{string}				{return STRING;}
{number}				{return NUMBER;}
{comment_line}			
{comment_block}			
{whitespace}			
{linefeed}              //++yylineno;
%%
