#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct s_NodoArbol
{
    struct s_NodoArbol *izq;
    struct s_NodoArbol *der;
    char info[50];
}t_NodoArbol;

typedef t_NodoArbol* t_arbol;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

t_NodoArbol* crearHoja( char* lexema);
t_NodoArbol* crearNodo(char* lexema, t_NodoArbol* hijoIzq, t_NodoArbol* hijoDer);
void VaciarArbol(t_arbol *pa);
void InOrden(t_arbol *pa, FILE *pIntermedia);
void mostrarArbolDeIzqADer(t_arbol *pa, FILE* pArbol);
void mostrarArbolDeIzqADerAux(t_arbol *pa,int nivel, FILE* pArbol);
void crearAssembler(t_arbol *pa, FILE *ass);
void traducirAssembler(t_arbol *pa, FILE *ass);
void traducirOp(t_arbol* pa,FILE *ass, char* op);
void traducirIf(t_arbol* pa,FILE* ass);
void traducirCondicion(t_arbol* pa, FILE* ass);
void traducirCondicionOR(t_arbol* pa, FILE* ass);
void traducirIfElse(t_arbol* pa,FILE* ass);
void traducirWhile(t_arbol* pa,FILE* ass);
void traducirCondicionWhile(t_arbol* pa, FILE* ass);
void traducirCondicionORWhile(t_arbol* pa, FILE* ass);

int contAux=0;
char str_Aux[20];
char str_Salto[20];
char str_FinIf[20];
int contCuerp=0;
int contWhile=0;
int contSalto = 1;
int contFinIf = 1;
int empezar=0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

t_NodoArbol* crearHoja( char* lexema)
{
    t_NodoArbol* nue = (t_NodoArbol*) malloc (sizeof(t_NodoArbol));
    if(!nue)
    {
        printf("No se pudo reservar memoria para el nodo.\n");
        return NULL;
    }
    nue->izq = NULL;
    nue->der = NULL;
    strcpy(nue->info, lexema);
    return nue;
}

t_NodoArbol* crearNodo(char* lexema, t_NodoArbol* hijoIzq, t_NodoArbol* hijoDer)
{
    t_NodoArbol* padre = (t_NodoArbol*) malloc (sizeof(t_NodoArbol));
    
    if(!padre)
    {
        printf("No se pudo reservar memoria para el nodo.\n");
        return NULL;
    }

    padre->izq = hijoIzq;
    padre->der = hijoDer;
    strcpy(padre->info, lexema);

    return padre;
}

void VaciarArbol(t_arbol *pa)
{
    if(!*pa)
        return;
    VaciarArbol(&(*pa)->izq);
    VaciarArbol(&(*pa)->der);
    free(*pa);
    *pa = NULL;
}

void InOrden(t_arbol *pa, FILE *pIntermedia)
{
    if(!(*pa))
        return;
    InOrden(&(*pa)->izq, pIntermedia);
    fprintf(pIntermedia, " %s  ", (*pa)->info);  
    InOrden(&(*pa)->der, pIntermedia);
}

void mostrarArbolDeIzqADer(t_arbol *pa, FILE* pArbol)
{
    pArbol=fopen("Arbol.txt","wt");
    mostrarArbolDeIzqADerAux(pa,0,pArbol);
    fclose(pArbol);
}
void mostrarArbolDeIzqADerAux(t_arbol *pa,int nivel, FILE* pArbol)
{
    int i;
    if(!*pa)
        return;
    mostrarArbolDeIzqADerAux(&(*pa)->der,nivel+1,pArbol);
    fprintf(pArbol,"\n");
    for(i = 0; i < nivel; i++)
        fprintf(pArbol,"\t");
    fprintf(pArbol,"%s", (*pa)->info);
    mostrarArbolDeIzqADerAux(&(*pa)->izq,nivel+1,pArbol);
}

void traduccionWhile(t_arbol* pArbol,FILE* pAssembler, char* salto){
     if(!*pArbol)
        return;
     if(contWhile==1){
        insertarEnTablaDeSimbolos("principiowhile","CTE_STRING");
         fprintf(pAssembler,"%s\n","principiowhile");
         printf("Entro contCuerp2");
         return;
     }
     else  if(contWhile==2){
        insertarEnTablaDeSimbolos("principiowhile","CTE_STRING");
         fprintf(pAssembler,"JMP _principiowhile\n");
         insertarEnTablaDeSimbolos("saltoelse","CTE_STRING");
         fprintf(pAssembler,"saltoelse\n");
         free((*pArbol)->izq);
         free((*pArbol)->der);

        (*pArbol)->izq = NULL;
        (*pArbol)->der = NULL;
     }

  
}

