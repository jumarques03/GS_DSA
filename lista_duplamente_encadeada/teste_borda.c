// ==================== teste_borda.c ====================
#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista;
    int valor;
    
    printf("=== TESTES DE BORDA ===\n\n");
    
    // Teste 1: Remoção de lista vazia
    printf("Teste 1: Remoçao de lista vazia\n");
    inicializar(&lista);
    if (remover_inicio(&lista, &valor)) {
        printf("Removido do inicio: %d\n", valor);
    } else {
        printf("Nao foi possivel remover do inicio (lista vazia)\n");
    }
    if (remover_fim(&lista, &valor)) {
        printf("Removido do fim: %d\n", valor);
    } else {
        printf("Nao foi possivel remover do fim (lista vazia)\n");
    }
    printf("\n");
    
    // Teste 2: Inserir e remover um único elemento
    printf("Teste 2: Inserir e remover um unico elemento\n");
    printf("Inserindo 42 no inicio...\n");
    inserir_inicio(&lista, 42);
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Removendo do inicio...\n");
    if (remover_inicio(&lista, &valor)) {
        printf("Removido: %d\n", valor);
    }
    printf("Lista vazia? %s\n\n", esta_vazia(&lista) ? "Sim" : "Não");
    
    // Teste 3: Inserir no fim e remover do início com um elemento
    printf("Teste 3: Inserir no fim e remover do inicio (1 elemento)\n");
    inserir_fim(&lista, 99);
    percorrer_frente(&lista);
    if (remover_inicio(&lista, &valor)) {
        printf("Removido do inicio: %d\n", valor);
    }
    printf("Lista vazia? %s\n\n", esta_vazia(&lista) ? "Sim" : "Não");
    
    // Teste 4: Alternar inserções e remoções
    printf("Teste 4: Alternar insercoes e remocoes\n");
    inserir_inicio(&lista, 1);
    inserir_fim(&lista, 2);
    percorrer_frente(&lista);
    remover_fim(&lista, &valor);
    printf("Removido do fim: %d\n", valor);
    remover_inicio(&lista, &valor);
    printf("Removido do inicio: %d\n", valor);
    printf("Lista vazia? %s\n\n", esta_vazia(&lista) ? "Sim" : "Não");
    
    // Teste 5: Esvaziar lista completamente
    printf("Teste 5: Esvaziar lista completamente\n");
    inserir_inicio(&lista, 10);
    inserir_inicio(&lista, 20);
    inserir_inicio(&lista, 30);
    printf("Lista antes de esvaziar:\n");
    percorrer_frente(&lista);
    printf("Removendo todos os elementos...\n");
    while (!esta_vazia(&lista)) {
        remover_inicio(&lista, &valor);
        printf("Removido: %d (tamanho: %d)\n", valor, obter_tamanho(&lista));
    }
    printf("Lista vazia? %s\n\n", esta_vazia(&lista) ? "Sim" : "Não");
    
    // Teste 6: Múltiplas inserções seguidas de múltiplas remoções
    printf("Teste 6: Multiplas insercoes e remocoes\n");
    for (int i = 1; i <= 5; i++) {
        inserir_fim(&lista, i * 10);
    }
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Removendo do fim 3 vezes:\n");
    for (int i = 0; i < 3; i++) {
        if (remover_fim(&lista, &valor)) {
            printf("Removido: %d\n", valor);
        }
    }
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    printf("Tamanho final: %d\n\n", obter_tamanho(&lista));
    
    // Teste 7: Verificação de integridade dos ponteiros
    printf("Teste 7: Verificacao de integridade (lista com 2 elementos)\n");
    liberar(&lista);
    inserir_inicio(&lista, 100);
    inserir_fim(&lista, 200);
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    remover_inicio(&lista, &valor);
    printf("Apos remover inicio: ");
    percorrer_frente(&lista);
    percorrer_tras(&lista);
    remover_fim(&lista, &valor);
    printf("Apos remover fim (deve estar vazia): ");
    percorrer_frente(&lista);
    printf("Lista vazia? %s\n\n", esta_vazia(&lista) ? "Sim" : "Não");
    
    liberar(&lista);
    printf("Todos os testes de borda concluidos!\n");
    
    return 0;
}