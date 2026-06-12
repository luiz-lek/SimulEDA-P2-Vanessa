#include "resposta.h"
#include <stdio.h>

void soma_k(char *arqA, char *arqB, char *saida, int k) {
    FILE *f = fopen(arqA, "r");
    Hash *tab = hash_inicializa(101);

    int lido;
    while(fscanf(f, "%d", &lido) == 1) {
        hash_insere(tab, 101, lido);
    }
    fclose(f);

    f = fopen(arqB, "r");
    FILE *fs = fopen(saida, "w");
    while(fscanf(f, "%d", &lido) == 1) {
        int alvo = k - hash(lido, 101);
        int h = hash(alvo, 101);
        TH *p = tab[h];
        while (p != NULL) {
            fprintf(fs, "%d %d", lido, p->chave);
            p = p->prox;
        }
    }

    tab = hash_libera(tab, 101);
    fclose(f);
    fclose(fs);
}