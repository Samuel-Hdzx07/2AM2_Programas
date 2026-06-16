#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Definición de la estructura del nodo
struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};

// 2. Función auxiliar para crear un nuevo nodo en la memoria
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

//Contar los nodos pares e impares 
// ==========================================
// NUEVA FUNCIÓN: CONTAR NODOS (La de la clase)
// ==========================================
//dado un numero imprimir todos los nodos mayores a ese numero

void imprimirNodosMayores(struct Nodo* nodo, int numero){
    if(nodo == NULL) return;
    if(nodo->dato > numero){
        printf("%d ", nodo->dato);
    }
    imprimirNodosMayores(nodo->izquierda, numero);
    imprimirNodosMayores(nodo->derecha, numero);
}

void imprimirNodosMenors(struct Nodo* nodo, int numero){
    if(nodo == NULL) return;
    if(nodo->dato < numero){
        printf("%d ", nodo->dato);
    }
    imprimirNodosMayores(nodo->izquierda, numero);
    imprimirNodosMayores(nodo->derecha, numero);
}

void pertenencia(struct Nodo* nodo, int numero){

    if(nodo == NULL) {
        printf("El numero %d no pertenece al arbol.\n", numero);
        return;
    }

    if(nodo->dato == numero) {
        printf("El numero %d pertenece al arbol.\n", numero);
        return;
    }
}


int contarNodos(struct Nodo* nodo) {
    // Si el nodo actual está vacío, aporta 0 a la cuenta
    if (nodo == NULL) {
        return 0;
    }
    // Retorna 1 (el nodo actual) + lo que cuente a la izquierda + lo que cuente a la derecha
    return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
}

// ==========================================
// MÉTODOS DE RECORRIDO
// ==========================================

// Pre-orden: Raíz -> Izquierda -> Derecha
void preOrden(struct Nodo* nodo) {
    if (nodo == NULL) return;
    
    printf("%d ", nodo->dato);       // Visita la Raíz
    preOrden(nodo->izquierda);       // Recorre el subárbol izquierdo
    preOrden(nodo->derecha);         // Recorre el subárbol derecho
}

// In-orden: Izquierda -> Raíz -> Derecha
void inOrden(struct Nodo* nodo) {
    if (nodo == NULL) return;
    
    inOrden(nodo->izquierda);        // Recorre el subárbol izquierdo
    printf("%d ", nodo->dato);       // Visita la Raíz
    inOrden(nodo->derecha);          // Recorre el subárbol derecho
}

// Post-orden: Izquierda -> Derecha -> Raíz
void postOrden(struct Nodo* nodo) {
    if (nodo == NULL) return;
    
    postOrden(nodo->izquierda);      // Recorre el subárbol izquierdo
    postOrden(nodo->derecha);        // Recorre el subárbol derecho
    printf("%d ", nodo->dato);       // Visita la Raíz
}

// In-orden Descendente (INVERSO): Derecha -> Raíz -> Izquierda
void inOrdenDescendente(struct Nodo* nodo) {
    if (nodo == NULL) return;
    
    inOrdenDescendente(nodo->derecha);    // Recorre el subárbol DERECHO primero
    printf("%d ", nodo->dato);             // Visita la Raíz
    inOrdenDescendente(nodo->izquierda);  // Recorre el subárbol IZQUIERDO
}

int nodosHoja(struct Nodo* nodo) {
    if (nodo == NULL) {
        return 0; // No hay nodos, por lo tanto no hay hojas
    }
    if (nodo->izquierda == NULL && nodo->derecha == NULL) {
        return 1; // Es un nodo hoja
    }
    // Suma las hojas del subárbol izquierdo y derecho
    return nodosHoja(nodo->izquierda) + nodosHoja(nodo->derecha);
}

// ==========================================
// FUNCIÓN PARA RECOLECTAR CLAVES
// ==========================================
void recolectarClaves(struct Nodo* nodo, int arr[], int* indice) {
    if (nodo == NULL) return;
    
    arr[*indice] = nodo->dato;
    (*indice)++;
    
    recolectarClaves(nodo->izquierda, arr, indice);
    recolectarClaves(nodo->derecha, arr, indice);
}

// Comparador para qsort (orden descendente)
int compararDescendente(const void* a, const void* b) {
    return *(int*)b - *(int*)a;  // Mayor a menor
}

// Función RECURSIVA para imprimir un arreglo
void imprimirArregloRecursivo(int arr[], int indice, int pos) {
    if (pos >= indice) return;  // Caso base: llegó al final
    
    printf("%d ", arr[pos]);
    imprimirArregloRecursivo(arr, indice, pos + 1);  // Llamada recursiva
}

// Función para imprimir claves en forma descendente
void imprimirClaveDescendente(struct Nodo* raiz) {
    if (raiz == NULL) return;
    
    int arr[100];
    int indice = 0;
    
    // Recolecta todas las claves del árbol
    recolectarClaves(raiz, arr, &indice);
    
    // Ordena las claves en forma descendente
    qsort(arr, indice, sizeof(int), compararDescendente);
    
    // Imprime las claves ordenadas (RECURSIVAMENTE)
    imprimirArregloRecursivo(arr, indice, 0);
    printf("\n");
}
// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================

int main() {
    /* Vamos a construir el siguiente árbol de ejemplo:
             1
            / \
           2   3
          / \
         4   5
    */
    
    struct Nodo* raiz = crearNodo(1000);
    raiz->izquierda = crearNodo(2);
    raiz->derecha = crearNodo(3);
    raiz->izquierda->izquierda = crearNodo(4);
    raiz->izquierda->derecha = crearNodo(5);

    // Imprimimos los resultados de los recorridos
    printf("Recorrido Pre-orden: ");
    preOrden(raiz);
    printf("\n");

    printf("Recorrido In-orden:  ");
    inOrden(raiz);
    printf("\n");

    printf("Recorrido Post-orden: ");
    postOrden(raiz);
    printf("\n");

    printf("Recorrido In-orden Descendente: ");
    inOrdenDescendente(raiz);
    printf("\n");

    printf("Claves del arbol en forma descendente (ORDENADAS): ");
    imprimirClaveDescendente(raiz);

    printf("Numeros mayores al numero dado: ");
    imprimirNodosMayores(raiz, 100);
    printf("\n");

    printf("Numeros menores al numero dado: ");
    imprimirNodosMenors(raiz, 100);
    printf("\n");

    printf("Pertenencia de un numero al arbol: ");
    pertenencia(raiz, 1000);
    printf("\n");

    // ==========================================
    // LLAMADA A LA NUEVA FUNCIÓN
    // ==========================================
    int totalNodos = contarNodos(raiz);
    printf("Total de nodos en el arbol: %d\n", totalNodos); 
    // Para este árbol de ejemplo (1, 2, 3, 4, 5), imprimirá: 5

    return 0;
}