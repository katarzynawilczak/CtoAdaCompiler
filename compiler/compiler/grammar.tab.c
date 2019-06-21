/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "compiler/grammar.y" /* yacc.c:339  */
  //definitions
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

#line 80 "grammar.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
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
#line 2 "compiler/grammar.y" /* yacc.c:355  */

	#include "SyntaxTree/SyntaxTree.hpp"
	#include<iostream>

#line 115 "grammar.tab.c" /* yacc.c:355  */

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

/* Copy the second part of user declarations.  */

#line 186 "grammar.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    47,    48,    51,    54,    55,    58,    59,
      62,    63,    66,    67,    70,    71,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    86,    89,    92,    93,    94,
      95,    98,    99,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   118,   119,
     120,   123,   124,   127,   128,   132,   133,   136,   139,   140,
     141,   142,   145,   146,   147,   148,   149,   150,   153,   154,
     155,   156,   157,   158,   163,   164,   167,   168,   172,   175,
     178,   179,   180,   181,   184,   185,   186,   189,   190,   191,
     192,   193,   194,   195,   198,   199,   202,   203,   206,   209,
     210,   213,   214,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "DOT", "COMMA", "QUOTE",
  "COLON", "LEFT_ROUND_BRACKET", "RIGHT_ROUND_BRACKET",
  "RIGHT_ANGLE_BRACKET", "LEFT_ANGLE_BRACKET", "LEFT_CURLY_BRACKET",
  "RIGHT_CURLY_BRACKET", "NAME", "INCLUDE", "INT_TYPE", "CHAR_TYPE",
  "STRING_TYPE", "BOOL_TYPE", "VOID_TYPE", "PRINTF", "RETURN", "WHILE",
  "DO", "FOR", "IF", "ELSE", "ELSEIF", "SWITCH", "CASE", "BREAK",
  "DEFAULT", "GREATER_EQUAL", "LESS_EQUAL", "EQUAL_EQUAL", "NOT_EQUAL",
  "EQUALS", "AND", "OR", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "NUMBER",
  "TRUE_STR", "FALSE_STR", "linefeed", "$accept", "input", "libraries",
  "library", "procedure_main_is", "function_list", "function",
  "argument_list", "argument", "expression", "name", "number", "type",
  "statements", "statement", "return_statement", "variables", "variable",
  "statement_with_or_without_brackets", "while", "conditions", "condition",
  "condition_operand", "if", "else_ifs", "do_while", "for",
  "for_expression", "for_statement", "for_step", "switch", "cases", "case",
  "value", "break", "default", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-163)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    34,    19,     7,    18,    61,  -163,  -163,   283,  -163,
    -163,    78,  -163,  -163,  -163,  -163,    61,  -163,   283,    61,
      61,    79,  -163,    80,    87,   259,   259,  -163,    95,   101,
      61,   103,   109,   259,  -163,   110,   259,  -163,   259,    61,
     258,   259,   258,    -1,   121,    71,   140,   245,   148,   154,
     166,   248,   162,   258,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,   170,  -163,   168,   178,  -163,   168,  -163,  -163,  -163,
      10,  -163,   105,   258,  -163,   171,     4,   105,    61,   168,
      59,    28,   163,   165,  -163,  -163,  -163,    21,    -6,   123,
    -163,   168,   168,   168,   168,    61,   105,   264,   217,   186,
    -163,   172,   197,   105,   255,    61,   199,   203,  -163,   198,
     207,    83,   168,   215,   168,   218,   168,   168,  -163,  -163,
     214,   226,  -163,   264,   264,   264,   264,   235,   123,   229,
     206,  -163,  -163,  -163,  -163,  -163,  -163,   185,   245,   105,
     105,  -163,   105,    89,   168,    99,    52,   205,   219,   221,
     245,   105,   245,   231,  -163,   117,  -163,   128,  -163,   138,
     149,   246,   251,  -163,   217,  -163,   168,   264,  -163,   -33,
     -33,   208,    61,   264,   168,  -163,   168,  -163,   168,   168,
     168,  -163,   115,   233,   224,  -163,  -163,  -163,  -163,   270,
     290,   189,   277,   291,   255,  -163,   264,   264,   264,   264,
     264,    61,   300,   282,    -3,    15,   224,  -163,  -163,   168,
     264,  -163,  -163,  -163,   105,   245,    61,  -163,   303,  -163,
     304,   299,  -163,   305,   210,  -163,   307,   258,   258,  -163,
    -163,   245,  -163,   284,   284,  -163,   313,  -163,  -163,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     7,     4,     0,     1,     6,     9,     3,
      25,     0,    27,    28,    29,    30,     0,     2,     9,     0,
       0,     0,     8,     0,     0,    15,    15,     5,     0,    13,
       0,     0,     0,    15,    14,     0,    52,    12,    52,     0,
      32,    52,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    47,    42,    43,    44,    45,    46,
      51,     0,    53,     0,     0,    50,     0,    21,    23,    24,
       0,    22,     0,    32,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    31,    10,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,    62,    22,     0,
      61,     0,     0,     0,    84,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    26,
       0,     0,    16,    17,    18,    19,    20,     0,    62,    22,
       0,    73,    72,    68,    69,    70,    71,     0,    48,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,    48,     0,    35,     0,    33,     0,    34,     0,
       0,     0,     0,    67,     0,    58,     0,    63,    57,    59,
      60,     0,    80,    89,     0,    87,     0,    88,     0,     0,
       0,    79,     0,    77,     0,    36,    37,    38,    39,     0,
       0,     0,    22,     0,     0,    82,    90,    91,    92,    93,
      85,    81,     0,    74,     0,     0,    97,    40,    41,     0,
      64,    66,    78,    83,     0,    48,     0,   100,     0,    94,
       0,     0,    96,    22,     0,    75,     0,    32,    32,    95,
      65,    48,    99,   102,   102,    76,     0,    98,   103,   101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,   314,  -163,  -163,   301,  -163,    44,  -163,   -36,
      -5,   113,     8,   -41,   -43,  -163,   160,  -163,  -121,  -163,
     -37,  -163,   156,  -163,  -163,  -163,  -163,  -163,  -163,  -162,
    -163,   116,  -163,  -163,    90,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    17,    18,    28,    29,    97,
      71,   121,    30,    52,    53,    54,    40,    41,    75,    55,
      99,   100,   137,    56,   203,    57,    58,   106,   107,   108,
      59,   205,   206,   218,   237,   221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    61,    62,   216,    74,   139,   140,   103,    10,    70,
     195,    21,    85,    90,    23,    24,    19,   168,    10,     6,
      12,    13,    14,    15,   118,    34,    19,    87,   219,   181,
      89,   183,   101,     1,    43,    51,    63,    51,   119,   213,
     109,   119,    51,   111,    39,     5,    39,   220,    51,    39,
      91,    92,    93,    94,     7,   123,   124,   125,   126,   130,
     128,    91,    92,    93,    94,   114,   143,    98,    51,   115,
      31,   104,    98,   110,    65,    10,   155,    37,   157,    66,
     159,   160,    20,   120,   105,    10,   154,    25,    26,   176,
     127,   129,   172,   177,   225,    74,   112,    27,    98,   113,
     149,   167,   169,   170,    32,   171,    33,    74,   173,    74,
     235,    95,    35,    96,   182,    67,    68,    69,   201,    10,
     185,    36,    38,    91,    92,    93,    94,   139,   140,    64,
      89,   186,   122,    51,    98,    98,   174,    98,   196,   175,
     197,   187,   198,   199,   200,    51,    98,    51,    72,    67,
      68,    69,   188,   139,   140,   210,    76,    91,    92,    93,
      94,   192,    77,    91,    92,    93,    94,   194,    91,    92,
      93,    94,    74,    89,    78,    84,    66,   224,    91,    92,
      93,    94,    10,    86,    88,   141,   233,   234,    74,    91,
      92,    93,    94,   166,   102,   138,   194,   209,    42,    10,
     116,    60,   117,    10,   223,   142,   151,   152,   150,    98,
      51,   226,    67,    68,    69,   165,   153,   193,   156,   231,
     161,   158,    51,    51,   139,   140,    51,   131,   132,    67,
      68,    69,   162,    67,    68,    69,   139,   140,   164,   131,
     132,   163,   178,   184,   139,   140,   139,   140,   139,   140,
     133,   134,   135,   136,   204,   189,   179,    73,   180,    10,
     190,   202,   133,   134,   135,   136,    44,    45,    46,    47,
      48,    49,    10,   207,    50,    12,    13,    14,    15,    44,
      45,    46,    47,    48,    49,    79,   211,    50,    80,    81,
      82,    83,   144,   208,   212,   145,   146,   147,   148,    12,
      13,    14,    15,    16,    91,    92,    93,    94,   214,   215,
     227,   228,   229,   232,   230,   236,   239,   217,     9,    22,
     191,     0,   222,     0,   238
};

