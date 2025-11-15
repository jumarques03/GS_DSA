CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

all: teste_simples teste_borda

teste_simples: teste_simples.o lista.o
	$(CC) $(CFLAGS) -o teste_simples teste_simples.o lista.o

teste_borda: teste_borda.o lista.o
	$(CC) $(CFLAGS) -o teste_borda teste_borda.o lista.o

teste_simples.o: teste_simples.c lista.h
	$(CC) $(CFLAGS) -c teste_simples.c

teste_borda.o: teste_borda.c lista.h
	$(CC) $(CFLAGS) -c teste_borda.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

clean:
	rm -f *.o teste_simples teste_borda

run_simples: teste_simples
	./teste_simples

run_borda: teste_borda
	./teste_borda

run_all: teste_simples teste_borda
	@echo "Executando testes simples..."
	./teste_simples
	@echo "\nExecutando testes de borda..."
	./teste_borda

.PHONY: all clean run_simples run_borda run_all