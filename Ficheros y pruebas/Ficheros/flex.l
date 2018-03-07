%{
#include "bison.tab.h"
#include "SymbolTable.h"
#include "breaklist.h"
#include "FunctionsList.h"
#include <string>
#include <stdio.h>
int numlin=1;
extern void yyerror(std::string mens);
%}

%option noyywrap
%option yylineno


letra [a-zA-Z]
digito [0-9]
letdig {letra}|{digito}

%%
cat 									{yylval.ristra  =   strdup(yytext); return CAT;}
{digito}+ 								{yylval.ristra  =   strdup(yytext); return CATVALUE;}
kitty									{yylval.ristra  =   strdup(yytext); return KITTY;} 
{digito}+"."{digito}{1,8}				{yylval.ristra  =   strdup(yytext); return KITTYVALUE;} 
kitten									{yylval.ristra  =   strdup(yytext); return KITTEN;}
{digito}+"."{digito}{1,16}				{yylval.ristra  =   strdup(yytext); return KITTENVALUE;}
\"[^\"]\"								{yylval.ristra  =   strdup(yytext); return CKITTYVALUE;}
\"[^\"]*\"								{yylval.ristra  =   strdup(yytext); return CKITTENVALUE;}
","										{return SEPARADOR;}
"main"                                  {yylval.ristra  =   strdup(yytext); return MAIN;}
"."										{return CONCATENA;}
"+"                       				{return SUMA;}
"-"                        				{return RESTA;}
"/"                        				{return DIVISION;}
"*"                        				{return MULTIPLICACION;}
"="										{return IGUAL;}
"!"										{return DISTINTO;}
">"										{return MAYORQUE;}
"<"										{return MENORQUE;}
">="									{return MAYORIGUAL;}
"<="									{return MENORIGUAL;}
"|"                       				{return OR;}
"&"                       				{return AND;}
"¬"                        				{return NOT;}
"kin"									{return LEETECLADO; }
"kout"									{return ESCRIBEPANTALLA;}
"~" 									{return ASIGNA;}
";"                     				{return PUNTOYCOMA;}
":"										{return DOSPUNTOS;}
"("                        				{return ABREPARENTESIS;}
")"                        				{return CIERRAPARENTESIS;}
"{"                        				{return ABRELLAVE;}
"}"                        				{return CIERRALLAVE;}
"claw"									{return IF;}
"scratch" 								{return ELSE;}
"purr" 									{return BREAK;}
"meow" 									{return WHILE;}
"fishy"									{return FOR;}
"call"									{return LLAMADA;}
"define"								{return FUNCION;}
"halt" 									{return HALT;}
"in"                                    {return IN;}
"/CR"                                   {return SALTOLINEA;}
"@".*
[ \t]
{letra}{letdig}* 						{yylval.ristra = strdup(yytext); return IDENTIF;}
\n										{numlin++;}
. 										{yyerror("error lexico");}
<<EOF>> 								{return 0;}
%%

