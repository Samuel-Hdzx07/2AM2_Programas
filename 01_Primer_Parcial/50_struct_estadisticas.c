    #include <stdio.h>
    #include <math.h>

    struct datosEst{
        float arreglo[20];
        float *ptr;
        int numDatos;
        float prom;
        float desvstd;
    };

    int meterDatos(struct datosEst *ptrS){

        printf("Ingrese el numero de datos: ");
        scanf("%d", &ptrS->numDatos);

        for(ptrS->ptr = ptrS->arreglo; ptrS->ptr < &ptrS->arreglo[ptrS->numDatos]; ptrS->ptr = ptrS->ptr + 1){
            printf("Ingrese el dato: ");
            scanf("%f", ptrS->ptr);
        }

        return 0;
    }

    int calculosEstadisticos(struct datosEst *ptrS){
        float sum = 0.0;
        for(ptrS->ptr= ptrS->arreglo; ptrS->ptr < &ptrS->arreglo[ptrS->numDatos]; ptrS->ptr = ptrS->ptr + 1)
            sum +=  *ptrS->ptr;

        ptrS->prom = sum / (ptrS->numDatos);

        float sumDesv = 0.0;
        for(ptrS->ptr= ptrS->arreglo; ptrS->ptr < &ptrS->arreglo[ptrS->numDatos]; ptrS->ptr = ptrS->ptr + 1)
            sum = sum +  pow((*ptrS->ptr - ptrS->prom), 2);

            sum = sum / (ptrS->numDatos);
            ptrS->desvstd = pow(sum, 0.5);
        return 0;

    }

    int menu(){
        int op;
        printf("1. Ingresar datos\n");
        printf("2. Calcular promedio y desviacion estandar\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &op);
        return op;
    }


    int main(){
        struct datosEst datest, *miptrS;
        miptrS = &datest;

        for(;;){
            switch(menu()){
                case 1:
                    meterDatos(miptrS);
                    break;
                case 2:
                    calculosEstadisticos(miptrS);
                    printf("Promedio: %.2f\n", miptrS->prom);
                    printf("Desviacion estandar: %.2f\n", miptrS->desvstd);
                    break;
                case 3:
                    printf("Saliendo del programa...\n");
                    return 0;
                default:
                    printf("Opcion no valida. Intente de nuevo.\n");
            }
        }

        return 0;
    }

    //hacer funcion de datos estadisticos con apuntadores, que me calcule las calificaciones del smestre , meter los datos en el arreglo y en datos ing meter las materias , guardar promedio y desviacion estandar]