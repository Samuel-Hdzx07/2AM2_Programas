#include <stdio.h>
#include <stdlib.h>
//en el main poner un ptr doble, ptrreferencia 1 apunta a null ptrreferencia2 apunta a null , y los punteros diblas toman direcciones de punteros, pero los punteros simples apuntan a NUll, el profe dijo que sin nodo de cabecera

typedef struct Datos{
    char nombre [30];
    int edad;
}Datos;

typedef struct Nodo{
    struct Datos datos;
    struct Nodo *ptrSig, *ptrAnt;
}Nodo;

