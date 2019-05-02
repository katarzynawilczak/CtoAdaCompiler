%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    int yylex (void);
    void yyerror (char const *);
%}

%define api.value.type {double}

%token NAME COLON RIGHT_ARROW LEFT_BRACE RIGHT_BRACE SEMICOLON


%start input

%%

input:
    NAME COLON RIGHT_ARROW LEFT_BRACE RIGHT_BRACE       {}
    | %empty
    
statements:
    statements statement                                {}
    | %empty

statement:
    NAME SEMICOLON                                      {}

%%

void yyerror(char const *x)
{
    printf ("Error %s\n", x);
    exit(1);
}
