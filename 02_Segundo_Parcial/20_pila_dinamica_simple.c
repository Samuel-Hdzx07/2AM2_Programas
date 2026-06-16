#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============= ESTRUCTURAS =============
typedef struct {
    char nombre[30];
    int edad;
} Dato;

typedef struct nodo {
    Dato dato;
    struct nodo *ptrSig;
    struct nodo *ptrAnt;
} Nodo;

typedef struct {
    Nodo *tope;
    int cantidad;
} Pila;

// ============= FUNCIONES DE PILA =============

// Inicializar la pila
Pila* crear_pila() {
    Pila *p = (Pila*) malloc(sizeof(Pila));
    if (p != NULL) {
        p->tope = NULL;
        p->cantidad = 0;
    }
    return p;
}

// Verificar si la pila está vacía
int esta_vacia(Pila *p) {
    return (p == NULL || p->tope == NULL);
}

// Obtener la cantidad de elementos
int obtener_cantidad(Pila *p) {
    return (p == NULL) ? 0 : p->cantidad;
}

// Apilar (push) - agregar elemento al tope
int apilar(Pila *p, Dato dato) {
    if (p == NULL) return 0;
    
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevo == NULL) return 0;
    
    nuevo->dato = dato;
    nuevo->ptrAnt = NULL;
    nuevo->ptrSig = p->tope;
    
    if (p->tope != NULL) {
        p->tope->ptrAnt = nuevo;
    }
    
    p->tope = nuevo;
    p->cantidad++;
    
    return 1;
}

// Desapilar (pop) - remover elemento del tope
int desapilar(Pila *p, Dato *dato) {
    if (esta_vacia(p)) return 0;
    
    Nodo *aux = p->tope;
    *dato = aux->dato;
    
    p->tope = aux->ptrSig;
    if (p->tope != NULL) {
        p->tope->ptrAnt = NULL;
    }
    
    free(aux);
    p->cantidad--;
    
    return 1;
}

// Ver el tope sin desapilarlo
int ver_tope(Pila *p, Dato *dato) {
    if (esta_vacia(p)) return 0;
    
    *dato = p->tope->dato;
    return 1;
}

// Mostrar todos los elementos de la pila
void mostrar_pila(Pila *p) {
    if (esta_vacia(p)) {
        printf("\n*** PILA VACIA ***\n");
        return;
    }
    
    printf("\n===== CONTENIDO DE LA PILA =====\n");
    printf("Cantidad de elementos: %d\n", obtener_cantidad(p));
    printf("--------------------------------\n");
    
    Nodo *actual = p->tope;
    int posicion = 1;
    
    while (actual != NULL) {
        printf("[%d] Nombre: %-20s | Edad: %d\n", 
               posicion, actual->dato.nombre, actual->dato.edad);
        actual = actual->ptrSig;
        posicion++;
    }
    printf("================================\n\n");
}

// Liberar memoria de la pila
void liberar_pila(Pila *p) {
    if (p == NULL) return;
    
    Nodo *actual = p->tope;
    while (actual != NULL) {
        Nodo *aux = actual;
        actual = actual->ptrSig;
        free(aux);
    }
    
    free(p);
}

// ============= PROGRAMA PRINCIPAL =============

int main() {
    Pila *miPila = crear_pila();
    Dato d;
    int opcion;
    
    while (1) {
        printf("\n========== MENU PILA ==========\n");
        printf("1. Apilar elemento\n");
        printf("2. Desapilar elemento\n");
        printf("3. Ver tope\n");
        printf("4. Mostrar pila\n");
        printf("5. Cantidad de elementos\n");
        printf("6. Salir\n");
        printf("===============================\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer
        
        switch (opcion) {
            case 1:
                printf("\nINGRESAR NUEVO ELEMENTO:\n");
                printf("Nombre (max 29 caracteres): ");
                fgets(d.nombre, sizeof(d.nombre), stdin);
                d.nombre[strcspn(d.nombre, "\n")] = 0; // remover salto de línea
                
                printf("Edad: ");
                scanf("%d", &d.edad);
                
                if (apilar(miPila, d)) {
                    printf("*** Elemento apilado correctamente ***\n");
                } else {
                    printf("*** ERROR: No se pudo apilar ***\n");
                }
                break;
                
            case 2:
                if (desapilar(miPila, &d)) {
                    printf("\n*** Elemento desapilado ***\n");
                    printf("Nombre: %s\n", d.nombre);
                    printf("Edad: %d\n\n", d.edad);
                } else {
                    printf("\n*** PILA VACIA: No hay elementos para desapilar ***\n\n");
                }
                break;
                
            case 3:
                if (ver_tope(miPila, &d)) {
                    printf("\n*** ELEMENTO DEL TOPE ***\n");
                    printf("Nombre: %s\n", d.nombre);
                    printf("Edad: %d\n\n", d.edad);
                } else {
                    printf("\n*** PILA VACIA ***\n\n");
                }
                break;
                
            case 4:
                mostrar_pila(miPila);
                break;
                
            case 5:
                printf("\nLa pila contiene %d elemento(s)\n\n", obtener_cantidad(miPila));
                break;
                
            case 6:
                printf("\nLiberando memoria...\n");
                liberar_pila(miPila);
                printf("¡Hasta luego!\n");
                return 0;
                
            default:
                printf("\n*** OPCION INVALIDA ***\n\n");
        }
    }
    
    return 0;
}
