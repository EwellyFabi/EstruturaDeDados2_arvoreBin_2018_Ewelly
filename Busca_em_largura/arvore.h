#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

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

void imprime_escolhendo_ordem(Arv_bin* arv, int ordem);
void imprime_pre_ordem(Nodo* raiz);
void imprime_infixa_ordem(Nodo* raiz);
void imprime_pos_ordem(Nodo* raiz);

void imprime_arv_formatando(Arv_bin* arv);
void imprime_arv_formatando_no(Nodo* raiz);

void arv_libera(Arv_bin* arv);
void arv_libera_no(Nodo* raiz);

int arv_pertence(Arv_bin* arv, char c);
int arv_pertence_no(Nodo* raiz, char c);

Nodo* arv_busca(Arv_bin* arv, char c);
Nodo* arv_busca_no(Nodo* raiz, char c);

int arv_altura(Arv_bin* arv);
int altura_maior(int alt_sae, int alt_sad);
int arv_altura_no(Nodo* raiz);

int tamanho(Arv_bin* arv);
int arv_tamanho_no(Nodo* raiz);

int arv_bin_completa(Arv_bin* arv);

#endif // ARVORE_H_INCLUDED
