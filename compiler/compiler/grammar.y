
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
%token INT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE VOID_TYPE
%token PRINTF
%token RETURN
%token WHILE DO FOR IF ELSE ELSEIF SWITCH CASE BREAK DEFAULT
%token GREATER_EQUAL LESS_EQUAL EQUAL_EQUAL NOT_EQUAL EQUALS
%token AND OR
%token PLUS MINUS MULTIPLY DIVIDE
%token NUMBER TRUE_STR FALSE_STR linefeed


%start input

%%

input:
	 libraries procedure_main_is function_list								{root.reset(new Input($1, $2, $3));}

libraries:
	library libraries														{$$ = new compiler::Libraries($1, $2);}
	| %empty
	
library:
	INCLUDE LEFT_ANGLE_BRACKET name DOT name RIGHT_ANGLE_BRACKET			{$$ = new compiler::Library($3, $5);}
	
procedure_main_is:
	linefeed																{$$ = new compiler::ProcedureMainIs();}
	| %empty																{$$ = new compiler::ProcedureMainIs();}

function_list:
	function function_list													{$$ = new compiler::FunctionList($1, $2);}
	| %empty																{$$ = nullptr;}

function:
    type name LEFT_ROUND_BRACKET argument_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET variables statements RIGHT_CURLY_BRACKET  	{$$ = new compiler::Function($2, $4, $7, $8, $1);}  
	| VOID_TYPE name LEFT_ROUND_BRACKET argument_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET variables statements RIGHT_CURLY_BRACKET {$$ = new compiler::Function($2, $4, $7, $8);}
  
argument_list:
	argument COMMA argument_list											{$$ = new compiler::ArgumentList($1, $3);}
	| argument																{$$ = $1;}
	
argument:
	type name																{$$ = new compiler::Argument($1, $2);}
	| %empty																{$$ = nullptr;}
    
expression:
	LEFT_ROUND_BRACKET expression RIGHT_ROUND_BRACKET						{$$ = new compiler::Expression("exp", $2);}
	| expression PLUS expression											{$$ = new compiler::Expression("+", $1, $3);}
	| expression MINUS expression											{$$ = new compiler::Expression("-", $1, $3);}
	| expression MULTIPLY expression										{$$ = new compiler::Expression("*", $1, $3);}
	| expression DIVIDE expression											{$$ = new compiler::Expression("/", $1, $3);}
	| NUMBER																{$$ = new compiler::Name(yytext);}
	| name																	{$$ = $1;}
	| TRUE_STR																{$$ = new compiler::Name(yytext);}
	| FALSE_STR																{$$ = new compiler::Name(yytext);}
	
	
name:
	NAME																	{$$ = new compiler::Name(yytext);}

number:
	NUMBER																	{$$ = new compiler::Name(yytext);}
    
type:
	INT_TYPE																{$$ = new compiler::Type("Integer");}
	| CHAR_TYPE																{$$ = new compiler::Type("Character");}
	| STRING_TYPE															{$$ = new compiler::Type("String");}
	| BOOL_TYPE																{$$ = new compiler::Type("Boolean");}
    
statements:
    statement statements													{$$ = new compiler::Statements($1, $2);}
    | %empty																{$$ = nullptr;}

statement:
	name PLUS PLUS SEMICOLON												{$$ = new compiler::Statement("++", $1);}
	| name MINUS MINUS SEMICOLON											{$$ = new compiler::Statement("--", $1);}
    | name EQUALS expression SEMICOLON										{$$ = new compiler::Statement("=", $1, $3);}
	| name PLUS EQUALS expression SEMICOLON									{$$ = new compiler::Statement("+=", $1, $4);}
	| name MINUS EQUALS expression SEMICOLON								{$$ = new compiler::Statement("-=", $1, $4);}
	| name MULTIPLY EQUALS expression SEMICOLON								{$$ = new compiler::Statement("*=", $1, $4);}
	| name DIVIDE EQUALS expression SEMICOLON 								{$$ = new compiler::Statement("/=", $1, $4);}
    | PRINTF LEFT_ROUND_BRACKET QUOTE name QUOTE RIGHT_ROUND_BRACKET SEMICOLON	{$$ = new compiler::Statement("printf", $4);}
	| PRINTF LEFT_ROUND_BRACKET QUOTE number QUOTE RIGHT_ROUND_BRACKET SEMICOLON{$$ = new compiler::Statement("printf", $4);}
	| while																	{$$ = $1;}
	| if																	{$$ = $1;}
	| do_while																{$$ = $1;}
	| for																	{$$ = nullptr;}
	| switch																{$$ = $1;}
	| return_statement														{$$ = $1;}

