// Arquivo: codificacao.h

#ifndef CODIFICACAO_H
#define CODIFICACAO_H

#include "hash.h"

void codificar_mensagem(char *mensagem, char *codificada, TabelaHash *tabela);
void decodificar_mensagem(char *codificada, char *original, TabelaHash *tabela);

#endif
