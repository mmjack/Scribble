/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 4 "./src/Parser/Parser.yy"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <Statement/ThreadStatement.hpp>
#include <Statement/BoolStatement.hpp>
#include <Statement/IntStatement.hpp>
#include <Statement/OperateStatement.hpp>
#include <Statement/StringStatement.hpp>
#include <Statement/AssignVariable.hpp>
#include <Statement/GetVariableStatement.hpp>
#include <Statement/FunctionStatement.hpp>
#include <Statement/AndStatement.hpp>
#include <Statement/ForStatement.hpp>
#include <Statement/TestStatement.hpp>
#include <Statement/IfStatement.hpp>
#include <Statement/OperateStatement.hpp>
#include <Statement/ReturnStatement.hpp>
#include <Statement/TestNilStatement.hpp>
#include <Statement/WhileStatement.hpp>
#include <Statement/IncrementStatement.hpp>
#include <Statement/ArrayStatement.hpp>
#include <Statement/ArraySliceStatement.hpp>
#include <Statement/AssignArrayStatement.hpp>
#include <Statement/GetArrayStatement.hpp>
#include <Statement/ArrayLengthStatement.hpp>
#include <Statement/NegativeStatement.hpp>
#include <Statement/StructureStatement.hpp>
#include <Statement/GetStructureElementStatement.hpp>
#include <Statement/StructureAssignElement.hpp>
#include <Parser/TypeReference.hpp>
#include <Pointers/SmartPointer.hpp>
#include <Function/Function.hpp>
#include <Function/ScriptedFunction.hpp>
#include <Function/WriteFunction.hpp>
#include <Value/TypeManager.hpp>
#include <Value/Util.hpp>
#include <Parser/Parser.hpp>
#include <Value/StructureInfo.hpp>

#include <Value/Variable.hpp>
#include <Value/String.hpp>

int yylex();
void yyerror(const char* s);

bool ParsingError;
std::vector<std::string> ImportList;
std::map<std::string, SP<Variable>> Variables;

std::map<std::string, NamespaceType> Namespace;
NamespaceType Functions;

std::vector<TypeReference> TypeReferences;
std::vector<SP<Variable>> VariableReferences;
std::vector<ParserReference> StatementReferences;

void parser_free_all() {
	ImportList.clear();
	Variables.clear();
	Namespace.clear();
	Functions.clear();
	StatementReferences.clear();
	TypeReferences.clear();
	VariableReferences.clear();
	ParsingError = false;
}

extern int yylineno;	// defined and maintained in lex.c
extern char *yytext;	// defined and maintained in lex.c



/* Line 268 of yacc.c  */
#line 148 "./gen/Parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     WORD = 258,
     STRING = 259,
     REAL = 260,
     INT = 261,
     PLUS = 262,
     MINUS = 263,
     TIMES = 264,
     DIVIDE = 265,
     POWER = 266,
     EQUALS = 267,
     ASSIGN = 268,
     IF = 269,
     ELSE = 270,
     GREATER = 271,
     LESSER = 272,
     FOR = 273,
     TYPE_ARRAY = 274,
     TYPE_VOID = 275,
     RETURN = 276,
     WHILE = 277,
     NOT = 278,
     IMPORT = 279,
     LINK = 280,
     LPAREN = 281,
     RPAREN = 282,
     LBRACKET = 283,
     RBRACKET = 284,
     COMMA = 285,
     TWOMINUS = 286,
     TWOPLUS = 287,
     TYPE_BOOL = 288,
     TRUE = 289,
     FALSE = 290,
     AUTO = 291,
     AND = 292,
     NIL = 293,
     TYPE = 294,
     FUNCTION = 295,
     VARIABLE = 296,
     CONST = 297,
     STRUCT = 298,
     LENGTH = 299,
     THREAD = 300,
     POINT = 301,
     TYPE_INT = 302,
     TYPE_STRING = 303,
     COLON = 304,
     LSQBRACKET = 305,
     RSQBRACKET = 306,
     END = 307,
     NEG = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 80 "./src/Parser/Parser.yy"

	std::string* string;
	std::vector<SmartPointer<Statement>>* statements;
	std::vector<SmartPointer<Variable>>* variables;
	StructureInfo* structureinfo;
	Statement* statement;
	Function* function;
	SP<Variable>* variable;
	float real;
	int integer;
	TypeReference* type;



