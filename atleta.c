#include "atleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


SLList * camp = NULL;

typedef struct _atleta_{
    char nome[30];
    int idade;
    float altura;
    float TempoMin;
} Atleta;


SLList * criarCampeonato(){
    if(camp == NULL){
        camp = SllCreate();
        return camp;
    } else {
        printf("Campeonato já criado");
        return NULL;
    }
}

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


int inserirAtleta(){
    if (camp == NULL){
        printf("Crie um campeonato primeiro!\n");
        return FALSE;
    }
        char nome[30];
        int idade;
        float altura, TempoMin;
        Atleta * atleta;
        
        printf("Digite as informações do Atleta a ser inserido!\n");
        printf("Nome Completo:\n");
        fgets(nome, 30, stdin);

        printf("Idade:\n");
        scanf("%d", &idade);

        printf("Altura:\n");
        scanf("%f", &altura);
        
        printf("Menor Tempo:\n");
        scanf("%f", &TempoMin);

        atleta = criarAtleta(nome, idade, altura, TempoMin);

        SLLInsert(camp, atleta);

        return TRUE;
}


Atleta * removerAtleta(){
    if (camp == NULL){
        printf("Crie um campeonato e insira um atleta primeiro!\n");
        return FALSE;
    }
        char nome[30];
        int idade;
        float altura, TempoMin;
        Atleta * atleta;
        
        printf("Digite as informações do Atleta a ser removido!\n");
        printf("Nome Completo:\n");
        fgets(nome, 30, stdin);

        printf("Idade:\n");
        scanf("%d", &idade);

        printf("Altura:\n");
        scanf("%f", &altura);
        
        printf("Menor Tempo:\n");
        scanf("%f", &TempoMin);

        //atleta = SllRemoveSpec(camp, ) CHECAR A REMOÇÃO
}


Atleta * consultarAtleta(){
    if (camp == NULL){
        printf("Crie um campeonato e insira um atleta primeiro!\n");
        return FALSE;
    }
        char nome[30];
        int idade;
        float altura, TempoMin;
        Atleta * atleta;
        
        printf("Digite as informações do Atleta a ser consultado!\n");
        printf("Nome Completo:\n");
        fgets(nome, 30, stdin);

        printf("Idade:\n");
        scanf("%d", &idade);

        printf("Altura:\n");
        scanf("%f", &altura);
        
        printf("Menor Tempo:\n");
        scanf("%f", &TempoMin);

        //atleta = SllQuery(camp,) CHECAR A CONSULTA
}


//PARA LISTAR É NECESSÁRIO CONSTRUIR MÉTODOS GET PARA CONSEGUIR OS ATRIBUTOS DO TAD

//MÉTODO DESTROY É PADRÃO