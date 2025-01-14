// Arquivo: pilha.c

#include "pilha.h"

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, char *mensagem) {
    NoPilha *novo_no = (NoPilha *)malloc(sizeof(NoPilha));
    if (!novo_no) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo_no->mensagem = strdup(mensagem);
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
}

char* desempilhar(Pilha *pilha) {
    if (pilha_vazia(pilha)) {
        return NULL;
    }
    NoPilha *no_removido = pilha->topo;
    char *mensagem = no_removido->mensagem;
    pilha->topo = no_removido->prox;
    free(no_removido);
    return mensagem;
}

int pilha_vazia(Pilha *pilha) {
    return pilha->topo == NULL;
}
