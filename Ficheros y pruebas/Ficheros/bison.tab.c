/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

#include <stdio.h>
#include "SymbolTable.h"
#include "breaklist.h"
#include "FunctionsList.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <typeinfo>

using namespace std;

FILE *file;

extern FILE *yyin; /* declarado en l´exico */
extern int numlin; /* l´exico le da valores */
int yylex(void);
extern char* yytext;
extern int yydebug; /* modo debug si -t */
extern void yyerror(string mens);

void createVar(int type, string name);
Symbol* createVar2(int type, string name);
void checkIsNotString(int tipo);
void createParameter(int type, string name);
void generaCabecera();
void varEnPilaSymbol(string name);
void varEnPilaValue(int tipo);
void posicionMemoria(Symbol * item);
void checkAritmetic(int tipo1, int tipo2);
void checkLogic(int tipo1, int tipo2);
void checkEqualType(int tipo1, int tipo2);

#define generateCode(formato, params...) { \
	fprintf(file, formato, ##params);\
}

SymbolTable tabla;
breaklist breaks;
FunctionsList listaFunciones;

unsigned int tamanoString = 0; //Se usa para conocer el tamaño de las ristras que se van a imprimir
unsigned int etiqueta = 2; 
unsigned int dirRetorno; 

#line 112 "bison.tab.c" /* yacc.c:339  */

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
   by #include "bison.tab.h".  */
#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CAT = 258,
    KITTY = 259,
    KITTEN = 260,
    IDENTIF = 261,
    CKITTYVALUE = 262,
    CKITTENVALUE = 263,
    KITTENVALUE = 264,
    CATVALUE = 265,
    KITTYVALUE = 266,
    MAIN = 267,
    ASIGNA = 268,
    PUNTOYCOMA = 269,
    SUMA = 270,
    RESTA = 271,
    DIVISION = 272,
    MULTIPLICACION = 273,
    IGUAL = 274,
    DISTINTO = 275,
    MAYORQUE = 276,
    MENORQUE = 277,
    MAYORIGUAL = 278,
    MENORIGUAL = 279,
    OR = 280,
    AND = 281,
    NOT = 282,
    LLAMADA = 283,
    SEPARADOR = 284,
    FUNCION = 285,
    ABRELLAVE = 286,
    CIERRALLAVE = 287,
    ABREPARENTESIS = 288,
    CIERRAPARENTESIS = 289,
    HALT = 290,
    DOSPUNTOS = 291,
    BREAK = 292,
    IF = 293,
    ELSE = 294,
    WHILE = 295,
    FOR = 296,
    LEETECLADO = 297,
    ESCRIBEPANTALLA = 298,
    CONCATENA = 299,
    SALTOLINEA = 300,
    IN = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 47 "bison.y" /* yacc.c:355  */
 float real; double doble; int entero; char *ristra; char caracter; unsigned int uentero;

#line 202 "bison.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "bison.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    72,    87,    68,   102,   103,   107,   107,
     147,   169,   147,   196,   201,   207,   210,   211,   214,   231,
     253,   268,   269,   281,   290,   301,   315,   316,   317,   318,
     335,   341,   346,   353,   359,   335,   411,   421,   411,   438,
     448,   456,   459,   438,   466,   504,   503,   558,   559,   568,
     584,   602,   607,   608,   609,   612,   612,   661,   706,   715,
     724,   733,   742,   756,   770,   784,   798,   812,   825,   840,
     855,   871,   872,   875,   880,   885,   891
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CAT", "KITTY", "KITTEN", "IDENTIF",
  "CKITTYVALUE", "CKITTENVALUE", "KITTENVALUE", "CATVALUE", "KITTYVALUE",
  "MAIN", "ASIGNA", "PUNTOYCOMA", "SUMA", "RESTA", "DIVISION",
  "MULTIPLICACION", "IGUAL", "DISTINTO", "MAYORQUE", "MENORQUE",
  "MAYORIGUAL", "MENORIGUAL", "OR", "AND", "NOT", "LLAMADA", "SEPARADOR",
  "FUNCION", "ABRELLAVE", "CIERRALLAVE", "ABREPARENTESIS",
  "CIERRAPARENTESIS", "HALT", "DOSPUNTOS", "BREAK", "IF", "ELSE", "WHILE",
  "FOR", "LEETECLADO", "ESCRIBEPANTALLA", "CONCATENA", "SALTOLINEA", "IN",
  "$accept", "programa", "$@1", "$@2", "$@3", "conjunto_funciones",
  "funcion", "$@4", "$@5", "$@6", "parametros", "bloque_llaves",
  "lista_instrucciones", "imprimir", "instruccion", "$@7", "@8", "@9",
  "$@10", "$@11", "@12", "@13", "@14", "@15", "$@16", "$@17", "$@18",
  "parametros_instruccion", "declaracion", "tipo", "asignacion", "$@19",
  "exp", "valor", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -90,    17,   -26,   -90,    23,     3,     6,   -90,     7,     4,
     -90,   -90,   -90,   -90,    30,    43,    40,    49,   -90,   -90,
     -90,    51,     5,    38,     4,   -90,    65,   -90,    44,    42,
      39,   -90,   -90,    46,    47,    48,    59,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -11,   -90,   -90,    62,    71,   -90,
      44,   -90,   -90,   -90,   -90,    42,    42,   160,   -90,    78,
      42,    42,    56,   -90,   -90,     5,   -90,   113,    94,   -90,
      68,    79,   -90,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,   114,   123,    99,   119,   124,
     -90,   -90,    42,    97,   -90,   195,   195,    87,    87,   -90,
     -90,   -90,   -90,   -90,   -90,    68,    68,   -90,   103,   112,
     -90,   -90,   -90,    42,   173,   -90,    63,   123,   101,     7,
       7,   185,   -90,     7,   115,   142,   -90,   144,   -90,   -90,
     137,   -90,   106,   138,   152,   129,   163,   187,    63,   -90,
     -90,   -90,    63,   -90,     7,   157,   165,   -90,    42,   188,
     139,   -90,   -90,     7,     7,   -90,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     3,     0,    17,
       4,    52,    53,    54,     0,     0,     0,     0,    39,    36,
      30,     0,     0,     0,    17,    27,     0,    26,     7,     0,
       0,    47,    48,     0,     0,     0,     0,    18,    20,    19,
      25,    22,    24,    23,     0,    15,    16,    55,     0,     5,
       7,    76,    75,    73,    74,     0,     0,     0,    72,    45,
       0,     0,     0,    29,    28,     0,    51,     0,     0,     6,
      70,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    21,     0,    10,    71,    60,    58,    61,    59,    63,
      62,    64,    65,    67,    66,    68,    69,    44,    50,     0,
      40,    37,    55,     0,     0,     8,     0,     0,     0,     0,
       0,    32,    56,     0,     0,     0,    49,     0,    41,    38,
       0,     9,     0,    13,     0,     0,     0,     0,     0,    46,
      42,    33,     0,    14,     0,     0,     0,    43,     0,     0,
       0,    11,    34,     0,     0,    12,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   -90,   -90,   122,   -90,   -90,   -90,   -90,
      83,   -89,   199,   159,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   108,   -90,   -60,
     164,   -90,   -55,   -90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,    28,    49,    50,   123,   116,   153,
     124,    10,    23,    44,    24,    35,   113,   130,   145,   154,
      34,   120,    33,   119,   135,   144,    86,   109,    25,    26,
      27,    67,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    71,    89,    64,     4,    87,    88,    11,    12,    13,
      14,    37,    38,    39,    40,    41,    42,     3,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     128,   129,    15,    65,   131,     5,     6,   114,     9,    16,
       7,    17,    18,    29,    19,    20,    21,    22,    51,    30,
      43,    52,    53,    54,    31,   147,   125,    36,   121,    11,
      12,    13,    14,    32,   155,   156,    11,    12,    13,    55,
      45,    47,    59,    63,    48,    56,    66,    68,   125,    60,
      61,    62,   146,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,   150,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    77,    78,    79,    80,
      81,    82,    85,    94,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    92,    93,   107,   108,
     112,   115,   117,   110,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   118,   127,   133,   132,
     134,   136,   137,   111,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   139,   138,   140,   141,
     148,   149,    69,   152,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   122,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    75,    76,    77,    78,    79,    80,    81,    82,
     142,   143,   151,    46,    91,   126,    90
};

