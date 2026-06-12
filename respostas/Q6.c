#include "questoes.h"

int moda(int *vet, int tam_vet, int n) {
    int tam_hash = n+1;
    int hash[tam_hash];

    for (int i = 0; i < tam_hash; i++) hash[i] = 0;

    for(int i = 0; i < tam_vet; i++) hash[vet[i]]++;

    int moda = 0;

    for (int i = 0; i < tam_hash; i++) {
        if (hash[i] > hash[moda]) moda = i;
    }

    return hash[moda];
}