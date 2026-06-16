#define TAM 10
#include <stdio.h>

//Definicion de la estructura per
struct per{
    char nombre[20];
    int edad;
    char sexo;
};

struct Dato{
    struct per arreglo[TAM];
    int i;
};

int main(){
    //Hacer uso de la estructura 
    struct Dato dato;
    for(dato.i=0;dato.i<TAM;dato.i=dato.i+1){
        setbuf(stdin,NULL);
        printf("\nIngrese un nombre\t");
        fgets(dato.arreglo[dato.i].nombre,20,stdin);
        printf("\nIngrese una edad\t");
        scanf("%d",&dato.arreglo[dato.i].edad);
        setbuf(stdin,NULL);
        printf("\nIngrese un sexo\t");
        dato.arreglo[dato.i].sexo=getchar();
    }

    // Mostrar todos los datos ingresados
    printf("\n\n====== DATOS INGRESADOS ======\n");
    for(dato.i=0;dato.i<TAM;dato.i=dato.i+1){
        printf("\nPersona %d:\n", dato.i+1);
        printf("  Nombre: %s", dato.arreglo[dato.i].nombre);
        printf("  Edad: %d\n", dato.arreglo[dato.i].edad);
        printf("  Sexo: %c\n", dato.arreglo[dato.i].sexo);
        printf("  Direccion de nombre: %p\n", &dato.arreglo[dato.i].nombre);
        printf("  Direccion de edad: %p\n", &dato.arreglo[dato.i].edad);
        printf("  Direccion de sexo: %p\n", &dato.arreglo[dato.i].sexo);
        printf("  ---\n");
    }

    // Calcular y mostrar estadísticas
    printf("\n====== ESTADISTICAS ======\n");
    int sumaEdades = 0;
    int mayores18 = 0;
    int menores18 = 0;
    int masculinos = 0;
    int femeninos = 0;
    
    for(dato.i=0;dato.i<TAM;dato.i=dato.i+1){
        sumaEdades += dato.arreglo[dato.i].edad;
        
        if(dato.arreglo[dato.i].edad >= 18){
            mayores18++;
        } else {
            menores18++;
        }
        
        if(dato.arreglo[dato.i].sexo == 'M' || dato.arreglo[dato.i].sexo == 'm'){
            masculinos++;
        } else if(dato.arreglo[dato.i].sexo == 'F' || dato.arreglo[dato.i].sexo == 'f'){
            femeninos++;
        }
    }
    
    printf("Edad promedio: %.2f\n", (float)sumaEdades / TAM);
    printf("Mayores de 18: %d\n", mayores18);
    printf("Menores de 18: %d\n", menores18);
    printf("Masculinos: %d\n", masculinos);
    printf("Femeninos: %d\n", femeninos);
    printf("===========================\n");

    return 0;
}