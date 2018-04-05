#ifndef IMPRIMIR_RECURSIVO_H_INCLUDED
#define IMPRIMIR_RECURSIVO_H_INCLUDED

void imprime_escolhendo_ordem(Arv_bin* arv, int ordem);
void imprime_pre_ordem(Nodo* raiz);
void imprime_infixa_ordem(Nodo* raiz);
void imprime_pos_ordem(Nodo* raiz);

void imprime_arv_formatando(Arv_bin* arv);
void imprime_arv_formatando_no(Nodo* raiz);

#endif // IMPRIMIR_RECURSIVO_H_INCLUDED
