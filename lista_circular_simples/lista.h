// ========== lista.h ==========
#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} ListaCircular;

// Funções básicas
void inicializar(ListaCircular* lista);
void inserir(ListaCircular* lista, int valor);
void imprimir(ListaCircular* lista);
void liberar(ListaCircular* lista);
int esta_vazia(ListaCircular* lista);
int obter_tamanho(ListaCircular* lista);

// Funções específicas
No* avancar_k_posicoes(ListaCircular* lista, No* no_atual, int k);
int remover_no(ListaCircular* lista, int valor);

#endif