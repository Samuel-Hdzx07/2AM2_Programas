#include<stdio.h>

#define TAM 2

struct dato{
    int arg[TAM];
    int *ptr;
};

int main(){
    struct dato dato1, *ptrS; 
    ptrS = &dato1;
    for(ptrS->ptr=ptrS->arg;ptrS->ptr<&ptrS->arg[TAM];ptrS->ptr+=1){
        printf("\nIngrese un entero\t");
        scanf("%d",ptrS->ptr);
    }
    for(ptrS->ptr=ptrS->arg;ptrS->ptr<&ptrS->arg[TAM];ptrS->ptr+=1){
        printf("\nEn la celda %d esta el valor %d en lan direccion %lu",(int)(ptrS->ptr-ptrS->arg),*ptrS->ptr,ptrS->ptr);
    }
    return 0;
}