static const yytype_uint8 yycheck[] =
{
      55,    56,    62,    14,    30,    60,    61,     3,     4,     5,
       6,     6,     7,     8,     9,    10,    11,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     119,   120,    28,    44,   123,    12,    33,    92,    31,    35,
      34,    37,    38,    13,    40,    41,    42,    43,     6,     6,
      45,     9,    10,    11,    14,   144,   116,     6,   113,     3,
       4,     5,     6,    14,   153,   154,     3,     4,     5,    27,
      32,     6,    33,    14,    30,    33,    14,     6,   138,    33,
      33,    33,   142,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   148,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    19,    20,    21,    22,
      23,    24,    34,    34,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    13,    33,    14,     6,
       6,    34,    29,    34,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    34,    46,     6,    34,
       6,    14,    46,    34,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    14,    29,    39,     6,
      13,     6,    50,    34,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    17,    18,    19,    20,    21,    22,    23,    24,
      33,   138,    34,    24,    65,   117,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,    30,    12,    33,    34,    50,    31,
      58,     3,     4,     5,     6,    28,    35,    37,    38,    40,
      41,    42,    43,    59,    61,    75,    76,    77,    51,    13,
       6,    14,    14,    69,    67,    62,     6,     6,     7,     8,
       9,    10,    11,    45,    60,    32,    59,     6,    30,    52,
      53,     6,     9,    10,    11,    27,    33,    79,    80,    33,
      33,    33,    33,    14,    14,    44,    14,    78,     6,    52,
      79,    79,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    34,    73,    79,    79,    76,
      77,    60,    13,    33,    34,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    14,     6,    74,
      34,    34,     6,    63,    79,    34,    55,    29,    34,    70,
      68,    79,    14,    54,    57,    76,    74,    46,    58,    58,
      64,    58,    34,     6,     6,    71,    14,    46,    29,    14,
      39,     6,    33,    57,    72,    65,    76,    58,    13,     6,
      79,    34,    34,    56,    66,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    49,    50,    51,    48,    52,    52,    54,    53,
      55,    56,    53,    57,    57,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      62,    63,    64,    65,    66,    61,    67,    68,    61,    69,
      70,    71,    72,    61,    61,    73,    61,    61,    61,    74,
      74,    75,    76,    76,    76,    78,    77,    77,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     2,     0,     0,     6,
       0,     0,    13,     2,     4,     3,     2,     0,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       0,     0,     0,     0,     0,    15,     0,     0,     7,     0,
       0,     0,     0,    11,     5,     0,     9,     2,     2,     3,
       1,     3,     1,     1,     1,     0,     6,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     1,     1,     1
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
#line 68 "bison.y" /* yacc.c:1646  */
    {
		    generaCabecera();
		}
#line 1421 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "bison.y" /* yacc.c:1646  */
    {
                Symbol *item = createVar2(FUNCTION,"main");
                if(item==NULL){yyerror("La función no se ha declarado");}
                if(item->etiquetaFuncion == -1){
                    tabla.addEtiquetaToFuncion((yyvsp[-2].ristra), 1); //MAIN siempre tendrá la etq 1
                }
				
                tabla.addScope();
            
			    generateCode("L %u:\tR7 = R6 - 8;\t //Comienza la funcion\n", item->etiquetaFuncion);
			    tabla.relDir += 8;
                item->direction = tabla.relDir;

        }
#line 1440 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "bison.y" /* yacc.c:1646  */
    {
            generateCode("\t\tGT(-2);\n");        
        }
#line 1448 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "bison.y" /* yacc.c:1646  */
    {
            string fallo = listaFunciones.checkAllDefined();
            if( fallo != " "){
                ostringstream o;
				o <<  "No se ha declarado la funcion: " << fallo << "\n";
				yyerror(o.str());
            }
    		generateCode("END\n");
		}
#line 1462 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 107 "bison.y" /* yacc.c:1646  */
    {
                listaFunciones.setDefined((yyvsp[-2].ristra));

                //tabla.imprimir();

                Symbol *item = createVar2(FUNCTION,(yyvsp[-2].ristra));
                if(item==NULL){yyerror("La función no se ha declarado");}
                if(item->etiquetaFuncion == -1){
                    tabla.addEtiquetaToFuncion((yyvsp[-2].ristra), etiqueta);
                    etiqueta++;
                }
				
                tabla.addScope();
            
                //PILA = R6Previo, L retorno | parametros... (ninguno en este caso)

                //ponemos el cabezal de la pila en la zona donde están las variables de entrada
			    generateCode("L %u:\t\tR7 = R6 - 8; //Cmienza la funcion\n", item->etiquetaFuncion);

			    tabla.relDir += 8;
                item->direction = tabla.relDir;

			}
#line 1490 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "bison.y" /* yacc.c:1646  */
    {

                //guardar R6 antiguo
		      	generateCode("\t\tR5 = P(R6); //Guardamos en R5 el R6 antiguo\n");

		      	//guardar direccion de retorno
			    generateCode("\t\tR2 = P(R6 - 8); //Guardamos en R2 la etiqueta de retorno\n");
			    //movemos la cima de la pila al estado deseado para retornar (vacía y con el resultado en la pila)
		      	generateCode("\t\tR7 = R6 + 8;\n");
                
                //recuperamos R6 del nivel superior
			    generateCode("\t\tR6 = R5; //Hacemos que R6 vuelva a su antiguo lugar\n");
			    generateCode("\t\tGT(R2); //Vamos a la etiqueta de retorno\n");

            }
#line 1510 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "bison.y" /* yacc.c:1646  */
    {
                listaFunciones.setDefined((yyvsp[-1].ristra));

                tabla.imprimir();

                Symbol *item = createVar2(FUNCTION,(yyvsp[-1].ristra));
                if(item==NULL){yyerror("La función no se ha declarado");}
                if(item->etiquetaFuncion == -1){
                    tabla.addEtiquetaToFuncion((yyvsp[-1].ristra), etiqueta);
                    etiqueta++;
                }
				
                tabla.addScope();
            
                //PILA = R6Previo, L retorno | parametros... (ninguno en este caso) | var retorno en caso de haberla

                //ponemos el cabezal de la pila en la zona donde están las variables de entrada
			    generateCode("L %u:\t\tR7 = R6 - 8; //Cmienza la funcion\n", item->etiquetaFuncion);
			    tabla.relDir += 8;
                item->direction = tabla.relDir;
                generateCode("\t\t//La direccion es %u\n", item->direction);

            }
#line 1538 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 169 "bison.y" /* yacc.c:1646  */
    {
                createParameter((yyvsp[-2].entero),(yyvsp[-1].ristra)); 
                varEnPilaSymbol((yyvsp[-1].ristra));
			}
#line 1547 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 173 "bison.y" /* yacc.c:1646  */
    {
                //guardar R6 antiguo
		      	generateCode("\t\tR5 = P(R6);\n");

		      	//guardar direccion de retorno
			    generateCode("\t\tR2 = P(R6 - 8);\n");
			    //movemos la cima de la pila al estado deseado para retornar (vacía y con el resultado en la pila)
		      	generateCode("\t\tR7 = R6 + 8;\n");
                
                Symbol *item2 = tabla.search_symbol((yyvsp[-3].ristra));
		  	    posicionMemoria(item2); //Deja la dir en R1
                generateCode("\t\tR7 = R7 - 8;\n");
		  		generateCode("\t\tRR1 = D(R1);\n");
				generateCode("\t\tD(R7) = RR1;\n");

                //recuperamos R6 del nivel superior
			    generateCode("\t\tR6 = R5;\n");
			    generateCode("\t\tGT(R2);\n");

            }
#line 1572 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 196 "bison.y" /* yacc.c:1646  */
    { 
                createParameter((yyvsp[-1].entero),(yyvsp[0].ristra)); //Crea el símbolo, dice que es parámetro, y lo relaciona con la última función creada. Falta que sea scope 0
                varEnPilaSymbol((yyvsp[0].ristra));

            }
#line 1582 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 201 "bison.y" /* yacc.c:1646  */
    { 
                createParameter((yyvsp[-3].entero),(yyvsp[-2].ristra)); //Crea el símbolo, dice que es parámetro, y lo relaciona con la última función creada. Falta que sea scope 0
                varEnPilaSymbol((yyvsp[-2].ristra));
            }
#line 1591 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 207 "bison.y" /* yacc.c:1646  */
    {tabla.quitScope();}
#line 1597 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 214 "bison.y" /* yacc.c:1646  */
    {
				Symbol *item = tabla.search_symbol((yyvsp[0].ristra));
			    if(item != NULL){
				    checkIsNotString(item->type); //Solo se imprimen digitos
                    posicionMemoria(item); 
                    generateCode("\t\tR2=R1; //POSICION PILA A IMPRIMIR\n");
                    generateCode("\t\tR1=0x11ff8 ; //COMIENZA IMPRIMIR\n");
                    generateCode("\t\tR3=-1; //IMRIMIR DIGITO\n");
                    generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                    generateCode("\t\tGT(putf_);\n");
                    generateCode("L %u:\n", etiqueta);
                    etiqueta++;				
			    } else {
				    yyerror("La variable no se ha declarado o no tiene tipo");
			    }
				
			}
#line 1619 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 232 "bison.y" /* yacc.c:1646  */
    {
                
                string a = (yyvsp[0].ristra);
                //Se quitan dos posiciones una el caracter final " y otra porque se empieza en 0
                string c = a.substr (1,a.size()-2);
                tamanoString = c.size();
                generateCode("\t\tR7 = R7 - %d;\n", tamanoString*4);
			    for(int i = 0; i<tamanoString;i++)
			    {
                    string d = c.substr (i,1);
				    generateCode("\t\tU(R7 + %d) = '%c';\n",i*4 , c[i]);
			    }
                generateCode("\t\tR1=0x11ffc; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=%d; //NUMERO CARRACTERES\n", tamanoString);
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
                
            }
#line 1645 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 254 "bison.y" /* yacc.c:1646  */
    {
                varEnPilaValue(STRING);
                string a = (yyvsp[0].ristra);
                string c = a.substr (1,1);
                tamanoString = c.size();
			    generateCode("\t\tU(R7) = '%c';\n", c[0]);
                generateCode("\t\tR1=0x11ffc; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=%d; //NUMERO CARRACTERES\n", tamanoString);
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
#line 1664 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 268 "bison.y" /* yacc.c:1646  */
    {}
#line 1670 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 269 "bison.y" /* yacc.c:1646  */
    { 
			    varEnPilaValue(INTEGER);
			    generateCode("\t\tI(R7) = %s; //Cojo el valor y lo pongo en la cima de la pila \n", (yyvsp[0].ristra));
                generateCode("\t\tR1=0x11ff4 ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=-2; //IMRIMIR DIGITO\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
    
             }
#line 1687 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 281 "bison.y" /* yacc.c:1646  */
    {
                generateCode("\t\tR1=0x11ffc ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2 = 10; //POSICION PILA A IMPRIMIR\n"); //Valor ASCII de salto de linea
                generateCode("\t\tR3 = -3; //IMPRIMIR SALTO LINEA\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
#line 1701 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 290 "bison.y" /* yacc.c:1646  */
    {
                varEnPilaValue(FLOAT);
			    generateCode("\t\tD(R7) = %s;\n", (yyvsp[0].ristra));
                generateCode("\t\tR1=0x11ff8 ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=-1; //NUMERO CARRACTERES\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
#line 1717 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 301 "bison.y" /* yacc.c:1646  */
    {
                varEnPilaValue(DOUBLE);
			    generateCode("\t\tD(R7) = %s;\n", (yyvsp[0].ristra));
                generateCode("\t\tR1=0x11ff8 ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=-1; //NUMERO CARRACTERES\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
#line 1733 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 317 "bison.y" /* yacc.c:1646  */
    { }
#line 1739 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 319 "bison.y" /* yacc.c:1646  */
    {
				Symbol *item = tabla.search_symbol((yyvsp[-1].ristra));
			    if(item != NULL){
				    checkIsNotString(item->type);
                    posicionMemoria(item);
                    //En R1 se encuentra la direccion de memoria de la variable
                    generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                    generateCode("\t\tGT(scanf_);\n");
                    generateCode("L %u:\n", etiqueta);
                    etiqueta++;
						
			    } else {
				    yyerror("La variable no se ha declarado o no tiene tipo");
			    }
				
			}
#line 1760 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 335 "bison.y" /* yacc.c:1646  */
    {
                tabla.addScope();
                generateCode("\t\tR7 = R7 - 8; //AQUI COMIENZA EL FOR\n");
				generateCode("\t\tP(R7) = R6;\n");
				generateCode("\t\tR6 = R7;\n");
            }
#line 1771 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 341 "bison.y" /* yacc.c:1646  */
    {
            	(yyval.uentero) = etiqueta; //dirección de repeticion
                generateCode("L %u:\t\n",etiqueta);	
			  	etiqueta++;
            }
#line 1781 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 346 "bison.y" /* yacc.c:1646  */
    {
                (yyval.uentero) = etiqueta;
                breaks.addNode(etiqueta);
                generateCode("\t\tRR1 = D(R7);\n");
		  	    generateCode("\t\tIF (RR1 == 0) GT(%u); //Comprobación FOR\n", etiqueta);
                etiqueta++;
            }
#line 1793 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 353 "bison.y" /* yacc.c:1646  */
    {
                if (strcmp((yyvsp[-5].ristra), (yyvsp[0].ristra))){
                    ostringstream o;
					o <<  "Los identificadores que controlan el for no coinciden: " << (yyvsp[-5].ristra) << "----" << (yyvsp[0].ristra);
					yyerror(o.str());
                }
            }
#line 1805 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 359 "bison.y" /* yacc.c:1646  */
    {
                  Symbol *item = tabla.search_symbol((yyvsp[-4].ristra));
                        if( item == NULL) {
	                         string mensaje = "La variable no ha sido declarada";
	                        yyerror(mensaje);
                        } else {
                            switch(item->type){
                                case INTEGER:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
                                    generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                case FLOAT:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
                                    generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                case DOUBLE:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
                                    generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                case STRING:
                                    posicionMemoria(item); 
                                    for (int i = 0; i < tamanoString; i++){
                                        generateCode("\t\tR2 = U(R7 + %i);\n",i);
                                        generateCode("\t\tU(R1 + %i) = R2;\n", i);
                                    }
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                default:
                                    break;
                            }

                        }
            }
#line 1853 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 403 "bison.y" /* yacc.c:1646  */
    {
                generateCode("\t\tGT(%u);\n", (yyvsp[-10].uentero));
		  	    generateCode("L %u:", (yyvsp[-8].uentero));
                generateCode("\t\tR7 = R6;\n");
				generateCode("\t\tR6 = P(R7);\n");
				generateCode("\t\tR7 = R7 + 8; //AQUI TERMINA EL FOR\n");
                breaks.deleteLast();
            }
#line 1866 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 411 "bison.y" /* yacc.c:1646  */
    {
                tabla.addScope();
                generateCode("\t\tR7 = R7 - 8; //AQUI COMIENZA EL WHILE\n");
				generateCode("\t\tP(R7) = R6;\n");
				generateCode("\t\tR6 = R7;\n");

			  	(yyval.uentero) = etiqueta; //dirección de repeticion
                generateCode("L %u:\t\n",etiqueta);	
			  	etiqueta++;
            }
#line 1881 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "bison.y" /* yacc.c:1646  */
    {
                (yyval.uentero) = etiqueta;
                breaks.addNode(etiqueta);
                generateCode("\t\tRR1 = D(R7);\n");
		  	    generateCode("\t\tIF (RR1 == 0) GT(%u); //Comprobación WHILE\n", etiqueta);
                etiqueta++;
            }
#line 1893 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 429 "bison.y" /* yacc.c:1646  */
    {

                generateCode("\t\tGT(%u);\n", (yyvsp[-5].uentero));
		  	    generateCode("L %u:", (yyvsp[-1].uentero));
                generateCode("\t\tR7 = R6;\n");
				generateCode("\t\tR6 = P(R7);\n");
				generateCode("\t\tR7 = R7 + 8; //AQUI TERMINA EL WHILE\n");
                breaks.deleteLast();
            }
#line 1907 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 438 "bison.y" /* yacc.c:1646  */
    {
                tabla.addScope();
                generateCode("\t\tR7 = R7 - 8; //AQUI COMIENZA EL IF\n");
				generateCode("\t\tP(R7) = R6;\n");
				generateCode("\t\tR6 = R7;\n");

			  	(yyval.uentero) = etiqueta; //dirección de salida
			  	etiqueta++;
			
			}
#line 1922 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 448 "bison.y" /* yacc.c:1646  */
    { 
			
			  	(yyval.uentero) = etiqueta; //dirección de else 
			  	
			  	generateCode("\t\tRR1 = D(R7);\n");
			  	generateCode("\t\tIF(RR1 < 1) GT(%u);\n",etiqueta);
		  		etiqueta++;
			}
#line 1935 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 456 "bison.y" /* yacc.c:1646  */
    {
				generateCode("\t\tGT(%u);\n",(yyvsp[-5].uentero));
		  		generateCode("L %u:\tR7 = R7 + 8;\n",(yyvsp[-1].uentero));			
			}
#line 1944 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 459 "bison.y" /* yacc.c:1646  */
    {tabla.addScope();}
#line 1950 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 459 "bison.y" /* yacc.c:1646  */
    {
				generateCode("L %u:", (yyvsp[-9].uentero));
				generateCode("\t\tR7 = R6;\n");
				generateCode("\t\tR6 = P(R7);\n");
				generateCode("\t\tR7 = R7 + 8; //AQUI TERMINA EL IF\n");
				
			}
#line 1962 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 467 "bison.y" /* yacc.c:1646  */
    {
                    listaFunciones.addNode((yyvsp[-3].ristra));
                    //No vamos a tener parámetros en esta versión

                    //PILA = R6previo | L de retorno | parametros .. (ninguno en este caso)

                    //Reservamos espacio para meter el R6 luego
			        generateCode("\t\tR7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> %d \n",etiqueta);  
			        generateCode("\t\tR5 = R7; //guardamos la direccion donde va a estar R6 \n"); 
                    

                    //Añadimos la L de retorno
                    generateCode("\t\tR7 = R7 - 8;\n");
			        dirRetorno = etiqueta;
                    etiqueta++;
			        generateCode("\t\tP(R7) = %u;\n", dirRetorno);
            
                    //Aquí se trabajaria con las var de param si hubiese...

                    Symbol *item = createVar2(FUNCTION,(yyvsp[-3].ristra));
                    if(item==NULL){yyerror("La función no se ha declarado");}
                    if(item->etiquetaFuncion == -1){
                        tabla.addEtiquetaToFuncion((yyvsp[-3].ristra), etiqueta);
                        cout << "se acaba de crear " << item->name << " con la etiqueta " << item->etiquetaFuncion << " \n";
                        etiqueta++;
                    }
				
                    //Actualizamos R6
                    generateCode("\t\tP(R5) = R6;\n");
			        generateCode("\t\tR6 = R5;\n");


                    //ponemos el salto L a donde tiene que retornar y llamamos a la funcion
			        generateCode("\t\tGT(%u);\n", item->etiquetaFuncion); //Busca la funcion a la que llamas y ve a ella
			        generateCode("L %u://Fin codigo LLAMADA \n ", dirRetorno); //L a la que hay que volver desde la funcion
                }
#line 2003 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 504 "bison.y" /* yacc.c:1646  */
    {
                    listaFunciones.addNode((yyvsp[-1].ristra));
                    //No vamos a tener parámetros en esta versión

                    //PILA = R6previo | L de retorno | parametros .. (ninguno en este caso)

                    //Reservamos espacio para meter el R6 luego
			        generateCode("\t\tR7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> %d \n",etiqueta);  
			        generateCode("\t\tR5 = R7; //Metemos en R5 la dir donde va a estar R6 \n"); 
                    

                    //Añadimos la L de retorno
                    generateCode("\t\tR7 = R7 - 8; //Dejamos un hueco\n");
			        dirRetorno = etiqueta;
                    etiqueta++;
			        generateCode("\t\tP(R7) = %u; //Metemos en ese hueco la etiqueta a la que ir cuando acabe la llamada\n", dirRetorno);
                }
#line 2025 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 522 "bison.y" /* yacc.c:1646  */
    {
                    Symbol *item = createVar2(FUNCTION,(yyvsp[-7].ristra));
                    if(item==NULL){yyerror("La función no se ha declarado");}
                    if(item->etiquetaFuncion == -1){
                        tabla.addEtiquetaToFuncion((yyvsp[-7].ristra), etiqueta);
                        cout << "se acaba de crear " << item->name << " con la etiqueta " << item->etiquetaFuncion << " \n";
                        etiqueta++;
                    }
				
                    //Actualizamos R6
                    generateCode("\t\tP(R5) = R6; //Guardo el R6 como puntero en donde apunta R5\n");
			        generateCode("\t\tR6 = R5; //Pongo ahora R6 en donde apunta R5\n");


                    //ponemos el salto L a donde tiene que retornar y llamamos a la funcion
			        generateCode("\t\tGT(%u);\n", item->etiquetaFuncion); //Busca la funcion a la que llamas y ve a ella
			        generateCode("L %u://Fin codigo LLAMADA \n ", dirRetorno); //L a la que hay que volver desde la funcion


                    //Almacenamos lo que se queda en la cima de la pila en la variable
                    Symbol *item2 = tabla.search_symbol((yyvsp[-1].ristra));
				    if( item2 != NULL) {
                        posicionMemoria(item2);
                        generateCode("\t\tRR1 = D(R7); //Cojo lo de la cima, que deberia ser el resultado de la funcion\n");
					    generateCode("\t\tD(R1) = RR1; //Voy a la variable y meto el resultado\n");
                        //generateCode("\t\tR7 = R6 - 8; //Esto es dudoso...\n");
                        generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir);
                    } else {
					    ostringstream o;
					    o <<  "La variable " << (yyvsp[-1].ristra) << " no ha sido declarada";
					    yyerror(o.str());

				    }

                }
#line 2065 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 558 "bison.y" /* yacc.c:1646  */
    { generateCode("\t\tGT(-2);\n"); }
#line 2071 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 559 "bison.y" /* yacc.c:1646  */
    {
                if(breaks.last != NULL){
                    generateCode("\t\tGT(%u);\n",breaks.last->value);
                    breaks.deleteLast();
                }                    
            }
#line 2082 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 569 "bison.y" /* yacc.c:1646  */
    {
							Symbol *item = tabla.search_symbol((yyvsp[-2].ristra));
							if( item == NULL) {
								ostringstream o;
								o <<  "La variable" << (yyvsp[-2].ristra) << " no ha sido declarada";
								yyerror(o.str());
					
							} else {
	                            varEnPilaValue(item->type);
                                posicionMemoria(item); 
				                generateCode("\t\tRR3 = D(R1);\n");
				                generateCode("\t\tD(R7) = RR3;\n");
							}

						}
#line 2102 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 585 "bison.y" /* yacc.c:1646  */
    {
							Symbol *item = tabla.search_symbol((yyvsp[0].ristra));
							if( item == NULL) {
								ostringstream o;
								o <<  "La variable" << (yyvsp[0].ristra) << " no ha sido declarada";
								yyerror(o.str());
					
							} else {
			  					varEnPilaValue(item->type);
                                posicionMemoria(item); 
				                generateCode("\t\tRR3 = D(R1);\n");
				                generateCode("\t\tD(R7) = RR3;\n");
							}
						}
#line 2121 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 602 "bison.y" /* yacc.c:1646  */
    {
                 createVar((yyvsp[-2].entero),(yyvsp[-1].ristra)); 
                 varEnPilaSymbol((yyvsp[-1].ristra));
            }
#line 2130 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 607 "bison.y" /* yacc.c:1646  */
    {(yyval.entero) = INTEGER;}
#line 2136 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 608 "bison.y" /* yacc.c:1646  */
    {(yyval.entero) = FLOAT;}
#line 2142 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 609 "bison.y" /* yacc.c:1646  */
    {(yyval.entero) = DOUBLE;}
#line 2148 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 612 "bison.y" /* yacc.c:1646  */
    {
			
				createVar((yyvsp[-1].entero),(yyvsp[0].ristra));

                //crear variable en la pila
				varEnPilaSymbol((yyvsp[0].ristra));

                }
#line 2161 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 619 "bison.y" /* yacc.c:1646  */
    {
                        
                        //Poner la direccion en R1
                        Symbol *item = tabla.search_symbol((yyvsp[-4].ristra));
                        if( item == NULL) {
	                         string mensaje = "La variable no ha sido declarada";
	                        yyerror(mensaje);

                        } else {
                            checkEqualType((yyvsp[-5].entero), (yyvsp[-1].real));
                		    switch((yyvsp[-5].entero)){
                                case INTEGER:
                	                posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case FLOAT:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case DOUBLE:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;
	
                                default:
	                                break;

                            }

						
						    (yyval.ristra) = (yyvsp[-4].ristra);
                        }

				}
#line 2208 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 661 "bison.y" /* yacc.c:1646  */
    {

				Symbol *item = tabla.search_symbol((yyvsp[-3].ristra));
				if( item != NULL) {
					checkEqualType(item->type, (yyvsp[-1].real));
                		    switch(item->type){
                                case INTEGER:
                	                posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case FLOAT:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case DOUBLE:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                default:
	                                break;

                            }

						
						    (yyval.ristra) = (yyvsp[-3].ristra);
					
				} else {
					ostringstream o;
					o <<  "La variable " << (yyvsp[-3].ristra) << " no ha sido declarada";
					yyerror(o.str());
	
				}
			}
#line 2255 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 706 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos RESTA\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 - RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final RESTA\n");
        (yyval.real) = (yyvsp[-2].real);
    }
#line 2269 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 715 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos MULTIPLICACION\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 * RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final MULTIPLICACION\n");
        (yyval.real) = (yyvsp[-2].real);
    }
#line 2283 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 724 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos SUMA\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 + RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final SUMA\n");
        (yyval.real) = (yyvsp[-2].real);
    }
#line 2297 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 733 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos DIVISION\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 / RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final DIVISION\n");
        (yyval.real) = (yyvsp[-2].real);
    }
#line 2311 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 742 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos DISTINTO\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 != RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final DISTINTO\n");
        (yyval.real) = LOGICO;
    }
#line 2330 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 756 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos IGUALDAD\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 == RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final IGUALDAD\n");
        (yyval.real) = LOGICO;
    }
#line 2349 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 770 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos MAYOR\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 > RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MAYOR\n");
        (yyval.real) = LOGICO;
    }
#line 2368 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 784 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos MENOR\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 < RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MENOR\n");
        (yyval.real) = (yyvsp[-2].real);
    }
