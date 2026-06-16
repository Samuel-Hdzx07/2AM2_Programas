#include<stdio.h>

#define TAM 2

struct per{
    char nom[30];
    int edad;
    char sexo;
};

struct dato{
    struct per arg[TAM];
    int i;
};

int main(){
    struct dato dato1, *ptrS;
    ptrS=&dato1;
    for(ptrS->i=0;ptrS->i<TAM;ptrS->i++){
        setbuf(stdin,NULL);
        fflush(stdin);
        printf("\nIngrese un nombre\t");
        fgets(ptrS->arg[ptrS->i].nom,30,stdin);
        printf("\nIngrese una edad\t");
        scanf("%d",&ptrS->arg[ptrS->i].edad);
        setbuf(stdin,NULL);
        printf("\nIngrese un sexo\t");
        ptrS->arg[ptrS->i].sexo=getchar();
    }
    for(dato1.i=0;dato1.i<TAM;dato1.i++){
        printf("\nEn la celda %d esta %s con direccion %lu\t",ptrS->i,ptrS->arg[ptrS->i].nom,&ptrS->arg[ptrS->i].nom);
        printf("\nEn la celda %d esta %d con direccion %lu\t",ptrS->i,ptrS->arg[ptrS->i].edad,&ptrS->arg[ptrS->i].edad);
        printf("\nEn la celda %d esta %c con direccion %lu\t",ptrS->i,ptrS->arg[ptrS->i].sexo,&ptrS->arg[ptrS->i].sexo);
    }
    return 0;
}