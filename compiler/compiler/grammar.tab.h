/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "compiler/grammar.y" /* yacc.c:1909  */

	#include "SyntaxTree/SyntaxTree.hpp"
	#include<iostream>

#line 49 "grammar.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    DOT = 259,
    COMMA = 260,
    QUOTE = 261,
    COLON = 262,
    LEFT_ROUND_BRACKET = 263,
    RIGHT_ROUND_BRACKET = 264,
    RIGHT_ANGLE_BRACKET = 265,
    LEFT_ANGLE_BRACKET = 266,
    LEFT_CURLY_BRACKET = 267,
    RIGHT_CURLY_BRACKET = 268,
    NAME = 269,
    INCLUDE = 270,
    INT_TYPE = 271,
    CHAR_TYPE = 272,
    STRING_TYPE = 273,
    BOOL_TYPE = 274,
    VOID_TYPE = 275,
    PRINTF = 276,
    RETURN = 277,
    WHILE = 278,
    DO = 279,
    FOR = 280,
    IF = 281,
    ELSE = 282,
    ELSEIF = 283,
    SWITCH = 284,
    CASE = 285,
    BREAK = 286,
    DEFAULT = 287,
    GREATER_EQUAL = 288,
    LESS_EQUAL = 289,
    EQUAL_EQUAL = 290,
    NOT_EQUAL = 291,
    EQUALS = 292,
    AND = 293,
    OR = 294,
    PLUS = 295,
    MINUS = 296,
    MULTIPLY = 297,
    DIVIDE = 298,
    NUMBER = 299,
    TRUE_STR = 300,
    FALSE_STR = 301,
    linefeed = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef compiler::SyntaxTree * YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
