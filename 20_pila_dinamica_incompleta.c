#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Datos{
    char nombre [30];
    int edad;
    char sexo[2];
}Datos;

typedef struct Nodo{
    struct Datos datos;
    struct Nodo *ptrSig;
}Nodo;

typedef struct Pila{
    Nodo *ptrTop;
}Pila;

void iniciarPila(Pila *pila){
    pila->ptrTop = NULL;
}

// Verificar si la pila está vacía
int estaVacia(Pila *pila){
    return pila->ptrTop == NULL;
}

// Apilar (push) - agregar elemento al tope
int apilar(Pila *pila, Datos dato){
    if(pila == NULL) return 0;
    
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevo == NULL) return 0;
    
    nuevo->datos = dato;
    nuevo->ptrSig = pila->ptrTop;
    pila->ptrTop = nuevo;
    
    return 1;
}

// Desapilar (pop) - remover elemento del tope
int desapilar(Pila *pila, Datos *dato){
    if(estaVacia(pila)) return 0;
    
    Nodo *aux = pila->ptrTop;
    *dato = aux->datos;
    
    pila->ptrTop = aux->ptrSig;
    free(aux);
    
    return 1;
}

// Ver el elemento en el tope sin eliminarlo
int peek(Pila *pila, Datos *dato){
    if(estaVacia(pila)) return 0;
    *dato = pila->ptrTop->datos;
    return 1;
}

// Mostrar todos los elementos de la pila
void mostrarPila(Pila *pila){
    if(estaVacia(pila)){
        printf("\nLa pila esta vacia\n");
        return;
    }
    
    printf("\n=== CONTENIDO DE LA PILA ===\n");
    Nodo *aux = pila->ptrTop;
    int posicion = 1;
    
    while(aux != NULL){
        printf("%d. Nombre: %s | Edad: %d | Sexo: %s\n", 
               posicion, aux->datos.nombre, aux->datos.edad, aux->datos.sexo);
        aux = aux->ptrSig;
        posicion++;
    }
    printf("============================\n");
}

// Liberar toda la memoria de la pila
void liberarPila(Pila *pila){
    while(!estaVacia(pila)){
        Nodo *aux = pila->ptrTop;
        pila->ptrTop = aux->ptrSig;
        free(aux);
    }
}

// Menú principal
void mostrarMenu(){
    printf("\n====== MENU PILA DINAMICA ======\n");
    printf("1. Apilar (Push)\n");
    printf("2. Desapilar (Pop)\n");
    printf("3. Ver tope (Peek)\n");
    printf("4. Mostrar pila completa\n");
    printf("5. Salir\n");
    printf("================================\n");
    printf("Selecciona una opcion: ");
}

// Función principal
int main(){
    Pila miPila;
    iniciarPila(&miPila);
    
    int opcion;
    Datos temporal;
    
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // limpiar buffer
        
        switch(opcion){
            case 1:
                printf("\nIngresa nombre: ");
                fgets(temporal.nombre, 30, stdin);
                temporal.nombre[strcspn(temporal.nombre, "\n")] = 0;
                
                printf("Ingresa edad: ");
                scanf("%d", &temporal.edad);
                getchar();
                
                printf("Ingresa sexo (M/F): ");
                fgets(temporal.sexo, 2, stdin);
                
                if(apilar(&miPila, temporal)){
                    printf("✓ Persona apilada exitosamente\n");
                } else {
                    printf("✗ Error al apilar\n");
                }
                break;
                
            case 2:
                if(desapilar(&miPila, &temporal)){
                    printf("\n✓ Desapilado: %s (Edad: %d, Sexo: %s)\n", 
                           temporal.nombre, temporal.edad, temporal.sexo);
                } else {
                    printf("\n✗ La pila esta vacia\n");
                }
                break;
                
            case 3:
                if(peek(&miPila, &temporal)){
                    printf("\n✓ Tope: %s (Edad: %d, Sexo: %s)\n", 
                           temporal.nombre, temporal.edad, temporal.sexo);
                } else {
                    printf("\n✗ La pila esta vacia\n");
                }
                break;
                
            case 4:
                mostrarPila(&miPila);
                break;
                
            case 5:
                printf("\nLiberando memoria...\n");
                liberarPila(&miPila);
                printf("¡Hasta luego!\n");
                break;
                
            default:
                printf("\n✗ Opcion invalida\n");
        }
    } while(opcion != 5);
    
    return 0;
}