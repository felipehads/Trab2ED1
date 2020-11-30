#include "sll.h"
#include <stdio.h>

struct _SLNode_ {
    struct _SLNode_ *next;
    void * data;
} SLNode;

typedef struct _SLList_{
    SLNode *first;
    SLNode *cur;
}SLList;

//CRIA UMA LISTA
SLList *SllCreate(){
    SLList *l;
    //É ALOCADO UM SLLIST NA VARIÁVEL l
    l = (SLList *)malloc(sizeof(SLList));
    //É CHECADA A ALOCAÇÃO DE l
    if(l != NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}


int SllInsert(SLList *l, void * data){
    SLNode * newnode;
    if (l != NULL){
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL){
            newnode->data = data;
            if(l->first == NULL){
                newnode->next = NULL;
            } else {
                newnode->next = l->first;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}


void * SllRemoveSpec(SLList * l, void * key, int(*cmp)(void *, void *)){
    void * data;
    SLNode *spec, *prev;
    if (l != NULL){
        if(l->first != NULL){
            spec = l->first;
            prev = NULL;
            while (spec->next != NULL && cmp(key,spec->data) != TRUE){
                prev = spec;
                spec = spec->next;
            }
            if (cmp(key,spec->data) == TRUE){
                data = spec->data;
                if(spec == l->first){
                    l->first = spec->next;
                } else {
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

void * SllQuery(SLList *l, void * key, int(*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first != NULL){
            l->cur = l->first;
            while(l->cur != NULL && cmp(key,l->cur->data) != TRUE){
                l->cur = l->cur->next;
            }
            if(cmp(key, l->cur->data) == TRUE){
                return l->cur->data;
            }
        }
    }
    return NULL;
}

void * SllShow(SLList *l){
}

int SllDestroy(SLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}
