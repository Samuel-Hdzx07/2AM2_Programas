#include <stdio.h>
#include <stdlib.h>
//Cola con doble cabecera para que sea mas eficiente meter y sacar 
//que es crear un nodo con doble enlace
//Nodo de cabecera y ptr de referencia, la problematica es que para por ejemplo 1000 millones de nodos no es optimo recorrer toda la cola y recorrer y recorrer 
//¿Que podemos hacer para que sea eficiente tanto la entrada como la salida de los elementos? 
//el chiste es meter nuevos nodos a lado de refrencia uno, en medio de ptrreferenciaa uno y ptrreferencia2, todos los que vengan despues de ptrreferencia1 se van a mover a ptrreferencia2, y el nuevo nodo se va a colocar entre ptrreferencia1 y ptrreferencia2, entonces no es necesario recorrer toda la cola para insertar un nuevo nodo, solo es necesario actualizar los punteros de referencia.

typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
}Nodo;

typedef struct Cola{
    Nodo* ptrinicio;
    Nodo* ptrfinal;
}Cola;

Nodo* crearNodo(int valor){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato= valor;
    nuevo->siguiente = NULL;
    return nuevo;    
}

int escolaVacio(Cola *ptrcola){
    return (ptrcola->ptrinicio == NULL);
}

void inicializarCola(Cola* ptrcola){
    ptrcola->ptrinicio = NULL;
    ptrcola->ptrfinal = NULL;
}

void encolar(Cola *ptrcola, int valor){
    Nodo *nuevo = crearNodo(valor);

    if(escolaVacio(ptrcola)){
        ptrcola->ptrinicio = nuevo;
        ptrcola->ptrfinal = nuevo;
    }
    
    ptrcola->ptrfinal->siguiente = nuevo;
    ptrcola->ptrfinal = nuevo;
}
