#include <stdio.h>
#include <string.h>
#define max 1000

typedef struct {
    char palavra[max];
    int qtd;
}palavras;

void intercala(int p, int m, int u, palavras *v) {
    int i, j, k;
    i = p; j = m; k = 0;

    palavras aux[max];

    while (i < m && j < u) {
        if (v[i].qtd >= v[j].qtd) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    while (i < m) {
        aux[k] = v[i];
        i++;
        k++;
    }
    while (j < u) {
        aux[k] = v[j];
        j++;
        k++;
    }
    for (int c = p; c < u; c++) {
        v[c] = aux[c-p];
    }
}

void mergesort(int p, int u, palavras *v) {
    int m;

    if (p < u-1) {
        m = (p+u)/2;
        mergesort(p, m, v);
        mergesort(m, u, v);
        intercala(p, m, u, v);
    }
}

int main(void) {
    int vezes, i = 0, q = 0, n = 0, k = 0;
    char vetor_aux[max];

    scanf("%d", &vezes);

    for (int v = 0; v < vezes; v++) {
        palavras vetor_string[max];

        scanf(" %[^\n]", vetor_aux);

        while (vetor_aux[i] != '\0') {
            if(vetor_aux[i] != ' ') {
                vetor_string[n].palavra[k] = vetor_aux[i];
                q++;
                k++;
            } else {
                vetor_string[n].palavra[k] = '\0';
                vetor_string[n].qtd = q;
                n++;
                q = 0;
                k = 0;
            }
            i++;
        }
        vetor_string[n].palavra[k] = '\0';
        vetor_string[n].qtd = q;

        mergesort(0, n+1, vetor_string);

        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                printf("%s", vetor_string[j].palavra);
            } else {
                printf(" %s", vetor_string[j].palavra);
            }
        }
        printf("\n");
        i = 0;
        q = 0;
        n = 0;
        k = 0;
    }
    return 0;
}
