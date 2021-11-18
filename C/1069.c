#include <stdio.h>
#define max 1000

void empilha_seq(int *t, char *pilha, char y, int n) {

    if (*t != n - 1) {
        (*t)++;
        pilha[*t] = y;
    }
}

int sinal(char *palavra, int n) {
    int t = -1, qtd = 0;
    char pilha[n];

    for (int c = 0; c < n; c++) {
        if (palavra[c] == '<') {
            empilha_seq(&t, pilha, palavra[c], n);
        }
        else if (t != - 1) {
            if (palavra[c] == '>' && pilha[t] == '<'){
                t--;
                qtd++;
            } else {
                return qtd;
            }
        } else if (palavra[0] == '.') {
            return 0;
        }
    }
    if (t == -1) {
        return qtd;
    } else {
        return qtd;
    }
}

int main(void) {
    int resp, n = 0, qtd;
    char palavra[max], p[max];

    scanf("%d", &qtd);

    for (int q = 0; q < qtd; q++) {
        scanf(" %[^\n]%*c", palavra);

        for (int i = 0; palavra[i] != '\0'; i++) {
            if (palavra[i] != '.') {
                p[n] = palavra[i];
                n++;
            }
        }
        p[n] = '\0';

        resp = sinal(p, n);
        n = 0;

        printf("%d\n", resp);

    }
    return 0;
}
