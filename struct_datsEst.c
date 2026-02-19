#include <stdio.h>

struct datosEst{
    float arreglo[10];
    int *ptr;
    int datosIng;
    float prom;
    float desvstd;
};

int main(){
    struct datosEst est;
    est.ptr = est.arreglo; // Apuntar al inicio del arreglo

    return 0;
}

//hacer funcion de datos estadisticos con apuntadores, que me calcule las calificaciones del smestre , meter los datos en el arreglo y en datos ing meter las materias , guardar promedio y desviacion estandar]