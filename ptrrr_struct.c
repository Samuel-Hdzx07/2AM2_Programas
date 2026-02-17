#include<stdio.h>

#define TAM 2

struct per{
    char nom[30];
    int edad;
    char sexo;
};

struct dato{
    struct per arg[TAM];
    struct per *ptr;
};

int main(){
    struct dato dato, *ptrS;
    
    // Inicializar el puntero a la estructura dato
    ptrS = &dato;
    
    for(ptrS->ptr=ptrS->arg; ptrS->ptr<ptrS->arg+TAM; ptrS->ptr++){
        setbuf(stdin,NULL);
        fflush(stdin);
        printf("\nIngrese un nombre\t");
        fgets(ptrS->ptr->nom,30,stdin);
        printf("\nIngrese una edad\t");
        scanf("%d",&ptrS->ptr->edad);
        setbuf(stdin,NULL);
        printf("\nIngrese un sexo\t");
        ptrS->ptr->sexo=getchar();
    }
    
    
    for(ptrS->ptr=ptrS->arg; ptrS->ptr<ptrS->arg+TAM; ptrS->ptr++){
        printf("\nEn la celda %d esta %s con direccion %p\t",ptrS->ptr-ptrS->arg,ptrS->ptr->nom,&ptrS->ptr->nom);
        printf("\nEn la celda %d esta %d con direccion %p\t",ptrS->ptr-ptrS->arg,ptrS->ptr->edad,&ptrS->ptr->edad);
        printf("\nEn la celda %d esta %c con direccion %p\t",ptrS->ptr-ptrS->arg,ptrS->ptr->sexo,&ptrS->ptr->sexo);
    }
    return 0;
}