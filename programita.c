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

    return 0;
}