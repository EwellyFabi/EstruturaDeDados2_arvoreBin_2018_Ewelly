#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "arvore_bin.h"
#include "bfs.h"
#include <queue>

using namespace std;
/*
          #####BUSCA EM LARGURA#####
Fun��o que imprime os nodos da arvore por n�veis
*/
void bfs (Arv_bin *arv){
    queue <Nodo *> fila;
    Nodo *p = NULL;

    fila.push(arv->raiz);

    printf("Imprime usando busca em largura: ");

    while(!fila.empty()){
        p = fila.front();
        printf("%c\t", p->info);
        fila.pop();
        if(p->esq != NULL)
            fila.push(p->esq);
        if(p->dir != NULL)
            fila.push(p->dir);

    }
    printf("\n");
}
