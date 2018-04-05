#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arvore_bin.h"
#include "imprimir_iterativo.h"
#include <stack>

using namespace std;

void imprime_pre_ordem_iterativo(Arv_bin *arv){
    imprime_pre_ordem_iterativo_no(arv->raiz);
}

void imprime_pre_ordem_iterativo_no(Nodo* raiz){
    stack<Nodo *> pilha;
    Nodo *p = NULL;

    printf("Pre-ordem iterativo: ");
    pilha.push(raiz);

    while(!pilha.empty()){
        p = pilha.top();
        printf("%c\t", p->info);
        pilha.pop();
        if(p->dir!=NULL)
            pilha.push(p->dir);
        if(p->esq!=NULL)
            pilha.push(p->esq);
    }
    printf("\n");
}

void imprime_in_ordem_iterativo(Arv_bin* arv){
    imprime_in_ordem_iterativo_no(arv->raiz);
}

void imprime_in_ordem_iterativo_no(Nodo* raiz){
    stack<Nodo *> pilha;
    Nodo *p = raiz;

    printf("In-ordem iterativo: ");

    while (p || !pilha.empty()) {

        if (p != NULL){
            pilha.push(p);
            p = p->esq;
        } else {
            p = pilha.top();
            printf("%c\t",p->info);
            pilha.pop();
            p = p->dir;
        }
    }

    printf("\n");
}


/*
void imprime_in_ordem_iterativo_no(Nodo* raiz){
    stack<Nodo *> pilha;
    Nodo *p = arv->raiz;

    printf("In-ordem iterativo: ");

    while (p != NULL) {
        while(p != NULL) {
            if (p->dir != NULL)
                pilha.push(p->dir);
            pilha.push(p);
            p = p->esq;
        }
        p = pilha.top();
        pilha.pop();

        while (!pilha.empty() && p->dir == NULL) {
            printf("%c\t",p->info);
            p = pilha.top();
            pilha.pop();
        }
        printf("%c\t",p->info);
        if (!pilha.empty()){
            p = pilha.top();
            pilha.pop();
        } else{
            p = NULL;
        }
    }

    printf("\n");
}

*/

void imprime_pos_ordem_iterativo(Arv_bin *arv){
    imprime_pos_ordem_iterativo_no(arv->raiz);
}

void imprime_pos_ordem_iterativo_no(Nodo *raiz){
    stack <Nodo *> pilha;
    stack <Nodo *> pilha_aux;
    Nodo *p = NULL;
    Nodo *q = NULL;

    printf("Pos-ordem iterativo: ");
    pilha.push(raiz);

    while(!pilha.empty()){
        p = pilha.top();
        pilha_aux.push(p);
        pilha.pop();

        if(p->esq!=NULL){
            pilha.push(p->esq);
        }
        if(p->dir!=NULL){
            pilha.push(p->dir);
        }
    }

    while(!pilha_aux.empty()){
        q = pilha_aux.top();
        printf("%c\t", q->info);
        pilha_aux.pop();
    }
    printf("\n");

}
/*
void imprime_pos_ordem_iterativo_no(Nodo *raiz){
    stack <Nodo *> pilha;
    Nodo *p = NULL;
    Nodo *ant = arv->raiz;

    printf("Pos-ordem iterativo: ");
    pilha.push(arv->raiz);

    while(!pilha.empty()){
        p = pilha.top();

        if(p->dir != ant){
            if(p->dir!=NULL){
                pilha.push(p->dir);
            }
            if(p->esq!=NULL){
                pilha.push(p->esq);
            }
            if(p->dir!=NULL || p->esq!=NULL){
                continue;
            }
        }
        printf("%c\t", p->info);
        ant = p;
        pilha.pop();
    }
    printf("\n");
}

*/
