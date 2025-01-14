# Makefile

CC = gcc
CFLAGS = -Wall -g

OBJS = pilha.o deque.o hash.o codificacao.o main.o

all: programa

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

programa: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o programa

clean:
	rm -f *.o programa

.PHONY: all clean
