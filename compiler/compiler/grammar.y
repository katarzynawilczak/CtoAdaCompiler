
%code requires {
	#include "SyntaxTree/SyntaxTree.hpp"
	#include<iostream>
}

%{  //definitions
	#include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <memory>
    #include "SyntaxTree/Includes.hpp"
    std::unique_ptr<compiler::SyntaxTree> root;
    using namespace compiler;
    int yylex (void);
    extern char *yytext;
    void yyerror (char const *);
%}

%define api.value.type {compiler::SyntaxTree *}

%token NAME LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET SEMICOLON
%token LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET
%token MAIN
%token RIGHT_ANGLE_BRACKET LEFT_ANGLE_BRACKET
%token INCLUDE DOT COMMA
%token INT_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE STRING
%token PRINTF
%token EQUALS
%token QUOTE
%token RETURN
%token WHILE DO FOR IF ELSE
%token GREATER_EQUAL LESS_EQUAL EQUAL_EQUAL NOT_EQUAL
%token AND OR


%start input

%%

input:
	 libraries function_list													{root.reset(new Input($1, $2));}

libraries:
	library libraries
	| %empty
	
library:
	INCLUDE LEFT_ANGLE_BRACKET lib_name RIGHT_ANGLE_BRACKET						{std::cout<<"\n\n\nLibrary\n";}
	
lib_name:
	NAME DOT NAME
	| NAME
	
function_list:
	function function_list
	| %empty

function:
    type NAME LEFT_ROUND_BRACKET argument_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET  	{std::cout<<"Function detected\n";}
     
argument_list:
	argument COMMA argument_list
	| argument
	
argument:
	type NAME
	| %empty
    
type:
	INT_TYPE
	| DOUBLE_TYPE
	| FLOAT_TYPE
	| CHAR_TYPE
	| STRING_TYPE
    
statements:
    statement statements
    | %empty

statement:
    variable
    | PRINTF LEFT_ROUND_BRACKET QUOTE NAME QUOTE RIGHT_ROUND_BRACKET SEMICOLON	{std::cout<<"printf function called\n";}
	| while
	| RETURN name SEMICOLON
    
variable:
    type name SEMICOLON		{std::cout<<"new variable\n";}
    
name:
	NAME

while:
	WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET
	| WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement
	
conditions:
	condition AND condition
	| condition OR condition
	| condition

condition:
	name condition_operand name
	| name
	| QUOTE name QUOTE

condition_operand:
	LEFT_CURLY_BRACKET
	| RIGHT_CURLY_BRACKET
	| GREATER_EQUAL
	| LESS_EQUAL
	| EQUAL_EQUAL
	| NOT_EQUAL

%%  //implementations

void yyerror(char const *x)
{
    printf ("Error: %s\n", x);
    exit(1);
}
