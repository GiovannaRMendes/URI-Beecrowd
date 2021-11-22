#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char caracter;
    struct celula *prox;
} celula;

void imprimir(celula *p) {
    celula *q;

    if (p->prox != NULL) {
        for (q = p->prox; q != NULL; q = q->prox) {
            printf("%c", q->caracter);
        }
        printf("\n");
    }
}

void inserir(char l, celula *p) {
    celula *nova;

    nova = (celula *) malloc (sizeof (celula));
    nova->caracter = l;
    nova->prox = p->prox;
    p->prox = nova;
}

void remover(celula *p) {
    celula *lixo;

    while (p != NULL) {
        lixo = p;
        p = lixo->prox;
        free(lixo);
    }
}

int main(void) {
    celula *t, *i, *f;
    t = (celula *) malloc(sizeof (celula));
    t->prox = NULL;
    i = t;
    f = t;

    char c;

    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            imprimir(i);
            remover(i);

            t = (celula *) malloc(sizeof (celula));
            t->prox = NULL;
            i = t;
            f = t;
        } else {
            if (c == '[') {
                t = i;
            } else if (c == ']') {
                t = f;
            } else {
                inserir(c, t);
                t = t->prox;

                if (t->prox == NULL) {
                    f = t;
                }
            }
        }
    }
    return 0;
}