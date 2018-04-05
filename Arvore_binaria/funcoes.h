#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

int arv_altura(Arv_bin* arv);
int altura_maior(int alt_sae, int alt_sad);
int arv_altura_no(Nodo* raiz);

int tamanho(Arv_bin* arv);
int arv_tamanho_no(Nodo* raiz);

int arv_bin_completa(Arv_bin* arv);

int arv_bin_estritamente(Arv_bin* arv);
int arv_bin_estritamente_no(Nodo* raiz);

int arv_numero_folhas(Arv_bin* arv);
int arv_numero_folhas_no(Nodo* raiz);

void arv_espelho(Arv_bin* arv_original, Arv_bin* arv_copia);
void arv_espelho_no(Nodo* original, Nodo* copia);

#endif // FUNCOES_H_INCLUDED
