#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void allocateMatrix(int ***matrix, int filas, int columnas) {
    *matrix = malloc(filas * sizeof(int*));
    for (int f = 0; f < filas; f++) {
        (*matrix)[f] = malloc(columnas * sizeof(int));
    }
}

void fillMatrix(int **matrix, int filas, int columnas) {
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            *(*(matrix + f) + c) = (rand() % 10) + 1; 
        }
    }
}

// void redimensionarMatrix(int ***matrix, int m1, int n1, int m2, int n2) {
//     int filasNuevas, columnasNuevas;
//     if (m1 > m2) {
//         int filasNuevas = m1 - m2;
//         for (int f = m1 - 1; f < m2; f--) {
//             free(matrix[f]);
//         }
//     } 

//     if (n1 > n2) {
//         int columnasNuevas = n1 - n2;
//         for (int f = filasNuevas - 1; f >= 0; f--) {
//             for (int c = n1 - 1; c < n2; c--)
//                 free(matrix[f][c]);
//         }
//     }

//     if (m1 < m2) {
//         int filasNuevas = m2 - m1;

//         for (int f = m1 - 1; f < (m1 + filasNuevas); f++) {
//             *matrix = malloc(sizeof(int*));
//             (*matrix)[f] = malloc(n2 * sizeof(int));
//         }
//     }

    

//     if (n1 < n2) {
//         int columnasNuevas = n2 - n1;
//         for (int f = 0; f < filas; f++) {

//             (*matrix)[f] = malloc(columnas * sizeof(int));
//         }


//     }


// }

void redimensionarMatrix(int **matrix1, int **matrix2, int m1, int n1, int m2, int n2) {

    if (m1 > m2 && n1 > n2) { // caso 1

        for (int f = 0; f < m2; f++) {
            for (int c = 0; c < n2; c++) {                          // copiar matriz
                *(*(matrix2 + f) + c) = *(*(matrix1 + f) + c); 
            }
        }

    }

    if (m1 > m2 && n1 < n2) { // caso 2

        for (int f = 0; f < m2; f++) {
            for (int c = 0; c < n1; c++) {                          // copiar matriz
                *(*(matrix2 + f) + c) = *(*(matrix1 + f) + c); 
            }
        }

        for (int f = 0; f < m2; f++) {
            for (int c = n1; c < n2; c++) {
                *(*(matrix2 + f) + c) = (rand() % 10) + 1;          // llenar el resto
            }
        }

    }

    if (m1 < m2 && n1 > n2) { // caso 3

        for (int f = 0; f < m1; f++) {
            for (int c = 0; c < n2; c++) {                          // copiar matriz
                *(*(matrix2 + f) + c) = *(*(matrix1 + f) + c); 
            }
        }

        for (int f = m1; f < m2; f++) {
            for (int c = 0; c < n2; c++) {
                *(*(matrix2 + f) + c) = (rand() % 10) + 1;          // llenar el resto
            }   
        }

    }

    if (m1 < m2 && n1 < n2) { // caso 4

        for (int f = 0; f < m1; f++) {
            for (int c = 0; c < n1; c++) {
                *(*(matrix2 + f) + c) = *(*(matrix1 + f) + c);      // copiar matriz
            }
        }


        for (int f = 0; f < m2; f++) {
            if (f >= m1) {
                for (int c = 0; c < n2; c++) {
                    *(*(matrix2 + f) + c) = (rand() % 10) + 1;      // llenar el resto
                }

            } else {
                for (int c = n1; c < n2; c++) {
                    *(*(matrix2 + f) + c) = (rand() % 10) + 1; 
                }
            }   
        }
    }

}

void printMatrix(int **matrix, int filas, int columnas) {
    printf("Matrix (%dx%d): \n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d  ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {

    srand(time(NULL));

    int filas1, columnas1;
    int **matrix1 = NULL;
    printf("Ingrese el # de filas de la matriz: ");
    scanf("%d", &filas1);
    printf("Ingrese el # de columnas de la matriz: ");
    scanf("%d", &columnas1);

    allocateMatrix(&matrix1, filas1, columnas1);

    fillMatrix(matrix1, filas1, columnas1);

    printMatrix(matrix1, filas1, columnas1);

    int filas2, columnas2;
    int **matrix2 = NULL;
    printf("Ingrese el # de filas de la matriz: ");
    scanf("%d", &filas2);
    printf("Ingrese el # de columnas de la matriz: ");
    scanf("%d", &columnas2);

    allocateMatrix(&matrix2, filas2, columnas2);
    redimensionarMatrix(matrix1, matrix2, filas1, columnas1, filas2, columnas2);
    printMatrix(matrix2, filas2, columnas2);

    freeMatrix(matrix1, filas1);
    freeMatrix(matrix2, filas2);

    return 0;

}
