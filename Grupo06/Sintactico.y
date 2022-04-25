%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "TablaSimbolos.h"

extern FILE* yyin;
FILE* archTS;

%}

%token WHILE                 
%token IF 
%token ELSE                  
%token WRITE
%token READ                  
%token AND                   
%token OR
%token NOT
%token DECVAR
%token ENDDEC
%token INLIST
%token TAKE               


%token FLOAT
%token STRING
%token INT

%token OP_MAS
%token OP_REST
%token OP_MULT
%token OP_DIV
%token OP_ASIG
%token COMP_DIST
%token COMP_MAY
%token COMP_MEN

%token COMP_IGUAL
%token COMP_MAYOI
%token COMP_MENOI

%token COND_AND
%token COND_OR
%token COND_NOT

%token P_A
%token P_C
%token LL_A
%token LL_C
%token C_A
%token C_C

%token COMA
%token PYC
%token DP

%token ID
%token CTE_INT
%token CTE_FLOAT
%token CTE_STRING

%token COMENT
%token whitespace
%token linefeed


%%

programa:   sentencia                                                           {printf(" FIN\n");}
;

sentencia:  declaracion sentencia                                               {printf("   declaracion sentencia es SENTENCIA\n");}
            |   estructura sentencia                                            {printf("   sentencia estructura es SENTENCIA\n");}
            |   estructura                                                      {printf("   estructura es SENTENCIA\n");}
;

declaracion: DECVAR listaDeclaraciones ENDDEC                                   {printf("   DECVAR ListadoDeDeclaraciones ENDDEC es DECLARACION\n");}
;

listaDeclaraciones: listaID DP tipoDato listaDeclaraciones                      {printf("   ListaDeID : TipoDeDato ListadoDeDeclaraciones es LISTADECLARACIONES\n");}
            |   listaID DP tipoDato                                             {printf("   ListaDeID : TipoDeDato es LISTADECLARACIONES\n");}
;

listaID:    listaID COMA ID                                                     {printf("   listaID , ID es LISTAID\n");}
            |   ID                                                              {printf("   ID es LISTAID\n");}
;

tipoDato:   STRING                                                              {printf("   STRING es TIPODATO\n");}
            |   INT                                                             {printf("   INT es TIPODATO\n");}
            |   FLOAT                                                           {printf("   FLOAT es TIPODATO\n");}
;

estructura: while                                                               {printf("   WHILE es ESTRUCTURA\n");}
            |   if                                                              {printf("   IF es ESTRUCTURA\n");}
            |   asign                                                           {printf("   ASIGN es ESTRUCTURA\n");}
            |   write                                                           {printf("   WRITE es ESTRUCTURA\n");}
            |   take                                                            {printf("   TAKE es ESTRUCTURA\n");}
            |   read                                                            {printf("   READ es ESTRUCTURA\n");}
            |   inlist                                                          {printf("   INLIST es ESTRUCTURA\n");}
;

while:      WHILE condicionFinal LL_A sentencia LL_C                            {printf("   WHILE condicionFinal { sentencia } es WHILE\n");}
;

if:         IF condicionFinal LL_A sentencia LL_C                               {printf("   IF condicionFinal { sentencia } es IF\n");}
            | IF condicionFinal LL_A sentencia LL_C ELSE LL_A sentencia LL_C    {printf("   IF condicionFinal { sentencia } es ELSE { sentencia }\n");}
;

condicionFinal: condicionFinal COND_AND condicion                               {printf("   condicionFinal && condicion es CONDICIONFINAL\n");}
            | P_A condicionFinal COND_AND condicion P_C                         {printf("   ( condicionFinal && condicion ) es CONDICIONFINAL\n");}
            | P_A condicionFinal COND_AND  condicionFinal P_C                   {printf("   ( condicionFinal && condicionFinal ) es CONDICIONFINAL\n");}
            | condicionFinal COND_OR condicion                                  {printf("   condicionFinal || condicion es CONDICIONFINAL\n");}
            | P_A condicionFinal COND_OR condicion P_C                          {printf("   ( condicionFinal || condicion ) es CONDICIONFINAL\n");}
            | P_A condicionFinal COND_OR  condicionFinal P_C                    {printf("   ( condicionFinal || condicionFinal ) es CONDICIONFINAL\n");}
            | COND_NOT condicionFinal                                           {printf("   ! condicionFinal es CONDICIONFINAL\n");}
            | P_A COND_NOT condicion P_C                                        {printf("   ( ! condicionFinal ) es CONDICIONFINAL\n");}
            | P_A condicion P_C                                                 {printf("   ( condicion ) es CONDICIONFINAL\n");}
            | condicion                                                         {printf("   condicion es CONDICIONFINAL\n");}
;

