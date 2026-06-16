#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo* ptrSig, *ptrAnt;
}Nodo;

typedef struct Lista{
    struct Nodo* ptrPrim, *ptrUlt;
}Lista;

// ============= FUNCIONES DE LISTA =============

// Inicializar la lista
void inicializarLista(Lista *lista){
    lista->ptrPrim = NULL;
    lista->ptrUlt = NULL;
}

// Crear un nuevo nodo
Nodo* crearNodo(int dato){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevo == NULL) return NULL;
    
    nuevo->dato = dato;
    nuevo->ptrSig = NULL;
    nuevo->ptrAnt = NULL;
    return nuevo;
}

// Insertar al final de la lista
int insertarFinal(Lista *lista, int dato){
    Nodo *nuevo = crearNodo(dato);
    if(nuevo == NULL) return 0;
    
    if(lista->ptrPrim == NULL){
        lista->ptrPrim = nuevo;
        lista->ptrUlt = nuevo;
    } else {
        lista->ptrUlt->ptrSig = nuevo;
        nuevo->ptrAnt = lista->ptrUlt;
        lista->ptrUlt = nuevo;
    }
    return 1;
}

// Insertar al inicio de la lista
int insertarInicio(Lista *lista, int dato){
    Nodo *nuevo = crearNodo(dato);
    if(nuevo == NULL) return 0;
    
    if(lista->ptrPrim == NULL){
        lista->ptrPrim = nuevo;
        lista->ptrUlt = nuevo;
    } else {
        nuevo->ptrSig = lista->ptrPrim;
        lista->ptrPrim->ptrAnt = nuevo;
        lista->ptrPrim = nuevo;
    }
    return 1;
}

// Eliminar del inicio
int eliminarInicio(Lista *lista){
    if(lista->ptrPrim == NULL) return 0;
    
    Nodo *aux = lista->ptrPrim;
    lista->ptrPrim = aux->ptrSig;
    
    if(lista->ptrPrim == NULL){
        lista->ptrUlt = NULL;
    } else {
        lista->ptrPrim->ptrAnt = NULL;
    }
    
    free(aux);
    return 1;
}

// Eliminar del final
int eliminarFinal(Lista *lista){
    if(lista->ptrUlt == NULL) return 0;
    
    Nodo *aux = lista->ptrUlt;
    lista->ptrUlt = aux->ptrAnt;
    
    if(lista->ptrUlt == NULL){
        lista->ptrPrim = NULL;
    } else {
        lista->ptrUlt->ptrSig = NULL;
    }
    
    free(aux);
    return 1;
}

// Buscar un elemento
Nodo* buscar(Lista *lista, int dato){
    Nodo *aux = lista->ptrPrim;
    while(aux != NULL){
        if(aux->dato == dato) return aux;
        aux = aux->ptrSig;
    }
    return NULL;
}

// Mostrar lista de izquierda a derecha
void mostrarIzqDer(Lista *lista){
    if(lista->ptrPrim == NULL){
        printf("\n--- LA LISTA ESTA VACIA ---\n");
        return;
    }
    
    printf("\n=== LISTA (Izquierda → Derecha) ===\n");
    Nodo *aux = lista->ptrPrim;
    while(aux != NULL){
        printf("[%d] <-> ", aux->dato);
        aux = aux->ptrSig;
    }
    printf("NULL\n");
}

// Mostrar lista de derecha a izquierda
void mostrarDerIzq(Lista *lista){
    if(lista->ptrUlt == NULL){
        printf("\n--- LA LISTA ESTA VACIA ---\n");
        return;
    }
    
    printf("\n=== LISTA (Derecha → Izquierda) ===\n");
    Nodo *aux = lista->ptrUlt;
    while(aux != NULL){
        printf("[%d] <-> ", aux->dato);
        aux = aux->ptrAnt;
    }
    printf("NULL\n");
}

// Contar elementos
int contarElementos(Lista *lista){
    int contador = 0;
    Nodo *aux = lista->ptrPrim;
    while(aux != NULL){
        contador++;
        aux = aux->ptrSig;
    }
    return contador;
}

// Liberar toda la lista
void liberarLista(Lista *lista){
    Nodo *aux = lista->ptrPrim;
    while(aux != NULL){
        Nodo *temp = aux;
        aux = aux->ptrSig;
        free(temp);
    }
    lista->ptrPrim = NULL;
    lista->ptrUlt = NULL;
}

// Menú
void mostrarMenu(){
    printf("\n======= LISTA DOBLEMENTE ENLAZADA =======\n");
    printf("1. Insertar al inicio\n");
    printf("2. Insertar al final\n");
    printf("3. Eliminar del inicio\n");
    printf("4. Eliminar del final\n");
    printf("5. Buscar elemento\n");
    printf("6. Mostrar (Izq → Der)\n");
    printf("7. Mostrar (Der → Izq)\n");
    printf("8. Contar elementos\n");
    printf("9. Salir\n");
    printf("==========================================\n");
    printf("Selecciona una opcion: ");
}

// Función principal
int main(){
    Lista miLista;
    inicializarLista(&miLista);
    
    int opcion, dato;
    Nodo *encontrado;
    
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        
        switch(opcion){
            case 1:
                printf("Ingresa el valor a insertar al inicio: ");
                scanf("%d", &dato);
                if(insertarInicio(&miLista, dato)){
                    printf("✓ Valor insertado al inicio\n");
                } else {
                    printf("✗ Error al insertar\n");
                }
                break;
                
            case 2:
                printf("Ingresa el valor a insertar al final: ");
                scanf("%d", &dato);
                if(insertarFinal(&miLista, dato)){
                    printf("✓ Valor insertado al final\n");
                } else {
                    printf("✗ Error al insertar\n");
                }
                break;
                
            case 3:
                if(eliminarInicio(&miLista)){
                    printf("✓ Primer elemento eliminado\n");
                } else {
                    printf("✗ La lista esta vacia\n");
                }
                break;
                
            case 4:
                if(eliminarFinal(&miLista)){
                    printf("✓ Ultimo elemento eliminado\n");
                } else {
                    printf("✗ La lista esta vacia\n");
                }
                break;
                
            case 5:
                printf("Ingresa el valor a buscar: ");
                scanf("%d", &dato);
                encontrado = buscar(&miLista, dato);
                if(encontrado != NULL){
                    printf("✓ Elemento %d ENCONTRADO\n", dato);
                } else {
                    printf("✗ Elemento %d NO ENCONTRADO\n", dato);
                }
                break;
                
            case 6:
                mostrarIzqDer(&miLista);
                break;
                
            case 7:
                mostrarDerIzq(&miLista);
                break;
                
            case 8:
                printf("\nTotal de elementos: %d\n", contarElementos(&miLista));
                break;
                
            case 9:
                printf("\nLiberando memoria...\n");
                liberarLista(&miLista);
                printf("¡Hasta luego!\n");
                break;
                
            default:
                printf("✗ Opcion invalida\n");
        }
    } while(opcion != 9);
    
    return 0;
}