#include <stdio.h>
#include <stdlib.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mediana(int arr[], int ini, int fim) {
    int meio = ini + (fim - ini) / 2;

    if (arr[ini] > arr[meio]) {
        trocar(&arr[ini], &arr[meio]);
    }
    if (arr[ini] > arr[fim]) {
        trocar(&arr[ini], &arr[fim]);
    }
    if (arr[meio] > arr[fim]) {
        trocar(&arr[meio], &arr[fim]);
    }
    trocar(&arr[meio], &arr[fim]);
}

int partir(int arr[], int ini, int fim) {
    int pivo = arr[fim], i = (ini - 1);

    for (int j = ini; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

void quicksort(int arr[], int ini, int fim) {
    while (ini < fim) {
        mediana(arr, ini, fim);
        int indice = partir(arr, ini, fim);

        if (indice - ini < fim - indice) {
            quicksort(arr, ini, indice - 1);
            ini = indice + 1;
        }
        else {
            quicksort(arr, indice + 1, fim);
            fim = indice - 1;
        }
    }
}

int main() {
    int NC;

    scanf("%d",&NC);
    if (NC == 0) return 0;

    int N;
    while (NC > 0) {
        scanf("%d",&N);
        int* arr = (int*)malloc(N*sizeof(int));

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        quicksort(arr, 0, N - 1);

        for (int i = 0; i < N; i++) {
            printf("%d%c", arr[i], i == N - 1 ? '\0' : ' ');
        }
        printf("\n");

        free(arr);
        NC--;
    }

    return 0;
}