#include <stdio.h>
#include <assert.h>
#include "lista.h"

void teste_inserir_ordem() {
    printf("=== Teste: Inserir em ordem ===\n");
    Lista lista;
    inicializar(&lista);

    inserir(&lista, 5);
    inserir(&lista, 2);
    inserir(&lista, 8);
    inserir(&lista, 1);
    inserir(&lista, 9);

    printf("Lista apos insercoes: ");
    imprimir(&lista);

    // Verificar ordem
    assert(lista.inicio->valor == 1);
    assert(lista.inicio->prox->valor == 2);
    assert(lista.inicio->prox->prox->valor == 5);
    assert(lista.inicio->prox->prox->prox->valor == 8);
    assert(lista.inicio->prox->prox->prox->prox->valor == 9);

    liberar(&lista);
    printf("Teste passou!\n\n");
}

void teste_buscar() {
    printf("=== Teste: Buscar valores ===\n");
    Lista lista;
    inicializar(&lista);

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);

    printf("Lista: ");
    imprimir(&lista);

    No* resultado = buscar(&lista, 20);
    assert(resultado != NULL);
    assert(resultado->valor == 20);
    printf("Encontrou 20\n");

    resultado = buscar(&lista, 10);
    assert(resultado != NULL);
    assert(resultado->valor == 10);
    printf("Encontrou 10\n");

    resultado = buscar(&lista, 99);
    assert(resultado == NULL);
    printf("Nao encontrou 99 (esperado)\n");

    liberar(&lista);
    printf("Teste passou!\n\n");
}

void teste_remover() {
    printf("=== Teste: Remover elementos ===\n");
    Lista lista;
    inicializar(&lista);

    inserir(&lista, 15);
    inserir(&lista, 25);
    inserir(&lista, 35);
    inserir(&lista, 45);

    printf("Lista inicial: ");
    imprimir(&lista);

    int removido = remover(&lista, 25);
    assert(removido == 1);
    printf("Apos remover 25: ");
    imprimir(&lista);

    removido = remover(&lista, 15);
    assert(removido == 1);
    printf("Apos remover 15: ");
    imprimir(&lista);

    removido = remover(&lista, 100);
    assert(removido == 0);
    printf("Tentou remover 100 (nao existe)\n");

    liberar(&lista);
    printf("Teste passou!\n\n");
}

int main() {
    printf("======= TESTES SIMPLES =======\n\n");
    
    teste_inserir_ordem();
    teste_buscar();
    teste_remover();
    
    printf("======= TODOS OS TESTES PASSARAM! =======\n");
    return 0;
}