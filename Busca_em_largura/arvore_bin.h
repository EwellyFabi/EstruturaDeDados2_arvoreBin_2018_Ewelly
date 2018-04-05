#ifndef ARVORE_BIN_H_INCLUDED
#define ARVORE_BIN_H_INCLUDED

typedef struct no{
    char info;
    struct no * esq;
    struct no * dir;
}Nodo;

typedef struct arv_bin{
    Nodo *raiz;
}Arv_bin;

Arv_bin* cria_arv_binaria(Nodo* raiz);
Nodo* cria_no_arv(char c, Nodo* esq, Nodo* dir);

void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);

int arv_pertence(Arv_bin* arv, char c);
int arv_pertence_no(Nodo* raiz, char c);

Nodo* arv_busca(Arv_bin* arv, char c);
Nodo* arv_busca_no(Nodo* raiz, char c);

#endif // ARVORE_BIN_H_INCLUDED
