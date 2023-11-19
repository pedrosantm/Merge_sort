#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mergesort(int vet[], int inicio, int fim);

int main() {
    int vet[TAM] = {3, 2, 5, 1, 4};
    printf("Vetor desordenado:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }

    mergesort(vet, 0, TAM - 1);
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}

void mergesort(int vet[], int inicio, int fim){
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergesort(vet, inicio, meio);
        mergesort(vet, meio + 1, fim);

        int i, j, k;
        int tam1 = meio - inicio + 1;
        int tam2 = fim - meio;

        int *esq = malloc(tam1 * sizeof(int));
        int *dir = malloc(tam2 * sizeof(int));

        for (i = 0; i < tam1; i++)
            esq[i] = vet[inicio + i];
        for (j = 0; j < tam2; j++)
            dir[j] = vet[meio + 1 + j];

        i = 0;
        j = 0;
        k = inicio;

        while (i < tam1 && j < tam2) {
            if (esq[i] <= dir[j]) {
                vet[k] = esq[i];
                i++;
            } else {
                vet[k] = dir[j];
                j++;
            }
            k++;
        }

        while (i < tam1) {
            vet[k] = esq[i];
            i++;
            k++;
        }

        while (j < tam2) {
            vet[k] = dir[j];
            j++;
            k++;
        }

        free(esq);
        free(dir);
    }
}