void traduccionCuerpoIf(t_arbol* pArbol,FILE* pAssembler, char* salto){
     if(!*pArbol)
        return;
     if(contCuerp==1){
         char salto2[5]="JMP";
         insertarEnTablaDeSimbolos("fin_if","CTE_STRING");
         sprintf(str_FinIf, "fin_if%d", contFinIf);
         fprintf(pAssembler,"%s %s\n",salto2, str_FinIf);
         fprintf(pAssembler,"%s\n",salto);
         return;
     }
     else  if(contCuerp==2){
         insertarEnTablaDeSimbolos("fin_if","CTE_STRING");
         sprintf(str_FinIf, "fin_if%d", contFinIf);
         fprintf(pAssembler,"%s\n", str_FinIf);
         free((*pArbol)->izq);
         free((*pArbol)->der);

        (*pArbol)->izq = NULL;
        (*pArbol)->der = NULL;
     }

  
}

int esHoja(t_arbol* pNodoArbol){
    if(!*pNodoArbol)
        return 0;
 
    if((!(*pNodoArbol)->izq) && (!(*pNodoArbol)->der))
        return 1;
    else
        return 0;
}


void crearAssembler(t_arbol *pa, FILE *ass)
{
    if(!(*pa))
        return;
    if((*pa) && (*pa)->izq != NULL){
        crearAssembler(&(*pa)->izq, ass);
    }
    if((*pa) && empezar == 0 && strcmp(((*pa)->info),"S") == 0){
        empezar=1;
    }
    if((*pa) && empezar==1 && esHoja(pa) == 0){
        traducirAssembler(pa,ass); 
    }
    if((*pa) && (*pa)->der != NULL){
        crearAssembler(&(*pa)->der, ass);
    }
}

void traducirAssembler(t_arbol *pa, FILE *ass){
    char nombre[1000] = "_";
    if(strcmp((*pa)->info,"=")==0){
        if((*pa)->der->izq != NULL){
            crearAssembler(&(*pa)->der,ass);
        }else{
            if(strcmp(getTipo(((*pa)->der)->info),"INT") == 0 || strcmp(getTipo(((*pa)->der)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->der)->info),"STRING") == 0){
                fprintf(ass,"FLD %s\n",((*pa)->der)->info);
            }else{
                strcat(nombre,((*pa)->der)->info);
                replace_char(nombre,'.','_');
                fprintf(ass,"FLD %s\n",nombre);
                strcpy(nombre,"_");
            }
        }

            fprintf(ass,"FSTP %s\n",((*pa)->izq)->info);

        free((*pa)->izq);
        free((*pa)->der);

        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else
    if(strcmp((*pa)->info,"+")==0){
        traducirOp(pa,ass,"FADD");
    }else
    if(strcmp((*pa)->info,"/")==0){
        traducirOp(pa,ass,"FDIV");
    }else
    if(strcmp((*pa)->info,"*")==0){
        traducirOp(pa,ass,"FMUL");
    }else
    if(strcmp((*pa)->info,"-")==0){
        traducirOp(pa,ass,"FSUB");
    }else
    if(strcmp((*pa)->info,"W")==0){
        if(strcmp(getTipo(((*pa)->der)->info),"INT") == 0 || strcmp(getTipo(((*pa)->der)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->der)->info),"STRING") == 0){
            fprintf(ass,"displayString %s \n",((*pa)->der)->info);
        }else{
            fprintf(ass,"displayString _%s \n",((*pa)->der)->info);
        }
        
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else
    if(strcmp((*pa)->info,"R")==0){
        if(strcmp(getTipo(((*pa)->der)->info),"INT") == 0 || strcmp(getTipo(((*pa)->der)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->der)->info),"STRING") == 0){
        fprintf(ass,"displayString %s \n",((*pa)->der)->info);
        }else{
            fprintf(ass,"displayString %s \n",((*pa)->der)->info);
        }
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else
    if(strcmp((*pa)->info,"IF")==0){
        if(strcmp((*pa)->der->info,"CUERPO")==0){
            traducirIfElse(pa,ass);
        }else{
            traducirIf(pa,ass);
        }
    }else
    if(strcmp((*pa)->info,"WHILE")==0){
        traducirWhile(pa,ass);
    }
}


