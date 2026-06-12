#include "questoes.h"
#include <stdlib.h>

// A resoluçao considera que o vetor da heap inicia em 1, como está nos slides.

int pai(int n, int indice_filho) {
    return ((indice_filho-2)/n) + 1;
}

int filho_i(int n, int indice_pai, int i) {
    return n*(indice_pai-1)+i+1;
}

void subir(int *heap, int n, int i) {
    int j = pai(n, i);
    if (heap[i] > heap[j]) {
        int tamp = heap[i];
        heap[i] = heap[j];
        heap[j] = tamp;
        subir(heap, n, j);
    }
}

void descer(int *heap, int ultimo_indice, int n, int i) {
    int maior = i;
    for(int j = 1; j <= n; j++) {
        int indice_filho = filho_i(n, i, j);
        if (indice_filho > ultimo_indice) break;
        if(heap[indice_filho] > heap[maior]) maior = indice_filho;
    }

    if(maior != i) {
        int tamp = heap[i];
        heap[i] = heap[maior];
        heap[maior] = tamp;
        descer(heap, ultimo_indice, n, maior);
    }
}

int insere(int *heap, int ultimo_indice, int n, int novo) {
    heap = realloc(heap, sizeof(int) * (ultimo_indice + 2));
    ultimo_indice += 1;
    heap[ultimo_indice] = novo;
    subir(heap, n, ultimo_indice);
    return ultimo_indice;
}

int exclui(int *heap, int ultimo_indice, int n) {
    heap[1] = heap[ultimo_indice];
    ultimo_indice -= 1;
    heap = realloc(heap, sizeof(int) * (ultimo_indice + 1));
    descer(heap, ultimo_indice, n, 1);
    return ultimo_indice;
}