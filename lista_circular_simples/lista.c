// ========== lista.c ==========
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar(ListaCircular* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserir(ListaCircular* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    
    novo->valor = valor;
    
    if (lista->inicio == NULL) {
        // Primeira inserção
        novo->proximo = novo;
        lista->inicio = novo;
    } else {
        // Inserir no final (antes do início)
        No* ultimo = lista->inicio;
        while (ultimo->proximo != lista->inicio) {
            ultimo = ultimo->proximo;
        }
        novo->proximo = lista->inicio;
        ultimo->proximo = novo;
    }
    
    lista->tamanho++;
}

void imprimir(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    No* atual = lista->inicio;
    printf("Lista Circular: ");
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != lista->inicio);
    printf("-> (volta ao inicio)\n");
}

No* avancar_k_posicoes(ListaCircular* lista, No* no_atual, int k) {
    if (lista->inicio == NULL || no_atual == NULL) {
        return NULL;
    }
    
    No* atual = no_atual;
    for (int i = 0; i < k; i++) {
        atual = atual->proximo;
    }
    
    return atual;
}

int remover_no(ListaCircular* lista, int valor) {
    if (lista->inicio == NULL) {
        return 0; // Lista vazia
    }
    
    No* atual = lista->inicio;
    No* anterior = NULL;
    
    // Encontrar o último nó (para caso especial)
    No* ultimo = lista->inicio;
    while (ultimo->proximo != lista->inicio) {
        ultimo = ultimo->proximo;
    }
    
    // Procurar o nó a ser removido
    do {
        if (atual->valor == valor) {
            // Nó encontrado
            if (atual == lista->inicio) {
                // Remover o início
                if (atual->proximo == lista->inicio) {
                    // Único elemento
                    free(atual);
                    lista->inicio = NULL;
                } else {
                    // Múltiplos elementos
                    ultimo->proximo = atual->proximo;
                    lista->inicio = atual->proximo;
                    free(atual);
                }
            } else {
                // Remover nó intermediário ou final
                anterior->proximo = atual->proximo;
                free(atual);
            }
            lista->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != lista->inicio);
    
    return 0; // Valor não encontrado
}

int esta_vazia(ListaCircular* lista) {
    return lista->inicio == NULL;
}

int obter_tamanho(ListaCircular* lista) {
    return lista->tamanho;
}

void liberar(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        return;
    }
    
    No* atual = lista->inicio;
    No* temp;
    
    do {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    } while (atual != lista->inicio);
    
    lista->inicio = NULL;
    lista->tamanho = 0;
}