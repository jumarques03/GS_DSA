// ==================== pilha.h ====================
#ifndef PILHA_H
#define PILHA_H

// Estrutura do nó da pilha
typedef struct No {
    char valor;
    struct No* proximo;
} No;

// Estrutura da pilha
typedef struct {
    No* topo;
    int tamanho;
} Pilha;

// Funções da pilha
void inicializar(Pilha* pilha);
void push(Pilha* pilha, char valor);
char pop(Pilha* pilha);
char top(Pilha* pilha);
int isEmpty(Pilha* pilha);
void liberar(Pilha* pilha);
int tamanho(Pilha* pilha);

// Função para verificar expressão balanceada
int expressao_balanceada(const char* expressao);

#endif