void traducirOp(t_arbol* pa,FILE *ass, char* op){
    char nombre[100] = "_";
    if(esHoja(&(*pa)->izq)==1 && strcmp((*pa)->izq->info,"+")!=0 && strcmp((*pa)->izq->info,"-")!=0 && strcmp((*pa)->izq->info,"/")!=0 && strcmp((*pa)->izq->info,"*")!=0){
            if(strcmp(getTipo(((*pa)->izq)->info),"INT") == 0 || strcmp(getTipo(((*pa)->izq)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->izq)->info),"STRING") == 0){
                fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
            }else{
                strcat(nombre,((*pa)->izq)->info);
                replace_char(nombre,'.','_');
                fprintf(ass,"FLD %s\n",nombre);
                strcpy(nombre,"_");

                /*strcat(nombre,((*pa)->izq)->info);
                fprintf(ass,"FLD %s \n",nombre);
                strcpy(nombre,"_");*/
            }
    
    
    }
    if(esHoja(&(*pa)->der)==1){
            if(strcmp(getTipo(((*pa)->der)->info),"INT") == 0 || strcmp(getTipo(((*pa)->der)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->der)->info),"STRING") == 0){
                fprintf(ass,"FLD %s\n",((*pa)->der)->info);
            }else{
                strcat(nombre,((*pa)->der)->info);
                replace_char(nombre,'.','_');
                fprintf(ass,"FLD %s\n",nombre);
                strcpy(nombre,"_");
                /*strcat(nombre,((*pa)->der)->info);
                fprintf(ass,"FLD %s\n",nombre);
                strcpy(nombre,"_");*/
            }
        
    }else{
        crearAssembler(&(*pa)->der,ass);
        free((*pa)->izq);
        free((*pa)->der);
        (*pa)->izq = NULL;
        (*pa)->der = NULL;        
    }
    if(esHoja(&(*pa)->izq)==0 && esHoja(&(*pa)->der)==0){
        
    }
    fprintf(ass,"%s \n",op);

}

void traducirIf(t_arbol* pa,FILE* ass){
    char valor[2];
    char destino_verdadera[50] = "parteVerdadera";
    char destino_finIf[50] = "finIf";
    if(strcmp((*pa)->izq->info,"AND")==0){
        traducirCondicion(&(*pa)->izq->izq,ass);
        traducirCondicion(&(*pa)->izq->der,ass);
    }else if(strcmp((*pa)->izq->info,"OR")==0){
        traducirCondicionOR(&(*pa)->izq->izq,ass);
        traducirCondicionOR(&(*pa)->izq->der,ass);
        itoa(contFinIf,valor,10);
        //insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
        fprintf(ass,"JMP _finIf%d\n",contFinIf);
       // insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        fprintf(ass,"_parteVerdadera%d:\n",contFinIf);        
    }if(strcmp((*pa)->izq->info,"INLIST")==0){

        fprintf(ass,"INLIST\n");
     
    }
    else{
        traducirCondicion(&(*pa)->izq,ass);
    }
    crearAssembler(&(*pa)->der,ass);
    fprintf(ass,"_finIf%d\n",contFinIf);
    contFinIf++;
}