/* Line 293 of yacc.c  */
#line 252 "./gen/Parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 277 "./gen/Parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1009

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    10,    13,    19,    28,    29,    34,
      36,    38,    40,    42,    47,    51,    53,    58,    63,    67,
      69,    73,    84,    94,    96,   100,   101,   104,   108,   111,
     116,   120,   127,   133,   135,   137,   139,   142,   144,   149,
     154,   159,   166,   171,   178,   183,   185,   189,   191,   193,
     195,   201,   211,   215,   219,   223,   227,   237,   243,   247,
     251,   255,   260,   264,   268,   273,   278,   282,   286,   289,
     292,   295,   298,   302,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    55,    24,    26,     4,    27,    -1,
      55,    62,    -1,    55,    39,     3,    13,    57,    -1,    55,
      39,     3,    13,    43,    28,    56,    29,    -1,    -1,    56,
       3,    49,    57,    -1,    47,    -1,    48,    -1,    33,    -1,
      20,    -1,    19,    26,    57,    27,    -1,     3,    25,     3,
      -1,     3,    -1,    41,     3,    49,    57,    -1,    41,     3,
      13,    66,    -1,     3,    49,    57,    -1,    60,    -1,    61,
      30,    60,    -1,    40,     3,    26,    61,    27,    49,    57,
      28,    64,    29,    -1,    40,     3,    26,    27,    49,    57,
      28,    64,    29,    -1,    66,    -1,    63,    30,    66,    -1,
      -1,    64,    66,    -1,    64,    21,    66,    -1,    64,    21,
      -1,     3,    26,    63,    27,    -1,     3,    26,    27,    -1,
       3,    25,     3,    26,    63,    27,    -1,     3,    25,     3,
      26,    27,    -1,    34,    -1,    35,    -1,     6,    -1,     8,
      66,    -1,     4,    -1,    57,    28,    63,    29,    -1,    44,
      26,    66,    27,    -1,    50,    66,    51,    57,    -1,    66,
      50,    66,    51,    13,    66,    -1,    66,    50,    66,    51,
      -1,    66,    50,    66,    49,    66,    51,    -1,    45,    28,
      64,    29,    -1,    58,    -1,    58,    13,    66,    -1,    59,
      -1,     3,    -1,    65,    -1,    14,    66,    28,    64,    29,
      -1,    14,    66,    28,    64,    29,    15,    28,    64,    29,
      -1,    66,     7,    66,    -1,    66,     8,    66,    -1,    66,
       9,    66,    -1,    66,    10,    66,    -1,    18,    66,    52,
      66,    52,    66,    28,    64,    29,    -1,    22,    66,    28,
      64,    29,    -1,    38,    12,    66,    -1,    66,    12,    38,
      -1,    66,    12,    66,    -1,    66,    23,    12,    66,    -1,
      66,    16,    66,    -1,    66,    17,    66,    -1,    66,    17,
      12,    66,    -1,    66,    16,    12,    66,    -1,    26,    66,
      27,    -1,     3,    13,    66,    -1,     3,    32,    -1,    32,
       3,    -1,     3,    31,    -1,    31,     3,    -1,    66,    37,
      66,    -1,    66,    46,     3,    -1,    66,    46,     3,    13,
      66,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   126,   130,   132,   136,   142,   144,   151,
     153,   155,   157,   159,   162,   169,   186,   207,   231,   252,
     256,   263,   321,   375,   378,   384,   386,   389,   392,   398,
     418,   431,   452,   468,   470,   472,   474,   476,   483,   489,
     491,   494,   496,   498,   500,   503,   506,   509,   511,   525,
     527,   530,   534,   536,   538,   540,   542,   545,   548,   550,
     552,   554,   556,   558,   560,   562,   564,   566,   579,   591,
     602,   613,   623,   625,   633
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WORD", "STRING", "REAL", "INT", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "POWER", "EQUALS", "ASSIGN", "IF", "ELSE",
  "GREATER", "LESSER", "FOR", "TYPE_ARRAY", "TYPE_VOID", "RETURN", "WHILE",
  "NOT", "IMPORT", "LINK", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "COMMA", "TWOMINUS", "TWOPLUS", "TYPE_BOOL", "TRUE", "FALSE", "AUTO",
  "AND", "NIL", "TYPE", "FUNCTION", "VARIABLE", "CONST", "STRUCT",
  "LENGTH", "THREAD", "POINT", "TYPE_INT", "TYPE_STRING", "COLON",
  "LSQBRACKET", "RSQBRACKET", "END", "NEG", "$accept", "Program",
  "BaseStructureInfo", "Type", "Variable", "AutoVariable",
  "ArgumentDefinition", "ArgumentDefinitions", "Function", "Arguments",
  "Statements", "FunctionCall", "Statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     2,     5,     8,     0,     4,     1,
       1,     1,     1,     4,     3,     1,     4,     4,     3,     1,
       3,    10,     9,     1,     3,     0,     2,     3,     2,     4,
       3,     6,     5,     1,     1,     1,     2,     1,     4,     4,
       4,     6,     4,     6,     4,     1,     3,     1,     1,     1,
       5,     9,     3,     3,     3,     3,     9,     5,     3,     3,
       3,     4,     3,     3,     4,     4,     3,     3,     2,     2,
       2,     2,     3,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     3,    15,     0,    12,    11,     0,     9,
      10,     5,     0,     0,    19,     0,     0,     0,     7,     0,
       0,     0,     0,    14,     0,     0,    18,     0,     0,    20,
      13,     0,     6,    25,     0,     0,     0,    25,     8,    48,
      37,    35,     0,     0,     0,    28,     0,     0,    22,     0,
       0,    33,    34,     0,     0,     0,     0,     0,     0,    45,
      47,    49,    26,     0,     0,     0,     0,    70,    68,    36,
       0,     0,    27,     0,     0,    71,    69,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    67,    14,    30,     0,
      23,    25,     0,    25,    66,    58,     0,     0,     0,     0,
       0,     0,    46,    52,    53,    54,    55,    59,    60,     0,
      62,     0,    63,     0,    72,    73,     0,     0,    29,     0,
       0,     0,     0,    17,    16,    39,    44,    40,    38,    65,
      64,    61,     0,     0,    42,    32,     0,    24,    50,     0,
      57,    74,     0,     0,    31,     0,     0,    43,    41,    25,
      25,     0,     0,    51,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    35,    68,    69,    70,    24,    25,     6,   109,
      46,    71,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
     -92,    41,   -92,   -20,    16,    18,   -92,    22,    20,     8,
       9,    58,     0,   -92,    12,    13,   -92,   -92,    17,   -92,
     -92,   -92,    -9,    11,   -92,   -14,    55,    84,   -92,    84,
      84,    14,    59,   -92,    42,     1,   -92,    40,    84,   -92,
     -92,    21,   -92,   -92,    48,    84,   107,   -92,   -92,    -8,
     -92,   -92,   635,   635,   635,   635,   635,   635,   -92,    70,
      76,   -92,   -92,    73,    79,    63,    65,   635,    67,    83,
     -92,   -92,   949,   155,   635,    94,   443,   -92,   -92,   959,
     820,   727,   949,   855,   872,   -92,   -92,   635,   -11,   635,
     -92,   796,   635,   635,   635,   635,   635,   635,   683,   491,
     539,    86,   635,    96,   635,   -92,   949,    74,   -92,    -2,
     949,   -92,   635,   -92,   -92,   949,   635,    84,   903,   203,
      84,   -15,   949,   959,   959,   196,   196,    73,   949,   635,
     949,   635,   949,   635,   949,    89,   751,   587,   -92,   635,
     251,   739,   299,   949,   -92,   -92,   -92,   -92,   -92,   949,
     949,   949,   635,   635,    99,   -92,     5,   949,   101,   635,
     -92,   949,   808,   635,   -92,    81,   927,   -92,   949,   -92,
     -92,   347,   395,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,    45,   -92,   -92,    87,   -92,   -92,   -91,
     -47,   -92,   -45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yytype_int16 yytable[] =
{
      73,   121,   116,    22,    41,    74,     7,    79,    80,    81,
      82,    83,    84,    31,   148,   139,    32,    75,    76,     8,
     -15,     9,    91,    77,    78,   138,    10,    23,   139,   106,
      42,   110,   164,    11,    12,   139,    13,    26,   117,    27,
      29,     2,   115,   119,   118,    28,   156,   110,   122,   123,
     124,   125,   126,   128,   130,   132,    21,   134,    33,   136,
      30,    14,    22,    38,   140,     3,   142,   141,    43,    40,
      45,   143,    34,    85,    36,    37,    47,    15,    16,    86,
       4,     5,    88,    44,   149,    87,   150,    14,   151,    89,
      48,    17,   110,    90,   157,    92,    93,   107,   133,   135,
     137,    18,   152,    15,    16,    19,    20,   161,   162,   169,
      49,    50,   163,    51,   166,    52,   165,    17,   168,    39,
       0,    53,   171,   172,     0,    54,    15,    16,    55,    56,
       0,    19,    20,    57,     0,     0,    58,     0,    59,    60,
      17,    61,    62,     0,     0,    63,     0,     0,    64,     0,
       0,    65,    66,     0,    19,    20,     0,    67,    49,    50,
       0,    51,   144,    52,     0,   147,     0,     0,     0,    53,
       0,     0,     0,    54,    15,    16,    55,    56,     0,     0,
       0,    57,     0,     0,   105,     0,    59,    60,    17,    61,
      62,     0,     0,    63,     0,     0,    64,     0,     0,    65,
      66,     0,    19,    20,     0,    67,    49,    50,    98,    51,
       0,    52,    99,   100,     0,     0,     0,    53,     0,   101,
       0,    54,    15,    16,    55,    56,     0,     0,     0,    57,
       0,     0,   146,   102,    59,    60,    17,    61,    62,     0,
       0,    63,   103,     0,    64,     0,   104,    65,    66,     0,
      19,    20,     0,    67,    49,    50,     0,    51,     0,    52,
       0,     0,     0,     0,     0,    53,     0,     0,     0,    54,
      15,    16,    55,    56,     0,     0,     0,    57,     0,     0,
     158,     0,    59,    60,    17,    61,    62,     0,     0,    63,
       0,     0,    64,     0,     0,    65,    66,     0,    19,    20,
       0,    67,    49,    50,     0,    51,     0,    52,     0,     0,
       0,     0,     0,    53,     0,     0,     0,    54,    15,    16,
      55,    56,     0,     0,     0,    57,     0,     0,   160,     0,
      59,    60,    17,    61,    62,     0,     0,    63,     0,     0,
      64,     0,     0,    65,    66,     0,    19,    20,     0,    67,
      49,    50,     0,    51,     0,    52,     0,     0,     0,     0,
       0,    53,     0,     0,     0,    54,    15,    16,    55,    56,
       0,     0,     0,    57,     0,     0,   173,     0,    59,    60,
      17,    61,    62,     0,     0,    63,     0,     0,    64,     0,
       0,    65,    66,     0,    19,    20,     0,    67,    49,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,    53,
       0,     0,     0,    54,    15,    16,    55,    56,     0,     0,
       0,    57,     0,     0,   174,     0,    59,    60,    17,    61,
      62,     0,     0,    63,     0,     0,    64,     0,     0,    65,
      66,     0,    19,    20,     0,    67,    49,    50,     0,    51,
       0,    52,     0,     0,     0,     0,     0,    53,     0,     0,
       0,    54,    15,    16,     0,    56,     0,     0,     0,    57,
     108,     0,     0,     0,    59,    60,    17,    61,    62,     0,
       0,    63,     0,     0,    64,     0,     0,    65,    66,     0,
      19,    20,     0,    67,    49,    50,     0,    51,     0,    52,
       0,     0,     0,   129,     0,    53,     0,     0,     0,    54,
      15,    16,     0,    56,     0,     0,     0,    57,     0,     0,
       0,     0,    59,    60,    17,    61,    62,     0,     0,    63,
       0,     0,    64,     0,     0,    65,    66,     0,    19,    20,
       0,    67,    49,    50,     0,    51,     0,    52,     0,     0,
       0,   131,     0,    53,     0,     0,     0,    54,    15,    16,
       0,    56,     0,     0,     0,    57,     0,     0,     0,     0,
      59,    60,    17,    61,    62,     0,     0,    63,     0,     0,
      64,     0,     0,    65,    66,     0,    19,    20,     0,    67,
      49,    50,     0,    51,     0,    52,     0,     0,     0,     0,
       0,    53,     0,     0,     0,    54,    15,    16,     0,    56,
       0,     0,     0,    57,   155,     0,     0,     0,    59,    60,
      17,    61,    62,     0,     0,    63,     0,     0,    64,     0,
       0,    65,    66,     0,    19,    20,     0,    67,    49,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,    53,
       0,     0,     0,    54,    15,    16,     0,    56,     0,     0,
       0,    57,     0,     0,     0,     0,    59,    60,    17,    61,
      62,     0,     0,    63,     0,     0,    64,     0,     0,    65,
      66,     0,    19,    20,     0,    67,    49,    50,     0,    51,
       0,    52,     0,     0,     0,     0,     0,    53,     0,     0,
       0,    54,    15,    16,     0,    56,     0,     0,     0,    57,
       0,     0,     0,     0,    59,    60,    17,    61,    62,     0,
       0,   127,     0,     0,    64,     0,     0,    65,    66,     0,
      19,    20,     0,    67,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,     0,    94,    95,    96,    97,
     101,    98,     0,     0,     0,    99,   100,     0,    94,    95,
      96,    97,   101,    98,   102,     0,     0,    99,   100,     0,
       0,     0,     0,   103,   101,     0,   102,   104,     0,   112,
       0,     0,     0,     0,     0,   103,     0,     0,   102,   104,
       0,   159,     0,     0,     0,     0,     0,   103,     0,     0,
     153,   104,   154,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,     0,    94,    95,    96,    97,   101,
      98,     0,     0,     0,    99,   100,     0,    94,    95,    96,
      97,   101,    98,   102,     0,     0,    99,   100,     0,     0,
       0,     0,   103,   101,     0,   102,   104,   120,   111,     0,
       0,     0,     0,     0,   103,     0,     0,   102,   104,   167,
       0,     0,    94,    95,    96,    97,   103,    98,     0,     0,
     104,    99,   100,     0,     0,     0,     0,     0,   101,    94,
      95,    96,    97,   113,    98,     0,     0,     0,    99,   100,
       0,     0,   102,     0,     0,   101,     0,     0,     0,   114,
       0,   103,     0,     0,     0,   104,     0,     0,     0,   102,
      94,    95,    96,    97,     0,    98,     0,     0,   103,    99,
     100,     0,   104,     0,     0,     0,   101,     0,     0,     0,
     145,     0,     0,     0,    94,    95,    96,    97,     0,    98,
     102,     0,     0,    99,   100,     0,     0,     0,     0,   103,
     101,     0,     0,   104,     0,   170,    94,    95,    96,    97,
       0,    98,     0,     0,   102,    99,   100,     0,    96,    97,
       0,    98,   101,   103,     0,    99,   100,   104,     0,     0,
       0,     0,   101,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   102,     0,     0,   104,
       0,     0,     0,     0,     0,   103,     0,     0,     0,   104
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-92))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      47,    92,    13,     3,     3,    13,    26,    52,    53,    54,
      55,    56,    57,    27,    29,    30,    30,    25,    26,     3,
      28,     3,    67,    31,    32,    27,     4,    27,    30,    74,
      29,    76,    27,    13,    26,    30,    27,    25,    49,    26,
      49,     0,    87,    90,    89,    28,   137,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    11,   102,     3,   104,
      49,     3,     3,    49,   111,    24,   113,   112,    28,    27,
      49,   116,    27,     3,    29,    30,    28,    19,    20,     3,
      39,    40,     3,    38,   129,    12,   131,     3,   133,    26,
      45,    33,   137,    28,   139,    28,    13,     3,    12,     3,
      26,    43,    13,    19,    20,    47,    48,   152,   153,    28,
       3,     4,    13,     6,   159,     8,    15,    33,   163,    32,
      -1,    14,   169,   170,    -1,    18,    19,    20,    21,    22,
      -1,    47,    48,    26,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    -1,    47,    48,    -1,    50,     3,     4,
      -1,     6,   117,     8,    -1,   120,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,
      45,    -1,    47,    48,    -1,    50,     3,     4,    12,     6,
      -1,     8,    16,    17,    -1,    -1,    -1,    14,    -1,    23,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      -1,    -1,    29,    37,    31,    32,    33,    34,    35,    -1,
      -1,    38,    46,    -1,    41,    -1,    50,    44,    45,    -1,
      47,    48,    -1,    50,     3,     4,    -1,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    -1,    47,    48,
      -1,    50,     3,     4,    -1,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      31,    32,    33,    34,    35,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    -1,    47,    48,    -1,    50,
       3,     4,    -1,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    -1,    47,    48,    -1,    50,     3,     4,
      -1,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,
      45,    -1,    47,    48,    -1,    50,     3,     4,    -1,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,
      47,    48,    -1,    50,     3,     4,    -1,     6,    -1,     8,
      -1,    -1,    -1,    12,    -1,    14,    -1,    -1,    -1,    18,
      19,    20,    -1,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    -1,    47,    48,
      -1,    50,     3,     4,    -1,     6,    -1,     8,    -1,    -1,
      -1,    12,    -1,    14,    -1,    -1,    -1,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    -1,    47,    48,    -1,    50,
       3,     4,    -1,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    18,    19,    20,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    -1,    47,    48,    -1,    50,     3,     4,
      -1,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    18,    19,    20,    -1,    22,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,
      45,    -1,    47,    48,    -1,    50,     3,     4,    -1,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,
      47,    48,    -1,    50,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    16,    17,    -1,     7,     8,     9,    10,
      23,    12,    -1,    -1,    -1,    16,    17,    -1,     7,     8,
       9,    10,    23,    12,    37,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    46,    23,    -1,    37,    50,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    37,    50,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    16,    17,    -1,     7,     8,     9,    10,    23,
      12,    -1,    -1,    -1,    16,    17,    -1,     7,     8,     9,
      10,    23,    12,    37,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    46,    23,    -1,    37,    50,    51,    28,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    37,    50,    51,
      -1,    -1,     7,     8,     9,    10,    46,    12,    -1,    -1,
      50,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,     7,
       8,     9,    10,    28,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,    37,    -1,    -1,    23,    -1,    -1,    -1,    27,
      -1,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    37,
       7,     8,     9,    10,    -1,    12,    -1,    -1,    46,    16,
      17,    -1,    50,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      27,    -1,    -1,    -1,     7,     8,     9,    10,    -1,    12,
      37,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    46,
      23,    -1,    -1,    50,    -1,    28,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    37,    16,    17,    -1,     9,    10,
      -1,    12,    23,    46,    -1,    16,    17,    50,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    37,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,    24,    39,    40,    62,    26,     3,     3,
       4,    13,    26,    27,     3,    19,    20,    33,    43,    47,
      48,    57,     3,    27,    60,    61,    25,    26,    28,    49,
      49,    27,    30,     3,    57,    56,    57,    57,    49,    60,
      27,     3,    29,    28,    57,    49,    64,    28,    57,     3,
       4,     6,     8,    14,    18,    21,    22,    26,    29,    31,
      32,    34,    35,    38,    41,    44,    45,    50,    57,    58,
      59,    65,    66,    64,    13,    25,    26,    31,    32,    66,
      66,    66,    66,    66,    66,     3,     3,    12,     3,    26,
      28,    66,    28,    13,     7,     8,     9,    10,    12,    16,
      17,    23,    37,    46,    50,    29,    66,     3,    27,    63,
      66,    28,    52,    28,    27,    66,    13,    49,    66,    64,
      51,    63,    66,    66,    66,    66,    66,    38,    66,    12,
      66,    12,    66,    12,    66,     3,    66,    26,    27,    30,
      64,    66,    64,    66,    57,    27,    29,    57,    29,    66,
      66,    66,    13,    49,    51,    27,    63,    66,    29,    52,
      29,    66,    66,    13,    27,    15,    66,    51,    66,    28,
      28,    64,    64,    29,    29
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 123 "./src/Parser/Parser.yy"
    {
		Variables.clear();
		(yyval.statements) = 0;
	}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 126 "./src/Parser/Parser.yy"
    {
		ImportList.push_back(*(yyvsp[(4) - (5)].string));
		delete (yyvsp[(4) - (5)].string);
		(yyval.statements) = 0;
	}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 130 "./src/Parser/Parser.yy"
    {
		(yyval.statements) = 0;
	}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 132 "./src/Parser/Parser.yy"
    {
		Functions[*(yyvsp[(3) - (5)].string)] = NamespaceEntry(*(yyvsp[(5) - (5)].type));
		delete (yyvsp[(3) - (5)].string);
		delete (yyvsp[(5) - (5)].type);
	}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 136 "./src/Parser/Parser.yy"
    {
		Functions[*(yyvsp[(3) - (8)].string)] = NamespaceEntry(TypeReference(new TypeReferenceCore(*(yyvsp[(3) - (8)].string), (yyvsp[(7) - (8)].structureinfo))));
		delete (yyvsp[(3) - (8)].string);
	}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 142 "./src/Parser/Parser.yy"
    {
		(yyval.structureinfo) = new StructureInfo();
	}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 144 "./src/Parser/Parser.yy"
    {
		(yyvsp[(1) - (4)].structureinfo)->addInfo(*(yyvsp[(2) - (4)].string), *(yyvsp[(4) - (4)].type));
		delete (yyvsp[(2) - (4)].string);
		delete (yyvsp[(4) - (4)].type);
	}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 151 "./src/Parser/Parser.yy"
    {
		(yyval.type) = new TypeReference( new TypeReferenceCore ( "", getTypeManager().getType(Int) ) );
	}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 153 "./src/Parser/Parser.yy"
    {
		(yyval.type) = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(String) ) );
	}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 155 "./src/Parser/Parser.yy"
    {
		(yyval.type) = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(Boolean) ) );
	}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 157 "./src/Parser/Parser.yy"
    {
		(yyval.type) = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(Void) ) );
	}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 159 "./src/Parser/Parser.yy"
    {
		(yyval.type) = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(Array, *(yyvsp[(3) - (4)].type)) ) );
		delete (yyvsp[(3) - (4)].type);
	}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 162 "./src/Parser/Parser.yy"
    {
	
		(yyval.type) = new TypeReference ( new TypeReferenceCore( *(yyvsp[(1) - (3)].string), *(yyvsp[(3) - (3)].string), nullptr) );
		TypeReferences.push_back(*(yyval.type));
		delete (yyvsp[(1) - (3)].string);
		delete (yyvsp[(3) - (3)].string);
		
	}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 169 "./src/Parser/Parser.yy"
    {
		
		/**
		if (Functions[*$1].type() != TypeEntry) {
			char err[256];
			sprintf(err, "%s is not a type\n", $1->c_str());
			yyerror(err);
			return -1;
		}*/
		
		(yyval.type) = new TypeReference( new TypeReferenceCore ( *(yyvsp[(1) - (1)].string), nullptr ) );
		TypeReferences.push_back(*(yyval.type));
		
		delete (yyvsp[(1) - (1)].string);
	}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 186 "./src/Parser/Parser.yy"
    {

		printf("TODO: Check no variable is declared as void\n");

		auto it = Variables.find(*(yyvsp[(2) - (4)].string));
			
		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
			SP<Variable>* nVar = new SP<Variable>(new Variable(0, *(yyvsp[(4) - (4)].type), nullptr));
			VariableReferences.push_back(*nVar);
			Variables[*(yyvsp[(2) - (4)].string)] = *nVar;
			(yyval.variable) = nVar;
		}
		
		delete (yyvsp[(2) - (4)].string);
		delete (yyvsp[(4) - (4)].type);
	}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 207 "./src/Parser/Parser.yy"
    {

		auto it = Variables.find(*(yyvsp[(2) - (4)].string));
				
		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
		
			SafeStatement sp = (yyvsp[(4) - (4)].statement);
		
			SP<Variable> nVar = SP<Variable>(new Variable(0, nullptr, nullptr));
			Variables[*(yyvsp[(2) - (4)].string)] = nVar;
			
			ParserReference r(AutoVariablePair(nVar, sp));
			StatementReferences.push_back(r);			

			(yyval.statement) = new AssignVariableStatement(yylineno, yytext, nVar, sp);
		}
		
		delete (yyvsp[(2) - (4)].string);
	}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 231 "./src/Parser/Parser.yy"
    {
		
		printf("TODO: Stop void argument declaration\n");

		auto it = Variables.find(*(yyvsp[(1) - (3)].string));

		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
			SP<Variable>* nVar = new SP<Variable>(new Variable(0, *(yyvsp[(3) - (3)].type), nullptr));
			VariableReferences.push_back(*nVar);
			Variables[*(yyvsp[(1) - (3)].string)] = *nVar;
			(yyval.variable) = nVar;
		}
		
		delete (yyvsp[(1) - (3)].string);
		delete (yyvsp[(3) - (3)].type);
	}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 252 "./src/Parser/Parser.yy"
    {
		(yyval.variables) = new std::vector<SP<Variable>>();
		(yyval.variables)->push_back(*(yyvsp[(1) - (1)].variable));
		delete (yyvsp[(1) - (1)].variable);
	}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 256 "./src/Parser/Parser.yy"
    {
		(yyval.variables) = (yyvsp[(1) - (3)].variables);
		(yyval.variables)->push_back(*(yyvsp[(3) - (3)].variable));
		delete (yyvsp[(3) - (3)].variable);
	}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 263 "./src/Parser/Parser.yy"
    {
		std::vector<SP<Variable>> values;

		int pos = 0;
		for (auto it = Variables.begin(); it != Variables.end(); it++) {
			it->second->setPosition(pos);
			values.push_back(it->second);
			pos++;
		}


		SP<Variable> returnTemplate = new Variable(0, *(yyvsp[(7) - (10)].type), nullptr);
		VariableReferences.push_back(returnTemplate);
		SP<Function> fn = new ScriptedFunction(*(yyvsp[(7) - (10)].type), returnTemplate, *(yyvsp[(9) - (10)].statements), values, *(yyvsp[(4) - (10)].variables));
		
		if (Functions[*(yyvsp[(2) - (10)].string)].type() == EmptyEntry) {
		
			std::vector<SafeFunction> newSet;
			newSet.push_back(fn);

			Functions[*(yyvsp[(2) - (10)].string)] = NamespaceEntry(newSet);
		
		} else {
		
			if ( Functions[*(yyvsp[(2) - (10)].string)].type() != FunctionSetEntry) {
				yyerror("Not a function type");
				return -1;
			}
			
			std::vector<SafeFunction> functions = Functions[*(yyvsp[(2) - (10)].string)].getFunctionSet();
			
			if ( functions.size() > 0) {
				
				printf("TODO: Function return type.\n");
				
				if (Parser::functionSetAlreadyContainsEquivilent(fn, functions) == true) {
					yyerror("Identical function already defined");
					return -1;
				}
			}
			
			Functions[*(yyvsp[(2) - (10)].string)].addFunctionToSet(fn);
		
		}
		
		Variables.clear();
		
		//Delete name
		delete (yyvsp[(2) - (10)].string);
		
		//Delete statements vector
		delete (yyvsp[(9) - (10)].statements);
		
		//Delete variables vector
		delete (yyvsp[(4) - (10)].variables);
		
		delete (yyvsp[(7) - (10)].type);

	}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 321 "./src/Parser/Parser.yy"
    {
		
		std::vector<SP<Variable>> values;

		int pos = 0;
		for (auto it = Variables.begin(); it != Variables.end(); it++) {
			it->second->setPosition(pos);
			values.push_back(it->second);
			pos++;
		}
	
	
		SP<Variable> returnTemplate = new Variable(0, *(yyvsp[(6) - (9)].type), nullptr);
		VariableReferences.push_back(returnTemplate);
		SP<Function> fn = SP<Function>(new ScriptedFunction(*(yyvsp[(6) - (9)].type), returnTemplate, *(yyvsp[(8) - (9)].statements), values, std::vector<SP<Variable>>()));
		
		if (Functions[*(yyvsp[(2) - (9)].string)].type() == EmptyEntry) {
		
			std::vector<SafeFunction> newSet;
			newSet.push_back(fn);

			Functions[*(yyvsp[(2) - (9)].string)] = NamespaceEntry(newSet);
		
		} else {
		
			if ( Functions[*(yyvsp[(2) - (9)].string)].type() != FunctionSetEntry) {
				yyerror("Not a function type");
				return -1;
			}
			
			std::vector<SafeFunction> functions = Functions[*(yyvsp[(2) - (9)].string)].getFunctionSet();
			
			if ( functions.size() > 0) {
			
				printf("TODO: Function return type.\n");
				
				if (Parser::functionSetAlreadyContainsEquivilent(fn, functions) == true) {
					yyerror("Identical function already defined");
					return -1;
				}
			}
			
			Functions[*(yyvsp[(2) - (9)].string)].addFunctionToSet(fn);
		
		}
	
		Variables.clear();

		delete (yyvsp[(2) - (9)].string);
		delete (yyvsp[(8) - (9)].statements);
		delete (yyvsp[(6) - (9)].type);
	}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 375 "./src/Parser/Parser.yy"
    {
		(yyval.statements) = new std::vector<SmartPointer<Statement>>();
		(yyval.statements)->push_back((yyvsp[(1) - (1)].statement));
	}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 378 "./src/Parser/Parser.yy"
    {
		(yyval.statements) = (yyvsp[(1) - (3)].statements);
		(yyval.statements)->push_back((yyvsp[(3) - (3)].statement));
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 384 "./src/Parser/Parser.yy"
    {
		(yyval.statements) = new std::vector<SmartPointer<Statement>>();
	}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 386 "./src/Parser/Parser.yy"
    {
		(yyval.statements) = (yyvsp[(1) - (2)].statements);
		(yyval.statements)->push_back((yyvsp[(2) - (2)].statement));
	}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 389 "./src/Parser/Parser.yy"
    {
		(yyval.statements) = (yyvsp[(1) - (3)].statements);
		(yyval.statements)->push_back(new ReturnStatement(yylineno, yytext, (yyvsp[(3) - (3)].statement)));
	}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 392 "./src/Parser/Parser.yy"
    {
		(yyval.statements) = (yyvsp[(1) - (2)].statements);
		(yyval.statements)->push_back(new ReturnStatement(yylineno, yytext, nullptr));
	}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 398 "./src/Parser/Parser.yy"
    {
	
		std::vector<SmartPointer<Statement>> args;
	
		for (unsigned int i = 0; i < (yyvsp[(3) - (4)].statements)->size(); ++i) {
			args.push_back((yyvsp[(3) - (4)].statements)->at(i));
		}
	
		delete (yyvsp[(3) - (4)].statements);
		
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference("", *(yyvsp[(1) - (4)].string), args, 0));
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		
		(yyval.statement) = new FunctionStatement(yylineno, yytext, reference);
		
		//Free the name pointer
		delete (yyvsp[(1) - (4)].string);
		
	}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 418 "./src/Parser/Parser.yy"
    {
		std::vector<SmartPointer<Statement>> args;
		
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference("", *(yyvsp[(1) - (3)].string), args, 0));
		
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		
		(yyval.statement) = new FunctionStatement(yylineno, yytext, reference);
		
		//Free the name pointer
		delete (yyvsp[(1) - (3)].string);
	}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 431 "./src/Parser/Parser.yy"
    {
	
		std::vector<SmartPointer<Statement>> args;
	
		for (unsigned int i = 0; i < (yyvsp[(5) - (6)].statements)->size(); ++i) {
			args.push_back((yyvsp[(5) - (6)].statements)->at(i));
		}
	
		delete (yyvsp[(5) - (6)].statements);
	
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference(*(yyvsp[(1) - (6)].string), *(yyvsp[(3) - (6)].string), args, 0));
	
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		(yyval.statement) = new FunctionStatement(yylineno, yytext, reference);
	
		//Free the name pointers
		delete (yyvsp[(1) - (6)].string);
		delete (yyvsp[(3) - (6)].string);
		
	}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 452 "./src/Parser/Parser.yy"
    {
		std::vector<SmartPointer<Statement>> args;
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference(*(yyvsp[(1) - (5)].string), *(yyvsp[(3) - (5)].string), args, 0));
		
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		(yyval.statement) = new FunctionStatement(yylineno, yytext, reference);
		
		//Free the name pointers
		delete (yyvsp[(1) - (5)].string);
		delete (yyvsp[(3) - (5)].string);

	}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 468 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new BoolStatement(yylineno, yytext, true);
	}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 470 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new BoolStatement(yylineno, yytext, false);
	}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 472 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new IntStatement(yylineno, yytext, (yyvsp[(1) - (1)].integer));
	}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 474 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new NegativeStatement(yylineno, yytext, (yyvsp[(2) - (2)].statement));
	}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 476 "./src/Parser/Parser.yy"
    {
		
		(yyval.statement) = new StringStatement(yylineno, yytext, *(yyvsp[(1) - (1)].string));
		
		//Free string pointer
		delete (yyvsp[(1) - (1)].string);

	}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 483 "./src/Parser/Parser.yy"
    {
	
		(yyval.statement) = new StructureStatement(yylineno, yytext, *(yyvsp[(1) - (4)].type), *(yyvsp[(3) - (4)].statements));
		delete (yyvsp[(3) - (4)].statements);
		delete (yyvsp[(1) - (4)].type);
		
	}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 489 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new ArrayLengthStatement(yylineno, yytext, (yyvsp[(3) - (4)].statement));
	}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 491 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new ArrayStatement(yylineno, yytext, getTypeManager().getType(Array, *(yyvsp[(4) - (4)].type)), (yyvsp[(2) - (4)].statement));
		delete (yyvsp[(4) - (4)].type);
	}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 494 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new AssignArrayStatement(yylineno, yytext, (yyvsp[(1) - (6)].statement), (yyvsp[(6) - (6)].statement), (yyvsp[(3) - (6)].statement)); 
	}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 496 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new GetArrayStatement(yylineno, yytext, (yyvsp[(1) - (4)].statement), (yyvsp[(3) - (4)].statement)); 
	}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 498 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new ArraySliceStatement(yylineno, yytext, (yyvsp[(1) - (6)].statement), (yyvsp[(3) - (6)].statement), (yyvsp[(5) - (6)].statement));
	}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 500 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new ThreadStatement(yylineno, yytext, *(yyvsp[(3) - (4)].statements));
		delete (yyvsp[(3) - (4)].statements);
	}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 503 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new GetVariableStatement(yylineno, yytext, *(yyvsp[(1) - (1)].variable));
		delete (yyvsp[(1) - (1)].variable);
	}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 506 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new AssignVariableStatement(yylineno, yytext, *(yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].statement));
		delete (yyvsp[(1) - (3)].variable);
	}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 509 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = (yyvsp[(1) - (1)].statement);
	}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 511 "./src/Parser/Parser.yy"
    {

		auto it = Variables.find(*(yyvsp[(1) - (1)].string));

		if (it == Variables.end()) {
			yyerror("Variable not defined");
			return -1;
		} else {
			(yyval.statement) = new GetVariableStatement(yylineno, yytext, it->second);
		}

		//Free name pointer
		delete (yyvsp[(1) - (1)].string);
		
	}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 525 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = (yyvsp[(1) - (1)].statement);
	}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 527 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new IfStatement(yylineno, yytext, (yyvsp[(2) - (5)].statement), *(yyvsp[(4) - (5)].statements), std::vector<SP<Statement>>());
		delete (yyvsp[(4) - (5)].statements);
	}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 530 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new IfStatement(yylineno, yytext, (yyvsp[(2) - (9)].statement), *(yyvsp[(4) - (9)].statements), *(yyvsp[(8) - (9)].statements));
		delete (yyvsp[(4) - (9)].statements);
		delete (yyvsp[(8) - (9)].statements);
	}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 534 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new OperateStatement(yylineno, yytext, Add, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 536 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new OperateStatement(yylineno, yytext, Subtract, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 538 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new OperateStatement(yylineno, yytext, Multiply, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 540 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new OperateStatement(yylineno, yytext, Divide, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 542 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new ForStatement(yylineno, yytext, (yyvsp[(2) - (9)].statement), (yyvsp[(4) - (9)].statement), (yyvsp[(6) - (9)].statement), *(yyvsp[(8) - (9)].statements));
		delete (yyvsp[(8) - (9)].statements);
	}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 545 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new WhileStatement(yylineno, yytext, (yyvsp[(2) - (5)].statement), *(yyvsp[(4) - (5)].statements));
		delete (yyvsp[(4) - (5)].statements);
	}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 548 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestNilStatement(yylineno, yytext, (yyvsp[(3) - (3)].statement));
	}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 550 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestNilStatement(yylineno, yytext, (yyvsp[(1) - (3)].statement));
	}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 552 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestStatement(yylineno, yytext, TestEquals, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 554 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestStatement(yylineno, yytext, TestNotEquals, (yyvsp[(1) - (4)].statement), (yyvsp[(4) - (4)].statement));
	}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 556 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestStatement(yylineno, yytext, TestGreater, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 558 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestStatement(yylineno, yytext, TestLess, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 560 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestStatement(yylineno, yytext, TestLessOrEqual, (yyvsp[(1) - (4)].statement), (yyvsp[(4) - (4)].statement));
	}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 562 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new TestStatement(yylineno, yytext, TestGreaterOrEqual, (yyvsp[(1) - (4)].statement), (yyvsp[(4) - (4)].statement));
	}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 564 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = (yyvsp[(2) - (3)].statement);
	}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 566 "./src/Parser/Parser.yy"
    {
		
		auto it = Variables.find(*(yyvsp[(1) - (3)].string));

		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			(yyval.statement) = new AssignVariableStatement(yylineno, yytext, it->second, (yyvsp[(3) - (3)].statement));
		}
		
		//Free up string pointer.
		delete (yyvsp[(1) - (3)].string);
		
	}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 579 "./src/Parser/Parser.yy"
    {
	
		auto it = Variables.find(*(yyvsp[(1) - (2)].string));
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			(yyval.statement) = new IncrementStatement(yylineno, yytext, it->second, Increment, false);
		}
		
		//Free name pointer
		delete (yyvsp[(1) - (2)].string);
		
	}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 591 "./src/Parser/Parser.yy"
    {
		auto it = Variables.find(*(yyvsp[(2) - (2)].string));
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			(yyval.statement) = new IncrementStatement(yylineno, yytext, it->second, Increment, true);
		}
		
		//Free name pointer
		delete (yyvsp[(2) - (2)].string);
		
	}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 602 "./src/Parser/Parser.yy"
    {
		auto it = Variables.find(*(yyvsp[(1) - (2)].string));
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			(yyval.statement) = new IncrementStatement(yylineno, yytext, it->second, Decrement, false);
		}
		
		//Free name pointer
		delete (yyvsp[(1) - (2)].string);
		
	}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 613 "./src/Parser/Parser.yy"
    {
		auto it = Variables.find(*(yyvsp[(2) - (2)].string));
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			(yyval.statement) = new IncrementStatement(yylineno, yytext, it->second, Decrement, true);
		}
		
		//Free name pointer
		delete (yyvsp[(2) - (2)].string);
	}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 623 "./src/Parser/Parser.yy"
    {
		(yyval.statement) = new AndStatement(yylineno, yytext, (yyvsp[(1) - (3)].statement), (yyvsp[(3) - (3)].statement));
	}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 625 "./src/Parser/Parser.yy"
    {
		
		(yyval.statement) = new GetStructureElementStatement(yylineno, yytext, (yyvsp[(1) - (3)].statement), *(yyvsp[(3) - (3)].string));
		
		ParserReference r((GetStructureElementStatement*) (yyval.statement));
		StatementReferences.push_back(r);
		
		delete (yyvsp[(3) - (3)].string);
	}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 633 "./src/Parser/Parser.yy"
    {
	
		(yyval.statement) = new StructureAssignElement(yylineno, yytext, (yyvsp[(1) - (5)].statement), (yyvsp[(5) - (5)].statement), *(yyvsp[(3) - (5)].string));
		
		ParserReference r((StructureAssignElement*) (yyval.statement));
		StatementReferences.push_back(r);
	
		delete (yyvsp[(3) - (5)].string);
	}
    break;



/* Line 1806 of yacc.c  */
#line 2859 "./gen/Parser.cpp"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 644 "./src/Parser/Parser.yy"


void yyerror(std::string s)
{

  printf("ERROR: %s at symbol %s on line %i\n", s.c_str(), yytext, yylineno);
  ParsingError = true;
}

void yyerror(const char* s)
{
  yyerror(std::string(s));
}