#line 2387 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 798 "bison.y" /* yacc.c:1646  */
    {
        checkAritmetic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos MENORIGUAL\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 <= RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MENORIGUAL\n");
        (yyval.real) = LOGICO;
    }
#line 2406 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 812 "bison.y" /* yacc.c:1646  */
    {
        generateCode("\t\tRR2 = D(R7); //Comenzamos MAYORIGUAL\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 >= RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MAYORIGUAL\n");
        (yyval.real) = LOGICO;
    }
#line 2424 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 825 "bison.y" /* yacc.c:1646  */
    {
        checkLogic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7); //Comenzamos OR\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 >= 1) GT(%u);\n", etiqueta);
		generateCode("\t\tIF (RR2 >= 1) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", (etiqueta - 1));
		generateCode ("\t\tD(R7) = RR1; //Final OR\n");
        (yyval.real) = LOGICO;
    }
#line 2444 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 840 "bison.y" /* yacc.c:1646  */
    {
        checkLogic((yyvsp[-2].real),(yyvsp[0].real));
        generateCode("\t\tRR2 = D(R7);\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 < 1) GT(%u);\n", etiqueta); //Si está false, voy a la etiq
		generateCode("\t\tIF (RR2 < 1) GT(%u);\n", etiqueta);
		generateCode("\t\tRR1 = 1;\n");
        etiqueta++;
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 0;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1;\n");
        (yyval.real) = LOGICO;
    }