void traducirIfElse(t_arbol* pa,FILE* ass){
    char valor[2];
    char destino_verdadera[50] = "parteVerdadera";
    char destino_finIf[50] = "finIf";
    char destino_finElse[50] = "finElse";
    if(strcmp((*pa)->izq->info,"AND")==0){
        traducirCondicion(&(*pa)->izq->izq,ass);
        traducirCondicion(&(*pa)->izq->der,ass);
    }else if(strcmp((*pa)->izq->info,"OR")==0){
        traducirCondicionOR(&(*pa)->izq->izq,ass);
        traducirCondicionOR(&(*pa)->izq->der,ass);
        itoa(contFinIf,valor,10);
       // insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
        //strcpy(destino_finIf,"finIf");
        fprintf(ass,"JMP _finIf%d\n",contFinIf);
       // insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
       // strcpy(destino_verdadera,"parteVerdadera");
        fprintf(ass,"_parteVerdadera%d:\n",contFinIf);        
    }else{
        traducirCondicion(&(*pa)->izq,ass);
    }
    crearAssembler(&(*pa)->der->izq,ass);
    itoa(contFinIf,valor,10);
    //insertarEnTablaDeSimbolos(strcat(destino_finElse,valor),"CTE_STRING");
   // strcpy(destino_finElse,"finElse");
    fprintf(ass,"JMP _finElse%d\n",contFinIf);

    //insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
    //strcpy(destino_finIf,"finIf");
    fprintf(ass,"_finIf%d:\n",contFinIf);
    crearAssembler(&(*pa)->der->der,ass);

    //insertarEnTablaDeSimbolos(strcat(destino_finElse,valor),"CTE_STRING");
    //strcpy(destino_finElse,"finElse");
    fprintf(ass,"_finElse%d:\n",contFinIf);
    contFinIf++;
}

