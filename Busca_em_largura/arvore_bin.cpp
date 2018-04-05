#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arvore_bin.h"
#include <math.h>
#include <stack>

Arv_bin* cria_arv_binaria(Nodo* raiz){
    Arv_bin* arv = (Arv_bin*) malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}

Nodo* cria_no_arv(char c, Nodo* esq, Nodo* dir){
    Nodo * nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->info = c;
    nodo->dir = dir;
    nodo->esq = esq;
    return nodo;
}

void arv_libera(Arv_bin* arv){
    arv_libera_no(arv->raiz);
    free(arv);
}

void arv_libera_no(Nodo* raiz){
    if(raiz != NULL){
        arv_libera_no(raiz->esq);
        arv_libera_no(raiz->dir);
        free(raiz);
    }
}

int arv_pertence(Arv_bin* arv, char c){
    return arv_pertence_no(arv->raiz,c);
}

int arv_pertence_no(Nodo* raiz, char c){
    if(raiz == NULL){
        return 0;
    } else if(raiz->info == c){
        return 1;
    } else if(arv_pertence_no(raiz->esq,c)){
        return 1;
    } else {
        return arv_pertence_no(raiz->dir, c);
    }
    //return arv_pertence_no(raiz->esq,c)||
    //return arv_pertence_no(raiz->dir,c);
}

Nodo* arv_busca(Arv_bin* arv, char c){
    return arv_busca_no(arv->raiz,c);
}

Nodo* arv_busca_no(Nodo* raiz, char c){
    if(raiz==NULL)
        return NULL;
    else if(raiz->info == c)
        return raiz;
    else{
        Nodo *no = arv_busca_no(raiz->esq,c);
        if(no!=NULL)
            return no;
        else
            return arv_busca_no(raiz->dir, c);
    }

}
