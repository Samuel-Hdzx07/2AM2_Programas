#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUCTURAS (Las que pidió el profe)
typedef struct Datos {
    char nombre[30];
    int edad;
} Datos;

typedef struct Nodo {
    struct Datos datos;
    struct Nodo *ptrSig, *ptrAnt;
} Nodo;

// 2. FUNCIÓN ENCOLAR (Con punteros dobles)
void encolar(Nodo** ptrInicio, Nodo** ptrFin, char* nom, int ed) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevo->datos.nombre, nom);
    nuevo->datos.edad = ed;
    nuevo->ptrSig = NULL;
    nuevo->ptrAnt = NULL;

    if (*ptrInicio == NULL) {
        *ptrInicio = nuevo;
        *ptrFin = nuevo;
    } else {
        (*ptrFin)->ptrSig = nuevo;
        nuevo->ptrAnt = *ptrFin;
        *ptrFin = nuevo;
    }
    printf("\n[Exito] %s se ha formado en la fila.\n", nom);
}

// 3. FUNCIÓN DESENCOLAR (Con punteros dobles)
void desencolar(Nodo** ptrInicio, Nodo** ptrFin) {
    if (*ptrInicio == NULL) {
        printf("\n[Error] La fila esta vacia. No hay a quien atender.\n");
        return;
    }
    
    Nodo* aux = *ptrInicio;
    *ptrInicio = aux->ptrSig;

    if (*ptrInicio == NULL) {
        *ptrFin = NULL;
    } else {
        (*ptrInicio)->ptrAnt = NULL;
    }
    
    printf("\n[Atendido] Saliendo de la fila: %s (Edad: %d)\n", aux->datos.nombre, aux->datos.edad);
    free(aux);
}

// 4. FUNCIÓN MOSTRAR 
void mostrar(Nodo* inicio) {
    if (inicio == NULL) {
        printf("\n--- LA FILA ESTA VACIA ---\n");
        return;
    }
    
    Nodo* aux = inicio;
    int posicion = 1;
    
    printf("\n--- ESTADO ACTUAL DE LA FILA ---\n");
    while (aux != NULL) {
        printf("%d. Nombre: %s \t| Edad: %d\n", posicion, aux->datos.nombre, aux->datos.edad);
        aux = aux->ptrSig;
        posicion++;
    }
    printf("--------------------------------\n");
}

// 5. FUNCIÓN PRINCIPAL (El Menú)
int main() {
    Nodo* inicio = NULL;
    Nodo* fin = NULL;
    
    int opcion;
    char tempNombre[30];
    int tempEdad;

    do {
        printf("\n====== MENU DE LA CAFETERIA ======\n");
        printf("1. Formar a alguien (Encolar)\n");
        printf("2. Atender al primero (Desencolar)\n");
        printf("3. Ver la fila completa\n");
        printf("4. Salir\n");
        printf("==================================\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nIngresa el nombre: ");
                // El espacio antes del % es VITAL. Limpia el "Enter" fantasma del teclado.
                // El [^\n] permite leer nombres con espacios (ej. "Juan Perez")
                scanf(" %[^\n]", tempNombre); 
                
                printf("Ingresa la edad: ");
                scanf("%d", &tempEdad);
                
                encolar(&inicio, &fin, tempNombre, tempEdad);
                break;
                
            case 2:
                desencolar(&inicio, &fin);
                break;
                
            case 3:
                mostrar(inicio);
                break;
                
            case 4:
                printf("\nSaliendo y cerrando la cafeteria...\n");
                // Buena práctica: Vaciar la memoria si quedaron nodos antes de apagar
                while(inicio != NULL) {
                    desencolar(&inicio, &fin);
                }
                break;
                
            default:
                printf("\n[Error] Opcion no valida. Intenta de nuevo.\n");
        }
    } while(opcion != 4);

    return 0;
}