// ==================== teste_borda.c ====================
#include <stdio.h>
#include <assert.h>
#include "pilha.h"

void teste_pilha_vazia() {
    printf("Teste 1: Operacoes em pilha vazia\n");
    Pilha pilha;
    inicializar(&pilha);
    
    assert(isEmpty(&pilha));
    assert(tamanho(&pilha) == 0);
    
    // Pop e top em pilha vazia devem retornar '\0'
    char resultado_pop = pop(&pilha);
    char resultado_top = top(&pilha);
    assert(resultado_pop == '\0');
    assert(resultado_top == '\0');
    
    liberar(&pilha);
    printf("Passou!\n\n");
}

void teste_um_elemento() {
    printf("Teste 2: Pilha com um elemento\n");
    Pilha pilha;
    inicializar(&pilha);
    
    push(&pilha, 'Z');
    assert(!isEmpty(&pilha));
    assert(tamanho(&pilha) == 1);
    assert(top(&pilha) == 'Z');
    
    char valor = pop(&pilha);
    assert(valor == 'Z');
    assert(isEmpty(&pilha));
    assert(tamanho(&pilha) == 0);
    
    liberar(&pilha);
    printf("Passou!\n\n");
}

void teste_multiplos_push_pop() {
    printf("Teste 3: Multiplos push/pop intercalados\n");
    Pilha pilha;
    inicializar(&pilha);
    
    push(&pilha, '1');
    push(&pilha, '2');
    assert(pop(&pilha) == '2');
    
    push(&pilha, '3');
    push(&pilha, '4');
    assert(pop(&pilha) == '4');
    assert(pop(&pilha) == '3');
    assert(pop(&pilha) == '1');
    assert(isEmpty(&pilha));
    
    liberar(&pilha);
    printf("Passou!\n\n");
}

void teste_expressao_vazia() {
    printf("Teste 4: Expressao vazia\n");
    
    assert(expressao_balanceada(""));
    assert(expressao_balanceada("abc123"));
    assert(expressao_balanceada("sem delimitadores"));
    
    printf("Passou!\n\n");
}

void teste_apenas_fechamento() {
    printf("Teste 5: Apenas delimitadores de fechamento\n");
    
    assert(!expressao_balanceada(")"));
    assert(!expressao_balanceada("]"));
    assert(!expressao_balanceada("}"));
    assert(!expressao_balanceada(")))"));
    assert(!expressao_balanceada("]]]"));
    
    printf("Passou!\n\n");
}

void teste_apenas_abertura() {
    printf("Teste 6: Apenas delimitadores de abertura\n");
    
    assert(!expressao_balanceada("("));
    assert(!expressao_balanceada("["));
    assert(!expressao_balanceada("{"));
    assert(!expressao_balanceada("((("));
    assert(!expressao_balanceada("[[["));
    
    printf("Passou!\n\n");
}

void teste_delimitadores_misturados() {
    printf("Teste 7: Delimitadores misturados incorretamente\n");
    
    assert(!expressao_balanceada("([)]"));
    assert(!expressao_balanceada("{[}]"));
    assert(!expressao_balanceada("[(])"));
    assert(!expressao_balanceada("({[}])"));
    
    printf("Passou!\n\n");
}

void teste_expressao_longa() {
    printf("Teste 8: Expressao muito longa\n");
    
    // Expressão profundamente aninhada
    assert(expressao_balanceada("((((((((((()))))))))))"));
    assert(expressao_balanceada("{[{[{[{[()]}]}]}]}"));
    
    // Expressão longa desbalanceada
    assert(!expressao_balanceada("((((((((((()))))))))"));
    assert(!expressao_balanceada("{[{[{[{[()]]}]}]}"));
    
    printf("Passou!\n\n");
}

void teste_tamanho_pilha() {
    printf("Teste 9: Verificacao de tamanho\n");
    Pilha pilha;
    inicializar(&pilha);
    
    assert(tamanho(&pilha) == 0);
    
    push(&pilha, 'A');
    assert(tamanho(&pilha) == 1);
    
    push(&pilha, 'B');
    push(&pilha, 'C');
    assert(tamanho(&pilha) == 3);
    
    pop(&pilha);
    assert(tamanho(&pilha) == 2);
    
    pop(&pilha);
    pop(&pilha);
    assert(tamanho(&pilha) == 0);
    
    liberar(&pilha);
    printf("Passou!\n\n");
}

void teste_liberar_multiplas_vezes() {
    printf("Teste 10: Liberar pilha multiplas vezes\n");
    Pilha pilha;
    inicializar(&pilha);
    
    push(&pilha, 'X');
    push(&pilha, 'Y');
    
    liberar(&pilha);
    assert(isEmpty(&pilha));
    
    // Liberar novamente não deve causar problemas
    liberar(&pilha);
    assert(isEmpty(&pilha));
    
    printf("Passou!\n\n");
}

int main() {
    printf("=== TESTES DE BORDA DA PILHA ===\n\n");
    
    teste_pilha_vazia();
    teste_um_elemento();
    teste_multiplos_push_pop();
    teste_expressao_vazia();
    teste_apenas_fechamento();
    teste_apenas_abertura();
    teste_delimitadores_misturados();
    teste_expressao_longa();
    teste_tamanho_pilha();
    teste_liberar_multiplas_vezes();
    
    printf("=== TODOS OS TESTES DE BORDA PASSARAM! ===\n");
    
    return 0;
}