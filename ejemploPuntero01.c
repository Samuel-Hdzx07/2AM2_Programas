#include<stdio.h>

int main(){
    int arrg[5];
    int *ptr;
    for(ptr = arrg;ptr<&arrg[5];ptr+=1){
    printf("Ingresa un entero\t");
    scanf("%d",ptr);
    }
    for(ptr = arrg;ptr<&arrg[5];ptr+=1)
    printf("\nEl numero %d esta en la casilla %d y esta en la direccion %p",*ptr,(int)(ptr-arrg),ptr);
    return 0;
}