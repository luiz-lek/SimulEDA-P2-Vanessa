//
// Created by luizao on 11/06/2026.
//

#ifndef TARVB_STRUCTS_E_FUNCOES_H
#define TARVB_STRUCTS_E_FUNCOES_H

#include "../estruturas/TLista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NoB {
    int m;
    struct NoB *pai;
    int *s;
    struct NoB **p;
} TNoB;

typedef struct NoBM {
    int m;
    struct NoBM *pai;
    int *s;
    struct NoBM **p;
    struct NoBM *prox;
} TNoBM;

// Questão 4
TLista* arvore_pra_lista(TNoB *a);

// Questão 5
char* caminho(TNoBM* a, int x);

// Questão 6
int moda(int *vet, int tam_vet, int n);


// Questão 7
void soma_k(char *arqA, char *arqB, char *saida, int k);

// Questão 9
int pai(int n, int indice_filho);
int filho_i(int n, int indice_pai, int i);
void subir(int *heap, int n, int i);
void descer(int *heap, int ultimo_indice, int n, int i);
int insere(int *heap, int ultimo_indice, int n, int novo);
int exclui(int *heap, int ultimo_indice, int n);

#endif //TARVB_STRUCTS_E_FUNCOES_H
