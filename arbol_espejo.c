#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
}Nodo;

// Crear nodo
Nodo* crearNodo(int dato){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

// Insertar en ABB
Nodo* insertar(Nodo *raiz, int dato){

    if(raiz == NULL)
        return crearNodo(dato);

    if(dato < raiz->dato)
        raiz->izq = insertar(raiz->izq,dato);

    else if(dato > raiz->dato)
        raiz->der = insertar(raiz->der,dato);

    return raiz;
}

// Inorden
void inorden(Nodo *raiz){

    if(raiz != NULL){

        inorden(raiz->izq);

        printf("%d ",raiz->dato);

        inorden(raiz->der);
    }
}

// Mostrar árbol
void mostrarArbol(Nodo *raiz,int espacio){

    if(raiz == NULL)
        return;

    espacio += 5;

    mostrarArbol(raiz->der,espacio);

    printf("\n");

    for(int i=5;i<espacio;i++)
        printf(" ");

    printf("%d\n",raiz->dato);

    mostrarArbol(raiz->izq,espacio);
}

// Árbol espejo
void espejo(Nodo *raiz){

    if(raiz == NULL)
        return;

    Nodo *aux = raiz->izq;
    raiz->izq = raiz->der;
    raiz->der = aux;

    espejo(raiz->izq);
    espejo(raiz->der);
}

// Menú principal
int main(){

    Nodo *raiz = NULL;

    int op,valor;

    do{

        printf("\n===== ARBOL ESPEJO =====\n");
        printf("1. Insertar nodo\n");
        printf("2. Mostrar Inorden\n");
        printf("3. Mostrar Arbol\n");
        printf("4. Convertir a Espejo\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d",&op);

        switch(op){

            case 1:
                printf("Dato: ");
                scanf("%d",&valor);

                raiz = insertar(raiz,valor);
                break;

            case 2:
                printf("\nRecorrido Inorden:\n");
                inorden(raiz);
                printf("\n");
                break;

            case 3:
                printf("\nArbol:\n");
                mostrarArbol(raiz,0);
                break;

            case 4:
                espejo(raiz);
                printf("\nArbol convertido a espejo.\n");
                break;

            case 5:
                printf("\nFin del programa.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    }while(op!=5);

    return 0;
}