return_statement:
	| RETURN expression SEMICOLON											{$$ = new compiler::Return($2);}
	| RETURN SEMICOLON														{$$ = new compiler::Return();}

variables:
	variable variables														{$$ = new compiler::Variables($1, $2);}
	| %empty																{$$ = nullptr;}

variable:
    type name SEMICOLON														{$$ = new compiler::Variable($1, $2);}
    | type name EQUALS expression SEMICOLON									{$$ = new compiler::Variable($1, $2, $4);}
    

statement_with_or_without_brackets:
	LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET						{$$ = $2;}
	| statement																{$$ = $1;}
    
while:
	WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement_with_or_without_brackets {$$ = new compiler::While($3, $5);}
	
conditions:
	LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET						{$$ = new compiler::Conditions("()", $2);}
	| conditions AND conditions												{$$ = new compiler::Conditions("and", $1, $3);}
	| conditions OR conditions												{$$ = new compiler::Conditions("or", $1, $3);}
	| condition																{$$ = $1;}

condition:
	expression																{$$ = $1;}
	| name condition_operand expression										{$$ = new compiler::Condition("name op exp", $1, $2, $3);}
	| LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET condition_operand expression {$$ = new compiler::Condition("(name) op exp", $2, $4, $5);}
	| LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET condition_operand LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET {$$ = new compiler::Condition("(name) op (name)", $2, $4, $6);}
	| name condition_operand LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET	{$$ = new compiler::Condition("name op (name)", $1, $2, $4);}
	| QUOTE name QUOTE														{$$ = new compiler::Condition("string", $2);}

condition_operand:
	GREATER_EQUAL															{$$ = new compiler::Name(yytext);}
	| LESS_EQUAL															{$$ = new compiler::Name(yytext);}
	| EQUAL_EQUAL															{$$ = new compiler::Name(yytext);}
	| NOT_EQUAL																{$$ = new compiler::Name(yytext);}
	| LEFT_ANGLE_BRACKET													{$$ = new compiler::Name(yytext);}
	| RIGHT_ANGLE_BRACKET													{$$ = new compiler::Name(yytext);}



if:
	IF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement_with_or_without_brackets else_ifs {$$ = new compiler::IfElse($3, $5, $6);}
	| IF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement_with_or_without_brackets else_ifs ELSE statement_with_or_without_brackets {$$ = new compiler::IfElse($3, $5, $6, $8);}
	
else_ifs:
	ELSEIF LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET statement_with_or_without_brackets  {$$ = new ElseIfs($3, $5);}
	| %empty																{$$ = nullptr;}


do_while:
	DO statement_with_or_without_brackets WHILE LEFT_ROUND_BRACKET conditions RIGHT_ROUND_BRACKET SEMICOLON {$$ = new compiler::DoWhile($2, $5);}

for:
	FOR LEFT_ROUND_BRACKET for_expression RIGHT_ROUND_BRACKET statement_with_or_without_brackets {$$ = new compiler::For($3, $5);}

for_expression:
	SEMICOLON conditions SEMICOLON												{$$ = new compiler::ForExpression($2);}
	| for_statement SEMICOLON conditions SEMICOLON								{$$ = new compiler::ForExpression("12", $1, $3);}
	| SEMICOLON conditions SEMICOLON for_step									{$$ = new compiler::ForExpression("23", $2, $4);}
	| for_statement SEMICOLON conditions SEMICOLON for_step						{$$ = new compiler::ForExpression($1, $3, $5);}

for_statement:
	name																		{$$ = $1;}
    | type name EQUALS expression
    | for_step
    
for_step:
	name PLUS PLUS
	| name MINUS MINUS
    | name EQUALS expression
    | name PLUS EQUALS expression
    | name MINUS EQUALS expression
    | name MULTIPLY EQUALS expression
    | name DIVIDE EQUALS expression

switch:
	SWITCH LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET cases RIGHT_CURLY_BRACKET {$$ = new compiler::Switch($3, $6);}
	| SWITCH LEFT_ROUND_BRACKET name RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET cases default RIGHT_CURLY_BRACKET {$$ = new compiler::Switch($3, $6, $7);}

cases:
	case cases																						{$$ = new compiler::Cases($1, $2);}
	| case																							{$$ = new compiler::Cases($1);}

case:
	CASE value COLON statements break																{$$ = new compiler::Case($2, $4, $5);}

value:
	QUOTE name QUOTE
	| number

break:
	BREAK SEMICOLON
	| %empty

default:
	DEFAULT COLON statements break																	{$$ = new compiler::Default($3, $4);}


%%  //implementations

void yyerror(char const *x)
{
    printf ("Error: %s\n", x);
    exit(1);
}
