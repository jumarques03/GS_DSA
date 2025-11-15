#include <stdio.h>
#include <assert.h>
#include "lista.h"

void teste_lista_vazia() {
    printf("=== Teste: Operacoes em lista vazia ===\n");
    Lista lista;
    inicializar(&lista);

    printf("Lista vazia: ");
    imprimir(&lista);

    // Buscar em lista vazia
    No* resultado = buscar(&lista, 10);
    assert(resultado == NULL);
    printf("Busca em lista vazia retorna NULL\n");

    // Remover de lista vazia
    int removido = remover(&lista, 10);
    assert(removido == 0);
    printf("Remoção em lista vazia retorna 0\n");

    liberar(&lista);
    printf("Teste passou!\n\n");
}

void teste_elemento_unico() {
    printf("=== Teste: Lista com um unico elemento ===\n");
    Lista lista;
    inicializar(&lista);

    inserir(&lista, 42);
    printf("Lista: ");
    imprimir(&lista);

    // Buscar o único elemento
    No* resultado = buscar(&lista, 42);
    assert(resultado != NULL);
    assert(resultado->valor == 42);
    printf("Encontrou elemento unico\n");

    // Remover o único elemento
    int removido = remover(&lista, 42);
    assert(removido == 1);
    assert(lista.inicio == NULL);
    printf("Lista apos remocao: ");
    imprimir(&lista);
    printf("Lista ficou vazia apos remover unico elemento\n");

    liberar(&lista);
    printf("Teste passou!\n\n");
}

void teste_valores_duplicados() {
    printf("=== Teste: Valores duplicados ===\n");
    Lista lista;
    inicializar(&lista);

    inserir(&lista, 5);
    inserir(&lista, 5);
    inserir(&lista, 5);
    inserir(&lista, 10);

    printf("Lista com duplicatas: ");
    imprimir(&lista);

    // Remover deve remover apenas a primeira ocorrência
    int removido = remover(&lista, 5);
    assert(removido == 1);
    printf("Apos remover um 5: ");
    imprimir(&lista);

    // Ainda deve encontrar outro 5
    No* resultado = buscar(&lista, 5);
    assert(resultado != NULL);
    printf("Ainda ha valores 5 na lista\n");

    liberar(&lista);
    printf("Teste passou!\n\n");
}

void teste_extremos() {
    printf("=== Teste: Valores extremos ===\n");
    Lista lista;
    inicializar(&lista);

    inserir(&lista, -100);
    inserir(&lista, 0);
    inserir(&lista, 100);
    inserir(&lista, -50);

    printf("Lista: ");
    imprimir(&lista);

    assert(lista.inicio->valor == -100);
    printf("Menor valor no inicio\n");

    No* ultimo = lista.inicio;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    assert(ultimo->valor == 100);
    printf("Maior valor no fim\n");

    liberar(&lista);
    printf("Teste passou!\n\n");
}

void teste_remover_inicio_meio_fim() {
    printf("=== Teste: Remover do inicio, meio e fim ===\n");
    Lista lista;
    inicializar(&lista);

    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    inserir(&lista, 4);
    inserir(&lista, 5);

    printf("Lista inicial: ");
    imprimir(&lista);

    // Remover do início
    remover(&lista, 1);
    printf("Apos remover inicio (1): ");
    imprimir(&lista);
    assert(lista.inicio->valor == 2);

    // Remover do fim
    remover(&lista, 5);
    printf("Apos remover fim (5): ");
    imprimir(&lista);

    // Remover do meio
    remover(&lista, 3);
    printf("Apos remover meio (3): ");
    imprimir(&lista);

    liberar(&lista);
    printf("Teste passou!\n\n");
}

void teste_inserir_ordenado_extremos() {
    printf("=== Teste: Inserção sempre no inicio/fim ===\n");
    Lista lista;
    inicializar(&lista);

    // Inserir valores decrescentes (sempre no início)
    inserir(&lista, 50);
    inserir(&lista, 40);
    inserir(&lista, 30);
    inserir(&lista, 20);
    inserir(&lista, 10);

    printf("Insercao decrescente: ");
    imprimir(&lista);
    assert(lista.inicio->valor == 10);

    liberar(&lista);
    inicializar(&lista);

    // Inserir valores crescentes (sempre no fim)
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40);
    inserir(&lista, 50);

    printf("Insercao crescente: ");
    imprimir(&lista);
    assert(lista.inicio->valor == 10);

    liberar(&lista);
    printf("Teste passou!\n\n");
}

int main() {
    printf("======= TESTES DE CASOS DE BORDA =======\n\n");
    
    teste_lista_vazia();
    teste_elemento_unico();
    teste_valores_duplicados();
    teste_extremos();
    teste_remover_inicio_meio_fim();
    teste_inserir_ordenado_extremos();
    
    printf("======= TODOS OS TESTES DE BORDA PASSARAM! =======\n");
    return 0;
}