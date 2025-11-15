// ========== teste_borda.c ==========
#include <stdio.h>
#include "lista.h"

int main() {
    ListaCircular lista;
    
    printf("=== Testes de Borda - Lista Circular ===\n\n");
    
    // Teste 1: Lista vazia
    printf("Teste 1: Operacoes em lista vazia\n");
    inicializar(&lista);
    printf("Lista esta vazia? %s\n", esta_vazia(&lista) ? "Sim" : "Não");
    imprimir(&lista);
    printf("Tentando remover de lista vazia: %s\n", 
           remover_no(&lista, 10) ? "Sucesso" : "Falhou (esperado)");
    printf("Tentando avancar em lista vazia: %s\n\n", 
           avancar_k_posicoes(&lista, NULL, 5) == NULL ? "NULL (esperado)" : "Inesperado");
    
    // Teste 2: Lista com um único elemento
    printf("Teste 2: Lista com um unico elemento\n");
    inserir(&lista, 100);
    imprimir(&lista);
    printf("Tamanho: %d\n", obter_tamanho(&lista));
    
    No* no = avancar_k_posicoes(&lista, lista.inicio, 5);
    printf("Avancar 5 posicoes (deve voltar ao mesmo): %d\n", no->valor);
    
    printf("Removendo unico elemento...\n");
    remover_no(&lista, 100);
    imprimir(&lista);
    printf("Lista está vazia? %s\n\n", esta_vazia(&lista) ? "Sim" : "Nao");
    
    // Teste 3: Remover todos os elementos sequencialmente
    printf("Teste 3: Remover todos os elementos\n");
    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    imprimir(&lista);
    
    printf("Removendo 2...\n");
    remover_no(&lista, 2);
    imprimir(&lista);
    
    printf("Removendo 1...\n");
    remover_no(&lista, 1);
    imprimir(&lista);
    
    printf("Removendo 3...\n");
    remover_no(&lista, 3);
    imprimir(&lista);
    printf("\n");
    
    // Teste 4: Avançar k = 0
    printf("Teste 4: Avancar k = 0 posições\n");
    inserir(&lista, 10);
    inserir(&lista, 20);
    no = avancar_k_posicoes(&lista, lista.inicio, 0);
    printf("Permanece no mesmo no: %d\n\n", no->valor);
    
    // Teste 5: Remover elemento inexistente
    printf("Teste 5: Remover elemento inexistente\n");
    imprimir(&lista);
    printf("Tentando remover 999: %s\n\n", 
           remover_no(&lista, 999) ? "Sucesso" : "Falhou (esperado)");
    
    // Teste 6: Avançar múltiplas voltas completas
    printf("Teste 6: Avancar multiplas voltas (k = 100)\n");
    liberar(&lista);
    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    imprimir(&lista);
    no = avancar_k_posicoes(&lista, lista.inicio, 100);
    printf("Apos 100 posicoes, no atual: %d\n\n", no->valor);
    
    // Teste 7: Inserir após liberar
    printf("Teste 7: Inserir apos liberar lista\n");
    liberar(&lista);
    printf("Apos liberar, tamanho: %d\n", obter_tamanho(&lista));
    inserir(&lista, 77);
    inserir(&lista, 88);
    imprimir(&lista);
    
    liberar(&lista);
    printf("\nTodos os testes de borda concluidos!\n");
    
    return 0;
}