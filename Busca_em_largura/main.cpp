#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "bfs.cpp"
#include "arvore_bin.cpp"
#include "funcoes.cpp"
#include "imprimir_iterativo.cpp"
#include "imprimir_recursivo.cpp"
#include <queue>
#include <stack>

using namespace std;

int main(){
//Criar a arvore binaria
    Arv_bin *arv = cria_arv_binaria(
                        cria_no_arv('a',
                            cria_no_arv('b', NULL,
                                cria_no_arv('d', NULL, NULL)
                            ),
                            cria_no_arv('c',
                                cria_no_arv('e', NULL, NULL),
                                cria_no_arv('f', NULL, NULL)
                            )
                        )
                    );
//formas de imprimir recursivamente
    imprime_escolhendo_ordem(arv, 1);
    imprime_escolhendo_ordem(arv, 2);
    imprime_escolhendo_ordem(arv, 3);
    imprime_arv_formatando(arv);

    if(!(arv_pertence(arv, 'm')))
        printf("Nao pertece a arvore\n");
    else
        printf("Pertence a arvore\n");

    Nodo *n = arv_busca(arv, 'f');
    if(n!=NULL)
        printf("Nodo encontrado: %c\n", n->info);


    printf("Altura da arvore: %d\n", arv_altura(arv));

    printf("Numero de nos da arvore: %d\n", arv_tamanho(arv));

    if(arv_bin_completa(arv)==1)
        printf("Arvore completa\n");
    else
        printf("Arvore nao eh completa\n");

    bfs(arv);

    imprime_pre_ordem_iterativo(arv);
    imprime_in_ordem_iterativo(arv);
    imprime_pos_ordem_iterativo(arv);

    printf("Numero de folhas: %d\n", arv_numero_folhas(arv));

    if(arv_bin_estritamente(arv)==0){
        printf("A arvore eh extritamente binaria");
    } else {
        printf("A arvore nao eh extritamente binaria");
    }

    arv_libera(arv);

    return 0;
}
