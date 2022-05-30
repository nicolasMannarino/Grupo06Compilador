%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "TablaSimbolos.h"
#include "Arbol.h"

extern FILE* yyin;

void reiniciarPunteros();

FILE* archTS;
FILE *pArbol;
FILE *pIntermedia;

t_NodoArbol* Ptr;
t_NodoArbol* Sptr;
t_NodoArbol* Aptr;
t_NodoArbol* Eptr;
t_NodoArbol* Tptr;
t_NodoArbol* Optr;
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
t_NodoArbol* DECptr;
t_NodoArbol* LDECptr;
t_NodoArbol* VSptr;
t_NodoArbol* SGptr;
t_NodoArbol* LIDptr;
t_NodoArbol* TPptr;
t_NodoArbol* Vptr;
t_NodoArbol* CFptr;
t_NodoArbol* SFptr;
t_NodoArbol* SVptr;
t_NodoArbol* FDptr;
t_NodoArbol* FIptr;
t_NodoArbol* CONDptr;
t_NodoArbol* CONDFptr;
t_NodoArbol* AUXptr;
t_NodoArbol* CONDWptr;
t_NodoArbol* SENWHILEptr;
t_NodoArbol* SENIFptr;
t_NodoArbol* TAKEptr;

int nroTake;
float nroResultadoTake; 
char* signoTake;
char* nroCadenaTake;
%}

%union{
	char* strVal; 
}

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

%token <strVal>ID
%token <strVal>CTE_INT
%token <strVal>CTE_FLOAT
%token <strVal>CTE_STRING

%token COMENT
%token whitespace
%token linefeed


%%



programaFinal:   programa                                                       {mostrarArbolDeIzqADer(&Ptr,pArbol);InOrden(&Ptr, pIntermedia);}
;

programa:   sentencia                                                           {Ptr = SENptr; printf(" FIN\n");}
;

sentencia:  sentencia declaracion                                               {SENptr = crearNodo("S",SENptr,DECptr);}
            |   sentencia estructura                                            {SENptr = crearNodo("S",SENptr,ESTptr);}
            |   estructura                                                      {SENptr = ESTptr;}
            |   declaracion                                                     {SENptr = DECptr;}
;

declaracion: DECVAR listaDeclaraciones ENDDEC                                   {DECptr = LDECptr;}
;

listaDeclaraciones: listaDeclaraciones listaID DP tipoDato                      {AUXptr = crearNodo(":",LIDptr,TPptr);LDECptr = crearNodo("LISTADEC",AUXptr,LDECptr);}
            |   listaID DP tipoDato                                             {LDECptr = crearNodo(":",LIDptr,TPptr);}
;

listaID:    listaID COMA ID                                                     {LIDptr = crearNodo(",",LIDptr,crearHoja($3));}
            |   ID                                                              {LIDptr = crearHoja($1);}
;

tipoDato:   STRING                                                              {TPptr = crearHoja("STRING");}
            |   INT                                                             {TPptr = crearHoja("INT");}
            |   FLOAT                                                           {TPptr = crearHoja("FLOAT");}
;

estructura: while                                                               {ESTptr = WHptr;}
            |   if                                                              {ESTptr = IFptr;}
            |   asign                                                           {ESTptr = ASptr;}
            |   write                                                           {ESTptr = Wptr;}
            |   take                                                            {ESTptr = Tptr;}
            |   read                                                            {ESTptr = Rptr;}
            |   inlist                                                          {ESTptr = ILptr;}
;

while:      WHILE condicionWhile LL_A sentenciaWhile LL_C                            {WHptr = crearNodo("WHILE", CONDWptr, SENWHILEptr);}
;

sentenciaWhile: sentenciaWhile estructura                                             {SENWHILEptr = crearNodo("S",SENWHILEptr,ESTptr);}
            |   estructura                                                            {SENWHILEptr = ESTptr;}

condicionWhile: condicionFinal                                                           {CONDWptr = CONDFptr;}
;

if:         IF condicionFinal LL_A sentenciaV LL_C                              {IFptr = crearNodo("IF", CONDFptr, SVptr);}
            | IF condicionFinal LL_A sentenciaV LL_C ELSE LL_A sentenciaF LL_C  {IFptr = crearNodo("IF", CONDFptr, crearNodo("CUERPO",SVptr,SFptr));}
;

sentenciaIf: sentenciaIf estructura                                             {SENIFptr = crearNodo("S",SENIFptr,ESTptr);}
            |   estructura                                                      {SENIFptr = ESTptr;}


sentenciaV: sentenciaIf                                                           {SVptr = SENIFptr;}
;

sentenciaF: sentenciaIf                                                           {SFptr = SENIFptr;}
;

