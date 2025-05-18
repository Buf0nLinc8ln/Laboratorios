#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *archivo = fopen("input.txt", "r");
    if (archivo != NULL) {

        char lineas[100];
        char palabra_invertida[100];
        char palindromo[100];
        int tamano_palindromo = 0;

        while (fgets(lineas, sizeof(lineas), archivo) != NULL) {

            char *palabra = strtok(lineas, ".,;:¡!¿?()[]{}\"'«»–—-_\\/|@#$%^&*~`+=<> ");

            while (palabra != NULL) {

                for (int c = 0; palabra[c] != '\0'; c++) {
                    palabra[c] = tolower(palabra[c]);
                }
                
                for (int i = 0; i < strlen(palabra); i++) {
                    palabra_invertida[i] = palabra[strlen(palabra) - 1 - i];
                }

                palabra_invertida[strlen(palabra)] = '\0';

                if (strcmp(palabra, palabra_invertida) == 0 && strlen(palabra) > tamano_palindromo) { 
    
                        tamano_palindromo = strlen(palabra);
                        strcpy(palindromo, palabra);

                }
                palabra = strtok(NULL, ".,;:¡!¿?()[]{}\"'«»–—-_\\/|@#$%^&*~`+=<> ");
            }
                
        }

        fclose(archivo); 
        printf("El palíndromo mas largo encontrado es: '%s'\n", palindromo);

    } else {
        printf("Error al abrir el archivo.\n");
    }
    return 0;
}

// inicio
//      abrir archivo en modo lectura con "fopen"
//      si "fopen" retorna diferente a "NULL"
//          definir char "lineas" tamano 100
//          definir char "palabra_invertida" tamano 100
//          definir char "palindromo" tamano 100
//          definir tamano_palindromo igual a 0
//          while la linea sea diferente de "null"
//              separar las lineas por palabras sin ".,;:¡!¿?()[]{}\"'«»–—-_\\/|@#$%^&*~`+=<> "
//              while la palabra sea diferente a "null"
//                  for cada caracter de la palabra hasta "\0"
//                      caracter igual a "tolower(palabra)"
            //      finfor
//                  for cada indice desde 0 hasta "strlen(palabra)"
//                      palabra_invertida[indice] = palabra[strlen(palabra)- 1 - indice]
            //      finfor
//                  definir ultimo caracter de palabra_invertida igual a "\0"
//                  si ("palabra" y "palabra_invertida" son igual) y (tamano_palabra > tamano_palindromo)
//                      tamano_palindromo es igual a tamano_palabra
//                      palindromo es igual a palabra
//          cerrar archivo
//          imprimir palindromo
//      sino error al abrir archivo
// fin