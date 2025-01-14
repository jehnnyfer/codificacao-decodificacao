// Arquivo: hash.h

#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char caractere;
    int frequencia;
    int ocupado;
} EntradaHash;

typedef struct {
    EntradaHash *entradas;
    int tamanho;
} TabelaHash;

void inicializar_tabela_hash(TabelaHash *tabela, int tamanho);
void inserir_frequencia(TabelaHash *tabela, char caractere);
int obter_frequencia(TabelaHash *tabela, char caractere);
void limpar_tabela_hash(TabelaHash *tabela);

#endif
