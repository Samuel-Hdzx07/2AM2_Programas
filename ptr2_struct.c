#include<stdio.h>

#define TAM 2

struct per{
    char nom[30];
    int edad;
    char sexo;
};

struct dato{
    struct per arg[TAM];
    struct per *ptr,**pptr;
};

int main(){
    struct dato dato1, *ptrS;
    ptrS=&dato1;
    for(ptrS->ptr=&ptrS->arg,ptrS->pptr=&ptrS->ptr;*ptrS->pptr<&ptrS->arg[TAM];*ptrS->pptr+=1){
        setbuf(stdin,NULL);
        fflush(stdin);
        printf("\nIngrese un nombre\t");
        fgets((*ptrS->pptr)->nom,30,stdin);
        printf("\nIngrese una edad\t");
        scanf("%d",&(*ptrS->pptr)->edad);
        setbuf(stdin,NULL);
        printf("\nIngrese un sexo\t");
        (*ptrS->pptr)->sexo=getchar();
    }
    for(ptrS->ptr=&ptrS->arg;ptrS->ptr<&ptrS->arg[TAM];ptrS->ptr+=1){
        printf("\nEn la celda %d esta %s con direccion %lu\t",(int)(*ptrS->pptr-ptrS->arg),(*ptrS->pptr)->nom,&(*ptrS->pptr)->nom);
        printf("\nEn la celda %d esta %d con direccion %lu\t",(int)(*ptrS->pptr-ptrS->arg),(*ptrS->pptr)->edad,&(*ptrS->pptr)->edad);
        printf("\nEn la celda %d esta %c con direccion %lu\t",(int)(*ptrS->pptr-ptrS->arg),(*ptrS->pptr)->sexo,&(*ptrS->pptr)->sexo);
    }
    return 0;
}