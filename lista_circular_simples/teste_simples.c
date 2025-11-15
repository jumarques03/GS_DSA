// ========== teste_simples.c ==========
#include <stdio.h>
#include "lista.h"

int main() {
    ListaCircular lista;
    inicializar(&lista);
    
    printf("=== Testes Simples - Lista Circular ===\n\n");
    
    // Teste 1: Inserção básica
    printf("Teste 1: Inserindo elementos 10, 20, 30, 40\n");
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40);
    imprimir(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    // Teste 2: Avançar k posições
    printf("Teste 2: Avancar k posições a partir do inicio\n");
    No* no_atual = lista.inicio;
    printf("No atual: %d\n", no_atual->valor);
    
    no_atual = avancar_k_posicoes(&lista, no_atual, 2);
    printf("Apos avançar 2 posicoes: %d\n", no_atual->valor);
    
    no_atual = avancar_k_posicoes(&lista, no_atual, 3);
    printf("Apos avancar 3 posicoes: %d\n", no_atual->valor);
    
    no_atual = avancar_k_posicoes(&lista, no_atual, 4);
    printf("Apos avancar 4 posicoes (da volta completa): %d\n\n", no_atual->valor);
    
    // Teste 3: Remover elemento do meio
    printf("Teste 3: Removendo elemento 20\n");
    if (remover_no(&lista, 20)) {
        printf("Elemento 20 removido com sucesso!\n");
    }
    imprimir(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    // Teste 4: Remover elemento do início
    printf("Teste 4: Removendo elemento 10 (inicio)\n");
    if (remover_no(&lista, 10)) {
        printf("Elemento 10 removido com sucesso!\n");
    }
    imprimir(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    // Teste 5: Inserir mais elementos
    printf("Teste 5: Inserindo 50 e 60\n");
    inserir(&lista, 50);
    inserir(&lista, 60);
    imprimir(&lista);
    printf("Tamanho: %d\n\n", obter_tamanho(&lista));
    
    liberar(&lista);
    printf("Memoria liberada.\n");
    
    return 0;
}