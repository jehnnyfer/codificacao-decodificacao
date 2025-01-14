// Arquivo: deque.c

#include "deque.h"

void inicializar_deque(Deque *deque) {
    deque->inicio = deque->fim = NULL;
}

void inserir_inicio(Deque *deque, char *mensagem) {
    NoDeque *novo_no = (NoDeque *)malloc(sizeof(NoDeque));
    if (!novo_no) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo_no->mensagem = strdup(mensagem);
    novo_no->ant = NULL;
    novo_no->prox = deque->inicio;
    if (deque->inicio) {
        deque->inicio->ant = novo_no;
    } else {
        deque->fim = novo_no;
    }
    deque->inicio = novo_no;
}

void inserir_fim(Deque *deque, char *mensagem) {
    NoDeque *novo_no = (NoDeque *)malloc(sizeof(NoDeque));
    if (!novo_no) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo_no->mensagem = strdup(mensagem);
    novo_no->prox = NULL;
    novo_no->ant = deque->fim;
    if (deque->fim) {
        deque->fim->prox = novo_no;
    } else {
        deque->inicio = novo_no;
    }
    deque->fim = novo_no;
}

char* remover_inicio(Deque *deque) {
    if (deque_vazio(deque)) {
        return NULL;
    }
    NoDeque *no_removido = deque->inicio;
    char *mensagem = no_removido->mensagem;
    deque->inicio = no_removido->prox;
    if (deque->inicio) {
        deque->inicio->ant = NULL;
    } else {
        deque->fim = NULL;
    }
    free(no_removido);
    return mensagem;
}

char* remover_fim(Deque *deque) {
    if (deque_vazio(deque)) {
        return NULL;
    }
    NoDeque *no_removido = deque->fim;
    char *mensagem = no_removido->mensagem;
    deque->fim = no_removido->ant;
    if (deque->fim) {
        deque->fim->prox = NULL;
    } else {
        deque->inicio = NULL;
    }
    free(no_removido);
    return mensagem;
}

int deque_vazio(Deque *deque) {
    return deque->inicio == NULL;
}
