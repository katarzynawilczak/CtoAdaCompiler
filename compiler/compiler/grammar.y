
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
%token INT_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE VOID_TYPE
%token PRINTF
%token RETURN
%token WHILE DO FOR IF ELSE SWITCH CASE BREAK DEFAULT
%token GREATER_EQUAL LESS_EQUAL EQUAL_EQUAL NOT_EQUAL EQUALS
%token AND OR
%token PLUS MINUS MULTIPLY DIVIDE
%token NUMBER TRUE_STR FALSE_STR


%start input

%%

input:
	 libraries function_list													{root.reset(new Input($1, $2));}

libraries:
	library libraries															{$$ = new compiler::Libraries($1, $2);}
	| %empty
	
library:
	INCLUDE LEFT_ANGLE_BRACKET name DOT name RIGHT_ANGLE_BRACKET				{$$ = new compiler::Library($3, $5);}

function_list:
	function function_list														{$$ = new compiler::FunctionList($1, $2);}
	| %empty																	{$$ = nullptr;}

function:
    type name LEFT_ROUND_BRACKET argument_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET  	{$$ = new compiler::Function($1, $2, $4, $7);}  
	| VOID_TYPE name LEFT_ROUND_BRACKET argument_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET
  
argument_list:
	argument COMMA argument_list												{$$ = new compiler::ArgumentList($1, $3);}
	| argument																	{$$ = $1;}
	
argument:
	type name																	{$$ = new compiler::Argument($1, $2);}
	| %empty																	{$$ = nullptr;}
    
expression:
	LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET
	| expression PLUS expression
	| expression MINUS expression
	| expression MULTIPLY expression
	| expression DIVIDE expression
	| NUMBER
	| name
	| TRUE_STR
	| FALSE_STR
    
type:
	INT_TYPE		{$$ = new compiler::Type(yytext);}
	| DOUBLE_TYPE	{$$ = new compiler::Type(yytext);}
	| FLOAT_TYPE	{$$ = new compiler::Type(yytext);}
	| CHAR_TYPE		{$$ = new compiler::Type(yytext);}
	| STRING_TYPE	{$$ = new compiler::Type(yytext);}
	| BOOL_TYPE		{$$ = new compiler::Type(yytext);}
    
statements:
    statement statements													{}
    | %empty																{$$ = nullptr;}

statement:
	variable
	| name PLUS PLUS SEMICOLON
	| name MINUS MINUS	SEMICOLON
    | name EQUALS expression SEMICOLON
	| name PLUS EQUALS expression SEMICOLON
	| name MINUS EQUALS expression SEMICOLON
	| name MULTIPLY EQUALS expression SEMICOLON
	| name DIVIDE EQUALS expression SEMICOLON 
    | PRINTF LEFT_ROUND_BRACKET QUOTE name QUOTE RIGHT_ROUND_BRACKET SEMICOLON	{}
	| PRINTF LEFT_ROUND_BRACKET QUOTE NUMBER QUOTE RIGHT_ROUND_BRACKET SEMICOLON	{}
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
	| RETURN SEMICOLON
    
variable:
    type name SEMICOLON														{$$ = new compiler::Variable($1, $2);}
    | type name EQUALS expression SEMICOLON									{$$ = new compiler::Variable($1, $2, $4);}
    
name:
	NAME																	{$$ = new compiler::Name(yytext);}
    
while:
	WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET
	| WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement
	
conditions:
	LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET
	| conditions AND conditions
	| conditions OR conditions
	| condition

condition:
	| expression
	| NAME condition_operand expression
	| LEFT_ROUND_BRACKET NAME RIGHT_ROUND_BRACKET condition_operand expression
	| LEFT_ROUND_BRACKET NAME RIGHT_ROUND_BRACKET condition_operand LEFT_ROUND_BRACKET NAME RIGHT_ROUND_BRACKET
	| NAME condition_operand LEFT_ROUND_BRACKET NAME RIGHT_ROUND_BRACKET
	| QUOTE NAME QUOTE

condition_operand:
	GREATER_EQUAL
	| LESS_EQUAL
	| EQUAL_EQUAL
	| NOT_EQUAL
	| LEFT_ANGLE_BRACKET
	| RIGHT_ANGLE_BRACKET

if:
	IF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET
	| IF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement

else:
	ELSE statement
	| ELSE LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET

if_expression:
	| if else
	| if

do_while:
	DO statement WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET SEMICOLON
	| DO LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET SEMICOLON

for:
	FOR LEFT_ROUND_BRACKET for_expression RIGHT_ROUND_BRACKET statement
	| FOR LEFT_ROUND_BRACKET for_expression RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET

for_expression:
	SEMICOLON conditions SEMICOLON
	| for_statement SEMICOLON conditions SEMICOLON
	| SEMICOLON conditions SEMICOLON for_step
	| for_statement SEMICOLON conditions SEMICOLON for_step

for_statement:
	NAME
    | type NAME EQUALS expression
    | for_step
    
for_step:
	| NAME PLUS PLUS
	| NAME MINUS MINUS
    | NAME EQUALS expression
    | NAME PLUS EQUALS expression
    | NAME MINUS EQUALS expression
    | NAME MULTIPLY EQUALS expression
    | NAME DIVIDE EQUALS expression

switch:
	SWITCH LEFT_ROUND_BRACKET NAME RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET cases RIGHT_CURLY_BRACKET
	| SWITCH LEFT_ROUND_BRACKET NAME RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET cases default RIGHT_CURLY_BRACKET

cases:
	case cases
	| case

case:
	CASE value COLON statements break

value:
	QUOTE NAME QUOTE
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