condicion:  factor COMP_MEN factor                                              {printf("   factor < factor es CONDICION\n");}
            |   factor COMP_MAY factor                                          {printf("   factor > factor es CONDICION\n");}
            |   factor COMP_MENOI factor                                        {printf("   factor <= factor es CONDICION\n");}
            |   factor COMP_MAYOI factor                                        {printf("   factor >= factor es CONDICION\n");}
            |   factor COMP_IGUAL factor                                        {printf("   factor == factor es CONDICION\n");}
            |   factor COMP_DIST factor                                         {printf("   factor != factor es CONDICION\n");}
            |   COND_NOT factor                                                 {printf("   ! factor es CONDICION\n");}
;

asign:      ID OP_ASIG expresion                                                {printf("   ID = expresion es ASIGN\n");}
;

inlist:     INLIST P_A ID PYC C_A listaExpresiones C_C P_C                      {printf("   INLISTA ( ID ; [ ListaDeExpresiones ] ) es INLIST\n");}
;

take:       TAKE P_A signo PYC CTE_INT PYC C_A valores C_C P_C                  {printf("   TAKE ( signo ; CTE_INT ; [ valores ] ) es TAKE\n");}
;

signo:      OP_MAS                                                              {printf("   + es SIGNO\n");}
            | OP_REST                                                           {printf("   - es SIGNO\n");}
            | OP_MULT                                                           {printf("   * es SIGNO\n");}
            | OP_DIV                                                            {printf("   / es SIGNO\n");}
;

valores:    valor PYC valores                                                   {printf("   valor ; valores es VALORES\n");}
            | valor                                                             {printf("   valor es VALORES\n");}
;

valor:      CTE_INT                                                             {printf("   CTE_INT es VALOR\n");}
            | OP_REST CTE_INT                                                   {printf("   - CTE_INT es VALOR\n");}
            | CTE_FLOAT                                                         {printf("   CTE_FLOAT es VALOR\n");}
            | OP_REST CTE_FLOAT                                                 {printf("   - CTE_FLOAT es VALOR\n");}
            | ID                                                                {printf("   ID es VALOR\n");}
;

listaExpresiones: expresion PYC listaExpresiones                                {printf("   expresion ; listaDeExpresiones es LISTAEXPRESIONES\n");}
            | expresion                                                         {printf("   expresion es LISTAEXPRESIONES\n");}
;

expresion:  expresion sumayresta termino                                        {printf("   expresion sumayresta termino es EXPRESION\n");}
            | termino                                                           {printf("   termino es EXPRESION\n");}
            | asign                                                             {printf("   asign es EXPRESION\n");}
;

termino:    termino multydiv operando                                           {printf("   termino multydiv operando es TERMINO\n");}
            | operando                                                          {printf("   operando es TERMINO\n");}
;

operando:   CTE_INT                                                             {printf("   CTE_INT es OPERANDO\n");}
            | OP_REST CTE_INT                                                   {printf("   - CTE_INT es OPERANDO\n");}
            | CTE_FLOAT                                                         {printf("   CTE_FLOAT es OPERANDO\n");}
            | OP_REST CTE_FLOAT                                                 {printf("   - CTE_FLOAT es OPERANDO\n");}
            | CTE_STRING                                                        {printf("   CTE_STRING es OPERANDO\n");}
            | ID                                                                {printf("   ID es OPERANDO\n");}
            | P_A expresion P_C                                                 {printf("   ( expresion ) es OPERANDO\n");}
;

sumayresta: OP_MAS                                                              {printf("   + es SUMAYRESTA\n");}
            | OP_REST                                                           {printf("   - es SUMAYRESTA\n");}
;

multydiv:   OP_DIV                                                              {printf("   / es MULTYDIV\n");}                                     
            | OP_MULT                                                           {printf("   * es MULTYDIV\n");}
;

write:      WRITE factor                                                        {printf("   WRITE factor es WRITE\n");}
;

read:       READ ID                                                             {printf("   READ ID es READ\n");}
;

factor:     ID                                                                  {printf("   ID es FACTOR\n");}
            | CTE_INT                                                           {printf("   CTE_INT es FACTOR\n");}
            | OP_REST CTE_INT                                                   {printf("   - CTE_INT es FACTOR\n");}
            | CTE_STRING                                                        {printf("   CTE_STRING es FACTOR\n");}
            | CTE_FLOAT                                                         {printf("   CTE_FLOAT es FACTOR\n");}
            | OP_REST CTE_FLOAT                                                 {printf("   - CTE_FLOAT es FACTOR\n");}
;  

%%


int main(int argc, char* argv[])
{
    archTS = fopen("ts.txt","w");

    if((yyin = fopen(argv[1],"rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo %s\n", argv[1]);
    }

    yyparse();

    generarArchivo();
    printf("\nCOMPILACION EXITOSA!\n");
    fclose(yyin);
    
    return 0;
}
