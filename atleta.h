#ifndef ATLETA_H
#define ATLETA_H

#include "sll.h"
#define TRUE 1
#define FALSE 0


typedef struct _atleta_ Atleta;

SLList * criarCampeonato();
Atleta *criarAtleta(char nome[], int idade, float altura, float TempoMin);
int cmpAtleta(void * atleta1, void * atleta2);
void inserirAtleta();
void removerAtleta();
void consultarAtleta();
void destruirCampeonato();
void listarAtleta(SLList * camp);

char retornaNome(Atleta * atleta);
int retornaIdade(Atleta * atleta);
float retornaAltura(Atleta * atleta);
float retornaTempoMin(Atleta * atleta);



#endif
