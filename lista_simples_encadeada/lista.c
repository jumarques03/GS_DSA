#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar(Lista* lista) {
    lista->inicio = NULL;
}

void inserir(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;

    // Lista vazia ou inserir no início
    if (lista->inicio == NULL || lista->inicio->valor >= valor) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return;
    }

    // Encontrar posição correta
    No* atual = lista->inicio;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    // Inserir na posição
    novo->prox = atual->prox;
    atual->prox = novo;
}

int remover(Lista* lista, int valor) {
    if (lista->inicio == NULL) {
        return 0;
    }

    // Remover do início
    if (lista->inicio->valor == valor) {
        No* temp = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(temp);
        return 1;
    }

    // Procurar no restante da lista
    No* atual = lista->inicio;
    while (atual->prox != NULL && atual->prox->valor != valor) {
        atual = atual->prox;
    }

    // Valor não encontrado
    if (atual->prox == NULL) {
        return 0;
    }

    // Remover nó
    No* temp = atual->prox;
    atual->prox = temp->prox;
    free(temp);
    return 1;
}

No* buscar(Lista* lista, int valor) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void liberar(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
}

void imprimir(Lista* lista) {
    No* atual = lista->inicio;
    printf("[");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->prox != NULL) {
            printf(", ");
        }
        atual = atual->prox;
    }
    printf("]\n");
}