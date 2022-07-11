#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MATRIZ 2000

typedef struct sRegistro
{
    char nombre[50];
    char tipo[50];
    char valor[50];
    int  longitud;
}tRegistro;

tRegistro matrizDeRegistros[TAM_MATRIZ];

int ultimaPosicion = 0;

int validarValorTabla (char* );
int insertarIDEnTablaDeSimbolos(char* ,char*);
void generarArchivo();
void insertarFLOATEnTablaDeSimbolos(char* );
void insertarEnTablaDeSimbolos(char* id, char* tipo);
char* eliminarComillasCTESTRING(char* );
char* getTipo(char*);
void pasarTablaAasembler(FILE* ass);
char* replace_char(char* str, char find, char replace);

int validarValorTabla(char* id){
    int aux=0;
    while( ultimaPosicion > aux ){
        if(strcmp(id,matrizDeRegistros[aux].nombre) == 0){
            return aux;
        }
        aux++;
    }
    return -1;
}

char* eliminarComillasCTESTRING(char* str)
{
    char* cad = str;
    char* cadInicio = cad;
    while(*str)
    {
        if(*str != '"')
        {
            (*cad) = (*str);
            cad++;
        }
        str++;
    }
    *cad = '\0';
    return cadInicio;
}

int insertarIDEnTablaDeSimbolos(char* id, char* tipo)
{  
    if(validarValorTabla(id) == -1){
        strcpy(matrizDeRegistros[ultimaPosicion].valor,"?");
        strcpy(matrizDeRegistros[ultimaPosicion].nombre,id);
        strcpy(matrizDeRegistros[ultimaPosicion].tipo,tipo);
        ultimaPosicion++;
    }
    else{
        return -1;
    }
}

void insertarEnTablaDeSimbolos(char* id, char* tipo)
{  
    char nombre[100] = "_";
    char nombreString_ini[100] = "\"";
    char nombreString_fin[100] = "\"";
    strcat(nombre,id);
    if(validarValorTabla(nombre) == -1){
        replace_char(nombre, '.', '_');
        if(strcmp(tipo,"CTE_STRING") == 0){
            strcat(nombreString_ini,id);
            strcat(nombreString_ini,nombreString_fin);
            strcpy(matrizDeRegistros[ultimaPosicion].valor,nombreString_ini);
        }else{
            strcpy(matrizDeRegistros[ultimaPosicion].valor,id);
        }
        strcpy(matrizDeRegistros[ultimaPosicion].nombre,nombre);
        strcpy(matrizDeRegistros[ultimaPosicion].tipo,tipo);
        if(strcmp(tipo,"STRING") == 0)
            matrizDeRegistros[ultimaPosicion].longitud = strlen(id);
        ultimaPosicion++;
    }
}

char* replace_char(char* str, char find, char replace){

    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

char* getTipo(char* id){
    int aux=0;
    while( ultimaPosicion > aux ){
        if(strcmp(id,matrizDeRegistros[aux].nombre) == 0){
            return matrizDeRegistros[aux].tipo;
        }
        aux++;
    }
    return "NULL";
};


void generarArchivo()
{
  FILE *fp;
  
  fp = fopen ( "ts.txt", "w+" );
  
  fprintf(fp,"              NOMBRE             |        TIPO        |              VALOR              |  LONGITUD   |\n");
  fprintf(fp,"------------------------------------------------------------------------------------------------------|\n");

  int i;
  for(i = 0; i < ultimaPosicion ; i++)
  {
    fprintf(fp, " %-*s | %-*s | %*s | %*d |\n", 31, matrizDeRegistros[i].nombre,
                                                 18, matrizDeRegistros[i].tipo,
                                                 31, matrizDeRegistros[i].valor,
                                                 11, matrizDeRegistros[i].longitud);
  }
  fclose ( fp );
}

void pasarTablaAasembler(FILE* ass){
     
  int i;
  fseek(ass,157,SEEK_SET);
  for(i = 0; i < ultimaPosicion ; i++)
  {
    if(strcmp(matrizDeRegistros[i].tipo, "CTE_STRING") == 0){
            fprintf(ass, "%-*s  %-*s  %*s \n", 31, matrizDeRegistros[i].nombre,
                                                 18, "db",
                                                 31, matrizDeRegistros[i].valor);
    }else{
        fprintf(ass, "%-*s  %-*s  %*s \n", 31, matrizDeRegistros[i].nombre,
                                                 18, "dd",
                                                 31, matrizDeRegistros[i].valor);
    }
  }
}