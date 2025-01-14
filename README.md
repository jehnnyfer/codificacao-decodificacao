# Sistema de Codificação e Decodificação de Mensagens

## Introdução
Este é um programa em C que implementa um sistema para codificar e decodificar mensagens utilizando estruturas de dados como pilha, deque e tabela hash. O sistema é interativo e permite ao usuário inserir mensagens, codificá-las, decodificá-las e visualizar mensagens codificadas armazenadas.

## Funcionalidades
1. **Inserir mensagem na pilha.**
2. **Codificar mensagens** com base em uma tabela hash de frequência de caracteres.
3. **Decodificar mensagens** previamente codificadas.
4. **Exibir todas as mensagens codificadas** armazenadas no deque.
5. **Encerrar o programa.**

## Estruturas de Dados Utilizadas

### Pilha
- **Arquivos:** `pilha.c`, `pilha.h`
- Usada para armazenar as mensagens inseridas pelo usuário, de forma que a mais recente seja codificada primeiro (LIFO).

### Deque
- **Arquivos:** `deque.c`, `deque.h`
- Usado para armazenar mensagens codificadas, permitindo inserção e remoção de mensagens tanto no início quanto no fim.

### Tabela Hash
- **Arquivos:** `hash.c`, `hash.h`
- Usada para calcular e armazenar a frequência de caracteres de cada mensagem durante o processo de codificação e decodificação.

## Estrutura do Código

- **`main.c`**: Contém o menu principal e a lógica de interação com o usuário.
- **`codificacao.c` e `codificacao.h`**: Implementação das funções de codificação e decodificação de mensagens.
- **`pilha.c` e `pilha.h`**: Manipulação da pilha para mensagens.
- **`deque.c` e `deque.h`**: Manipulação do deque para mensagens codificadas.
- **`hash.c` e `hash.h`**: Cálculo de frequências dos caracteres para alteração de mensagens.

## Como Usar

### Requisitos
- Compilador GCC ou equivalente.
- Sistema operacional compatível com C (Windows, Linux, macOS).

### Compilação e Execução

1. Compile todos os arquivos:
   ```bash
   gcc -o codificacao main.c pilha.c deque.c hash.c codificacao.c
2. Execute em linux:
   ```bash 
   ./codificacao
3. Execute em windows:
   ```bash 
   codificacao.exe

### Uso Interativo
- Após executar o programa, será exibido o seguinte menu:

  ```plaintext
    === Sistema de Codificação e Decodificação ===
    1. Inserir mensagem na pilha
    2. Codificar mensagem
    3. Decodificar mensagem
    4. Exibir mensagens codificadas
    5. Sair
    Escolha uma opção:
  
Selecione a opção desejada e siga as instruções do programa.