static const yytype_int16 yycheck[] =
{
       5,    42,     3,     6,    47,    38,    39,     3,    14,    45,
     172,    16,    53,     3,    19,    20,     8,   138,    14,     0,
      16,    17,    18,    19,     3,    30,    18,    63,    13,   150,
      66,   152,    73,    15,    39,    40,    37,    42,    44,   201,
      77,    44,    47,    79,    36,    11,    38,    32,    53,    41,
      40,    41,    42,    43,    47,    91,    92,    93,    94,    96,
      96,    40,    41,    42,    43,    37,   103,    72,    73,    41,
      26,    76,    77,    78,     3,    14,   112,    33,   114,     8,
     116,   117,     4,    88,    76,    14,     3,     8,     8,    37,
      95,    96,     3,    41,   215,   138,    37,    10,   103,    40,
     105,   137,   139,   140,     9,   142,     5,   150,   144,   152,
     231,     6,     9,     8,   151,    44,    45,    46,     3,    14,
       3,    12,    12,    40,    41,    42,    43,    38,    39,     8,
     166,     3,     9,   138,   139,   140,    37,   142,   174,    40,
     176,     3,   178,   179,   180,   150,   151,   152,     8,    44,
      45,    46,     3,    38,    39,   191,     8,    40,    41,    42,
      43,   166,     8,    40,    41,    42,    43,   172,    40,    41,
      42,    43,   215,   209,     8,    13,     8,   214,    40,    41,
      42,    43,    14,    13,     6,    13,   227,   228,   231,    40,
      41,    42,    43,     8,    23,     9,   201,     8,    38,    14,
      37,    41,    37,    14,   209,     8,     3,     9,     9,   214,
     215,   216,    44,    45,    46,     9,     9,     9,     3,     9,
       6,     3,   227,   228,    38,    39,   231,    10,    11,    44,
      45,    46,     6,    44,    45,    46,    38,    39,     9,    10,
      11,     6,    37,    12,    38,    39,    38,    39,    38,    39,
      33,    34,    35,    36,    30,     9,    37,    12,    37,    14,
       9,    28,    33,    34,    35,    36,    21,    22,    23,    24,
      25,    26,    14,     3,    29,    16,    17,    18,    19,    21,
      22,    23,    24,    25,    26,    37,     9,    29,    40,    41,
      42,    43,    37,     3,     3,    40,    41,    42,    43,    16,
      17,    18,    19,    20,    40,    41,    42,    43,     8,    27,
       7,     7,    13,     6,     9,    31,     3,   204,     4,    18,
     164,    -1,   206,    -1,   234
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    49,    50,    51,    11,     0,    47,    52,    50,
      14,    58,    16,    17,    18,    19,    20,    53,    54,    60,
       4,    58,    53,    58,    58,     8,     8,    10,    55,    56,
      60,    55,     9,     5,    58,     9,    12,    55,    12,    60,
      64,    65,    64,    58,    21,    22,    23,    24,    25,    26,
      29,    58,    61,    62,    63,    67,    71,    73,    74,    78,
      64,    61,     3,    37,     8,     3,     8,    44,    45,    46,
      57,    58,     8,    12,    62,    66,     8,     8,     8,    37,
      40,    41,    42,    43,    13,    61,    13,    57,     6,    57,
       3,    40,    41,    42,    43,     6,     8,    57,    58,    68,
      69,    61,    23,     3,    58,    60,    75,    76,    77,    68,
      58,    57,    37,    40,    37,    41,    37,    37,     3,    44,
      58,    59,     9,    57,    57,    57,    57,    58,    57,    58,
      68,    10,    11,    33,    34,    35,    36,    70,     9,    38,
      39,    13,     8,    68,    37,    40,    41,    42,    43,    58,
       9,     3,     9,     9,     3,    57,     3,    57,     3,    57,
      57,     6,     6,     6,     9,     9,     8,    57,    66,    68,
      68,    68,     3,    57,    37,    40,    37,    41,    37,    37,
      37,    66,    68,    66,    12,     3,     3,     3,     3,     9,
       9,    70,    58,     9,    58,    77,    57,    57,    57,    57,
      57,     3,    28,    72,    30,    79,    80,     3,     3,     8,
      57,     9,     3,    77,     8,    27,     6,    59,    81,    13,
      32,    83,    79,    58,    68,    66,    58,     7,     7,    13,
       9,     9,     6,    61,    61,    66,    31,    82,    82,     3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    59,    60,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      68,    68,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    74,
      75,    75,    75,    75,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    80,    81,
      81,    82,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     6,     1,     0,     2,     0,
       9,     9,     3,     1,     2,     0,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     4,     4,     4,     5,     5,     5,     5,
       7,     7,     1,     1,     1,     1,     1,     1,     0,     3,
       2,     2,     0,     3,     5,     3,     1,     5,     3,     3,
       3,     1,     1,     3,     5,     7,     5,     3,     1,     1,
       1,     1,     1,     1,     6,     8,     5,     0,     7,     5,
       3,     4,     4,     5,     1,     4,     1,     3,     3,     3,
       4,     4,     4,     4,     7,     8,     2,     1,     5,     3,
       1,     2,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 44 "compiler/grammar.y" /* yacc.c:1646  */
    {root.reset(new Input((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])));}
