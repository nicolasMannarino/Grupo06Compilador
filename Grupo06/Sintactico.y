0%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "TablaSimbolos.h"
#include "Arbol.h"

extern FILE* yyin;

FILE* archTS;
FILE *pArbol;

t_NodoArbol* Ptr;
t_NodoArbol* Sptr;
t_NodoArbol* Aptr;
t_NodoArbol* Eptr;
t_NodoArbol* Tptr;
t_NodoArbol* Fptr;
t_NodoArbol* Lptr;
t_NodoArbol* Wptr;
t_NodoArbol* Rptr;
t_NodoArbol* ILptr;
t_NodoArbol* ASptr;
t_NodoArbol* IFptr;
t_NodoArbol* WHptr;
t_NodoArbol* ESTptr;
t_NodoArbol* SENptr;


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



programaFinal:   programa                                                       {mostrarArbolDeIzqADer(&Ptr,pArbol);}
;

programa:   sentencia                                                           {Ptr = Sptr; printf(" FIN\n");}
;

sentencia:  declaracion sentencia                                               {SENptr = crearNodo("S",Dptr,SENptr);}
            |   estructura sentencia                                            {SENptr = crearNodo("S",ESTptr,SENptr);}
            |   estructura                                                      {SENptr = ESTptr;}
;

declaracion: DECVAR listaDeclaraciones ENDDEC                                   {DECprt = LDECprt;}
;

listaDeclaraciones: listaID DP tipoDato listaDeclaraciones                      {printf("   ListaDeID : TipoDeDato ListadoDeDeclaraciones es LISTADECLARACIONES\n");}
            |   listaID DP tipoDato                                             {LDECprt = crearNodo(":",LIDprt,TPprt));
;

listaID:    listaID COMA ID                                                     {LIDprt = crearNodo(",",LIDprt,crearHoja($3)));}
            |   ID                                                              {LIDprt = crearHoja($1);}
;

tipoDato:   STRING                                                              {TPprt = crearHoja($1);}
            |   INT                                                             {TPprt = crearHoja($1);}
            |   FLOAT                                                           {TPprt = crearHoja($1);}
;

estructura: while                                                               {ESTptr = WHptr;}
            |   if                                                              {ESTptr = IFptr;}
            |   asign                                                           {ESTptr = ASptr;}
            |   write                                                           {ESTptr = Wptr;}
            |   take                                                            {ESTptr = Tptr;}
            |   read                                                            {ESTptr = Rptr;}
            |   inlist                                                          {ESTptr = ILptr;}
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
            |   inlist                                                          {printf("   inlist es CONDICIONFINAL\n");}
;

asign:      ID OP_ASIG expresion                                                {printf("   ID = expresion es ASIGN\n");}
            | ID OP_ASIG CTE_STRING                                             {printf("   ID = CTE_STRING es ASIGN\n");}
;

inlist:     INLIST P_A ID PYC C_A listaExpresiones C_C P_C                      {printf("   INLISTA ( ID ; [ ListaDeExpresiones ] ) es INLIST\n");}
;

take:       TAKE P_A signo PYC CTE_INT PYC C_A valores C_C P_C                  {printf("   TAKE ( signo ; CTE_INT ; [ valores ] ) es TAKE\n");}
;

signo:      OP_MAS                                                              {SGptr = crearHoja($1);}
            | OP_REST                                                           {SGptr = crearHoja($1);}
            | OP_MULT                                                           {SGptr = crearHoja($1);}
            | OP_DIV                                                            {SGptr = crearHoja($1);}
;

valores:    valor PYC valores                                                   {VSprt = crearNodo(";",VSprt,Vptr);}
            | valor                                                             {VSprt = Vptr;}
;

valor:      CTE_INT                                                             {Vptr = crearHoja($1);}
            | OP_REST CTE_INT                                                   {Vptr = crearHoja($2);}
            | CTE_FLOAT                                                         {Vptr = crearHoja($1);}
            | OP_REST CTE_FLOAT                                                 {Vptr = crearHoja($2);}
            | ID                                                                {Vptr = crearHoja($1);}
;

listaExpresiones: expresion PYC listaExpresiones                                {Lptr = crearNodo(";",Lptr,Eptr);}
            | expresion                                                         {Lptr = Eptr;}
;

expresion:  expresion OP_MAS termino                                            {Eptr = crearNodo("+",Eptr,Tptr);}
            | expresion OP_REST termino                                         {Eptr = crearNodo("-",Eptr,Tptr);}
            | termino                                                           {Eptr = Tptr;}
;

termino:    termino OP_DIV operando                                             {Tptr = crearNodo("/",Tptr,Optr);}
            |termino OP_MULT operando                                           {Tptr = crearNodo("*",Tptr,Optr);}
            | operando                                                          {Tptr = Optr;}
;

operando:   CTE_INT                                                             {Optr = crearHoja($1);}
            | OP_REST CTE_INT                                                   {Optr = crearHoja($2);}
            | CTE_FLOAT                                                         {Optr = crearHoja($1);}
            | OP_REST CTE_FLOAT                                                 {Optr = crearHoja($2);}
            | ID                                                                {Optr = crearHoja($1);}
            | P_A expresion P_C                                                 {Optr = Eptr;}
;

write:      WRITE factor                                                        {Wptr = crearNodo("W",crearHoja($1),Fprt);}
;

read:       READ ID                                                             {Rptr = crearNodo("R",crearHoja($1),crearHoja($2));}
;

factor:     ID                                                                  {Fptr = crearHoja($1);}
            | CTE_INT                                                           {Fptr = crearHoja($1);}
            | OP_REST CTE_INT                                                   {Fptr = crearHoja($2);}
            | CTE_STRING                                                        {Fptr = crearHoja($1);}
            | CTE_FLOAT                                                         {Fptr = crearHoja($1);}
            | OP_REST CTE_FLOAT                                                 {Fptr = crearHoja($2);}
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
