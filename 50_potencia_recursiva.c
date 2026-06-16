#include<stdio.h>

int alaN(int m, int n){
    if(n==0){
        return 1;
    }
    else{
        return m * alaN(m, n-1);
    }
};

int main(void){
    int base, exponente;
    printf("Ingresa la base (m): ");
    scanf("%d", &base);
    printf("Ingresa el exponente (n): ");
    scanf("%d", &exponente);
    
    int resultado = alaN(base, exponente);
    printf("%d a la %d = %d\n", base, exponente, resultado);
    
    return 0;
}