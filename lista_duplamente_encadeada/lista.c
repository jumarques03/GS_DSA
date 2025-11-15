// ==================== lista.c ====================
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Inicializa a lista
void inicializar(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// Insere um elemento no início
void inserir_inicio(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    
    novo->valor = valor;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    
    if (lista->inicio != NULL) {
        lista->inicio->anterior = novo;
    } else {
        // Lista estava vazia
        lista->fim = novo;
    }
    
    lista->inicio = novo;
    lista->tamanho++;
}

// Insere um elemento no final
void inserir_fim(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    
    if (lista->fim != NULL) {
        lista->fim->proximo = novo;
    } else {
        // Lista estava vazia
        lista->inicio = novo;
    }
    
    lista->fim = novo;
    lista->tamanho++;
}

// Remove um elemento do início
int remover_inicio(Lista* lista, int* valor) {
    if (lista->inicio == NULL) {
        return 0; // Lista vazia
    }
    
    No* temp = lista->inicio;
    *valor = temp->valor;
    
    lista->inicio = temp->proximo;
    
    if (lista->inicio != NULL) {
        lista->inicio->anterior = NULL;
    } else {
        // Lista ficou vazia
        lista->fim = NULL;
    }
    
    free(temp);
    lista->tamanho--;
    return 1;
}

// Remove um elemento do final
int remover_fim(Lista* lista, int* valor) {
    if (lista->fim == NULL) {
        return 0; // Lista vazia
    }
    
    No* temp = lista->fim;
    *valor = temp->valor;
    
    lista->fim = temp->anterior;
    
    if (lista->fim != NULL) {
        lista->fim->proximo = NULL;
    } else {
        // Lista ficou vazia
        lista->inicio = NULL;
    }
    
    free(temp);
    lista->tamanho--;
    return 1;
}

// Percorre a lista da frente para trás (head → tail)
void percorrer_frente(Lista* lista) {
    No* atual = lista->inicio;
    
    printf("Lista (inicio -> fim): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Percorre a lista de trás para frente (tail → head)
void percorrer_tras(Lista* lista) {
    No* atual = lista->fim;
    
    printf("Lista (fim -> inicio): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

// Verifica se a lista está vazia
int esta_vazia(Lista* lista) {
    return lista->inicio == NULL;
}

// Retorna o tamanho da lista
int obter_tamanho(Lista* lista) {
    return lista->tamanho;
}

// Libera toda a memória da lista
void liberar(Lista* lista) {
    No* atual = lista->inicio;
    No* temp;
    
    while (atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}