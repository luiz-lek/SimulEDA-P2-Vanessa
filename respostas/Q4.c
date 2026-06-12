#include "questoes.h"
#include <stdlib.h>

TLista* aux(TNoB *a, TLista *l) {
    if(a == NULL) return l;

    l = aux(a->p[a->m], l);
    for(int i = a->m-1; i >= 0; i--) {
        l = insere_fim(l, a->s[i]);
        l = aux(a->p[i], l);
    }

    return l;
}

TLista* arvore_pra_lista(TNoB *a) {
    TLista *l = NULL;
    return aux(a, l);
}