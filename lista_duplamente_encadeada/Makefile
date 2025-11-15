// ==================== Makefile ====================
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
OBJ_DIR = obj
BIN_DIR = bin

# Criar diretórios se não existirem
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Alvos principais
all: $(BIN_DIR)/teste_simples $(BIN_DIR)/teste_borda

# Compilar lista.o
$(OBJ_DIR)/lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c -o $(OBJ_DIR)/lista.o

# Compilar e linkar teste_simples
$(OBJ_DIR)/teste_simples.o: teste_simples.c lista.h
	$(CC) $(CFLAGS) -c teste_simples.c -o $(OBJ_DIR)/teste_simples.o

$(BIN_DIR)/teste_simples: $(OBJ_DIR)/lista.o $(OBJ_DIR)/teste_simples.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/lista.o $(OBJ_DIR)/teste_simples.o -o $(BIN_DIR)/teste_simples

# Compilar e linkar teste_borda
$(OBJ_DIR)/teste_borda.o: teste_borda.c lista.h
	$(CC) $(CFLAGS) -c teste_borda.c -o $(OBJ_DIR)/teste_borda.o

$(BIN_DIR)/teste_borda: $(OBJ_DIR)/lista.o $(OBJ_DIR)/teste_borda.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/lista.o $(OBJ_DIR)/teste_borda.o -o $(BIN_DIR)/teste_borda

# Executar testes
test: all
	@echo "Executando testes simples..."
	@./$(BIN_DIR)/teste_simples
	@echo ""
	@echo "Executando testes de borda..."
	@./$(BIN_DIR)/teste_borda

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Recompilar tudo
rebuild: clean all

.PHONY: all test clean rebuild