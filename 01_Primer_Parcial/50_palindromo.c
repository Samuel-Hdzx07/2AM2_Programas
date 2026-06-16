#include <stdio.h> 

int palindromo(char *ptr){
char *ptr2;
for(ptr2=ptr;*ptr2!='\n';ptr2++);
ptr2--; // Retroceder para apuntar al último carácter antes del \n

 for(;ptr<ptr2;ptr++,ptr2--){
    if(*ptr!=*ptr2){
        return 0;
    }
 }
 return 1; // Es palíndromo
}

int main(){

    char cad[100];
    printf("Ingrese una cadena: ");
    fgets(cad, 100, stdin);
    if(palindromo(cad)){
        printf("La cadena es un palindromo\n");
    }else{
        printf("La cadena no es un palindromo\n");
    }

    return 0;
}