#include "atleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _atleta_{
    char nome[30];
    int idade;
    float altura;
    float TempoMin;
}Atleta;


Atleta * criarAtleta(char nome[], int idade, float altura, float TempoMin){
    Atleta * atleta;
    atleta = (Atleta *)malloc(sizeof(Atleta));
    if (atleta != NULL){
        strcpy(atleta->nome, nome);
        atleta->idade = idade;
        atleta->altura = altura;
        atleta->TempoMin = TempoMin;

        return atleta;
    }
    return NULL;
}

int cmpAtleta(void * atleta1, void * atleta2){
    if (atleta1 != NULL && atleta2 != NULL){
        char * nome1 = ((Atleta*)atleta1)->nome;
        int idade1 = ((Atleta*)atleta1)->idade;
        float altura1 = ((Atleta*)atleta1)->altura;
        float TempoMin1 = ((Atleta*)atleta1)->TempoMin;

        char * nome2 = ((Atleta*)atleta2)->nome;
        int idade2 = ((Atleta*)atleta2)->idade;
        float altura2 = ((Atleta*)atleta2)->altura;
        float TempoMin2 = ((Atleta*)atleta2)->TempoMin;

        if( strcmp(nome1,nome2) == 0 && idade1 == idade2 && altura1 == altura2 && TempoMin1 == TempoMin2){
            return TRUE;
        }
    }
    return FALSE;
}

