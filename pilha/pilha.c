// ==================== pilha.c ====================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// Inicializa a pilha
void inicializar(Pilha* pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

// Insere um elemento no topo da pilha
void push(Pilha* pilha, char valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    
    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

// Remove e retorna o elemento do topo
char pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return '\0';
    }
    
    No* temp = pilha->topo;
    char valor = temp->valor;
    pilha->topo = temp->proximo;
    free(temp);
    pilha->tamanho--;
    
    return valor;
}

// Retorna o elemento do topo sem remover
char top(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return '\0';
    }
    
    return pilha->topo->valor;
}

// Verifica se a pilha está vazia
int isEmpty(Pilha* pilha) {
    return pilha->topo == NULL;
}

// Retorna o tamanho da pilha
int tamanho(Pilha* pilha) {
    return pilha->tamanho;
}

// Libera toda a memória da pilha
void liberar(Pilha* pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}

// Verifica se um caractere é um delimitador de abertura
int eh_abertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

// Verifica se um caractere é um delimitador de fechamento
int eh_fechamento(char c) {
    return c == ')' || c == ']' || c == '}';
}

// Verifica se os delimitadores correspondem
int correspondem(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

// Verifica se uma expressão com parênteses está balanceada
int expressao_balanceada(const char* expressao) {
    Pilha pilha;
    inicializar(&pilha);
    
    int len = strlen(expressao);
    
    for (int i = 0; i < len; i++) {
        char c = expressao[i];
        
        if (eh_abertura(c)) {
            push(&pilha, c);
        } else if (eh_fechamento(c)) {
            if (isEmpty(&pilha)) {
                liberar(&pilha);
                return 0; // Fechamento sem abertura correspondente
            }
            
            char topo = pop(&pilha);
            if (!correspondem(topo, c)) {
                liberar(&pilha);
                return 0; // Delimitadores não correspondem
            }
        }
    }
    
    int balanceada = isEmpty(&pilha);
    liberar(&pilha);
    
    return balanceada;
}