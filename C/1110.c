#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int chave;
    struct celula *prox;
} celula;

void empilha_enc_C(int y, celula *t) {
    celula *nova;

    nova = (celula *) malloc (sizeof (celula));
    nova->chave = y;
    nova->prox = t->prox;
    t->prox = nova;
}

void desempilha_enc_C(celula *t) {
    celula *p;

    if (t->prox != NULL) {
        p = t->prox;
        t->prox = p->prox;
        printf(" %d", p->chave);
        free(p);
    }
}

void final (celula *t, celula **f) {
    celula *aux;

    aux = t->prox; // aux recebe a primeira celula depois da cabeça
    t->prox = aux->prox; // O proximo de cabeça recebe o proximo de auxiliar
    aux->prox = NULL; // aux aponta para o nulo 
    (*f)->prox = aux; // O fim aponta pro aux;
    *f = aux; // Agora aponta para aux;
}

int main(void) {
    celula *t, *f;
    t = (celula *) malloc (sizeof (celula));

    int qtd;

    scanf(" %d", &qtd);
    while (qtd != 0) {
        if (qtd != 1) {

            empilha_enc_C(qtd, t);
            f = t->prox;

            for (int q = qtd-1; q >= 1; q--) {
                empilha_enc_C(q, t);
                
            }
            printf("Discarded cards:");

            for (int i = 0; i < qtd-2; i++) {
                desempilha_enc_C(t);
                printf(",");
                final(t, &f);
            }

            desempilha_enc_C(t);
            printf("\n");
            printf("Remaining card: %d\n", t->prox->chave);
            
        } else {
            printf("Discarded cards: \n");
            printf("Remaining card: 1\n");
        }
        scanf(" %d", &qtd);
    }
    return 0;
}