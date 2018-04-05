#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arvore.h"
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

int arv_altura(Arv_bin* arv){
    return arv_altura_no(arv->raiz);
}

int altura_maior(int alt_sae, int alt_sad){
    int maior;
    if(alt_sae>alt_sad){
        maior=alt_sae;
    } else {
        maior = alt_sad;
    }
    return maior;
    //return alt_sae>alt_sad ? alt_sae : alt_sad;
}

int arv_altura_no(Nodo* raiz){
    if(raiz == NULL)
        return -1;
    int alt_sae = 1 + arv_altura_no(raiz->esq);
    int alt_sad = 1 + arv_altura_no(raiz->dir);
    return altura_maior(alt_sae, alt_sad);
}
//Questão 3
int arv_tamanho(Arv_bin* arv){
    return arv_tamanho_no(arv->raiz)+1;
}

int arv_tamanho_no(Nodo* raiz){
    if(raiz == NULL)
        return -1;
    int nos_sae = 1 + arv_tamanho_no(raiz->esq);
    int nos_sad = 1 + arv_tamanho_no(raiz->dir);

    return nos_sae+nos_sad;
}
//Questão 9
int arv_bin_completa(Arv_bin* arv){
    int bin_completa;
    int tam_total;

    bin_completa = pow(2,arv_altura(arv))+1;
    tam_total = arv_tamanho(arv);

    if(bin_completa==tam_total)
        return 1;
    else
        return 0;

}
