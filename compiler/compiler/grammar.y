
%code requires {
	#include "SyntaxTree/SyntaxTree.hpp"
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

%token NAME COLON RIGHT_ARROW LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET SEMICOLON
%token LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET MAIN
%token RIGHT_ANGLE_BRACKET LEFT_ANGLE_BRACKET
%token INCLUDE DOT


%start input

%%

input:
	 libraries main_function function_list										{root.reset(new Input($1, $2, $3));}

libraries:
	library libraries															{$$ = $1;}
	| %empty																	{$$ = nullptr;}
	
library:
	INCLUDE LEFT_ANGLE_BRACKET lib_name RIGHT_ANGLE_BRACKET						{$$ = $3;}
	
lib_name:
	NAME DOT NAME																{$$ = $1;}
	| NAME																		{$$ = $1;}
	
function_list:
	function function_list														{$$ = $1;}
	| %empty																	{$$ = nullptr;}

main_function:
	MAIN LEFT_ROUND_BRACKET RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET {$$ = $5;}

function:
     NAME LEFT_ROUND_BRACKET argument_list RIGHT_ROUND_BRACKET LEFT_CURLY_BRACKET statements RIGHT_CURLY_BRACKET  	{$$ = new compiler::Function($1, $4);}
     
argument_list:
	argument																	{$$ = $1;}
	| %empty																	{$$ = nullptr;}
	
argument:
	NAME																		{$$ = $1;}
    
statements:
    statements statement														{$$ = new compiler::Statements($1, $2);}
    | %empty																	{$$ = nullptr;}

statement:
    name SEMICOLON																{$$ = new compiler::Statement($1);}
    
name:
	NAME																		{$$ = new compiler::Name(yytext);}

%%  //implementations

void yyerror(char const *x)
{
    printf ("Error %s\n", x);
    exit(1);
}
