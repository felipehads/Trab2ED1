#include "atleta.h"
#include "sll.h"
#include "sll.c"
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


void criarCampeonato(){
    if(camp == NULL){
        camp = SllCreate();
        printf("Campeonato criado!");
    } else {
        printf("Campeonato já criado");
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


void inserirAtleta(){
    int result = FALSE;
    if (camp == NULL){
        printf("Crie um campeonato primeiro!\n");
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

        result = SllInsert(camp, atleta);

        if (result == TRUE){
            printf("Atleta inserido na competição!\n\n");
        }
}


void removerAtleta(){
    void * result = NULL;
    if (camp == NULL){
        printf("Crie um campeonato e insira um atleta primeiro!\n");
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

        atleta = criarAtleta(nome, idade, altura, TempoMin);

        result = SllRemoveSpec(camp, atleta, cmpAtleta);

        if(result != NULL){
            printf("Atleta removido da competição!\n\n");
        }
}


void consultarAtleta(){
    void * result = NULL;
    if (camp == NULL){
        printf("Crie um campeonato e insira um atleta primeiro!\n");

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

        atleta = criarAtleta(nome,idade,altura,TempoMin);
        result = SllQuery(camp, atleta, cmpAtleta);

        if (result != NULL){
            printf("ATLETA ENCONTRADO!!\n");
            printf("NOME:%s\n", retornaNome(atleta));
            printf("IDADE:%d\n", retornaIdade(atleta));
            printf("ALTURA:%f\n", retornaAltura(atleta));
            printf("TEMPO MÍNIMO:%f\n", retornaTempoMin(atleta));
        }
        


}

void destruirCampeonato(){
    if (SllGetFirst(camp) != NULL){
        printf("Primeiro retire todos os atletas do campeonato!\n");
    } else {
        printf("O campeonato será destruido!!\n\n");
        if (SllDestroy(camp) == TRUE){
            printf("Campeonato destruído!!!\n");
        }
    }
}

void listarAtletas(){
    Atleta * atleta;
    if (camp != NULL){
        atleta = SllGetFirst(camp);
        while (atleta != NULL){
            printf("NOME: %s\n", retornaNome(atleta));
            printf("IDADE: %d\n", retornaIdade(atleta));
            printf("ALTURA: %f\n", retornaAltura(atleta));
            printf("TEMPO MÍNIMO: %f\n", retornaTempoMin(atleta));
            
            atleta = SllGetNext(camp);     
        }
    }
    if(camp == NULL){
        printf("Não há atletas!");
    }
}

char * retornaNome(Atleta * atleta){
    if (atleta != NULL){
        return atleta->nome;
    }
    return NULL;
};

int retornaIdade(Atleta * atleta){
    if(atleta != NULL){
        return atleta->idade;
    }
    return -1;
};

float retornaAltura(Atleta * atleta){
    if(atleta != NULL){
        return atleta->altura;
    }
    return -1;
};

float retornaTempoMin(Atleta * atleta){
    if(atleta != NULL){
        return atleta->TempoMin;
    }
    return -1;
};