#line 1443 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Libraries((yyvsp[-1]), (yyvsp[0]));}
#line 1449 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 51 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Library((yyvsp[-3]), (yyvsp[-1]));}
#line 1455 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 54 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::ProcedureMainIs();}
#line 1461 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 55 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::ProcedureMainIs();}
#line 1467 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 58 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::FunctionList((yyvsp[-1]), (yyvsp[0]));}
#line 1473 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 59 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = nullptr;}
#line 1479 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 62 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Function((yyvsp[-7]), (yyvsp[-5]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[-8]));}
#line 1485 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 63 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Function((yyvsp[-7]), (yyvsp[-5]), (yyvsp[-2]), (yyvsp[-1]));}
#line 1491 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 66 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::ArgumentList((yyvsp[-2]), (yyvsp[0]));}
#line 1497 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 67 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1503 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 70 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Argument((yyvsp[-1]), (yyvsp[0]));}
#line 1509 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 71 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = nullptr;}
#line 1515 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 74 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Expression("exp", (yyvsp[-1]));}
#line 1521 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 75 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Expression("+", (yyvsp[-2]), (yyvsp[0]));}
#line 1527 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Expression("-", (yyvsp[-2]), (yyvsp[0]));}
#line 1533 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 77 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Expression("*", (yyvsp[-2]), (yyvsp[0]));}
#line 1539 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 78 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Expression("/", (yyvsp[-2]), (yyvsp[0]));}
#line 1545 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 79 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1551 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 80 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1557 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 81 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1563 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 82 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1569 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1575 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 89 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1581 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Type("Integer");}
#line 1587 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 93 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Type("Character");}
#line 1593 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Type("String");}
#line 1599 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 95 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Type("Boolean");}
#line 1605 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 98 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statements((yyvsp[-1]), (yyvsp[0]));}
#line 1611 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 99 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = nullptr;}
#line 1617 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 102 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("++", (yyvsp[-3]));}
#line 1623 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 103 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("--", (yyvsp[-3]));}
#line 1629 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 104 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("=", (yyvsp[-3]), (yyvsp[-1]));}
#line 1635 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("+=", (yyvsp[-4]), (yyvsp[-1]));}
#line 1641 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("-=", (yyvsp[-4]), (yyvsp[-1]));}
#line 1647 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 107 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("*=", (yyvsp[-4]), (yyvsp[-1]));}
#line 1653 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 108 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("/=", (yyvsp[-4]), (yyvsp[-1]));}
#line 1659 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 109 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("printf", (yyvsp[-3]));}
#line 1665 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 110 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Statement("printf", (yyvsp[-3]));}
#line 1671 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 111 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1677 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 112 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1683 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 113 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1689 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 114 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = nullptr;}
#line 1695 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 115 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1701 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 116 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1707 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 119 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Return((yyvsp[-1]));}
#line 1713 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 120 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Return();}
#line 1719 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 123 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Variables((yyvsp[-1]), (yyvsp[0]));}
#line 1725 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 124 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = nullptr;}
#line 1731 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 127 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Variable((yyvsp[-2]), (yyvsp[-1]));}
#line 1737 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 128 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Variable((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]));}
#line 1743 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 132 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1749 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 133 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1755 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 136 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::While((yyvsp[-2]), (yyvsp[0]));}
#line 1761 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 139 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Conditions("()", (yyvsp[-1]));}
#line 1767 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 140 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Conditions("and", (yyvsp[-2]), (yyvsp[0]));}
#line 1773 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 141 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Conditions("or", (yyvsp[-2]), (yyvsp[0]));}
#line 1779 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 142 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1785 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 145 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1791 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 146 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Condition("name op exp", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));}
#line 1797 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 147 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Condition("(name) op exp", (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0]));}
#line 1803 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 148 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Condition("(name) op (name)", (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-1]));}
#line 1809 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 149 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Condition("name op (name)", (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]));}
#line 1815 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 150 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Condition("string", (yyvsp[-1]));}
#line 1821 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 153 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1827 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 154 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1833 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 155 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1839 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 156 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1845 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 157 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1851 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 158 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Name(yytext);}
#line 1857 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 163 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::IfElse((yyvsp[-3]), (yyvsp[-1]), (yyvsp[0]));}
#line 1863 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 164 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::IfElse((yyvsp[-5]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[0]));}
#line 1869 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 167 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new ElseIfs((yyvsp[-2]), (yyvsp[0]));}
#line 1875 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 168 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = nullptr;}
#line 1881 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 172 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::DoWhile((yyvsp[-5]), (yyvsp[-2]));}
#line 1887 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 175 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::For((yyvsp[-2]), (yyvsp[0]));}
#line 1893 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 178 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::ForExpression((yyvsp[-1]));}
#line 1899 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 179 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::ForExpression("12", (yyvsp[-3]), (yyvsp[-1]));}
#line 1905 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 180 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::ForExpression("23", (yyvsp[-2]), (yyvsp[0]));}
#line 1911 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 181 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::ForExpression((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));}
#line 1917 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 184 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1923 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 198 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Switch((yyvsp[-4]), (yyvsp[-1]));}
#line 1929 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 199 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Switch((yyvsp[-5]), (yyvsp[-2]), (yyvsp[-1]));}
#line 1935 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 202 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Cases((yyvsp[-1]), (yyvsp[0]));}
#line 1941 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 203 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Cases((yyvsp[0]));}
#line 1947 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 206 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Case((yyvsp[-3]), (yyvsp[-1]), (yyvsp[0]));}
#line 1953 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 217 "compiler/grammar.y" /* yacc.c:1646  */
    {(yyval) = new compiler::Default((yyvsp[-1]), (yyvsp[0]));}
#line 1959 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 1963 "grammar.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 220 "compiler/grammar.y" /* yacc.c:1906  */
  //implementations

void yyerror(char const *x)
{
    printf ("Error: %s\n", x);
    exit(1);
}
