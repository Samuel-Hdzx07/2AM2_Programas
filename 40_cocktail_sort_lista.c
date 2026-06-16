#include <stdio.h>
#include <stdlib.h> // Necesaria para usar malloc() y atoi()
#include <time.h>   // Necesaria para generar números aleatorios y medir el tiempo (clock)

typedef struct Nodo {
    int dato;                 // El número que vamos a ordenar
    struct Nodo* siguiente;   // Puntero al vecino de la derecha (vagón siguiente)
    struct Nodo* anterior;    // Puntero al vecino de la izquierda (vagón anterior)
} Nodo;

//Funcion para crear un nuevo nodo con un valor dado
Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;     // Guardamos el número en el nodo
    //inicializamos los punteros a NULL porque aún no están conectados a ningún otro nodo
    nuevo->siguiente = NULL; 
    nuevo->anterior = NULL;  
    
    return nuevo; 
}
//Usamos doble puntero (**cabeza) para poder modificar el inicio real de la lista
void insertarFinal(Nodo** cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor); //Creamos el nuevo nodo
    
    // Si la lista está totalmente vacía (El Post-it dice NULL)
    if (*cabeza == NULL) {
        *cabeza = nuevo; // El nuevo nodo se convierte en el primero de la lista
        return;
    }
    
    // Si ya hay nodos, usamos "temp" para caminar hasta el último nodo
    Nodo* temp = *cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente; // Avanzamos al siguiente
    }
    
    // Conectamos el último nodo actual con el nuevo vagón (en ambas direcciones)
    temp->siguiente = nuevo; // El último apunta al nuevo hacia la derecha
    nuevo->anterior = temp;  // El nuevo apunta al que era el último hacia la izquierda
}


//Funcion para mostrar la lista completa desde el inicio hasta el final
void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza; // Empezamos desde el principio
    
    while (temp != NULL) {
        printf("%d ", temp->dato); // Imprimimos el número
        temp = temp->siguiente;    // Recorremos al siguiente nodo
    }
    printf("\n"); 
}

// Función que implementa el Cocktail Sort 
void cocktailSortLista(Nodo* cabeza) {
    if (cabeza == NULL) return; // Si la lista está vacía, no hay nada que ordenar

    int huboIntercambio = 1; // Bandera para saber si el ciclo debe seguir
    Nodo *inicio = cabeza;   // Límite izquierdo (empieza en el primer nodo)
    Nodo *fin = NULL;        // Límite derecho (empieza en NULL, o sea, hasta el ultimo)

    // Mientras siga habiendo intercambio, seguimos ordenando
    while (huboIntercambio) {
        huboIntercambio = 0;  
        Nodo* actual = inicio; // Empezamos en el primer nodo 

        // LA IDA (De Izquierda a Derecha) 
        // Tenemos que mandar el numero mas grande al final, así que recorremos desde el inicio hasta el fin
        while (actual->siguiente != fin) {
            // Si el número de la izquierda es mayor que el de la derecha...
            if (actual->dato > actual->siguiente->dato) {
                // los intercambiamos usando una variable auxiliar
                int aux = actual->dato;
                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = aux;
                
                huboIntercambio = 1; // Activamos la bandera
            }
            actual = actual->siguiente; // Recorremos a la derecha
        }
        // Al terminar la ida, el número mayor ya quedó en su posición correcta al final.
        // Así que recorremos el límite derecho hacia atrás.
        fin = actual;

        // Si en toda la ida no se movió nada, ¡la lista ya está perfectamente ordenada!
        if (!huboIntercambio)
            break; 

        huboIntercambio = 0; // Volvemos a apagar la bandera para la vuelta

        //Ahora vamos de derecha a izquierda 
        while (actual->anterior != NULL) {
            // Si el número de la derecha es menor que el de su izquierda...
            if (actual->dato < actual->anterior->dato) {
                // ... los intercambiamos
                int aux = actual->dato;
                actual->dato = actual->anterior->dato;
                actual->anterior->dato = aux;
                
                huboIntercambio = 1; // Prendemos la bandera
            }
            actual = actual->anterior; // Damos un paso a la izquierda
        }
        // Al terminar la vuelta, el número menor ya quedó en su posición correcta al inicio.
        // Así que recorremos el límite izquierdo un paso hacia adelante.
        inicio = inicio->siguiente;
    }
}

int main(int argc, char *argv[]) {
    // Esperamos 4 cosas: [nombre_programa] [cantidad] [minimo] [maximo]
    if (argc != 4) {
        printf("Uso incorrecto. Debe ser: ./sorth_ptr <cantidad> <minimo> <maximo>\n");
        printf("Ejemplo: ./sorth_ptr 10000 0 200000\n");
        return 1; 
    }

    // Convertimos los textos de la terminal a números enteros usando atoi()
    int cantidad = atoi(argv[1]); 
    int min = atoi(argv[2]);      
    int max = atoi(argv[3]);      

    // Validación, el mínimo no puede ser mayor al máximo
    if (min > max) {
        printf("Error: El rango minimo no puede ser mayor al maximo.\n");
        return 1;
    }

    Nodo* cabeza = NULL; // Inicializamos nuestra lista vacía

    // GENERACIÓN DE NÚMEROS ALEATORIOS
    // Plantamos la "semilla" del reloj para que los números cambien en cada ejecución
    srand(time(NULL));
    printf("Generando %d numeros aleatorios entre %d y %d...\n", cantidad, min, max);

    // Ciclo para crear los nodos aleatorios
    for (int i = 0; i < cantidad; i++) {
        // Fórmula para sacar un número aleatorio dentro del rango [min, max]
        long long  valor = min + (((long long)rand() * rand()) % (long long)(max - min + 1));
        insertarFinal(&cabeza, valor); // Lo metemos al final de la lista
    }

    // Solo imprimimos la lista original si son 200 números o menos
    // (Imprimir 10,000 números trabaría la terminal)
    if (cantidad <= 500000) {
        printf("Lista original:\n");
        imprimirLista(cabeza);
    } else {
        printf("Lista generada en memoria (oculta por ser muy grande).\n");
    }

    printf("Iniciando Cocktail Sort... (Ten paciencia)\n");

    clock_t inicio_tiempo = clock(); // Inicializamos el cronometro para medir el tiempo de ordenamiento

    cocktailSortLista(cabeza); // Iniciamos el ordenamiento usando Cocktail Sort

    clock_t fin_tiempo = clock(); // Detenemos el cronometro después de ordenar para calcular el tiempo total

    // Calculamos el tiempo total en segundos con decimales
    double tiempo_segundos = ((double)(fin_tiempo - inicio_tiempo)) / CLOCKS_PER_SEC;

    // Solo imprimimos la lista ordenada si es pequeña
    if (cantidad <= 500000) {
        printf("Lista ordenada:\n");
        imprimirLista(cabeza);
    }

    printf("\n========================================\n");
    printf("Elementos ordenados: %d\n", cantidad);
    printf("TIEMPO TOTAL: %f segundos\n", tiempo_segundos);
    printf("========================================\n");

    return 0; 
}