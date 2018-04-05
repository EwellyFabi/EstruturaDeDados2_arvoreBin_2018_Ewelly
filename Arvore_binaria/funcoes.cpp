#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "funcoes.h"
#include <stack>

//chama funcao para saber a altura da arvore passando por parametro o nodo raiz
int arv_altura(Arv_bin* arv){
    return arv_altura_no(arv->raiz);
}
//recebe dois valores e retorna o maior entre eles
int altura_maior(int alt_sae, int alt_sad){
    int maior;
    if(alt_sae>alt_sad){
        maior=alt_sae;
    } else {
        maior = alt_sad;
    }
    return maior;
}
//calcula recursivamente a altura de uma arvore binaria
int arv_altura_no(Nodo* raiz){
    if(raiz == NULL)
        return -1;
    int alt_sae = 1 + arv_altura_no(raiz->esq);
    int alt_sad = 1 + arv_altura_no(raiz->dir);
    //compara a altura da sub-arvore direita com a da sub-arvore esquerda e retorna a maior
    return altura_maior(alt_sae, alt_sad);
}
//chama funcao para saber a quantidade de nos da arvore passando por parametro o raiz da arvore
int arv_tamanho(Arv_bin* arv){
    return arv_tamanho_no(arv->raiz)+1;
}
//soma a quantidade de nos que a arvore possui
int arv_tamanho_no(Nodo* raiz){
    if(raiz == NULL)
        return -1;
    int nos_sae = 1 + arv_tamanho_no(raiz->esq);
    int nos_sad = 1 + arv_tamanho_no(raiz->dir);
    //retorna a soma os nodos da direita e da esquerta
    return nos_sae+nos_sad;
}
//Verifica se a arvore eh binaria completa
int arv_bin_completa(Arv_bin* arv){
    int bin_completa;
    int tam_total;
//calcula a quantidade de nodos que a arvore dever ter para ser binaria completa
    bin_completa = pow(2,arv_altura(arv))+1;
    tam_total = arv_tamanho(arv);

    if(bin_completa==tam_total)
        return 1;
    else
        return 0;
}
//chama funcao para saber se a arvore eh extritamente binaria
int arv_bin_estritamente(Arv_bin* arv){
    return arv_bin_estritamente_no(arv->raiz);
}

int arv_bin_estritamente_no(Nodo* raiz){
//caso baso, retorna 1 sempre que tiver um nodo com valor NULL
    if(raiz == NULL)
        return 1;
//calcula a diferença entre o nodo direito e do nodo esquerdo
    int dif = arv_bin_estritamente_no(raiz->esq) - arv_bin_estritamente_no(raiz->dir);
//eh retornado o resultado da diferença dos dois nodos
    if(dif==0){
        return 0;
    }
    return dif;
}
//chama funcao para saber o numero de folhas da arvore binaria
int arv_numero_folhas(Arv_bin* arv){
    return arv_numero_folhas_no(arv->raiz);
}
//calcula o numero de folhas da arvore binaria
int arv_numero_folhas_no(Nodo* raiz){
//declara uma variavel estatica para salvar o valor total das folhas da arvore
    static int num_total = 0;
//soma 1 sempre que tiver uma raiz com valor nulo
    if(raiz == NULL)
        return num_total+1;
//soma as folhas da direita e esquerda
    num_total = arv_tamanho_no(raiz->esq)+arv_tamanho_no(raiz->dir);

    return num_total;
}

void arv_espelho(Arv_bin* arv_original, Arv_bin* arv_copia){
    arv_espelho_no(arv_original->raiz, arv_copia->raiz);
}

void arv_espelho_no(Nodo* original, Nodo* copia){
//copia a informacao do nodo da arvore original no nodo da arvore espelho
    copia->info = original->info;

    if (original->dir != NULL) {
        Nodo *novo = cria_no_arv(' ' , NULL , NULL); //cria um no folha
        copia->esq = novo; //o novo no eh apontado como sub-arvore a esquerda do no copia
        arv_espelho_no(original->dir , copia->esq);
    }
    if (original->esq != NULL) {
        Nodo *novo = cria_no_arv(' ' , NULL , NULL); //cria um no folha
        copia->dir = novo; //o novo no eh apontado como sub-arvore a direita do no copia
        arv_espelho_no(original->esq , copia->dir);
    }
}
