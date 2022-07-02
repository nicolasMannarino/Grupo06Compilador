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
        fprintf(ass,"WRITE %s \n",((*pa)->der)->info);
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }else
    if(strcmp((*pa)->info,"R")==0){
        fprintf(ass,"READ %s \n",((*pa)->der)->info);
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

    if(esHoja(&(*pa)->izq)==1 && strcmp((*pa)->izq->info,"+")!=0 && strcmp((*pa)->izq->info,"-")!=0 && strcmp((*pa)->izq->info,"/")!=0 && strcmp((*pa)->izq->info,"*")!=0){
        fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    }
    if(esHoja(&(*pa)->der)==1){
    fprintf(ass,"FLD %s\n",((*pa)->der)->info);
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

    if(strcmp((*pa)->izq->info,"AND")==0){
        traducirCondicion(&(*pa)->izq->izq,ass);
        traducirCondicion(&(*pa)->izq->der,ass);
    }else if(strcmp((*pa)->izq->info,"OR")==0){
        traducirCondicionOR(&(*pa)->izq->izq,ass);
        traducirCondicionOR(&(*pa)->izq->der,ass);
        fprintf(ass,"JMP finIf%d\n",contFinIf);
        fprintf(ass,"parteVerdadera%d\n",contFinIf);        
    }if(strcmp((*pa)->izq->info,"INLIST")==0){

        fprintf(ass,"INLIST\n");
     
    }
    else{
        traducirCondicion(&(*pa)->izq,ass);
    }
    crearAssembler(&(*pa)->der,ass);
    fprintf(ass,"finIf%d\n",contFinIf);
    contFinIf++;
}

void traducirIfElse(t_arbol* pa,FILE* ass){
    if(strcmp((*pa)->izq->info,"AND")==0){
        traducirCondicion(&(*pa)->izq->izq,ass);
        traducirCondicion(&(*pa)->izq->der,ass);
    }else if(strcmp((*pa)->izq->info,"OR")==0){
        traducirCondicionOR(&(*pa)->izq->izq,ass);
        traducirCondicionOR(&(*pa)->izq->der,ass);
        fprintf(ass,"JMP finIf%d\n",contFinIf);
        fprintf(ass,"parteVerdadera%d\n",contFinIf);        
    }else{
        traducirCondicion(&(*pa)->izq,ass);
    }
    crearAssembler(&(*pa)->der->izq,ass);
    fprintf(ass,"JMP finElse%d\n",contFinIf);
    fprintf(ass,"finIf%d\n",contFinIf);
    crearAssembler(&(*pa)->der->der,ass);
    fprintf(ass,"finElse%d\n",contFinIf);
    contFinIf++;
}

void traducirCondicion(t_arbol* pa, FILE* ass){
    fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"FSHF \n");
    if(strcmp((*pa)->info,"<")==0){
        fprintf(ass,"JAE finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">")==0){
        fprintf(ass,"JNA finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"<=")==0){
        fprintf(ass,"JA finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">=")==0){
        fprintf(ass,"JB finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"==")==0){
        fprintf(ass,"JNE finIf%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"!=")==0){
        fprintf(ass,"JE finIf%d\n",contFinIf);
    }
}

void traducirCondicionOR(t_arbol* pa, FILE* ass){
    fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"FSHF \n");
    if(strcmp((*pa)->info,"<")==0){
        fprintf(ass,"JB parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">")==0){
        fprintf(ass,"JA parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"<=")==0){
        fprintf(ass,"JNA parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,">=")==0){
        fprintf(ass,"JAE parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"==")==0){
        fprintf(ass,"JE parteVerdadera%d\n",contFinIf);
    }
    if(strcmp((*pa)->info,"!=")==0){
        fprintf(ass,"JNE parteVerdadera%d\n",contFinIf);
    }
}

void traducirWhile(t_arbol* pa,FILE* ass){
    fprintf(ass,"inicioWhile%d\n",contWhile);
    if(strcmp((*pa)->izq->info,"AND")==0){
        traducirCondicionWhile(&(*pa)->izq->izq,ass);
        traducirCondicionWhile(&(*pa)->izq->der,ass);
    }else if(strcmp((*pa)->izq->info,"OR")==0){
        traducirCondicionORWhile(&(*pa)->izq->izq,ass);
        traducirCondicionORWhile(&(*pa)->izq->der,ass);
        fprintf(ass,"JMP finWhile%d\n",contWhile);
        fprintf(ass,"parteVerdadera%d\n",contWhile);        
    }else{
        traducirCondicionWhile(&(*pa)->izq,ass);
    }
    crearAssembler(&(*pa)->der,ass);
    fprintf(ass,"JMP inicioWhile%d\n",contWhile);
    fprintf(ass,"finWhile%d\n",contWhile);
    contWhile++;
}

void traducirCondicionWhile(t_arbol* pa, FILE* ass){
    fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"FSHF \n");
    if(strcmp((*pa)->info,"<")==0){
        fprintf(ass,"JAE finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">")==0){
        fprintf(ass,"JNA finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"<=")==0){
        fprintf(ass,"JA finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">=")==0){
        fprintf(ass,"JB finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"==")==0){
        fprintf(ass,"JNE finWhile%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"!=")==0){
        fprintf(ass,"JE finWhile%d\n",contWhile);
    }
}

void traducirCondicionORWhile(t_arbol* pa, FILE* ass){
    fprintf(ass,"FLD %s \n",((*pa)->izq)->info);
    fprintf(ass,"FCOMP %s \n",((*pa)->der)->info);
    fprintf(ass,"FSTSW ax \n");
    fprintf(ass,"FSHF \n");
    if(strcmp((*pa)->info,"<")==0){
        fprintf(ass,"JB parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">")==0){
        fprintf(ass,"JA parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"<=")==0){
        fprintf(ass,"JNA parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,">=")==0){
        fprintf(ass,"JAE parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"==")==0){
        fprintf(ass,"JE parteVerdadera%d\n",contWhile);
    }
    if(strcmp((*pa)->info,"!=")==0){
        fprintf(ass,"JNE parteVerdadera%d\n",contWhile);
    }
}
#endif // ARBOL_H_INCLUDED