#line 2464 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 855 "bison.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].real) != LOGICO){
            ostringstream o;
		    o <<  "El NOT solo se puede emplear con valores logicos" << "\n";
		    yyerror(o.str());
        }
        generateCode("\t\tRR1 = D(R7);\n");
		generateCode("\t\tIF (RR1 < 1) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tD(R7) = RR1;\n", (etiqueta - 1));
        (yyval.real) = LOGICO;
    }
#line 2485 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 871 "bison.y" /* yacc.c:1646  */
    { (yyval.real) = (yyvsp[-1].real); }
#line 2491 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 872 "bison.y" /* yacc.c:1646  */
    { (yyval.real) = (yyvsp[0].real); }
#line 2497 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 875 "bison.y" /* yacc.c:1646  */
    { 
			varEnPilaValue(INTEGER);
			generateCode("\t\tD(R7) = %s; //Cojo el valor y lo pongo en la cima de la pila \n", (yyvsp[0].ristra));
            (yyval.real) = INTEGER;
         }
#line 2507 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 880 "bison.y" /* yacc.c:1646  */
    {
            varEnPilaValue(FLOAT);
			generateCode("\t\tD(R7) = %s;\n", (yyvsp[0].ristra));
            (yyval.real) = FLOAT;
        }
#line 2517 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 885 "bison.y" /* yacc.c:1646  */
    {
            varEnPilaValue(DOUBLE);
            cout << (yyvsp[0].ristra) << "\n";
			generateCode("\t\tD(R7) = %s;\n", (yyvsp[0].ristra));
            (yyval.real) = DOUBLE;
        }
