#include <stdio.h>
#include <string.h>
#define max 21

int tamanho(char palavra[]) {
    int n = 0, i = 0;
    while (palavra[i] != '\0') {
        i++;
    }
    return i;
}

int comparacao(char pl1[], char pl2[]) {
    int n = 0, i = 0;
    while (pl1[i] != '\0') {
        if (i == 0) {
            if (pl1[i] == pl2[i]) {
            n++;
            }
        } else {
            if (pl1[i] == pl2[i] && n != 0) {
                n++;
            }
        }
        i++;
    }
    return n;
}

int main() {
    char idioma[max], aux[max];
    int qtd, vez, n = 0, tamA, tamI, c = 0;

    scanf("%d", &qtd);

    for (int q = 0; q < qtd; q++) {
        scanf("%d", &vez);

        for (int v = 0; v < vez; v++) {

            if (v == 0) {
              scanf(" %s", aux);
              tamA = tamanho(aux);
            } else {
                scanf(" %s", idioma);
                n = n + comparacao(idioma, aux);
                tamI = tamanho(idioma);

                if (tamI != tamA) {
                    c++;
                }
            }
        }

        if (n != 0 && c == 0) {
            printf("%s\n", aux);
        } else {
            printf("ingles\n");
        }
        n = 0;
        c = 0;
    }
    return 0;
}
