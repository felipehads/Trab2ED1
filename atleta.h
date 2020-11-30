#ifndef ATLETA_H
#define ATLETA_H

#include "sll.h"
#define TRUE 1
#define FALSE 0


typedef struct _atleta_ Atleta;

SLList * criarCampeonato();
int InserirAtleta();
Atleta * removerAtleta();
Atleta * consultarAtleta();

Atleta *criarAtleta(char nome[], int idade, float altura, float TempoMin);
int cmpAtleta(void * atleta1, void * atleta2);



#endif
