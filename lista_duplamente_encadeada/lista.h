// ==================== lista.h ====================
#ifndef LISTA_H
#define LISTA_H

// Estrutura do nó da lista
typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

// Estrutura da lista
typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Lista;

// Funções da lista
void inicializar(Lista* lista);
void inserir_inicio(Lista* lista, int valor);
void inserir_fim(Lista* lista, int valor);
int remover_inicio(Lista* lista, int* valor);
int remover_fim(Lista* lista, int* valor);
void percorrer_frente(Lista* lista);
void percorrer_tras(Lista* lista);
int esta_vazia(Lista* lista);
int obter_tamanho(Lista* lista);
void liberar(Lista* lista);

#endif