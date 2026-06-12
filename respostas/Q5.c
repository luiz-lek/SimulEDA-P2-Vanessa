#include "questoes.h"

int altura(TNoBM* a) {
    if(!a) return 0;
    else return 1 + altura(a->p[0]);
}

void atualiza_path(char* path, int x) {
    char temp[256];
    snprintf(temp, sizeof(temp), "%d%s", x, path);
    strcpy(path, temp);
}

void caminho_aux(TNoBM* a, int x, char* path, int* encontrado) {
    if(!a) return;

    for(int i = 0; i < a->m; i++) {
        if((x == a->s[i]) && a->eh_folha) {
            *encontrado = 1;
            path[0] = '\0';
            return;
        }
        if(x < a->s[i]) {
            caminho_aux(a->p[i], x, path, encontrado);
            if(*encontrado) {
                atualiza_path(path, i);
            }
            return;
        }
    }

    caminho_aux(a->p[a->m], x, path, encontrado);
    if(*encontrado) {
        atualiza_path(path, a->m);
    }
}

char* caminho(TNoBM* a, int x) {
    if(!a) return NULL;
    int tam = altura(a);

    char* path = (char*)malloc(sizeof(char) * (tam + 1));
    if(!path) return NULL;
    path[0] = '\0';

    int encontrado = 0;
    caminho_aux(a, x, path, &encontrado);

    if(!encontrado) {
        free(path);
        return NULL;
    }

    return path;
}