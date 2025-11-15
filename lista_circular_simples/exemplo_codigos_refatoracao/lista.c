// ========== lista.c ==========
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar(ListaCircular* lista) {
    lista->fim = NULL;  
    lista->tamanho = 0;
}

void inserir(ListaCircular* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    
    novo->valor = valor;
    
    if (lista->fim == NULL) {
        // Primeira inserção - lista vazia
        novo->proximo = novo;  // Aponta para si mesmo
        lista->fim = novo;
    } else {
        // Inserir no final - O(1)
        novo->proximo = lista->fim->proximo;  // Novo nó aponta para o início
        lista->fim->proximo = novo;  // Antigo fim aponta para o novo nó
        lista->fim = novo;  // Atualiza o ponteiro do fim
    }
    
    lista->tamanho++;
}

void imprimir(ListaCircular* lista) {
    if (lista->fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    No* inicio = lista->fim->proximo;  // O início é o próximo do fim
    No* atual = inicio;
    printf("Lista Circular: ");
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != inicio);
    printf("-> (volta ao inicio)\n");
}

No* avancar_k_posicoes(ListaCircular* lista, No* no_atual, int k) {
    if (lista->fim == NULL || no_atual == NULL) {
        return NULL;
    }
    
    No* atual = no_atual;
    for (int i = 0; i < k; i++) {
        atual = atual->proximo;
    }
    
    return atual;
}

int remover_no(ListaCircular* lista, int valor) {
    if (lista->fim == NULL) {
        return 0; // Lista vazia
    }
    
    No* inicio = lista->fim->proximo;
    No* atual = inicio;
    No* anterior = lista->fim;
    
    // Procurar o nó a ser removido
    do {
        if (atual->valor == valor) {
            // Nó encontrado
            if (atual == lista->fim && atual->proximo == lista->fim) {
                // Único elemento na lista
                free(atual);
                lista->fim = NULL;
            } else {
                // Múltiplos elementos
                anterior->proximo = atual->proximo;
                
                // Se remover o último nó, atualizar o ponteiro fim
                if (atual == lista->fim) {
                    lista->fim = anterior;
                }
                
                free(atual);
            }
            lista->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != inicio);
    
    return 0; // Valor não encontrado
}

int esta_vazia(ListaCircular* lista) {
    return lista->fim == NULL;
}

int obter_tamanho(ListaCircular* lista) {
    return lista->tamanho;
}

void liberar(ListaCircular* lista) {
    if (lista->fim == NULL) {
        return;
    }
    
    No* inicio = lista->fim->proximo;
    No* atual = inicio;
    No* temp;
    
    do {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    } while (atual != inicio);
    
    lista->fim = NULL;
    lista->tamanho = 0;
}