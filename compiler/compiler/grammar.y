
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

%token SEMICOLON DOT COMMA QUOTE COLON			// ; . , " :
%token LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET	// ()
%token RIGHT_ANGLE_BRACKET LEFT_ANGLE_BRACKET	// <>
%token LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET	// {}
%token NAME STRING								// variable name, string for printf (all characters)
%token INCLUDE									// #include
%token INT_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE VOID_TYPE
%token PRINTF
%token RETURN
%token WHILE DO FOR IF ELSE SWITCH CASE BREAK DEFAULT
%token GREATER_EQUAL LESS_EQUAL EQUAL_EQUAL NOT_EQUAL EQUALS
%token AND OR
%token PLUS MINUS MULTIPLY DIVIDE
%token NUMBER


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
    
expression:
	LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET
	| expression PLUS expression
	| expression MINUS expression
	| expression MULTIPLY expression
	| expression DIVIDE expression
	| NUMBER
	| NAME
    
type:
	INT_TYPE
	| DOUBLE_TYPE
	| FLOAT_TYPE
	| CHAR_TYPE
	| STRING_TYPE
	| VOID_TYPE
    
statements:
    statement statements
    | %empty

statement:
    variable
	| NAME PLUS PLUS SEMICOLON
	| NAME MINUS MINUS	SEMICOLON
    | name EQUALS expression SEMICOLON
	| name PLUS EQUALS expression SEMICOLON
	| name MINUS EQUALS expression SEMICOLON
	| name MULTIPLY EQUALS expression SEMICOLON
	| name DIVIDE EQUALS expression SEMICOLON 
    | PRINTF LEFT_ROUND_BRACKET QUOTE NAME QUOTE RIGHT_ROUND_BRACKET SEMICOLON	{std::cout<<"printf function called\n";}
	| PRINTF LEFT_ROUND_BRACKET QUOTE NUMBER QUOTE RIGHT_ROUND_BRACKET SEMICOLON	{std::cout<<"printf function called\n";}
	| while
	| if_expression
	| do_while
	| for
	| switch
	| return_statement

return_statement:
	RETURN name SEMICOLON
	| RETURN NUMBER SEMICOLON
	| RETURN expression SEMICOLON
	
    
variable:
    type name SEMICOLON														
    | type name EQUALS expression SEMICOLON
    
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
	| name condition_operand expression
	| LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET condition_operand expression
	| LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET condition_operand LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET
	| LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET condition_operand name
	| name condition_operand LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET
	| LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET
	| QUOTE name QUOTE

condition_operand:
	GREATER_EQUAL
	| LESS_EQUAL
	| EQUAL_EQUAL
	| NOT_EQUAL

if:
	IF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET
	| IF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement

else:
	ELSE statement
	| ELSE LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET

else_if:
	ELSE if

else_ifs:
	else_if
	| else_if else_ifs

if_expression:
	if else_ifs else
	| if else_ifs
	| if else

do_while:
	DO statement WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET SEMICOLON
	| DO LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET SEMICOLON

for:
	FOR LEFT_ROUND_BRACKET for_expression RIGHT_ROUND_BRACKET statement
	| FOR LEFT_ROUND_BRACKET for_expression RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET

for_expression:
	SEMICOLON conditions SEMICOLON
	| for_statement SEMICOLON conditions SEMICOLON
	| SEMICOLON conditions SEMICOLON for_statement
	| for_statement SEMICOLON conditions SEMICOLON for_statement

for_statement:
	type name
    | type name EQUALS expression
	| NAME PLUS PLUS
	| NAME MINUS MINUS
    | name EQUALS expression

switch:
	SWITCH LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET cases RIGHT_CURLY_BRACKET
	| SWITCH LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET cases default RIGHT_CURLY_BRACKET

cases:
	case cases
	| case

case:
	CASE value COLON statements break

value:
	QUOTE name QUOTE
	| NUMBER

break:
	BREAK SEMICOLON
	| %empty

default:
	DEFAULT COLON statements break


%%  //implementations

void yyerror(char const *x)
{
    printf ("Error: %s\n", x);
    exit(1);
}
