#include<stdio.h>

#define TAM 2

struct dato{
    int arg[TAM];
    int i;
};

int main(){
    struct dato dato1, *ptrS; 
    ptrS = &dato1;
    for(ptrS->i=0;ptrS->i<TAM;ptrS->i++){
        printf("\nIngrese un entero\t");
        scanf("%d",&ptrS->arg[ptrS->i]);
    }
    for(ptrS->i=0;ptrS->i<TAM;ptrS->i++){
        printf("\nEn la celda %d esta el valor %d en lan direccion %lu",ptrS->i,ptrS->arg[ptrS->i],&ptrS->arg[ptrS->i]);
    }
    return 0;
}