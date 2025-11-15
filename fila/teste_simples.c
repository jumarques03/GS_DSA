// ==================== teste_simples.c ====================
#include <stdio.h>
#include "fila.h"

void simular_atendimento() {
    Fila fila;
    inicializar(&fila);
    
    printf("=== SIMULACAO DE ATENDIMENTO DE CLIENTES ===\n\n");
    
    // Clientes chegando
    printf("--- Clientes Chegando ---\n");
    enqueue(&fila, "João Silva", 101);
    printf("Cliente chegou: Joao Silva (ID: 101)\n");
    
    enqueue(&fila, "Maria Santos", 102);
    printf("Cliente chegou: Maria Santos (ID: 102)\n");
    
    enqueue(&fila, "Pedro Costa", 103);
    printf("Cliente chegou: Pedro Costa (ID: 103)\n");
    
    enqueue(&fila, "Ana Oliveira", 104);
    printf("Cliente chegou: Ana Oliveira (ID: 104)\n");
    
    printf("\n");
    imprimir(&fila);
    printf("\nTotal de clientes na fila: %d\n", tamanho_fila(&fila));
    
    // Atendendo clientes
    printf("\n--- Atendimento (FIFO) ---\n");
    
    No proximo = front(&fila);
    printf("\nProximo a ser atendido: %s (ID: %d)\n", proximo.nome, proximo.id);
    
    No atendido = dequeue(&fila);
    printf("Atendendo: %s (ID: %d)\n", atendido.nome, atendido.id);
    printf("Clientes restantes: %d\n", tamanho_fila(&fila));
    
    atendido = dequeue(&fila);
    printf("\nAtendendo: %s (ID: %d)\n", atendido.nome, atendido.id);
    printf("Clientes restantes: %d\n", tamanho_fila(&fila));
    
    // Mais clientes chegando
    printf("\n--- Mais Clientes Chegando ---\n");
    enqueue(&fila, "Carlos Mendes", 105);
    printf("Cliente chegou: Carlos Mendes (ID: 105)\n");
    
    printf("\n");
    imprimir(&fila);
    
    // Atendendo todos os restantes
    printf("\n--- Atendendo Clientes Restantes ---\n");
    while (!isEmpty(&fila)) {
        atendido = dequeue(&fila);
        printf("Atendendo: %s (ID: %d)\n", atendido.nome, atendido.id);
    }
    
    printf("\nFila vazia? %s\n", isEmpty(&fila) ? "Sim" : "Nao");
    
    liberar(&fila);
}

int main() {
    simular_atendimento();
    return 0;
}