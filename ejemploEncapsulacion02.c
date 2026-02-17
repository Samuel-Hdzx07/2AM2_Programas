#include<stdio.h>

#define TAM 2

struct dato{
    int arg[TAM];
    int *ptr;
};

int main(){
    struct dato dato1; 
    for(dato1.ptr=dato1.arg;dato1.ptr<&dato1.arg[TAM];dato1.ptr+=1){
        printf("\nIngrese un entero\t");
        scanf("%d",dato1.ptr);
    }
    for(dato1.ptr=dato1.arg;dato1.ptr<&dato1.arg[TAM];dato1.ptr+=1){
        printf("\nEn la celda %d esta el valor %d en lan direccion %",(int)(dato1.ptr-dato1.arg),*dato1.ptr,dato1.ptr);
    }
    return 0;
}