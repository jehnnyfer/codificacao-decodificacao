// Arquivo: pilha.h

#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoPilha {
    char *mensagem;
    struct NoPilha *prox;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

void inicializar_pilha(Pilha *pilha);
void empilhar(Pilha *pilha, char *mensagem);
char* desempilhar(Pilha *pilha);
int pilha_vazia(Pilha *pilha);

#endif

