#include<stdio.h>

#define TAM 2

struct dato{
    int arg[TAM];
    int i;
};

int main(){
    struct dato dato1; 
    for(dato1.i=0;dato1.i<TAM;dato1.i++){
        printf("\nIngrese un entero\t");
        scanf("%d",&dato1.arg[dato1.i]);
    }
    for(dato1.i=0;dato1.i<TAM;dato1.i++){
        printf("\nEn la celda %d esta el valor %d en lan direccion %lu",dato1.i,dato1.arg[dato1.i],&dato1.arg[dato1.i]);
    }
    return 0;
}