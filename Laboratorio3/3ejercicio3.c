#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 7

int findLargestLine(int matrix[][size]) {

    int tamano = 0;

    
// para las diagonales de izquierda a derecha

    for (int i = 0; i < size; i++) {
        int c = 0;
        int newtamano = 0;
        for (int f = i; f < size && c < size; f++) {
            if (matrix[f][c] == 1) {
                newtamano ++;
                if (newtamano > tamano) {
                    tamano = newtamano;
                }
            } else {
                newtamano = 0;
            }
            c++;
        }
    }
    for (int i = 0; i < size - 1; i++) {
        int c = 1 + i;
        int newtamano = 0;
        for (int f = 0; f < size - 1 && c < size; f++) {
            if (matrix[f][c] == 1) {
                newtamano ++;
                if (newtamano > tamano) {
                    tamano = newtamano;
                }
            } else {
                newtamano = 0;
            }

            c++;

        }

    }

    // para las diagonales de derecha a izquierda

    for (int i = 0; i < size; i++) {
        int c = size - 1;
        int newtamano = 0;
        for (int f = i; f < size && c >= 0; f++) {
            if (matrix[f][c] == 1) {
                newtamano ++;
                if (newtamano > tamano) {
                    tamano = newtamano;
                }
            } else {
                newtamano = 0;
            }
            c--;
        }
    }
    for (int i = 0; i < size - 1; i++) {
        int c = (size - 2) - i;
        int newtamano = 0;
        for (int f = 0; f < size && c >= 0; f++) {
            if (matrix[f][c] == 1) {
                newtamano ++;
                if (newtamano > tamano) {
                    tamano = newtamano;
                }
            } else {
                newtamano = 0;
            }
            c--;
        }
    }
    return tamano;
}

void MakeMatrixAleatoria(int matrix[][size]) {
    printf("La matriz de tamano %d utilizada corresponde a :\n", size);
    for (int f = 0; f < size; f++) {
        for (int c = 0; c < size; c++) {
            matrix[f][c] = rand() % 2;  // rellena la matriz con unos y ceros.
            printf("%d ", matrix[f][c]);
        }
        printf("\n");
    }
    
}

int main() {
    srand(time(NULL));

    int matrix[size][size];
    MakeMatrixAleatoria(matrix);

    int largestLine = findLargestLine(matrix);
    printf("El tamano de la secuencia de 1s mas grande es: %d\n" , largestLine);

    return 0;
}

// definir size fijo de matriz cuadrada
// funcion de buscar secuencia mas larga de unos.
//      definir contator de tamano en 0
    //  for i desde 0 hasta size
    //      definir inicio de la columna en 0
    //      definir contador de 1s en 0
    //      for f desde igual a i hasta f < size y c < size
    //          si el elemento de la matriz es igual a 1
    //              se aumenta el contador de 1s
    //              si contador de 1s > contador de tamano
    //                  contador de tamano = contador de 1s
    //              sino 
    //                  se reinicia contador de 1s
    //          se incrementa c
    //      finfor
    //   finfor

    // for i desde 0 hasta size - 1
    //      definir inicio de la columna en 1 + i 
    //      definir contador de 1s en 0
    //      for f desde 0 hasta f < size - 1 y c < size
    //          si el elemento de la matriz es igual a 1
    //              se aumenta el contador de 1s
    //              si contador de 1s > contador de tamano
    //                  contador de tamano = contador de 1s
    //              sino 
    //                  se reinicia contador de 1s
    //          se incrementa c
    //      finfor
//     finfor

    // for i desde 0 hasta size
    //      definir inicio de la columna en size - 1
    //      definir contador de 1s en 0
    //      for f desde igual a i hasta f < size y c >= 0
    //          si el elemento de la matriz es igual a 1
    //              se aumenta el contador de 1s
    //              si contador de 1s > contador de tamano
    //                  contador de tamano = contador de 1s
    //              sino 
    //                  se reinicia contador de 1s
    //          se decrementa c
    //      finfor
//     finfor


    // for i desde 0 hasta size - 1
    //      definir inicio de la columna en (size - 2) - i
    //      definir contador de 1s en 0
    //      for f desde 0 hasta f < size y c >= 0
    //          si el elemento de la matriz es igual a 1
    //              se aumenta el contador de 1s
    //              si contador de 1s > contador de tamano
    //                  contador de tamano = contador de 1s
    //              sino 
    //                  se reinicia contador de 1s
    //          se decrementa c
    //      finfor
//     finfor

    // retornar tamano
// fin

    // funcion void para hacer la matriz aleatoria
    //      imprimir titulo 
    //      for f desde 0 hasta size 
    //          for c desde 0 hasta size
    //              anadir elemento aleatorio entre 0 y 1
    //              imprimir elemento
    //          imprimir salto de linea

// inicio
//      cambiar la "semilla" conforme el tiempo
//      definir la matriz conforme size
//      definir el tamano de la secuencia
//      imprimir la secuencia
//      retornar 0
// fin



