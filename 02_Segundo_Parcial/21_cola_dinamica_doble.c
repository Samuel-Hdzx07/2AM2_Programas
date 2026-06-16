#include <stdio.h>
#include <stdlib.h>

// 1. DEFINICIÓN DE ESTRUCTURAS
// Esta es nuestra "cajita"
typedef struct Nodo {
    int dato;                // El valor que guardamos
    struct Nodo* siguiente;  // El puntero (flecha) al siguiente nodo
} Nodo;

// Esta es la estructura que administra la fila
typedef struct Cola {
    Nodo* frente;            // Apunta al primero de la fila (el próximo en salir)
    Nodo* final;             // Apunta al último de la fila (el recién llegado)
} Cola;


// 2. INICIALIZAR LA COLA
// Siempre que creamos una cola, debemos asegurarnos de que empiece vacía.
void inicializarCola(Cola* q) {
    q->frente = NULL;
    q->final = NULL;
}


// 3. ENCOLAR (Insertar al final)
void encolar(Cola* q, int valor) {
    // Paso A: Pedimos memoria RAM para el nuevo nodo
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    
    // Paso B: Preparamos el nodo
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL; // Como va al final, no hay nadie detrás de él
    
    // Paso C: Lo metemos a la cola
    if (q->frente == NULL) {
        // Caso especial: La cola estaba vacía. 
        // El nuevo nodo es tanto el primero como el último.
        q->frente = nuevoNodo;
        q->final = nuevoNodo;
    } else {
        // Caso normal: Ya hay gente en la fila.
        // Al que estaba al final, le decimos que su "siguiente" es el nuevo nodo.
        q->final->siguiente = nuevoNodo; 
        
        // Actualizamos nuestro puntero 'final' para que apunte al nuevo nodo.
        q->final = nuevoNodo;
    }
    printf("Se encolo el valor: %d\n", valor);
}


// 4. DESENCOLAR (Extraer del frente)
// Esta función saca al nodo, libera la memoria y nos devuelve el número que guardaba.
int desencolar(Cola* q) {
    // Si la cola está vacía, no hay nada que sacar.
    if (q->frente == NULL) {
        printf("Error: La cola esta vacia.\n");
        return -1; // Retornamos -1 como código de error
    }
    
    // Paso A: Creamos un auxiliar para NO perder el rastro del nodo que vamos a borrar
    Nodo* aux = q->frente; 
    
    // Paso B: Guardamos el dato para no perderlo cuando borremos el nodo
    int valorExtraido = aux->dato;
    
    // Paso C: Movemos el 'frente' al siguiente en la fila
    q->frente = aux->siguiente;
    
    // Paso D: ¿Qué pasa si sacamos al ÚNICO elemento que había?
    // El 'frente' ya se volvió NULL (paso anterior), pero el 'final' sigue apuntando a la memoria vieja.
    if (q->frente == NULL) {
        q->final = NULL; // Dejamos todo limpio
    }
    
    // Paso E: Liberamos la memoria de la RAM (¡Evitamos el memory leak!)
    free(aux);
    
    return valorExtraido;
}


// 5. MOSTRAR LA COLA (Recorrido)
void mostrarCola(Cola* q) {
    // Usamos un auxiliar para "caminar" por la cola sin mover el 'frente'
    Nodo* aux = q->frente;
    
    printf("Estado actual de la Cola: ");
    while (aux != NULL) {
        printf("[%d] -> ", aux->dato);
        aux = aux->siguiente; // Avanzamos al siguiente nodo
    }
    printf("NULL\n");
}


// 6. FUNCIÓN PRINCIPAL
int main() {
    Cola miCola;
    inicializarCola(&miCola);
    
    // Probamos insertar datos
    encolar(&miCola, 10);
    encolar(&miCola, 20);
    encolar(&miCola, 30);
    mostrarCola(&miCola);
    
    // Probamos sacar un dato
    printf("\nAtendiendo al cliente con turno... %d\n", desencolar(&miCola));
    mostrarCola(&miCola);
    
    // Sacamos otro
    printf("\nAtendiendo al cliente con turno... %d\n", desencolar(&miCola));
    mostrarCola(&miCola);
    
    return 0;
}