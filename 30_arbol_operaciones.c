#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ==========================================
// 1. ESTRUCTURA BASE DEL NODO
// ==========================================
typedef struct Nodo {
    int dato;
    struct Nodo* izq;
    struct Nodo* der;
} Nodo;

// Función para crear un nuevo nodo en memoria
Nodo* crearNodo(int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Función auxiliar para insertar elementos en el BST
Nodo* insertar(Nodo* raiz, int dato) {
    if (raiz == NULL) return crearNodo(dato);
    if (dato < raiz->dato) {
        raiz->izq = insertar(raiz->izq, dato);
    } else if (dato > raiz->dato) {
        raiz->der = insertar(raiz->der, dato);
    }
    return raiz;
}

// Función auxiliar para imprimir el árbol (recorrido Inorden)
void inorden(Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

// ==========================================
// 2. ELIMINACIÓN DE NODOS (Primera imagen)
// ==========================================

// Función auxiliar para el Caso 3: Encuentra el nodo menor de un subárbol
Nodo* encontrarMinimo(Nodo* raiz) {
    Nodo* actual = raiz;
    while (actual && actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}

Nodo* eliminarNodo(Nodo* raiz, int dato) {
    if (raiz == NULL) return raiz;

    // Buscar el nodo a eliminar
    if (dato < raiz->dato) {
        raiz->izq = eliminarNodo(raiz->izq, dato);
    } else if (dato > raiz->dato) {
        raiz->der = eliminarNodo(raiz->der, dato);
    } else {
        // Puntos 1 y 2: Nodos hoja o con un solo hijo (izq, der)
        if (raiz->izq == NULL) {
            Nodo* temp = raiz->der;
            free(raiz);
            return temp;
        } else if (raiz->der == NULL) {
            Nodo* temp = raiz->izq;
            free(raiz);
            return temp;
        }

        // Punto 3: Nodos con 2 hijos
        // Obtenemos el sucesor en inorden
        Nodo* temp = encontrarMinimo(raiz->der);
        
        // Copiamos el valor del sucesor al nodo actual
        raiz->dato = temp->dato;
        
        // Eliminamos el sucesor de manera recursiva
        raiz->der = eliminarNodo(raiz->der, temp->dato);
    }
    
    // Punto 4: Unir todo lo anterior devolviendo la raíz modificada
    return raiz; 
}

// ==========================================
// 3. OPERACIONES CON 2 ÁRBOLES (Segunda imagen)
// ==========================================

// 1) Comprobar que 2 árboles son iguales
bool sonIguales(Nodo* arbol1, Nodo* arbol2) {
    if (arbol1 == NULL && arbol2 == NULL) return true;
    if (arbol1 == NULL || arbol2 == NULL) return false;

    return (arbol1->dato == arbol2->dato) &&
           sonIguales(arbol1->izq, arbol2->izq) &&
           sonIguales(arbol1->der, arbol2->der);
}

// 2) Dado un árbol crear su árbol espejo
Nodo* crearArbolEspejo(Nodo* raiz) {
    if (raiz == NULL) return NULL;

    // Se reserva nueva memoria para el nodo clonado
    Nodo* nuevoNodo = crearNodo(raiz->dato);
    
    // Se cruzan las llamadas recursivas para invertir los lados
    nuevoNodo->izq = crearArbolEspejo(raiz->der); 
    nuevoNodo->der = crearArbolEspejo(raiz->izq); 

    return nuevoNodo;
}

// Liberar memoria del árbol al finalizar
void liberarArbol(Nodo* raiz) {
    if (raiz == NULL) return;
    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    free(raiz);
}

// ==========================================
// 4. FUNCIÓN PRINCIPAL DE PRUEBA
// ==========================================
int main() {
    Nodo* arbol1 = NULL;
    
    // Construcción del árbol original (BST)
    arbol1 = insertar(arbol1, 50);
    insertar(arbol1, 30);
    insertar(arbol1, 70);
    insertar(arbol1, 20);
    insertar(arbol1, 40);
    insertar(arbol1, 60);
    insertar(arbol1, 80);

    printf("Árbol 1 (Original) en Inorden:\n");
    inorden(arbol1);
    printf("\n\n");

    // --- Prueba de Eliminación ---
    printf("Eliminando el nodo 20 (Nodo hoja)...\n");
    arbol1 = eliminarNodo(arbol1, 20);
    printf("Árbol 1 después de eliminar 20:\n");
    inorden(arbol1);
    printf("\n\n");

    printf("Eliminando el nodo 30 (Nodo con un hijo)...\n");
    arbol1 = eliminarNodo(arbol1, 30);
    printf("Árbol 1 después de eliminar 30:\n");
    inorden(arbol1);
    printf("\n\n");

    // --- Prueba de Árbol Espejo ---
    printf("Creando el Árbol Espejo (Árbol 2)...\n");
    Nodo* arbolEspejo = crearArbolEspejo(arbol1);
    
    printf("Árbol Espejo en Inorden (debe verse invertido simétricamente):\n");
    inorden(arbolEspejo);
    printf("\n\n");

    // --- Prueba de Comparación ---
    printf("¿El Árbol 1 es igual al Árbol Espejo?\n");
    if (sonIguales(arbol1, arbolEspejo)) {
        printf("Resultado: Sí, son iguales.\n");
    } else {
        printf("Resultado: No, son diferentes.\n");
    }
    printf("\n");

    printf("¿El Árbol 1 es igual a sí mismo?\n");
    if (sonIguales(arbol1, arbol1)) {
        printf("Resultado: Sí, son iguales.\n");
    } else {
        printf("Resultado: No, son diferentes.\n");
    }

    // Limpieza de memoria
    liberarArbol(arbol1);
    liberarArbol(arbolEspejo);

    return 0;
}