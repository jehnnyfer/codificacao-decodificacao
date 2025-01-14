    // Arquivo: main.c

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "pilha.h"
    #include "deque.h"
    #include "hash.h"
    #include "codificacao.h"

    void menu() {
        printf("\n=== Sistema de Codificação e Decodificação ===\n");
        printf("1. Inserir mensagem na pilha\n");
        printf("2. Codificar mensagem\n");
        printf("3. Decodificar mensagem\n");
        printf("4. Exibir mensagens codificadas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
    }

    char mensagem[1000000];
    char codificada[1000000];
    char decodificada[1000000];

    int main() {
        Pilha pilha;
        Deque deque;
        TabelaHash tabela;

        inicializar_pilha(&pilha);
        inicializar_deque(&deque);
        inicializar_tabela_hash(&tabela, 40);

        
        int opcao;

        do {
            menu();
            scanf("%d", &opcao);
            getchar(); // Limpar buffer

            switch (opcao) {
                case 1:
                    printf("Digite a mensagem: ");
                    fgets(mensagem, 1000000, stdin);
                    mensagem[strcspn(mensagem, "\n")] = '\0';
                    empilhar(&pilha, mensagem);
                    printf("Mensagem inserida na pilha.\n");
                    break;

                case 2:
                    if (pilha_vazia(&pilha)) {
                        printf("Pilha vazia. Nenhuma mensagem para codificar.\n");
                    } else {
                        char *msg = desempilhar(&pilha);
                        printf("Codificando mensagem: %s\n", msg);

                        for (int i = 0; i < strlen(msg); i++) {
                            inserir_frequencia(&tabela, msg[i]);
                        }

                        codificar_mensagem(msg, codificada, &tabela);
                        inserir_fim(&deque, codificada);
                        printf("Mensagem codificada: %s\n", codificada);

                        limpar_tabela_hash(&tabela);
                        inicializar_tabela_hash(&tabela, 40);
                    }
                    break;

                case 3:
                    if (deque_vazio(&deque)) {
                        printf("Deque vazio. Nenhuma mensagem para decodificar.\n");
                    } else {
                        char *msg_codificada = remover_inicio(&deque);
                        printf("Decodificando mensagem: %s\n", msg_codificada);

                        for (int i = 0; i < strlen(msg_codificada); i++) {
                            inserir_frequencia(&tabela, msg_codificada[i]);
                        }

                        printf("Decodificando mensagem: %s\n", msg_codificada);
                        decodificar_mensagem(msg_codificada, decodificada, &tabela);
                        printf("Mensagem decodificada: %s\n", decodificada);

                        limpar_tabela_hash(&tabela); 
                        inicializar_tabela_hash(&tabela, 40);
                    }
                    break;

                case 4:
                    if (deque_vazio(&deque)) {
                        printf("Deque vazio. Nenhuma mensagem codificada.\n");
                    } else {
                        printf("Mensagens codificadas no deque:\n");
                        NoDeque *atual = deque.inicio;
                        while (atual) {
                            printf("%s\n", atual->mensagem);
                            atual = atual->prox;
                        }
                    }
                    break;

                case 5:
                    printf("Saindo do programa.\n");
                    break;

                default:
                    printf("Opção inválida. Tente novamente.\n");
            }
        } while (opcao != 5);

        return 0;
    }
