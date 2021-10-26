#include <stdio.h>
#define max 1001

typedef struct {
    int num_ascii;
    int frequencia;
}ascii;

void troca(char *a, char *b) {
  char aux;

  aux = *a;
  *a = *b;
  *b = aux;
}

int selectionsort(char v[]) {
  int min, q = 0;

  for (int i = 0; v[i] != '\0'; i++) {
    min = i;
    q++;

    for (int j = i+1; v[j] != '\0'; j++)
      if (v[j] < v[min])
        min = j;
    troca(&v[i], &v[min]);
  }
  return q;
}

void intercala(int p, int m, int u, ascii *v) {
    int i = p, j = m, n = 0;
    ascii aux[max];

    while(i < m && j < u) {
        if ((v[i].frequencia < v[j].frequencia) || (v[i].frequencia == v[j].frequencia && v[i].num_ascii > v[j].num_ascii)) {
            aux[n] = v[i];
            i++;
        } else {
            aux[n] = v[j];
            j++;
        }
        n++;
    }
    while(i < m) {
        aux[n] = v[i];
        i++;
        n++;
    }
    while(j < u) {
        aux[n] = v[j];
        j++;
        n++;
    }
    for (i = p; i < u; i++)
        v[i] = aux[i-p];
}

void mergesort(int p, int u, ascii *v) {
    int m;

    if(p < u-1) {
        m = (p+u)/2;
        mergesort(p, m, v);
        mergesort(m, u, v);
        intercala(p, m, u, v);
    }
}

int main(void) {
    char carac[max];
    int i = 0, q, d = 0, qtd = 1, l = 0;

    while((scanf(" %[^\n]", carac)) != EOF && l >= 0) {
        ascii vetor_ascii[max];
        if (l > 0) {
            printf("\n");
        }

        q = selectionsort(carac);

        vetor_ascii[0].num_ascii = carac[0];
        i = 1;
        for (int n = 1; n <= q; n++) {
            if (carac[n-1] == carac[n]) {
                qtd++;
            } else {
                vetor_ascii[i-1].frequencia = qtd;
                qtd = 1;
                vetor_ascii[i].num_ascii = carac[n];
                i++;
                d++;
            }
        }

        mergesort(0, d, vetor_ascii);

        for (int p = 0; p < d; p++) {
            printf("%d %d\n", vetor_ascii[p].num_ascii, vetor_ascii[p].frequencia);
        }

        l++;
        i = 0;
        d = 0;
        qtd = 1;
    }
    return 0;
}
