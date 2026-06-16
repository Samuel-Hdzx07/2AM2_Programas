#include<stdio.h>

int pal(char car[40]);

int main(){
    char cad[40];
    printf("\nIngresa una cadena\t");
    fgets(cad,40,stdin);
    if(pal(cad))
    printf("\nLa cadena si es un palindromo");
    else
    printf("\nLa cadena no es un palindromo");
    return 0;
}

int pal(char cad[40]){
    char *ptr1, *ptr2;
    for(ptr2 = cad;*ptr2 != '\n';ptr2+=1);
    for(ptr1 = cad,ptr2-=1;ptr1<ptr2;ptr1+=1,ptr2-=1)
        if(*ptr1!=*ptr2)
        return 0;
    return 1;
}