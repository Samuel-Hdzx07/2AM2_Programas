#include <stdio.h>
#include <string.h>

int longCad(char *cad){
    if(*cad == '\0'){
        return 0;
    }
    else{
        return 1 + longCad(cad+1);
    }
}

int algEucli(int a, int b){
    if(b==0){
        
        return a;
    }
    else{
        return algEucli(b, a%b);
    }
}

int inversa(char *cad){
    if(*cad == '\0'){
        return 0;
    }
    else{
        return 1 + inversa(cad+1);
    };

    printf("%c", *cad);
    
};

int main(){
    int a, b;
    char cadena[50];
    printf("Ingresa una cadena de texto: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = 0; // Eliminar el salto de línea al final si existe
    printf("dame dos numeros enteros:");
    scanf("%d %d", &a, &b);
    printf("El MCD de %d y %d es: %d\n", a, b, algEucli(a, b));
    printf("Ingresa una cadena para sacar su inversa: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = 0; // Eliminar el salto de línea al final si existe

    // Eliminar el salto de línea al final si existe
    printf("La longitud de la cadena es: %d\n", longCad(cadena));
    printf("La inversa de la cadena es: ", inversa(cadena));
    printf("\n");
    return 0;
}