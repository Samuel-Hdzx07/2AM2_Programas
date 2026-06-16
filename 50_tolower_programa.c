#include <stdio.h>
#define TAM 100

void miTolower(char *ptr){
    
    for(; *ptr != '\0'; ptr++){
        
        if(*ptr >= 'A' && *ptr <= 'Z'){
            *ptr = *ptr + 32;
        }
    }
}

int main(){
    
    char cadena[TAM];
    char *ptrC;
    
    ptrC = cadena;
    
    printf("Ingrese una cadena de texto: ");
    fgets(cadena, TAM, stdin);
    
    printf("\nCadena original: %s", cadena);
    
    miTolower(ptrC);
    
    printf("Cadena en minusculas: %s\n", cadena);
    
    return 0;
}
