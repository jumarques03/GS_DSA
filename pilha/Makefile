// ==================== Makefile ====================
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Arquivos
SOURCES = pilha.c
HEADERS = pilha.h
TESTS = teste_simples teste_borda

# Alvos principais
all: $(TESTS)

# Compilar teste simples
teste_simples: teste_simples.c pilha.c pilha.h
	$(CC) $(CFLAGS) -o teste_simples teste_simples.c pilha.c

# Compilar teste de borda
teste_borda: teste_borda.c pilha.c pilha.h
	$(CC) $(CFLAGS) -o teste_borda teste_borda.c pilha.c

# Executar todos os testes
test: all
	@echo "===================================="
	@echo "Executando testes simples..."
	@echo "===================================="
	./teste_simples
	@echo ""
	@echo "===================================="
	@echo "Executando testes de borda..."
	@echo "===================================="
	./teste_borda

# Limpar arquivos compilados
clean:
	rm -f $(TESTS) *.o

# Limpar e recompilar
rebuild: clean all

.PHONY: all test clean rebuild