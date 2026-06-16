#define TAM 10
#include <stdio.h>

//Definicion de la estructura per
struct per{
    char nombre[20];
    int edad;
    char sexo;
};

struct Dato{
    struct per arreglo[TAM];
    struct per *ptrS;
};

int main(){
    //Hacer uso de la estructura 
    struct Dato dato;
    
    // Inicializar el puntero al inicio del arreglo
    dato.ptrS = dato.arreglo;
    
    // Leer datos usando el puntero
    for(dato.arreglo; dato.ptrS<TAM; dato.ptrS= dato.ptrS + 1){
        setbuf(stdin,NULL);
        printf("\nIngrese un nombre\t");
        fgets(dato.ptrS->nombre,20,stdin);
        printf("\nIngrese una edad\t");
        scanf("%d",&dato.ptrS->edad);
        setbuf(stdin,NULL);
        printf("\nIngrese un sexo\t");
        dato.ptrS->sexo=getchar();
        dato.ptrS++;  // Avanzar el puntero a la siguiente posición
    }

    // Reiniciar el puntero al inicio para mostrar
    dato.ptrS = dato.arreglo;
    
    // Mostrar datos usando el puntero
    for(int i=0; i<TAM; i++){
        printf("\nEn la celda %d esta el nombre %s en la direccion %p",i,dato.ptrS->nombre,&dato.ptrS->nombre);
        printf("\nEn la celda %d esta la edad %d en la direccion %p",i,dato.ptrS->edad,&dato.ptrS->edad);
        printf("\nEn la celda %d esta el sexo %c en la direccion %p",i,dato.ptrS->sexo,&dato.ptrS->sexo);
        dato.ptrS++;  // Avanzar el puntero a la siguiente posición
    }

    return 0;
}