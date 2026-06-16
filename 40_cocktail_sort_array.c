#include <stdio.h>
#include <stdlib.h> // Necesaria para usar atoi()

// Función que implementa el algoritmo Cocktail Sort
void cocktailSort(int arr[], int n) {
    int swapped = 1;       // Indica si hubo intercambios en la pasada
    int start = 0;         // Límite izquierdo del arreglo
    int end = n - 1;       // Límite derecho del arreglo
    int temp;              // Variable auxiliar para intercambiar valores

    // El ciclo se repite mientras haya intercambios
    while (swapped) {
        swapped = 0; // Se reinicia antes de cada recorrido

        // Recorrido de izquierda a derecha
        // Mueve el elemento mayor hacia el final del arreglo
        for (int i = start; i < end; i++) {
            // Si el elemento actual es mayor que el siguiente, están desordenados
            if (arr[i] > arr[i + 1]) {
                // Intercambio usando variable temporal para no perder información
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                // Se marca que hubo un intercambio
                swapped = 1;
            }
        }

        // Si no hubo intercambios, el arreglo ya está ordenado
        if (!swapped)
            break;

        // Se reinicia la variable para la siguiente pasada
        swapped = 0;

        // Se reduce el límite derecho porque el mayor ya quedó en su posición final
        end--;

        // Recorrido de derecha a izquierda
        // Mueve el elemento menor hacia el inicio del arreglo
        for (int i = end - 1; i >= start; i--) {
            // Si el elemento actual es mayor que el siguiente, están desordenados
            if (arr[i] > arr[i + 1]) {
                // Intercambio usando variable temporal
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                // Se marca que hubo un intercambio
                swapped = 1;
            }
        }

        // Se aumenta el límite izquierdo porque el menor ya quedó en su posición inicial
        start++;
    }
}

int main(int argc, char *argv[]) {
    // Verifica que el usuario haya ingresado al menos un número
    if (argc < 2) {
        printf("El programa necesita argumentos\n");
        return 1; // Termina el programa con error
    }

    // El número de elementos que tendra el arreglo es igual a la cantidad de argumentos menos uno (el nombre del programa)
    int n = argc - 1;

    // Se crea un arreglo de tamaño n
    int arr[n];

    // Conversión de argumentos (texto) a enteros
    for (int i = 0; i < n; i++) {
        // argv[i + 1] contiene los números como texto (string)
        // atoi convierte ese texto a número entero
        arr[i] = atoi(argv[i + 1]);
    }

    cocktailSort(arr, n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n"); 

    return 0; 
}