#line 2528 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 891 "bison.y" /* yacc.c:1646  */
    {
			//Buscar simbolo y devolver tipo
			Symbol *item = tabla.search_symbol((yyvsp[0].ristra));
			if(item != NULL){
				//checkIsNotString(item->type);
                varEnPilaValue(item->type);
                cout << "SCOPE tabla: " << tabla.actualScope << "SCOPE item: " << item->scope << "\n"; 
                posicionMemoria(item); 
				generateCode("\t\tRR3 = D(R1);\n");
				generateCode("\t\tD(R7) = RR3;\n");
						
			} else {
				yyerror("La variable no se ha declarado o no tiene tipo");
			}
            (yyval.real) = item->type;
		}
#line 2549 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 2553 "bison.tab.c" /* yacc.c:1646  */
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
#line 909 "bison.y" /* yacc.c:1906  */


void checkEqualType(int tipo1, int tipo2){
    if (tipo1 != tipo2){
        ostringstream o;
		o <<  "Asignacion con tipos diferentes: " <<"\n";
		yyerror(o.str());
    }
}

void checkAritmetic(int tipo1, int tipo2){
    //Primero miro si los tipos son distintos
    if (tipo1 != tipo2){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con tipos diferentes" << "\n";
		yyerror(o.str());
    }

    //Compruebas que los tipos que te llegan no son strings para sumar (En verdad bastaria con comprobar uno porque al llegar aqui sabes que son iguales)
    if (tipo1 == STRING || tipo2 == STRING){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con STRINGS" << "\n";
		yyerror(o.str());
    }

    //Que no sean logicos que tu los logicos no los sumas ni na
    if (tipo1 == LOGICO || tipo2 == LOGICO){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con tipos logicos" << "\n";
		yyerror(o.str());
    }
}

