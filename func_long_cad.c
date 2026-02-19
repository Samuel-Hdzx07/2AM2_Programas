#include <stdio.h>

int longCad(char* ptr){
char *ptr2;
for(ptr2=ptr;*ptr2!='\n';ptr2++);
return (int)(ptr2-ptr);
}

int main(){

    char cad[100];
    printf("Ingrese una cadena: ");
    fgets(cad, 100, stdin);
    printf("La longitud de la cadena es: %d\n", longCad(cad));

    return 0;
}
