    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 5

    //pila dinamica con puntero y enlace simple

    struct Nodo {
        int datos[MAX];
        struct Nodo *ptrSig;
    };

    //Con apuntador simple enlace

    struct Nodo *crearNodo(int dato) {
        struct Nodo *ptrNuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

        if(ptrNuevo == NULL) {
            printf("Error al asignar memoria para el nuevo nodo.\n");
            return NULL;
        }

        ptrNuevo ->ptrSig = NULL;  // Inicializar el puntero siguiente a NULL

        ptrNuevo -> datos[0] = dato;  // Almacenar el dato en el nodo (puede ser un arreglo o un solo valor)
        return ptrNuevo;
    }

    //La refrencia de una pila siempre apunta al tope

    struct Nodo* meterDato(struct Nodo *ptrRef, int dato) {
        struct Nodo *ptrNuevo = crearNodo(dato);
        if (ptrNuevo == NULL) {
            return ptrRef;  // No se pudo crear el nodo, retornar la cima sin cambios
        }

        ptrNuevo->ptrSig = ptrRef;  // El nuevo nodo apunta a la cima actual
        return ptrNuevo;  // Retornar el nuevo nodo como la nueva cima
    }


    //Checar si esta vacia o hay mas de un nodo en la pila
    struct Nodo* sacarDato(struct Nodo *ptrRef) {
        if (ptrRef == NULL) {
            printf("La pila esta vacia. No se puede sacar dato.\n");
            return NULL;  // No hay nodos para sacar
        }
        
        if (ptrRef->ptrSig == NULL) {
            printf("Sacando el ultimo nodo de la pila.\n");
            free(ptrRef);
            return NULL;  // La pila queda vacía
        }

        struct Nodo *ptrBasura = ptrRef;  // Guardar la referencia al nodo a eliminar
        ptrRef = ptrRef->ptrSig;  // Mover la referencia a la siguiente cima
        free(ptrBasura);  // Liberar la memoria del nodo eliminado
        return ptrRef;  // Retornar la nueva cima
    }

    void mostrarPila(struct Nodo *ptrRef) {
        if (ptrRef == NULL) {
            printf("La pila esta vacia.\n");
            return;
        }
        
        struct Nodo *ptrTop = ptrRef;  // Empezar desde la cima
        printf("Pila: [");
        while (ptrTop != NULL) {
            printf("%d", ptrTop->datos[0]);  // Asumiendo que cada nodo tiene un solo dato
            if (ptrTop->ptrSig != NULL) {
                printf(", ");
            }
            ptrTop = ptrTop->ptrSig;  // Mover al siguiente nodo
        }
        printf("]\n");
    }

    int main(){
        struct Nodo *pila = NULL;  // Inicializar pila vacia
        int opcion, dato;
        
        do {
            printf("\n MENU DE PILA DINAMICA \n");
            printf("1. Meter dato \n");
            printf("2. Sacar dato \n");
            printf("3. Mostrar pila\n");
            printf("4. Salir\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);
            
            switch(opcion) {
                case 1:
                    printf("Ingrese el dato a meter: ");
                    scanf("%d", &dato);
                    pila = meterDato(pila, dato);
                    printf("Dato %d metido en la pila.\n", dato);
                    break;
                    
                case 2:
                    pila = sacarDato(pila);
                    if (pila != NULL || opcion == 2) {
                        printf("Dato sacado de la pila.\n");
                    }
                    break;
                    
                case 3:
                    mostrarPila(pila);
                    break;
                    
                case 4:
                    printf("Saliendo del programa...\n");
                    break;
                    
                default:
                    printf("Opcion invalida. Intente de nuevo.\n");
            }
        } while(opcion != 4);
        
        // Liberar memoria restante
        while(pila != NULL) {
            pila = sacarDato(pila);
        }

        return 0;
    }