void checkLogic(int tipo1, int tipo2){
    if (tipo1 != tipo2){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con tipos diferentes" << "\n";
		yyerror(o.str());
    }
    if (tipo1 == STRING || tipo2 == STRING){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con STRINGS" << "\n";
		yyerror(o.str());
    }

    //Este chequeo se usa solo un AND o OR (a ambos lados tiene que tener un logico, no puede haber una op aritm en plan 2+2 AND 3 > 1)
    if (tipo1 != LOGICO || tipo2 != LOGICO){
        ostringstream o;
		o <<  "Comparacion logica erronea" << "\n";
		yyerror(o.str());
    }
}

void checkIsNotString(int tipo) {
	if (tipo == STRING) {
		yyerror("El tipo es string, no puede asignar un numero.");
	}
}

void createVar(int type, string name) {
	Symbol *item = tabla.search_symbol(name);
	if( item == NULL) {
		//Creo el simbolo
		tabla.addSymbol(name,type);

	} else {
		string mensaje = "La variable " + name + " ya ha sido declarada";
		yyerror(mensaje);

	}
}

Symbol* createVar2(int type, string name) {
	Symbol *item = tabla.search_symbol(name);
	if( item == NULL) {
		//Creo el simbolo
		tabla.addSymbol(name,type);
        Symbol *item2 = tabla.search_symbol(name);
        return item2;
	} else {
		return item;

	}
}

