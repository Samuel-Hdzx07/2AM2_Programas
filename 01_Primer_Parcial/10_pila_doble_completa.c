#include <stdio.h>
#define TAM 10

struct PilasEncontradas{
    int arreglo[TAM];
    int *ptrIzq;
    int *ptrDer;
};

int pilaIzq_llena(struct PilasEncontradas *ptr){
    if(ptr->ptrIzq == ptr->ptrDer - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int pilaDer_llena(struct PilasEncontradas *ptr){
    if(ptr->ptrDer == ptr->ptrIzq + 1){
        return 1;
    }
    else{
        return 0;
    }
}

int pilaIzq_vacia(struct PilasEncontradas *ptr){
    if(ptr->ptrIzq == ptr->arreglo - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int pilaDer_vacia(struct PilasEncontradas *ptr){
    if(ptr->ptrDer == ptr->arreglo + TAM){
        return 1;
    }
    else{
        return 0;
    }
}

int pushIzq(struct PilasEncontradas *ptr, int datito){
    if(pilaIzq_llena(ptr)){
        printf("La pila izquierda esta llena, no se puede insertar el dato %d\n", datito);
        return 0;
    }
    else{
        ptr->ptrIzq = ptr->ptrIzq + 1;
        *(ptr->ptrIzq) = datito;
        return 1;
    }
}

int pushDer(struct PilasEncontradas *ptr, int datito){
    if(pilaDer_llena(ptr)){
        printf("La pila derecha esta llena, no se puede insertar el dato %d\n", datito);
        return 0;
    }
    else{
        ptr->ptrDer = ptr->ptrDer - 1;
        *(ptr->ptrDer) = datito;
        return 1;
    }
}

int popIzq(struct PilasEncontradas *ptr){
    int datito;
    
    if(pilaIzq_vacia(ptr)){
        printf("La pila izquierda esta vacia, no se puede sacar dato\n");
        return 0;
    }
    else{
        datito = *(ptr->ptrIzq);
        ptr->ptrIzq = ptr->ptrIzq - 1;
        return datito;
    }
}

int popDer(struct PilasEncontradas *ptr){
    int datito;
    
    if(pilaDer_vacia(ptr)){
        printf("La pila derecha esta vacia, no se puede sacar dato\n");
        return 0;
    }
    else{
        datito = *(ptr->ptrDer);
        ptr->ptrDer = ptr->ptrDer + 1;
        return datito;
    }
}

int mostrarPilas(struct PilasEncontradas *ptr){
    int *aux;
    
    printf("\n=== CONTENIDO DE LAS PILAS ===\n");
    
    if(pilaIzq_vacia(ptr)){
        printf("Pila izquierda: vacia\n");
    }
    else{
        printf("Pila izquierda:");
        for(aux = ptr->ptrIzq; aux >= ptr->arreglo; aux--){
            printf(" %d", *aux);
        }
        printf("\n");
    }
    
    if(pilaDer_vacia(ptr)){
        printf("Pila derecha: vacia\n");
    }
    else{
        printf("Pila derecha:");
        for(aux = ptr->ptrDer; aux < ptr->arreglo + TAM; aux++){
            printf(" %d", *aux);
        }
        printf("\n");
    }
    
    printf("==============================\n");
    
    return 1;
}

int menu(){
    int opcion;
    
    printf("\n MENU DE PILAS ENCONTRADAS \n");
    printf("1. Insertar por izquierda\n");
    printf("2. Insertar por derecha\n");
    printf("3. Sacar por izquierda\n");
    printf("4. Sacar por derecha\n");
    printf("5. Mostrar contenido de las pilas\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    
    return opcion;
}

int main(){
    struct PilasEncontradas pilas, *ptrP;
    ptrP = &pilas;
    
    ptrP->ptrIzq = ptrP->arreglo - 1;
    ptrP->ptrDer = ptrP->arreglo + TAM;
    
    int opcion;
    int valor;
    
    do{
        opcion = menu();
        
        switch(opcion){
            case 1:
                printf("Ingrese el dato a meter por izquierda: ");
                scanf("%d", &valor);
                pushIzq(ptrP, valor);
                break;
                
            case 2:
                printf("Ingrese el dato a meter por derecha: ");
                scanf("%d", &valor);
                pushDer(ptrP, valor);
                break;
                
            case 3:
                valor = popIzq(ptrP);
                if(valor != 0){
                    printf("El dato sacado por izquierda es: %d\n", valor);
                }
                break;
                
            case 4:
                valor = popDer(ptrP);
                if(valor != 0){
                    printf("El dato sacado por derecha es: %d\n", valor);
                }
                break;
                
            case 5:
                mostrarPilas(ptrP);
                break;
                
            case 6:
                printf("Saliendo del programa...\n");
                break;
                
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
        
    }while(opcion != 6);
    
    return 0;
}
