// ==================== Makefile ====================
# Makefile para compilação da Fila (Queue)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET_SIMPLES = teste_simples
TARGET_BORDA = teste_borda
OBJS = fila.o

all: $(TARGET_SIMPLES) $(TARGET_BORDA)

$(TARGET_SIMPLES): teste_simples.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET_SIMPLES) teste_simples.o $(OBJS)

$(TARGET_BORDA): teste_borda.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET_BORDA) teste_borda.o $(OBJS)

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

teste_simples.o: teste_simples.c fila.h
	$(CC) $(CFLAGS) -c teste_simples.c

teste_borda.o: teste_borda.c fila.h
	$(CC) $(CFLAGS) -c teste_borda.c

clean:
	rm -f *.o $(TARGET_SIMPLES) $(TARGET_BORDA)

run_simples: $(TARGET_SIMPLES)
	./$(TARGET_SIMPLES)

run_borda: $(TARGET_BORDA)
	./$(TARGET_BORDA)

run_all: $(TARGET_SIMPLES) $(TARGET_BORDA)
	@echo "=== Executando Testes Simples ==="
	./$(TARGET_SIMPLES)
	@echo ""
	@echo "=== Executando Testes de Borda ==="
	./$(TARGET_BORDA)

.PHONY: all clean run_simples run_borda run_all