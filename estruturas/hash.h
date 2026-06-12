#ifndef TARVB_HASH_H
#define TARVB_HASH_H

#define TAM 101

// Hash que aramazena a quantidade de vezes que um número pareceu
typedef struct hash {
    int chave;
    struct hash *prox;
} TH;

typedef TH* Hash;

int hash(int chave, int tam);
Hash* hash_inicializa(int m);
TH* hash_busca(Hash *tab, int m, int mat);
TH* hash_aloca(int chave);
void hash_insere(Hash *tab, int m, int chave);
Hash* hash_libera(Hash *tab, int m);
void hash_exclui(Hash *tab, int m, int chave);
void hash_imprime(Hash *tab, int m);

#endif