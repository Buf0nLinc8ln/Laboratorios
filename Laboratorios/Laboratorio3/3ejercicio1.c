#include <stdio.h>



int main() {

    // se inicializa el array bidimensional con valores

    int matriz[3][3] = {
        {1, 2, 3},
        {1, 5, 3},         // ejemplo #1
        {1, 2, 8}
    };

    // int matriz[4][4] = {
    //     {1, 2, 3, 4},
    //     {1, 7, 3, 4},         // ejemplo #2
    //     {1, 2, 9, 4},
    //     {1, 2, 3, 12}
    // };

    // int matriz[5][5] = {
    //     {1, 2, 3, 4, 5},
    //     {1, 2, 3, 4, 5},         // ejemplo #3
    //     {1, 2, 3, 4, 5},
    //     {1, 2, 3, 4, 5},
    //     {1, 2, 3, 4, 5}
    // };

    // se inicia con el primer elemento de la diagonal.

    
    int suma = 0;

    int j = 0;

    // tamano de la matriz, como se sabe que son cuadradas con solo saber la cantidad de filas basta.

    int tamano = sizeof(matriz) / sizeof(matriz[0]);

    // se recorre la matriz por filas.

    for (int i = 0; i < tamano; i++) {
        
        suma += matriz[i][j];
        j += 1;

    }

    if (tamano % 2 == 0) {

        j = tamano - 1;

        for (int i = 0; i < tamano; i++) {
        
        suma += matriz[i][j];

        j -= 1;
    
        } 

    } else {

        j = tamano - 1;

        for (int i = 0; i < tamano; i++) {

            if (i == tamano / 2 && j == tamano / 2) {
                j -= 1;
                continue;
            }
        
            suma += matriz[i][j];

            j -= 1;
        
        }
    }
    
    printf("Suma de los elementos de las diagonales: %d\n", suma);

    return 0;
}






// inicio
    //  definir arreglo_bidimensional[filas][columnas] de enteros
    //  definir variable suma = 0 como entero 
    //  definir variable j = 0 como entero 
    //  definir variable tamano igual a size matriz / size filas

    //  for i desde 0 hasta tamano
    //      agregar valor de elemento de matriz a suma con "+="
    //      ncrementar en 1 a j con "+= 1"

    //  si el residuo de tamano igual a 0
    //      definir j como tamano - 1
    //      for i desde 0 hasta tamano
    //          agregar valor de elemento de matriz a suma con "+="
    //          disminuir en 1 a j con "-="
    //  sino
    //      definir j como tamano - 1
    //      for i desde 0 hasta tamano
    //          si i y j son iguales a tamano / 2
    //              disminuir en 1 a j con "-="
    //              saltar a siguiente iteracion
    //          agregar valor de elemento de matriz a suma con "+="
    //          disminuir en 1 a j con "-="
    //  imprimir resultado de suma
// fin.