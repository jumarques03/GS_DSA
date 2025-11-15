# GS - DSA: Usando Inteligência Artificial como parceira (e não muleta) no raciocínio algorítmico

Este repositório contém o código-fonte da **Global Solution (GS)** da disciplina **Data Structure and Algorithms**.

**Aluna:** Júlia Souza Marques  
**RM:** 565010  

---

## 1. Sobre o Desafio

Este projeto teve como objetivo aplicar o uso **crítico** da Inteligência Artificial na resolução de problemas de estruturas de dados em C.

O *AI Companion* utilizado foi o **Claude Sonet 4.5**.

O desafio não era simplesmente “deixar a IA fazer o trabalho”, mas usá-la como um **copiloto**, seguindo um processo de:

- **Geração:** pedir à IA que implementasse 5 estruturas de dados.  
- **Testes:** compilar e executar testes simples e de borda.  
- **Análise Crítica:** avaliar o código quanto à correção, boas práticas e eficiência (Notação Big-O).  
- **Decisão:** manter, refatorar ou descartar a solução com base na análise.

---

## 2. Relatório Crítico (PDF)

A análise completa, documentação do processo, prompts utilizados e conclusões detalhadas estão disponíveis no relatório em PDF:

**[Link para o relatório](https://docs.google.com/document/d/1AGJhWeHWny50hY_JqTo29H4Xkw0ggpZshJZrXwGtqeg/edit?usp=sharing)**

---

## 3. Estrutura do Repositório

O repositório está organizado em pastas, uma para cada estrutura de dados analisada.

Cada pasta contém:

- `lista.c` / `pilha.c` / `fila.c` (e seus respectivos `.h`)
- `teste_simples.c`: Testes básicos de funcionalidade  
- `teste_borda.c`: Testes de casos extremos  
- `Makefile`: Compilação automatizada

---


## 4. Como Compilar e Executar

Cada estrutura pode ser compilada e testada individualmente.

### 1. Acesse a pasta da estrutura

```bash
cd 04_pilha/
```

### 2. Compile com o Makefile

```bash
mingw32-make
```

### 3. Rode os testes (os comandos podem mudar de acordo com a pasta)

```bash
mingw32-make run_simples   # Executa ./teste_simples
mingw32-make run_borda     # Executa ./teste_borda
```
