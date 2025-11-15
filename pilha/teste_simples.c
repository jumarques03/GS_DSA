// ==================== teste_simples.c ====================
#include <stdio.h>
#include <assert.h>
#include "pilha.h"

void teste_push_pop() {
    printf("Teste 1: Push e Pop basicos\n");
    Pilha pilha;
    inicializar(&pilha);
    
    push(&pilha, 'A');
    push(&pilha, 'B');
    push(&pilha, 'C');
    
    assert(pop(&pilha) == 'C');
    assert(pop(&pilha) == 'B');
    assert(pop(&pilha) == 'A');
    assert(isEmpty(&pilha));
    
    liberar(&pilha);
    printf("Passou!\n\n");
}

void teste_top() {
    printf("Teste 2: Funcao top\n");
    Pilha pilha;
    inicializar(&pilha);
    
    push(&pilha, 'X');
    push(&pilha, 'Y');
    
    assert(top(&pilha) == 'Y');
    assert(top(&pilha) == 'Y'); // Top não remove
    assert(!isEmpty(&pilha));
    
    pop(&pilha);
    assert(top(&pilha) == 'X');
    
    liberar(&pilha);
    printf("Passou!\n\n");
}

void teste_expressoes_balanceadas_simples() {
    printf("Teste 3: Expressoes balanceadas simples\n");
    
    assert(expressao_balanceada("()"));
    assert(expressao_balanceada("[]"));
    assert(expressao_balanceada("{}"));
    assert(expressao_balanceada("()[]{}"));
    assert(expressao_balanceada("{[()]}"));
    assert(expressao_balanceada("((()))"));
    
    printf("Passou!\n\n");
}

void teste_expressoes_desbalanceadas_simples() {
    printf("Teste 4: Expressoes desbalanceadas simples\n");
    
    assert(!expressao_balanceada("("));
    assert(!expressao_balanceada(")"));
    assert(!expressao_balanceada("(]"));
    assert(!expressao_balanceada("([)]"));
    assert(!expressao_balanceada("((()"));
    
    printf("Passou!\n\n");
}

void teste_expressoes_com_texto() {
    printf("Teste 5: Expressoes com texto\n");
    
    assert(expressao_balanceada("int main() { return 0; }"));
    assert(expressao_balanceada("array[0] = (x + y) * z"));
    assert(expressao_balanceada("func({a: [1, 2, 3]})"));
    assert(!expressao_balanceada("if (x > 0 { return; }"));
    assert(!expressao_balanceada("arr[0] = (1 + 2];"));
    
    printf("Passou!\n\n");
}

int main() {
    printf("=== TESTES SIMPLES DA PILHA ===\n\n");
    
    teste_push_pop();
    teste_top();
    teste_expressoes_balanceadas_simples();
    teste_expressoes_desbalanceadas_simples();
    teste_expressoes_com_texto();
    
    printf("=== TODOS OS TESTES SIMPLES PASSARAM! ===\n");
    
    return 0;
}
