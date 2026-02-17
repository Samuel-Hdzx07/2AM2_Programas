#include<stdio.h>

#define TAM 2

struct dato{
    int arg[TAM];
    int *ptr;
};

int main(){
    struct dato dato1, *ptrS, **pptrS; 
    ptrS = &dato1;
    pptrS = &ptrS;
    for((*pptrS)->ptr=(*pptrS)->arg;(*pptrS)->ptr<&(*pptrS)->arg[TAM];(*pptrS)->ptr+=1){
        printf("\nIngrese un entero\t");
        scanf("%d",(*pptrS)->ptr);
    }
    for((*pptrS)->ptr=(*pptrS)->arg;(*pptrS)->ptr<&(*pptrS)->arg[TAM];(*pptrS)->ptr+=1){
        printf("\nEn la celda %d esta el valor %d en lan direccion %lu",(int)((*pptrS)->ptr-(*pptrS)->arg),*(*pptrS)->ptr,(*pptrS)->ptr);
    }
    return 0;
}