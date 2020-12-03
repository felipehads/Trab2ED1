#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atleta.h"
#include "sll.h"
#include "atleta.c"

#define TRUE 1
#define FALSE 0

int main(void){
    int op = 0;


    printf("\n\t****************************\n");
    printf("\t*********Campeonato*********\n");
    printf("\t***Manipulacao de Atletas***\n");
    printf("\t****************************\n\n");

    printf("\t1 - Criar Campeonato.\n");
    printf("\t2 - Inserir Atleta.\n");
    printf("\t3 - Remover Atleta.\n");
    printf("\t4 - Consultar Atleta.\n");
    printf("\t5 - Listar Atletas.\n");
    printf("\t6 - Destruir campeonato.\n\n");

    printf("Digite a opcao:");
    scanf("%d", &op);


    switch(op){
        case 1:
            criarCampeonato();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            listarAtletas(camp);
            break;
        case 6:
            break;

        default:
        printf("\n\t****************************\n");
        printf("\tOPÇÃO INVÁLIDA!Tente Novamente!");
        printf("\n\t****************************\n");

    }


    return 0;

}
