#include <stdio.h>
#define max 300

void empilha(int *t, char c, char pilha[]) {
    (*t)++;
    pilha[*t] = c;
}

int main(void) {
    char ar[max], l;
    int qtd = 0, t = -1;

    while (scanf("%c", &l) != EOF) {

        if (l == '\n') {
            printf("%d\n", qtd);
            qtd = 0;
            t = -1;
        } else if ((l == 'S' && ar[t] == 'B') || (l == 'B' && ar[t] == 'S')) {
            t--;
            qtd++;
        } else if ((l == 'F' && ar[t] == 'C') || (l == 'C' && ar[t] == 'F')) {
            t--;
            qtd++;
        } else {
            empilha(&t, l, ar);
        }

    }
    return 0;
}
