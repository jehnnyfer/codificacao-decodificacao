// Arquivo: hash.c

#include "hash.h"

void inicializar_tabela_hash(TabelaHash *tabela, int tamanho) {
    tabela->tamanho = tamanho;
    tabela->entradas = (EntradaHash *)calloc(tamanho, sizeof(EntradaHash));
    if (!tabela->entradas) {
        printf("Erro ao alocar memória para a tabela hash.\n");
        exit(1);
    }

    printf("Tabela hash inicializada com tamanho: %d\n", tabela->tamanho);
}


void inserir_frequencia(TabelaHash *tabela, char caractere) {

    int hash = caractere % tabela->tamanho; 
    printf("Inserindo caractere '%c' com hash: %d\n", caractere, hash);

    while (tabela->entradas[hash].ocupado && tabela->entradas[hash].caractere != caractere) {
        hash = (hash + 1) % tabela->tamanho;
    }

    if (!tabela->entradas[hash].ocupado) {
        tabela->entradas[hash].caractere = caractere;
        tabela->entradas[hash].frequencia = 0;
        tabela->entradas[hash].ocupado = 1;
    }

    tabela->entradas[hash].frequencia++;
    printf("Caractere '%c' inserido com frequência %d\n", caractere, tabela->entradas[hash].frequencia);
}


int obter_frequencia(TabelaHash *tabela, char caractere) {
    printf("Buscando frequência de '%c'...\n", caractere);
    
    int hash = caractere % tabela->tamanho;
     while (tabela->entradas[hash].ocupado) {
        printf("Verificando na posição %d: caractere '%c'\n", hash, tabela->entradas[hash].caractere);
        if (tabela->entradas[hash].caractere == caractere) {
            printf("Frequência encontrada: %d\n", tabela->entradas[hash].frequencia);
            return tabela->entradas[hash].frequencia;
        }
        hash = (hash + 1) % tabela->tamanho;
    }

    printf("Caractere '%c' não encontrado.\n", caractere);
    return 0;
}

void limpar_tabela_hash(TabelaHash *tabela) {
    free(tabela->entradas);
    tabela->entradas = NULL;
    tabela->tamanho = 0;
}