void traducirCondicion(t_arbol* pa, FILE* ass){
    char valor[2];
    char destino_finIf[50] = "finIf";
    char nombre[100] = "_";
    
    if(strcmp(getTipo(((*pa)->izq)->info),"INT") == 0 || strcmp(getTipo(((*pa)->izq)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->izq)->info),"STRING") == 0){
        fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    }else{
                        strcat(nombre,((*pa)->izq)->info);
                replace_char(nombre,'.','_');
                fprintf(ass,"FLD %s\n",nombre);
                strcpy(nombre,"_");
       /* strcat(nombre,((*pa)->izq)->info);
        fprintf(ass,"FLD %s \n",nombre);
        strcpy(nombre,"_");*/
    }

    
    if(strcmp(getTipo(((*pa)->der)->info),"INT") == 0 || strcmp(getTipo(((*pa)->der)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->der)->info),"STRING") == 0){
        fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    }else{
        strcat(nombre,((*pa)->der)->info);
        fprintf(ass,"FCOMP %s \n",nombre);
        strcpy(nombre,"_");
    }
    
    
    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"SAHF \n");

    itoa(contFinIf,valor,10);
    if(strcmp((*pa)->info,"<")==0){
       // insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
       // strcpy(destino_finIf,"finIf");
        fprintf(ass,"JAE _finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">")==0){
       // insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
        //strcpy(destino_finIf,"finIf");
        fprintf(ass,"JNA _finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"<=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
        //strcpy(destino_finIf,"finIf");
        fprintf(ass,"JA _finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
        //strcpy(destino_finIf,"finIf");
        fprintf(ass,"JB _finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"==")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
        //strcpy(destino_finIf,"finIf");
        fprintf(ass,"JNE _finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"!=")==0){
                //insertarEnTablaDeSimbolos(strcat(destino_finIf,valor),"CTE_STRING");
        //strcpy(destino_finIf,"finIf");
        fprintf(ass,"JE _finIf%d\n",contFinIf);
    }
}

void traducirCondicionOR(t_arbol* pa, FILE* ass){
    char valor[2];
    char destino_verdadera[50] = "parteVerdadera";
    char nombre[100] = "_";

    if(strcmp(getTipo(((*pa)->izq)->info),"INT") == 0 || strcmp(getTipo(((*pa)->izq)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->izq)->info),"STRING") == 0){
            fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    }else{
                        strcat(nombre,((*pa)->izq)->info);
                replace_char(nombre,'.','_');
                fprintf(ass,"FLD %s\n",nombre);
                strcpy(nombre,"_");
            /*strcat(nombre,((*pa)->izq)->info);
            fprintf(ass,"FLD %s \n",nombre);
            strcpy(nombre,"_");*/
    }

    
    if(strcmp(getTipo(((*pa)->der)->info),"INT") == 0 || strcmp(getTipo(((*pa)->der)->info),"FLOAT") == 0|| strcmp(getTipo(((*pa)->der)->info),"STRING") == 0){
                fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    }else{
            strcat(nombre,((*pa)->der)->info);
                fprintf(ass,"FCOMP %s \n",nombre);
            strcpy(nombre,"_");
    }

    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"SAHF \n");
    itoa(contFinIf,valor,10);
    if(strcmp((*pa)->info,"<")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");
        fprintf(ass,"JB _parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");        
        fprintf(ass,"JA _parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"<=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");        
        fprintf(ass,"JNA _parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");        
        fprintf(ass,"JAE _parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"==")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");        
        fprintf(ass,"JE _parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"!=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");        
        fprintf(ass,"JNE _parteVerdadera%d\n",contFinIf);
    }
}

void traducirWhile(t_arbol* pa,FILE* ass){
    char valor[2];
    char destino_inicioWhile[50] = "inicioWhile";
    char destino_verdadera[50] = "parteVerdadera";
    char destino_finWhile[50] = "finWhile";
    itoa(contWhile,valor,10);

    //insertarEnTablaDeSimbolos(strcat(destino_inicioWhile,valor),"CTE_STRING");
    //strcpy(destino_inicioWhile,"inicioWhile");           
    fprintf(ass,"_inicioWhile%d:\n",contWhile);
    if(strcmp((*pa)->izq->info,"AND")==0){
        traducirCondicionWhile(&(*pa)->izq->izq,ass);
        traducirCondicionWhile(&(*pa)->izq->der,ass);
    }else if(strcmp((*pa)->izq->info,"OR")==0){
        traducirCondicionORWhile(&(*pa)->izq->izq,ass);
        traducirCondicionORWhile(&(*pa)->izq->der,ass);
        //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
        //strcpy(destino_finWhile,"finWhile");   
        fprintf(ass,"JMP _finWhile%d\n",contWhile);
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");           
        fprintf(ass,"_parteVerdadera%d:\n",contWhile);        
    }else{
        traducirCondicionWhile(&(*pa)->izq,ass);
    }
    crearAssembler(&(*pa)->der,ass);
    //insertarEnTablaDeSimbolos(strcat(destino_inicioWhile,valor),"CTE_STRING");
    //strcpy(destino_inicioWhile,"inicioWhile");      
    fprintf(ass,"JMP _inicioWhile%d\n",contWhile);
    //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
    //strcpy(destino_finWhile,"finWhile");     
    fprintf(ass,"_finWhile%d:\n",contWhile);
    contWhile++;
}

void traducirCondicionWhile(t_arbol* pa, FILE* ass){
    char valor[2];
    char destino_inicioWhile[50] = "inicioWhile";
    char destino_verdadera[50] = "parteVerdadera";
    char destino_finWhile[50] = "finWhile";
    itoa(contWhile,valor,10);
    fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"SAHF \n");
    if(strcmp((*pa)->info,"<")==0){
    //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
    //strcpy(destino_finWhile,"finWhile");           
        fprintf(ass,"JAE _finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
    //strcpy(destino_finWhile,"finWhile");       
        fprintf(ass,"JNA _finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"<=")==0){
    //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
    //strcpy(destino_finWhile,"finWhile");           
        fprintf(ass,"JA _finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">=")==0){
    //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
    //strcpy(destino_finWhile,"finWhile");           
        fprintf(ass,"JB _finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"==")==0){
    //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
    //strcpy(destino_finWhile,"finWhile");           
        fprintf(ass,"JNE _finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"!=")==0){
    //insertarEnTablaDeSimbolos(strcat(destino_finWhile,valor),"CTE_STRING");
    //strcpy(destino_finWhile,"finWhile");           
        fprintf(ass,"JE _finWhile%d\n",contWhile);
    }
}

void traducirCondicionORWhile(t_arbol* pa, FILE* ass){
    char valor[2];
    char destino_inicioWhile[50] = "inicioWhile";
    char destino_verdadera[50] = "parteVerdadera";
    char destino_finWhile[50] = "finWhile";    
    itoa(contWhile,valor,10);
    fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"SAHF \n");
    if(strcmp((*pa)->info,"<")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");          
        fprintf(ass,"JB _parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");          
        fprintf(ass,"JA _parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"<=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");          
        fprintf(ass,"JNA _parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");          
        fprintf(ass,"JAE _parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"==")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");          
        fprintf(ass,"JE _parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"!=")==0){
        //insertarEnTablaDeSimbolos(strcat(destino_verdadera,valor),"CTE_STRING");
        //strcpy(destino_verdadera,"parteVerdadera");          
        fprintf(ass,"JNE _parteVerdadera%d\n",contWhile);
    }
}
#endif // ARBOL_H_INCLUDED