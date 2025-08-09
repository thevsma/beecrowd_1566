#include <stdio.h>
#include <stdlib.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
    if (ini < fim) {
        int indice = partir(arr, ini, fim);
        quicksort(arr, ini, indice - 1);
        quicksort(arr, indice + 1, fim);
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
            printf("%d ", arr[i]);
        }

        free(arr);
        NC--;
    }

    return 0;
}
