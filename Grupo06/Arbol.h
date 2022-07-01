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
void recorrerIF(t_arbol* pa, FILE* ass);

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
         fprintf(pAssembler,"%s\n","principiowhile");
         printf("Entro contCuerp2");
         return;
     }
     else  if(contWhile==2){
         fprintf(pAssembler,"JMP principiowhile\n");
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
         sprintf(str_FinIf, "fin_if%d", contFinIf);
         fprintf(pAssembler,"%s %s\n",salto2, str_FinIf);
         fprintf(pAssembler,"%s\n",salto);
         return;
     }
     else  if(contCuerp==2){
         sprintf(str_FinIf, "fin_if%d", contFinIf);
         fprintf(pAssembler,"%s\n", str_FinIf);
         contFinIf++;
         free((*pArbol)->izq);
         free((*pArbol)->der);

        (*pArbol)->izq = NULL;
        (*pArbol)->der = NULL;
     }

  
}

void traduccionIf(t_arbol* pArbol,FILE* pAssembler, char* salto){
     if(!*pArbol)
        return;
    if(contCuerp==0){
    fprintf(pAssembler,"%s\n",salto);
    fprintf(pAssembler,"FFREE\n"); 
    
    }
    contCuerp=0;
    free((*pArbol)->izq);
    free((*pArbol)->der);

    (*pArbol)->izq = NULL;
    (*pArbol)->der = NULL;
}

void traduccionCond(t_arbol* pArbol,FILE* pAssembler, char* salto){
     if(!*pArbol)
        return;
    printf("Entra a condicion... \n");
    fprintf(pAssembler,"FLD %s\n",((*pArbol)->izq)->info);
    fprintf(pAssembler,"FCOMP %s\n",((*pArbol)->der)->info);
    fprintf(pAssembler,"FSTSW ax\n");
    fprintf(pAssembler,"SAHF\n");
    sprintf(str_Salto, "saltoelse%d", contSalto);
    fprintf(pAssembler,"%s %s\n", salto, str_Salto);

     free((*pArbol)->izq);
     free((*pArbol)->der);

    (*pArbol)->izq = NULL;
    (*pArbol)->der = NULL;
    
    

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
    crearAssembler(&(*pa)->izq, ass);
    if(empezar == 0 && strcmp(((*pa)->info),"S") == 0){
        empezar=1;
    }
    if(empezar==1){
        traducirAssembler(pa,ass); 
    }
    crearAssembler(&(*pa)->der, ass);
}

void traducirAssembler(t_arbol *pa, FILE *ass){


    if(strcmp((*pa)->info,"=")==0){
        if((*pa)->der->izq != NULL){
            crearAssembler(&(*pa)->der,ass);
        }else{
            fprintf(ass,"FLD %s\n",((*pa)->der)->info);
        }
        fprintf(ass,"FSTP %s\n",((*pa)->izq)->info);
        free((*pa)->izq);
        free((*pa)->der);

        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else

    if(strcmp((*pa)->info,"+")==0){

        if((*pa)->izq->izq != NULL){
            crearAssembler(&(*pa)->izq,ass);
        }else{
            if(strcmp((*pa)->izq->info,"+")!=0){
                fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
            }
        }

        if((*pa)->der->izq != NULL){ //no es hoja?
            crearAssembler(&(*pa)->der,ass);
        }else{
            fprintf(ass,"FLD %s\n",((*pa)->der)->info);
        }

        fprintf(ass,"FADD \n");
        
        free((*pa)->izq);
        free((*pa)->der);
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else

    if(strcmp((*pa)->info,"/")==0){

        if((*pa)->izq->izq != NULL){
            crearAssembler(&(*pa)->izq,ass);
        }else{
            if(strcmp((*pa)->izq->info,"/")!=0){
                fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
            }
        }

        if((*pa)->der->izq != NULL){ //no es hoja?
            crearAssembler(&(*pa)->der,ass);
        }else{
            fprintf(ass,"FLD %s\n",((*pa)->der)->info);
        }

        fprintf(ass,"FDIV \n");
        free((*pa)->izq);
        free((*pa)->der);

        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else

    if(strcmp((*pa)->info,"*")==0){
        
        if((*pa)->izq->izq != NULL){
            crearAssembler(&(*pa)->izq,ass);
        }else{
            if(strcmp((*pa)->izq->info,"*")!=0){
                fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
            }
        }

        if((*pa)->der->izq != NULL){ //no es hoja?
            crearAssembler(&(*pa)->der,ass);
        }else{
            if(strcmp((*pa)->der->info,"*")!=0){
                fprintf(ass,"FLD %s \n",((*pa)->der)->info);
            }
        }

        fprintf(ass,"FMUL \n");
        
        free((*pa)->izq);
        free((*pa)->der);

        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else

    if(strcmp((*pa)->info,"-")==0){

        if((*pa)->izq->izq != NULL){
            crearAssembler(&(*pa)->izq,ass);
        }else{
            if(strcmp((*pa)->izq->info,"-")!=0){
                fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
            }
        }

        if((*pa)->der->izq != NULL){ //no es hoja?
            crearAssembler(&(*pa)->der,ass);
        }else{
            if(strcmp((*pa)->der->info,"-")!=0){
                fprintf(ass,"FLD %s \n",((*pa)->der)->info);
            }
        }
        
        fprintf(ass,"FSUB \n");

        free((*pa)->izq);
        free((*pa)->der);

        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else

    if(strcmp((*pa)->info,"W")==0){
        fprintf(ass,"WRITE %s \n",((*pa)->der)->info);
    }else

    if(strcmp((*pa)->info,"R")==0){
        fprintf(ass,"READ %s \n",((*pa)->der)->info);
    }

    if(strcmp((*pa)->info,"IF")==0){
        if(strcmp((*pa)->izq->info,"AND")==0 || strcmp((*pa)->izq->info,"OR")==0){
            
        }else {
            fprintf(ass,"FLD %s \n",((*pa)->izq)->izq->info);
            fprintf(ass,"FCOMP %s \n",((*pa)->izq)->der->info);
            fprintf(ass,"FSTSW ax \n");
            fprintf(ass,"FSHF \n");
            if(strcmp((*pa)->izq->info,"<")==0){
                fprintf(ass,"JAE finIf\n");
            }
        }

        recorrerIF(&(*pa)->der,ass);
        
    }

}

void recorrerIF(t_arbol* pa, FILE* ass){

}


#endif // ARBOL_H_INCLUDED