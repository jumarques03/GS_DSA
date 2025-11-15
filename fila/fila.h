// ==================== fila.h ====================
#ifndef FILA_H
#define FILA_H

// Estrutura do nó da fila
typedef struct No {
    char nome[50];
    int id;
    struct No* proximo;
} No;

// Estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

// Funções da fila
void inicializar(Fila* fila);
int isEmpty(Fila* fila);
void enqueue(Fila* fila, const char* nome, int id);
No dequeue(Fila* fila);
No front(Fila* fila);
int tamanho_fila(Fila* fila);
void imprimir(Fila* fila);
void liberar(Fila* fila);

#endif