
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
%token NAME										// variable name, string for printf (all characters)
%token INCLUDE									// #include
%token INT_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE VOID_TYPE
%token PRINTF
%token RETURN
%token WHILE DO FOR IF ELSE SWITCH CASE BREAK DEFAULT
%token GREATER_EQUAL LESS_EQUAL EQUAL_EQUAL NOT_EQUAL EQUALS
%token AND OR
%token PLUS MINUS MULTIPLY DIVIDE
%token NUMBER TRUE_STR FALSE_STR linefeed


%start input

%%

input:
	 libraries procedure_main_is function_list									{root.reset(new Input($1, $2, $3));}

libraries:
	library libraries															{$$ = new compiler::Libraries($1, $2);}
	| %empty
	
library:
	INCLUDE LEFT_ANGLE_BRACKET name DOT name RIGHT_ANGLE_BRACKET				{$$ = new compiler::Library($3, $5);}
	
procedure_main_is:
	linefeed																	{$$ = new compiler::ProcedureMainIs();}
	| %empty																	{$$ = new compiler::ProcedureMainIs();}

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
	LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET							{$$ = nullptr;}
	| expression PLUS expression												{$$ = nullptr;}
	| expression MINUS expression												{$$ = nullptr;}
	| expression MULTIPLY expression											{$$ = nullptr;}
	| expression DIVIDE expression												{$$ = nullptr;}
	| NUMBER																	{$$ = $1;}
	| name																		{$$ = $1;}
	| TRUE_STR																	{$$ = $1;}
	| FALSE_STR																	{$$ = $1;}
    
type:
	INT_TYPE		{$$ = new compiler::Type(yytext);}
	| DOUBLE_TYPE	{$$ = new compiler::Type(yytext);}
	| FLOAT_TYPE	{$$ = new compiler::Type(yytext);}
	| CHAR_TYPE		{$$ = new compiler::Type(yytext);}
	| STRING_TYPE	{$$ = new compiler::Type(yytext);}
	| BOOL_TYPE		{$$ = new compiler::Type(yytext);}
    
statements:
    statement statements													{$$ = new compiler::Statements($1, $2);}
    | %empty																{$$ = nullptr;}

statement:
	variable																{$$ = nullptr;}
	| name PLUS PLUS SEMICOLON												{$$ = new compiler::Statement("++", $1);}
	| name MINUS MINUS SEMICOLON											{$$ = new compiler::Statement("--", $1);}
    | name EQUALS expression SEMICOLON										{$$ = new compiler::Statement("=", $1, $3);}
	| name PLUS EQUALS expression SEMICOLON									{$$ = new compiler::Statement("+=", $1, $4);}
	| name MINUS EQUALS expression SEMICOLON								{$$ = new compiler::Statement("-=", $1, $4);}
	| name MULTIPLY EQUALS expression SEMICOLON								{$$ = new compiler::Statement("*=", $1, $4);}
	| name DIVIDE EQUALS expression SEMICOLON 								{$$ = new compiler::Statement("/=", $1, $4);}
    | PRINTF LEFT_ROUND_BRACKET QUOTE name QUOTE RIGHT_ROUND_BRACKET SEMICOLON	{$$ = new compiler::Statement("printf", $4);}
	| PRINTF LEFT_ROUND_BRACKET QUOTE NUMBER QUOTE RIGHT_ROUND_BRACKET SEMICOLON{$$ = new compiler::Statement("printf", $4);}
	| while																	{$$ = nullptr;}
	| if																	{$$ = nullptr;}
	| do_while																{$$ = nullptr;}
	| for																	{$$ = nullptr;}
	| switch																{$$ = nullptr;}
	| return_statement														{$$ = nullptr;}

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
	
statement_with_or_without_brackets:
	LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET
	| statement
    
while:
	WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement_with_or_without_brackets
	
conditions:
	LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET
	| conditions AND conditions
	| conditions OR conditions
	| condition

condition:
	expression
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
	IF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement_with_or_without_brackets else

else:
	ELSE statement_with_or_without_brackets
	| %empty

do_while:
	DO statement_with_or_without_brackets WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET SEMICOLON

for:
	FOR LEFT_ROUND_BRACKET for_expression RIGHT_ROUND_BRACKET statement_with_or_without_brackets

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
	NAME PLUS PLUS
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
