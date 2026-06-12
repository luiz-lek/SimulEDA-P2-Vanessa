//
// Created by luizao on 11/06/2026.
//

#ifndef TARVB_TLISTA_H
#define TARVB_TLISTA_H

typedef struct lista {
    int valor;
    struct lista *prox;
} TLista;

TLista* insere_fim(TLista *l, int valor);

#endif //TARVB_TLISTA_H
