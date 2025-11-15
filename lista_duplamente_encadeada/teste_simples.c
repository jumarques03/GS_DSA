// ==================== teste_simples.c ====================
#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista;
    int valor;
    
    printf("=== TESTES SIMPLES ===\n\n");
    
    // Teste 1: Inicialização
    printf("Teste 1: Inicializacao\n");
    inicializar(&lista);
    printf("Lista criada. Tamanho: %d\n", obter_tamanho(&lista));
    printf("Lista vazia? %s\n\n", esta_vazia(&lista) ? "Sim" : "Não");
    
    // Teste 2: Inserção no início
    printf("Teste 2: Insercao no inicio (3, 2, 1)\n");
    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 1);
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    // Teste 3: Inserção no final
    printf("Teste 3: Insercao no final (4, 5, 6)\n");
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 6);
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    // Teste 4: Remoção do início
    printf("Teste 4: Remocao do inicio (2 vezes)\n");
    if (remover_inicio(&lista, &valor)) {
        printf("Removido: %d\n", valor);
    }
    if (remover_inicio(&lista, &valor)) {
        printf("Removido: %d\n", valor);
    }
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    // Teste 5: Remoção do final
    printf("Teste 5: Remocao do final (2 vezes)\n");
    if (remover_fim(&lista, &valor)) {
        printf("Removido: %d\n", valor);
    }
    if (remover_fim(&lista, &valor)) {
        printf("Removido: %d\n", valor);
    }
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    // Teste 6: Operações mistas
    printf("Teste 6: Operacoes mistas\n");
    inserir_inicio(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 25);
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    liberar(&lista);
    printf("Memoria liberada. Teste concluido!\n");
    
    return 0;
}