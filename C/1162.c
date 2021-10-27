#include <stdio.h>

void troca(int *a, int *b) {
  int aux;

  aux = *a;
  *a = *b;
  *b = aux;
}

int bubblesort(int n, int v[]) {
    int qtd = 0;

  for (int i = n-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {

      if (v[j] > v[j+1]) {
        troca(&v[j], &v[j+1]);
        qtd++;
      }
    }
  }
  return qtd;
}

int main(void) {
    int testes, vagoes, qtd;

    scanf("%d", &testes);

    for (int t = 0; t < testes; t++) {
        scanf("%d", &vagoes);

        int v[vagoes];

        for(int n = 0; n < vagoes; n++) {
            scanf(" %d", &v[n]);
        }
        qtd = bubblesort(vagoes, v);

        printf("Optimal train swapping takes %d swaps.\n", qtd);
    }
    return 0;
}