condicionFinal: condicionFinal COND_AND condicion                               {CONDFptr = crearNodo("AND",CONDFptr,CONDptr);}
            | P_A condicionFinal COND_AND condicion P_C                         {CONDFptr = crearNodo("AND",CONDFptr,CONDptr);}
            /*| P_A condicionFinal COND_AND  condicionFinal P_C                 {printf("   ( condicionFinal && condicionFinal ) es CONDICIONFINAL\n");}*/
            | condicionFinal COND_OR condicion                                  {CONDFptr = crearNodo("OR",CONDFptr,CONDptr);}
            | P_A condicionFinal COND_OR condicion P_C                          {CONDFptr = crearNodo("OR",CONDFptr,CONDptr);}
            /*| P_A condicionFinal COND_OR  condicionFinal P_C                  {printf("   ( condicionFinal || condicionFinal ) es CONDICIONFINAL\n");}*/
            | COND_NOT condicionFinal                                           {;}
            | P_A COND_NOT condicion P_C                                        {CONDFptr = CONDptr;}
            | P_A condicion P_C                                                 {CONDFptr = CONDptr;}
            | condicion                                                         {CONDFptr = CONDptr;}
;

condicion:  factorIzq COMP_MEN factorDer                                        {CONDptr = crearNodo("<",  FIptr, FDptr);}
            |   factorIzq COMP_MAY factorDer                                    {CONDptr = crearNodo(">",  FIptr, FDptr);}
            |   factorIzq COMP_MENOI factorDer                                  {CONDptr = crearNodo("<=", FIptr, FDptr);}
            |   factorIzq COMP_MAYOI factorDer                                  {CONDptr = crearNodo(">=", FIptr, FDptr);}
            |   factorIzq COMP_IGUAL factorDer                                  {CONDptr = crearNodo("==", FIptr, FDptr);}
            |   factorIzq COMP_DIST factorDer                                   {CONDptr = crearNodo("!=", FIptr, FDptr);}
            |   COND_NOT factor                                                 {CONDptr = Fptr;}
            |   inlist                                                          {CONDptr = ILptr;}
;

factorDer: factor                                                               {FDptr = Fptr;}
;

factorIzq: factor                                                               {FIptr = Fptr;}
;

asign:      ID OP_ASIG expresion                                                {ASptr = crearNodo("=", crearHoja($1),Eptr);}
            | ID OP_ASIG CTE_STRING                                             {ASptr = crearNodo("=", crearHoja($1), crearHoja($3));}
;

inlist:     INLIST P_A ID PYC C_A listaExpresiones C_C P_C                      {ILptr = crearNodo("INLIST",crearHoja($3),Lptr);}
;

take:       TAKE P_A signo PYC CTE_INT {nroTake = atoi($5); nroResultadoTake = 0;} PYC C_A valores C_C P_C    
{TAKEptr = crearHoja(itoa(nroResultadoTake,nroCadenaTake ,10 ));}
;

signo:      OP_MAS                                                              {signoTake = "+";}
            | OP_REST                                                           {signoTake = "-";}
            | OP_MULT                                                           {signoTake = "*";}
            | OP_DIV                                                            {signoTake = "/";}
;

valores:    valores PYC valor                                                   {;}
            | valor                                                             {;}
;

valor:      CTE_INT                                                             {if(strcmp(signoTake,"+") == 0)
                                                                                {nroResultadoTake += atoi($1);};}
            | OP_REST CTE_INT                                                   {if(strcmp(signoTake,"+") == 0)
                                                                                {nroResultadoTake += atoi($2);};}
            | CTE_FLOAT                                                         {;}
            | OP_REST CTE_FLOAT                                                 {;}
;

listaExpresiones:  listaExpresiones PYC expresion                               {Lptr = crearNodo(";",Lptr,Eptr);}
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
            | P_A expresion P_C                                                 {;}
            | take                                                              {Optr = TAKEptr;}
;

write:      WRITE factor                                                        {Wptr = crearNodo("W",crearHoja("WRITE"),Fptr);}
;

read:       READ ID                                                             {Rptr = crearNodo("R",crearHoja("READ"),crearHoja($2));}
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
    if((pIntermedia = fopen("Intermedia.txt", "wt")) == NULL)
	{
        printf("\nNo se puede abrir el archivo %s\n", "Intermedia.txt");
    }

    if((yyin = fopen(argv[1],"rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo %s\n", argv[1]);
    }

    yyparse();

    generarArchivo();
    printf("\nCOMPILACION EXITOSA!\n");
    reiniciarPunteros();
    fclose(pIntermedia);
    fclose(yyin);
    
    return 0;
}

void reiniciarPunteros(){
Ptr = NULL;
Sptr = NULL;
Aptr = NULL;
Eptr = NULL;
Tptr = NULL;
Optr = NULL;
Fptr = NULL;
Lptr = NULL;
Wptr = NULL;
Rptr = NULL;
ILptr = NULL;
ASptr = NULL;
IFptr = NULL;
WHptr = NULL;
ESTptr = NULL;
SENptr = NULL;
DECptr = NULL;
LDECptr = NULL;
VSptr = NULL;
SGptr = NULL;
LIDptr = NULL;
TPptr = NULL;
Vptr = NULL;
CFptr = NULL;
SFptr = NULL;
SVptr = NULL;
FDptr = NULL;
FIptr = NULL;
CONDptr = NULL;
CONDFptr = NULL;
AUXptr = NULL;
CONDWptr = NULL;
SENWHILEptr = NULL;
SENIFptr = NULL;
TAKEptr = NULL;
																						
}
