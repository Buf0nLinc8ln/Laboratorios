#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Funcion para encontrar la longitud de la linea mas larga de 1s en una matriz
cuadrada de tamano size.

Params
− int **matrix: Puntero a la matriz cuadrada de enteros.
− int size: Tamano de la matriz (numero de filas y columnas).
− int *result: Puntero donde se almacenara la longitud de la secuencia mas
larga de 1s.

Retorno:
− No retorna un valor, pero modifica el valor en result.
*/

void findLargestLine(int **matrix, int size, int * result) {

    for (int f = 0; f < size; f++) {
        int newresult = 0;
        for (int c = 0; c < size; c++) {
            if (*(*(matrix + f) + c) == 1) {
                newresult++;
                if (newresult > *result) {
                    *result = newresult;
                }
            } else {
                newresult = 0;
            }
        }
    }
}

// funcion de buscar secuencia mas larga de unos
//      parametros:
//      (puntero a la matriz, tamano de la matriz, puntero longitud)
    //  for filas desde 0 hasta size
    //      definir contador de 1s en 0
    //      for columnas desde 0 hasta size
    //          si el puntero de elemento de la matriz es igual a 1
    //              se aumenta el contador de 1s
    //              si contador de 1s > puntero longitud
    //                  puntero longitud = contador de 1s
    //              sino 
    //                  se reinicia contador de 1s
    //      finfor
    //   finfor
// finfuncion

/*
Funcion para reservar la matriz en memoria dinamica.

Params:
− int ***matrix: Doble puntero para la matriz que sera creada.
− int size: Tamano de la matriz (numero de filas y columnas).

Retorno:
− No retorna un valor. Reserva memoria para la matriz.
*/

void allocateMatrix(int ***matrix, int size) {
    *matrix = malloc(size * sizeof(int*));
    for (int f = 0; f < size; f++) {
        (*matrix)[f] = malloc(size * sizeof(int));
    }
}

// funcion para reservar la matriz en memoria dinamica.
//      parametros:
//      (direccion puntero a la matriz, tamano de la matriz)
//      puntero matriz igual a malloc(tamano de la matriz * tamano en bytes de puntero a entero)
//      for filas desde 0 hasta size
//          puntero matriz[filas] igual a malloc(tamano de la matriz * tamano en bytes entero)
//      finfor
// finfuncion

/*
Funcion para llenar la matriz con numeros aleatorios (0s y 1s).

Parametros:
− int **matrix: Puntero a la matriz a llenar.
− int size: tamano de la matriz (numero de filas y columnas).

Retorno:
− No retorna un valor. Llena la matriz con valores aleatorios.
*/

void fillMatrix(int **matrix, int size) {
    for (int f = 0; f < size; f++) {
        for (int c = 0; c < size; c++) {
            *(*(matrix + f) + c) = rand() % 2; 
        }
    }
}

// funcion void para llenar la matriz con numeros aleatorios (0s y 1s)
//      parametros:
//      (puntero a la matriz, tamano de la matriz)
    //  for filas desde 0 hasta size
    //      for columnas desde 0 hasta size
//             valor elemento = rand() con rango de 0 a 1
    //      finfor
    //   finfor
// finfuncion

/*
Funcion para imprimir la matriz.

Params:
− int **matrix: Puntero a la matriz que se va a imprimir.
− int size: tamano de la matriz (numero de filas y columnas).

Retorno:
− No retorna un valor. Imprime la matriz en la salida estandar.
*/
void printMatrix(int **matrix, int size) {
    printf("Matrix (%dx%d): \n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

/*
Funcion para liberar la memoria asignada a la matriz.

Params:
− int **matrix: Puntero a la matriz que se va a liberar.
− int size: tamano de la matriz (numero de filas y columnas).

Retorno:
− No retorna un valor. Libera la memoria utilizada por la matriz.
*/
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}



int main() {

    srand(time(NULL));

    int size, largestLine = 0;
    int **matrix = NULL;
    printf("Ingrese el tamano de la matriz cuadrada: ");
    scanf("%d", &size);

    allocateMatrix(&matrix, size);

    fillMatrix(matrix, size);

    printMatrix(matrix, size);

    findLargestLine(matrix, size, &largestLine);

    freeMatrix(matrix, size);

    printf("\nEl tamano de la secuencia de 1s mas grande es: %d\n", largestLine);
    return 0;

}

// funcion de buscar secuencia mas larga de unos
//      parametros:
//      (puntero a la matriz, tamano de la matriz, puntero longitud)
    //  for filas desde 0 hasta size
    //      definir contador de 1s en 0
    //      for columnas desde 0 hasta size
    //          si el puntero de elemento de la matriz es igual a 1
    //              se aumenta el contador de 1s
    //              si contador de 1s > puntero longitud
    //                  puntero longitud = contador de 1s
    //              sino 
    //                  se reinicia contador de 1s
    //      finfor
    //   finfor
// finfuncion

// funcion para reservar la matriz en memoria dinamica.
//      parametros:
//      (direccion puntero a la matriz, tamano de la matriz)
//      puntero matriz igual a malloc(tamano de la matriz * tamano en bytes de puntero a entero)
//      for filas desde 0 hasta size
//          puntero matriz[filas] igual a malloc(tamano de la matriz * tamano en bytes entero)
//      finfor
// finfuncion

// funcion para llenar la matriz con numeros aleatorios (0s y 1s)
//      parametros:
//      (puntero a la matriz, tamano de la matriz)
    //  for filas desde 0 hasta size
    //      for columnas desde 0 hasta size
//             valor elemento = rand() con rango de 0 a 1
    //      finfor
    //   finfor
// finfuncion

// inicio
//      cambiar la "semilla" conforme el tiempo
//      definir size y tamano de la secuencia en cero
//      definir el puntero de la matriz como nulo
//      solicitar al usuario el tamano de la matriz
//      ejecutar la funcion de reservar memoria dinamica de la matriz
//      ejecutar la funcion de llenar la matriz con 0s y 1s aleatorios
//      ejecutar la funcion de imprimir matriz
//      ejecutar la funcion de buscar la secuencia de 1s mas grande de cada fila.
//      ejecutar la funcion para liberar memoria dinamica.
//      imprimir la secuencia
//      retornar 0
// fin