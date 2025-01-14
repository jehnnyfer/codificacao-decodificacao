// Arquivo: deque.h

#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoDeque {
    char *mensagem;
    struct NoDeque *ant, *prox;
} NoDeque;

typedef struct {
    NoDeque *inicio, *fim;
} Deque;

void inicializar_deque(Deque *deque);
void inserir_inicio(Deque *deque, char *mensagem);
void inserir_fim(Deque *deque, char *mensagem);
char* remover_inicio(Deque *deque);
char* remover_fim(Deque *deque);
int deque_vazio(Deque *deque);

#endif
