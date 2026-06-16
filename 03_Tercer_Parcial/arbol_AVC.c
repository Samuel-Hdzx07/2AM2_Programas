#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
    int altura;
} Nodo;

//----------------------------------
// FUNCIONES AUXILIARES
//----------------------------------

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(Nodo *n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

Nodo* crearNodo(int dato) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->altura = 1;

    return nuevo;
}

int factorBalance(Nodo *n) {
    if (n == NULL)
        return 0;

    return altura(n->izq) - altura(n->der);
}

//----------------------------------
// ROTACIONES AVL
//----------------------------------

Nodo* rotacionDerecha(Nodo *y) {
    Nodo *x = y->izq;
    Nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;

    return x;
}

Nodo* rotacionIzquierda(Nodo *x) {
    Nodo *y = x->der;
    Nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;

    return y;
}

//----------------------------------
// INSERTAR
//----------------------------------

Nodo* insertar(Nodo *nodo, int dato) {

    if (nodo == NULL)
        return crearNodo(dato);

    if (dato < nodo->dato)
        nodo->izq = insertar(nodo->izq, dato);

    else if (dato > nodo->dato)
        nodo->der = insertar(nodo->der, dato);

    else
        return nodo;

    nodo->altura = 1 + max(altura(nodo->izq),
                            altura(nodo->der));

    int fb = factorBalance(nodo);

    // LL
    if (fb > 1 && dato < nodo->izq->dato)
        return rotacionDerecha(nodo);

    // RR
    if (fb < -1 && dato > nodo->der->dato)
        return rotacionIzquierda(nodo);

    // LR
    if (fb > 1 && dato > nodo->izq->dato) {
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
    }

    // RL
    if (fb < -1 && dato < nodo->der->dato) {
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

//----------------------------------
// NODO MINIMO
//----------------------------------

Nodo* nodoMinimo(Nodo *nodo) {

    Nodo *actual = nodo;

    while (actual->izq != NULL)
        actual = actual->izq;

    return actual;
}

//----------------------------------
// ELIMINAR
//----------------------------------

Nodo* eliminar(Nodo *raiz, int dato) {

    if (raiz == NULL)
        return raiz;

    if (dato < raiz->dato)
        raiz->izq = eliminar(raiz->izq, dato);

    else if (dato > raiz->dato)
        raiz->der = eliminar(raiz->der, dato);

    else {

        if ((raiz->izq == NULL) ||
            (raiz->der == NULL)) {

            Nodo *temp;

            if (raiz->izq)
                temp = raiz->izq;
            else
                temp = raiz->der;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            }
            else {
                *raiz = *temp;
            }

            free(temp);
        }
        else {

            Nodo *temp = nodoMinimo(raiz->der);

            raiz->dato = temp->dato;

            raiz->der =
                eliminar(raiz->der, temp->dato);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura =
        1 + max(altura(raiz->izq),
                altura(raiz->der));

    int fb = factorBalance(raiz);

    // LL
    if (fb > 1 &&
        factorBalance(raiz->izq) >= 0)
        return rotacionDerecha(raiz);

    // LR
    if (fb > 1 &&
        factorBalance(raiz->izq) < 0) {

        raiz->izq =
            rotacionIzquierda(raiz->izq);

        return rotacionDerecha(raiz);
    }

    // RR
    if (fb < -1 &&
        factorBalance(raiz->der) <= 0)
        return rotacionIzquierda(raiz);

    // RL
    if (fb < -1 &&
        factorBalance(raiz->der) > 0) {

        raiz->der =
            rotacionDerecha(raiz->der);

        return rotacionIzquierda(raiz);
    }

    return raiz;
}

//----------------------------------
// BUSCAR
//----------------------------------

Nodo* buscar(Nodo *raiz, int dato) {

    if (raiz == NULL)
        return NULL;

    if (raiz->dato == dato)
        return raiz;

    if (dato < raiz->dato)
        return buscar(raiz->izq, dato);

    return buscar(raiz->der, dato);
}

//----------------------------------
// RECORRIDOS
//----------------------------------

void preorden(Nodo *raiz) {

    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(Nodo *raiz) {

    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

void postorden(Nodo *raiz) {

    if (raiz != NULL) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->dato);
    }
}

//----------------------------------
// IMPRIMIR ARBOL
//----------------------------------

void imprimirArbol(Nodo *raiz, int espacio) {

    if (raiz == NULL)
        return;

    espacio += 5;

    imprimirArbol(raiz->der, espacio);

    printf("\n");

    for (int i = 5; i < espacio; i++)
        printf(" ");

    printf("%d\n", raiz->dato);

    imprimirArbol(raiz->izq, espacio);
}

//----------------------------------
// MENU
//----------------------------------

int main() {

    Nodo *raiz = NULL;

    int opcion;
    int valor;

    do {

        printf("\n===== AVL =====\n");
        printf("1. Insertar\n");
        printf("2. Eliminar\n");
        printf("3. Buscar\n");
        printf("4. Preorden\n");
        printf("5. Inorden\n");
        printf("6. Postorden\n");
        printf("7. Mostrar arbol\n");
        printf("8. Altura\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                raiz = insertar(raiz, valor);
                break;

            case 2:
                printf("Valor a eliminar: ");
                scanf("%d", &valor);
                raiz = eliminar(raiz, valor);
                break;

            case 3:
                printf("Valor a buscar: ");
                scanf("%d", &valor);

                if(buscar(raiz, valor))
                    printf("Encontrado\n");
                else
                    printf("No encontrado\n");
                break;

            case 4:
                preorden(raiz);
                printf("\n");
                break;

            case 5:
                inorden(raiz);
                printf("\n");
                break;

            case 6:
                postorden(raiz);
                printf("\n");
                break;

            case 7:
                imprimirArbol(raiz, 0);
                break;

            case 8:
                printf("Altura = %d\n",
                       altura(raiz));
                break;
        }

    } while(opcion != 0);

    return 0;
}