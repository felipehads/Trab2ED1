#ifndef ATLETA_H
#define ATLETA_H

#define TRUE 1
#define FALSE 0


typedef struct _atleta_ Atleta;


Atleta *criarAtleta(char nome[], int idade, float altura, float TempoMin);
int cmpAtleta(void * atleta1, void * atleta2);


char * pegarNome(Atleta * atleta);
int pegarIdade(Atleta * atleta);
float pegarAltura(Atleta * atleta);
float pegarTempoMin(Atleta * atleta);

#endif