void createParameter(int type, string name) {
	Symbol *item = tabla.search_symbol(name);
	if( item == NULL) {
		tabla.addParameter(name,type);

	} else {
		string mensaje = "El parámetro " + name + " ya ha sido declarado";
		yyerror(mensaje);

	}
}

void varEnPilaSymbol(string name){
        int alinearPila;
        Symbol *item = tabla.search_symbol(name);
	
	    if( item == NULL) {
		    yyerror("Variable no declarada");
	    } else {
		    switch(item->type){
			    case INTEGER:
				    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += 8; 
				
				    //Modifico el puntero a la cima de la pila
				    generateCode("\t\tR7 = R7 - 8; //Asigno espacio para la variable\n"); 
				
				    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
                    generateCode("\t\t//La direccion es %u\n", item->direction);
				    break;

                 case FLOAT:
				    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += 8; 
				
				    //Modifico el puntero a la cima de la pila
				    generateCode("\t\tR7 = R7 - 8;\n"); 
				
				    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
				    break;

                case DOUBLE:
				    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += 8; 
				
				    //Modifico el puntero a la cima de la pila
				    generateCode("\t\tR7 = R7 - 8;\n"); 
				
				    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
				    break;

                case STRING:
                    
                    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += alinearPila; 
		
		            //Modifico el puntero a la cima de la pila
		            if( tamanoString % 4 != 0){
                        alinearPila = tamanoString + (4 - ( tamanoString % 4 ));
                        generateCode("\t\tR7 = R7 - %d;\n", alinearPila); 
                    }else{
                        generateCode("\t\tR7 = R7 - %d;\n", tamanoString);
                    }

                    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
		            break;
				
			    default:
				    break;
		
		    }
		
	    }	
}

