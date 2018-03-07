/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 47 "bison.y" /* yacc.c:1909  */
 float real; double doble; int entero; char *ristra; char caracter; unsigned int uentero;

#line 104 "bison.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
