// Arquivo: codificacao.c

#include "codificacao.h"
#include <string.h>

const char caracteres_permitidos[] = "abcdefghijklmnopqrstuvwxyz0123456789, .?:";
const int tamanho_caracteres = 40;

int indice_caractere(char c) {
    for (int i = 0; i < tamanho_caracteres; i++) {
        if (caracteres_permitidos[i] == c) {
            return i;
        }
    }
    return -1;
}

void codificar_mensagem(char *mensagem, char *codificada, TabelaHash *tabela) {
    int tamanho = strlen(mensagem);
    for (int i = 0; i < tamanho; i++) {
        char c = mensagem[i];
        int indice = indice_caractere(c);
        if (indice != -1) {
            int frequencia = obter_frequencia(tabela, c);
            int novo_indice = (indice + frequencia + (i + 1)) % tamanho_caracteres;
            codificada[i] = caracteres_permitidos[novo_indice];
        } else {
            codificada[i] = c;
        }
    }
    codificada[tamanho] = '\0';
}

void decodificar_mensagem(char *codificada, char *original, TabelaHash *tabela) {
    int tamanho = strlen(codificada);
     
    printf("\n\nDecodificando a mensagem: %s\n", codificada);
       for (int i = 0; i < tamanho; i++) {
        
        char c = codificada[i];
        int indice = indice_caractere(c);
        if (indice != -1) {
            int frequencia = obter_frequencia(tabela, caracteres_permitidos[indice]);
            int indice_original = (indice - frequencia - (i + 1) + tamanho_caracteres) % tamanho_caracteres;
            original[i] = caracteres_permitidos[indice_original];
        } else {
            original[i] = c;
        }
    }
    original[tamanho] = '\0';
}
