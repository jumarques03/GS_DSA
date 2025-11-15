// ==================== teste_borda.c ====================
#include <stdio.h>
#include <string.h>
#include "fila.h"

void testar_fila_vazia() {
    printf("=== TESTE: Fila Vazia ===\n");
    Fila fila;
    inicializar(&fila);
    
    printf("Fila criada.\n");
    printf("isEmpty? %s\n", isEmpty(&fila) ? "Sim" : "Nao");
    printf("Tamanho: %d\n", tamanho_fila(&fila));
    
    printf("\nTentando dequeue em fila vazia:\n");
    No resultado = dequeue(&fila);
    if (resultado.id == -1) {
        printf("Retornou corretamente ID invalido (-1)\n");
    }
    
    printf("\nTentando front em fila vazia:\n");
    resultado = front(&fila);
    if (resultado.id == -1) {
        printf("Retornou corretamente ID invalido (-1)\n");
    }
    
    liberar(&fila);
    printf("\n");
}

void testar_um_elemento() {
    printf("=== TESTE: Um Unico Elemento ===\n");
    Fila fila;
    inicializar(&fila);
    
    enqueue(&fila, "Unico Cliente", 1);
    printf("Enqueue: Unico Cliente (ID: 1)\n");
    imprimir(&fila);
    
    printf("\nFront:\n");
    No frente = front(&fila);
    printf("ID: %d, Nome: %s\n", frente.id, frente.nome);
    printf("Tamanho apos front: %d\n", tamanho_fila(&fila));
    
    printf("\nDequeue:\n");
    No removido = dequeue(&fila);
    printf("Removido - ID: %d, Nome: %s\n", removido.id, removido.nome);
    
    printf("\nFila vazia? %s\n", isEmpty(&fila) ? "Sim" : "Nao");
    printf("Tamanho: %d\n", tamanho_fila(&fila));
    
    liberar(&fila);
    printf("\n");
}

void testar_enqueue_dequeue_alternado() {
    printf("=== TESTE: Enqueue/Dequeue Alternado ===\n");
    Fila fila;
    inicializar(&fila);
    
    printf("Enqueue: Cliente A\n");
    enqueue(&fila, "Cliente A", 1);
    
    printf("Dequeue: ");
    No removido = dequeue(&fila);
    printf("%s\n", removido.nome);
    
    printf("Enqueue: Cliente B\n");
    enqueue(&fila, "Cliente B", 2);
    
    printf("Enqueue: Cliente C\n");
    enqueue(&fila, "Cliente C", 3);
    
    printf("Dequeue: ");
    removido = dequeue(&fila);
    printf("%s\n", removido.nome);
    
    printf("Enqueue: Cliente D\n");
    enqueue(&fila, "Cliente D", 4);
    
    printf("\nFila final:\n");
    imprimir(&fila);
    
    liberar(&fila);
    printf("\n");
}

void testar_multiplos_enqueue_dequeue() {
    printf("=== TESTE: Multiplos Enqueue seguidos de Multiplos Dequeue ===\n");
    Fila fila;
    inicializar(&fila);
    
    printf("Adicionando 5 clientes...\n");
    for (int i = 1; i <= 5; i++) {
        char nome[50];
        sprintf(nome, "Cliente %d", i);
        enqueue(&fila, nome, i);
    }
    
    imprimir(&fila);
    printf("Tamanho: %d\n", tamanho_fila(&fila));
    
    printf("\nRemovendo todos os clientes:\n");
    while (!isEmpty(&fila)) {
        No removido = dequeue(&fila);
        printf("Removido: %s (ID: %d), Restantes: %d\n", 
               removido.nome, removido.id, tamanho_fila(&fila));
    }
    
    printf("\nFila vazia? %s\n", isEmpty(&fila) ? "Sim" : "Nao");
    
    liberar(&fila);
    printf("\n");
}

void testar_nome_longo() {
    printf("=== TESTE: Nome Muito Longo ===\n");
    Fila fila;
    inicializar(&fila);
    
    char nome_longo[100];
    for (int i = 0; i < 99; i++) {
        nome_longo[i] = 'A';
    }
    nome_longo[99] = '\0';
    
    enqueue(&fila, nome_longo, 999);
    printf("Enqueue com nome de 99 caracteres\n");
    
    No frente = front(&fila);
    printf("Nome armazenado (primeiros 49 caracteres + \\0): %s\n", frente.nome);
    printf("Tamanho do nome armazenado: %lu\n", strlen(frente.nome));
    
    liberar(&fila);
    printf("\n");
}

int main() {
    printf("========================================\n");
    printf("  TESTES DE BORDA - FILA (QUEUE)\n");
    printf("========================================\n\n");
    
    testar_fila_vazia();
    testar_um_elemento();
    testar_enqueue_dequeue_alternado();
    testar_multiplos_enqueue_dequeue();
    testar_nome_longo();
    
    printf("========================================\n");
    printf("  TODOS OS TESTES CONCLUIDOS\n");
    printf("========================================\n");
    
    return 0;
}