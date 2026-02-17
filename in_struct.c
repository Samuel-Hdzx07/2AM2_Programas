#define TAM 2
#include <stdio.h>

//Definicion de la estructura per
struct per{
    char nombre[20];
    int edad;
    char sexo;
};

struct Dato{
    struct per arreglo[TAM];
    int i;
};

int main(){
    //Hacer uso de la estructura 
    struct Dato dato;
    for(dato.i=0;dato.i<TAM;dato.i=dato.i+1){
        setbuf(stdin,NULL);
        printf("\nIngrese un nombre\t");
        fgets(dato.arreglo[dato.i].nombre,20,stdin);
        printf("\nIngrese una edad\t");
        scanf("%d",&dato.arreglo[dato.i].edad);
        setbuf(stdin,NULL);
        printf("\nIngrese un sexo\t");
        dato.arreglo[dato.i].sexo=getchar();
    }

    for(dato.i=0;dato.i<TAM;dato.i=dato.i+1){
        printf("\nEn la celda %d esta el nombre %s en la direccion %p",(int)(dato.i),dato.arreglo[dato.i].nombre,&dato.arreglo[dato.i].nombre);
        printf("\nEn la celda %d esta la edad %d en la direccion %p",(int)(dato.i),dato.arreglo[dato.i].edad,&dato.arreglo[dato.i].edad);
        printf("\nEn la celda %d esta el sexo %c en la direccion %p",(int)(dato.i),dato.arreglo[dato.i].sexo,&dato.arreglo[dato.i].sexo);
    }

    return 0;
}