void varEnPilaValue(int tipo){
    int alinearPila;
    switch(tipo){
	        case INTEGER:
		
		        //Modifico el puntero a la cima de la pila
		        generateCode("\t\tR7 = R7 - 8; //Creo espacio para meter valor\n"); 
		        break;

            case FLOAT:
		
		        //Modifico el puntero a la cima de la pila
		        generateCode("\t\tR7 = R7 - 8;\n"); 
		        break;

            case DOUBLE:
		
		        //Modifico el puntero a la cima de la pila
		        generateCode("\t\tR7 = R7 - 8;\n"); 
		        break;

            case STRING:
		        generateCode("\t\tR7 = R7 - 4;\n");
		        
		        break;
		
	        default:
		        break;
	
	}
}

void generaCabecera() {
	//Generar el comienzo del fichero Q
	generateCode("#include \"Q.h\" \n");
    generateCode("BEGIN\n");
	generateCode("STAT(0)\n");
    generateCode("\t\tSTR(0x11ffc, \"%%c\"); //formato caracteres\n");
    generateCode("\t\tSTR(0x11ff8, \"%%f\" ); //formato decimales\n");
    generateCode("\t\tSTR(0x11ff4,\"%%d\"); //formato entero\n");
    generateCode("CODE(0)\n");
	generateCode("L %d:\n", 0);
    generateCode("\t\tR6= R7;\n");
}

int main(int argc, char** argv) {

	file = fopen("./ejecutableQ.q.c","w");
	if(file == NULL) 
		yyerror("Fichero ejecutableQ no abierto");
	
	if (argc>1) 
		yyin=fopen(argv[1],"r");
	yyparse();

	fclose(file);
}

void yyerror(string mens) {
	//printf("Error en linea %i: %s ",numlin,mens);
	cout << "Error en linea " << numlin << ": " << mens << "\n";
	exit(0);
}

void posicionMemoria(Symbol * item)
{
	//Numero de saltos de R6 que hay que dar
	int numSaltos = tabla.actualScope - item->scope;

	generateCode("\t\tR1 = R6;\n");
	for (int i = 0; i < numSaltos; i++)
	{
		generateCode("\t\tR1 = P(R1);\n");
	}
	//aumentamos la dirección con la referencia a la dirección relativa
	generateCode("\t\tR1 = R1 - %u;\n", item->direction); 
}
