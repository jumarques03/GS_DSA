// ==================== fila.c ====================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Inicializa a fila
void inicializar(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

// Verifica se a fila está vazia
int isEmpty(Fila* fila) {
    return fila->inicio == NULL;
}

// Insere um elemento no final da fila (enqueue)
void enqueue(Fila* fila, const char* nome, int id) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    strncpy(novo->nome, nome, 49);
    novo->nome[49] = '\0';
    novo->id = id;
    novo->proximo = NULL;
    
    if (isEmpty(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    
    fila->tamanho++;
}

// Remove e retorna o elemento do início da fila (dequeue)
No dequeue(Fila* fila) {
    No resultado;
    resultado.id = -1;
    strcpy(resultado.nome, "");
    resultado.proximo = NULL;
    
    if (isEmpty(fila)) {
        printf("Erro: Fila vazia!\n");
        return resultado;
    }
    
    No* temp = fila->inicio;
    resultado.id = temp->id;
    strncpy(resultado.nome, temp->nome, 49);
    resultado.nome[49] = '\0';
    
    fila->inicio = temp->proximo;
    
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(temp);
    fila->tamanho--;
    
    return resultado;
}

// Retorna o elemento do início sem remover (front)
No front(Fila* fila) {
    No resultado;
    resultado.id = -1;
    strcpy(resultado.nome, "");
    resultado.proximo = NULL;
    
    if (isEmpty(fila)) {
        printf("Erro: Fila vazia!\n");
        return resultado;
    }
    
    resultado.id = fila->inicio->id;
    strncpy(resultado.nome, fila->inicio->nome, 49);
    resultado.nome[49] = '\0';
    
    return resultado;
}

// Retorna o tamanho da fila
int tamanho_fila(Fila* fila) {
    return fila->tamanho;
}

// Imprime a fila (do início ao fim)
void imprimir(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia\n");
        return;
    }
    
    No* atual = fila->inicio;
    printf("Fila (início -> fim):\n");
    
    int posicao = 1;
    while (atual != NULL) {
        printf("  %d. [ID: %d] %s\n", posicao, atual->id, atual->nome);
        atual = atual->proximo;
        posicao++;
    }
}

// Libera toda a memória da fila
void liberar(Fila* fila) {
    while (!isEmpty(fila)) {
        dequeue(fila);
    }
}