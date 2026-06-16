//Hacer una lista con doble enlace, doblemente ligada, con nodo de cabecera para un dato compuesto recorrido de izquierda a derecha y recorrido de derecha a izqueirda
// Y hacer una segunda evrsion sin el nodo de cabecera, osea con un puntero doble
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Datos{
    char nombre [30];
    int edad;
}Datos;

typedef struct Nodo{
    int key;
    struct Datos datos;
    struct Nodo *ptrSig, *ptrAnt;
}Nodo;

typedef struct Lista{
    Nodo * ptrin;
    Nodo * ptrfin;

}Lista;

Nodo * crearNodo(int k, char *nombre, int edad){
    Nodo * nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->key = k;
    strcpy(nuevoNodo->datos.nombre, nombre);
    nuevoNodo->datos.edad = edad;
    nuevoNodo->ptrSig=NULL;
    nuevoNodo->ptrAnt=NULL;

    return nuevoNodo;

};

void inicializarLista(Lista *lista){
    lista->ptrin = NULL;
    lista->ptrfin = NULL;
};

void insertarLista(Lista *lista, int k, char *nombre, int edad){
    Nodo *nuevo= crearNodo(k,nombre,edad);
    //Si la lista esta vacia
    if(lista->ptrfin == NULL){
        lista->ptrin = nuevo;
        lista->ptrfin = nuevo;
    }

    else{
        lista->ptrfin->ptrSig = nuevo; // El último agarra al nuevo
        nuevo->ptrAnt = lista->ptrfin; // El nuevo voltea y agarra al viejo último
        lista->ptrfin = nuevo;
    };

};

void mostrarDerizq(Lista *lista){
    Nodo *aux = lista->ptrfin;
    while(aux != NULL){
        printf("Key: %d, Nombre: %s, Edad: %d\n", aux->key, aux->datos.nombre, aux->datos.edad);
        aux = aux->ptrAnt;
    }

};

void mostrarIzqder(Lista *lista){
    Nodo *aux = lista->ptrin;
    while(aux!=NULL){
        printf("Key: %d, Nombre: %s, Edad: %d\n", aux->key, aux->datos.nombre, aux->datos.edad);
        aux = aux->ptrSig;
    }

};

void buscarPorkey(Lista *lista, int clabesita){
    Nodo * aux= lista->ptrin;
        while(aux!=NULL){
            if(aux->key==clabesita){
                printf("Key: %d, Nombre: %s, Edad: %d\n", aux->key, aux->datos.nombre, aux->datos.edad);
                return;
            }
            aux=aux->ptrSig;
        }

    printf("No se encontro la clave %d\n", clabesita);

};

void eliminarPorkey(Lista *lista, int clabesita){
    if(lista->ptrin == NULL){
        printf("La lista esta vacia y por lo tanto no se puede eliminar la clabe %d\n", clabesita);
        return;
    };

    Nodo *aux = lista->ptrin;
    while(aux!=NULL && aux->key!=clabesita){
            aux=aux->ptrSig;
        };
    
    if(aux==NULL){
        printf("No se encontro la clave %d\n", clabesita);
        return;
    }

    if(aux->ptrAnt!=NULL){
        aux->ptrAnt->ptrSig = aux->ptrSig;
    }
    else{
        lista->ptrin = aux->ptrSig;
    };

    if(aux->ptrSig!=NULL){
        aux->ptrSig->ptrAnt = aux->ptrAnt;
    }
    else{
        lista->ptrfin = aux->ptrAnt;

    }

    printf("\n[Eliminado] Clave %d (%s) fuera de la lista.\n", clabesita, aux->datos.nombre);
    free(aux);
};

void eliminarLista(Lista *lista){
    Nodo *aux= lista->ptrin;
    Nodo *temp;

    while(aux!=NULL){
        temp=aux;
        aux=aux->ptrSig;
        free(temp);
    }

    lista->ptrin = NULL;
    lista->ptrfin = NULL;
    printf("Lista eliminada exitosamente.\n");

};

//validacion que cuando metamos un dato que va a suceder si el dato o la lcave ya existe 
//y hacerlo para cadenas 

int main(void){
    Lista lista;
    inicializarLista(&lista);

    insertarLista(&lista, 10, "Ana", 20);
    insertarLista(&lista, 20, "Luis", 22);
    insertarLista(&lista, 30, "Marta", 21);

    printf("Recorrido izquierda a derecha:\n");
    mostrarIzqder(&lista);

    printf("\nRecorrido derecha a izquierda:\n");
    mostrarDerizq(&lista);

    printf("\nBuscar clave 20:\n");
    buscarPorkey(&lista, 20);

    eliminarPorkey(&lista, 20);

    printf("\nLista final:\n");
    mostrarIzqder(&lista);

    return 0;
}
