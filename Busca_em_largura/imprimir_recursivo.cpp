#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "imprimir_recursivo.h"

void imprime_escolhendo_ordem(Arv_bin* arv, int ordem){
    if(ordem==1)
        imprime_pre_ordem(arv->raiz);
    else if(ordem==2)
        imprime_infixa_ordem(arv->raiz);
    else if(ordem==3)
        imprime_pos_ordem(arv->raiz);
    else
        printf("Valor invalido, Escolha um valor entre 1 e 3\n");
    printf("\n");
}

void imprime_pre_ordem(Nodo* raiz){
    if(raiz!=NULL){
        printf("%c ", raiz->info);
        imprime_pre_ordem(raiz->esq);
        imprime_pre_ordem(raiz->dir);
    }
}

void imprime_infixa_ordem(Nodo* raiz){
    if(raiz!=NULL){
        imprime_infixa_ordem(raiz->esq);
        printf("%c ",raiz->info);
        imprime_infixa_ordem(raiz->dir);
    }
}

void imprime_pos_ordem(Nodo* raiz){
    if(raiz!=NULL){
        imprime_pos_ordem(raiz->esq);
        imprime_pos_ordem(raiz->dir);
        printf("%c ", raiz->info);
    }
}

void imprime_arv_formatando(Arv_bin* arv){
    imprime_arv_formatando_no(arv->raiz);
    printf("\n");
}

void imprime_arv_formatando_no(Nodo* raiz){
    printf("<");
    if(raiz!=NULL){
        printf("%c",raiz->info);
        imprime_arv_formatando_no(raiz->esq);
        imprime_arv_formatando_no(raiz->dir);
    }
    printf(">");
}
