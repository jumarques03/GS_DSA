#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} Lista;

// Inicializa uma lista vazia
void inicializar(Lista* lista);

// Insere um valor em ordem crescente
void inserir(Lista* lista, int valor);

// Remove um elemento dado um valor (primeira ocorrência)
// Retorna 1 se removeu, 0 se não encontrou
int remover(Lista* lista, int valor);

// Busca um valor e retorna o ponteiro para o nó (ou NULL)
No* buscar(Lista* lista, int valor);

// Libera toda a memória da lista
void liberar(Lista* lista);

// Imprime a lista (auxiliar para debug)
void imprimir(Lista* lista);

#endif