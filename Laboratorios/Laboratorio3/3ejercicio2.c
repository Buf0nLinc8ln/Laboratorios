#include <stdio.h>

int encontrarMaximo (int arr[], int n) {
    int maximo = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }

    return maximo;
}

int main() {
    int numeros[ ] = {10, 20, 5, 40, 30};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    printf("Array: \n");
    for (int e = 0; e < n; e++) {
        printf("%d ", numeros[e]);
    }
    printf("\n");
    int maximo = encontrarMaximo (numeros, n);
    printf("El numero mas grande es: %d\n", maximo);
    return 0;
}.