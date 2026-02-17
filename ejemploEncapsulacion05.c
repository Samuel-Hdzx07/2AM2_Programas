#include<stdio.h>

#define TAM 2

struct dato{
    int arg[TAM];
    int *ptr,**pptr;
};

int main(){
    struct dato dato1, *ptrS; 
    ptrS = &dato1;
    for(ptrS->ptr=ptrS->arg,ptrS->pptr=&ptrS->ptr;*ptrS->pptr<&ptrS->arg[TAM];*ptrS->pptr+=1){
        printf("\nIngrese un entero\t");
        scanf("%d",*ptrS->pptr);
    }
    for(ptrS->ptr=ptrS->arg,ptrS->pptr=&ptrS->ptr;*ptrS->pptr<&ptrS->arg[TAM];*ptrS->pptr+=1){
        printf("\nEn la celda %d esta el valor %d en lan direccion %lu",(int)(*ptrS->pptr-ptrS->arg),**ptrS->pptr,*ptrS->pptr);
    }
    return 0;
}