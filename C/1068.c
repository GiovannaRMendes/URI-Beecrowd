#include <stdio.h>
#include <string.h>
#define max 1000

void empilha_seq(int *t, char *pilha, char y, int n) {

    if (*t != n - 1) {
        (*t)++;
        pilha[*t] = y;
    }
}

void bdp(char *palavra, int n) {
    int t = -1;
    char pilha[n];

    for (int c = 0; palavra[c] != '\0'; c++) {
        
        if (t == -1 && palavra[c] == ')') {
            printf("incorrect\n");
            return;
        }
        else if (palavra[c] == '(') {
            empilha_seq(&t, pilha, palavra[c], n);
        }
        else if (t != - 1) {
            if (palavra[c] == ')' && pilha[t] == '(') {
                t--;
            }
        }
    }
    if (t == -1) {
        printf("correct\n");
        return;
    } else {
        printf("incorrect\n");
        return;
    }
}

int main(void) {
    char palavra[max];

    while (scanf(" %s", palavra) != EOF) {
        bdp(palavra, strlen(palavra));
    }
    return 0;
}
