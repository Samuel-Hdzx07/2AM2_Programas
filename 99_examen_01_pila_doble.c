#include <stdio.h>
#define TAM 10

struct Pilas{
    int arr[TAM];
    int *pilaizq;
    int *pilader;
};

int pilaizq_llena(struct Pilas *ptr){
    if(ptr->pilaizq == ptr->pilader - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int pilader_llena(struct Pilas *ptr){
    if(ptr->pilader == ptr->pilaizq + 1){
        return 1;
    }
    else{
        return 0;
    }
}

int pilaizq_vacia(struct Pilas *ptr){
    if(ptr->pilaizq == ptr->arr - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int pilader_vacia(struct Pilas *ptr){
    if(ptr->pilader == ptr->arr + TAM){
        return 1;
    }
    else{
        return 0;
    }
}

int meterdato_izq(struct Pilas *ptr, int dato){
    if(pilaizq_llena(ptr)){
        printf("La pila izquierda esta llena, no se puede insertar %d\n", dato);
        return 0;
    }
    else{
        ptr->pilaizq++;
        *(ptr->pilaizq) = dato;
        return 1;
    }
}

int meterdato_der(struct Pilas *ptr, int dato){
    if(pilader_llena(ptr)){
        printf("La pila derecha esta llena, no se puede insertar %d\n", dato);
        return 0;
    }
    else{
        ptr->pilader--;
        *(ptr->pilader) = dato;
        return 1;
    }
}

int sacardato_izq(struct Pilas *ptr){
    int dato;
    if(pilaizq_vacia(ptr)){
        printf("La pila izquierda esta vacia\n");
        return -1;
    }
    else{
        dato = *(ptr->pilaizq);
        ptr->pilaizq--;
        return dato;
    }
}

int sacardato_der(struct Pilas *ptr){
    int dato;
    if(pilader_vacia(ptr)){
        printf("La pila derecha esta vacia\n");
        return -1;
    }
    else{
        dato = *(ptr->pilader);
        ptr->pilader++;
        return dato;
    }
}

void mostrar_pila(struct Pilas *ptr){
    printf("\n=== ESTADO DE LAS PILAS ===\n");
    
    printf("Pila Izquierda: ");
    if(pilaizq_vacia(ptr)){
        printf("VACIA");
    } else {
        for(int *aux = ptr->arr; aux <= ptr->pilaizq; aux++){
            printf("[%d] ", *aux);
        }
    }
    printf("\n");
    
    printf("Pila Derecha: ");
    if(pilader_vacia(ptr)){
        printf("VACIA");
    } else {
        for(int *aux = ptr->pilader; aux < ptr->arr + TAM; aux++){
            printf("[%d] ", *aux);
        }
    }
    printf("\n==========================\n\n");
}

void mostrar_menu(){
    printf("\n====== MENU DOBLE PILA ======\n");
    printf("1. Meter dato en pila izquierda\n");
    printf("2. Meter dato en pila derecha\n");
    printf("3. Sacar dato de pila izquierda\n");
    printf("4. Sacar dato de pila derecha\n");
    printf("5. Mostrar estado de pilas\n");
    printf("6. Salir\n");
    printf("=============================\n");
    printf("Selecciona una opcion: ");
}

int main(){
    struct Pilas misPilas;
    
    // Inicializar punteros
    misPilas.pilaizq = misPilas.arr - 1;
    misPilas.pilader = misPilas.arr + TAM;
    
    int opcion;
    int valor, resultado;
    
    do {
        mostrar_menu();
        scanf("%d", &opcion);
        
        switch(opcion){
            case 1:
                printf("Ingresa el valor para pila izquierda: ");
                scanf("%d", &valor);
                if(meterdato_izq(&misPilas, valor)){
                    printf("✓ Valor %d insertado en pila izquierda\n", valor);
                } else {
                    printf("✗ Error al insertar\n");
                }
                break;
                
            case 2:
                printf("Ingresa el valor para pila derecha: ");
                scanf("%d", &valor);
                if(meterdato_der(&misPilas, valor)){
                    printf("✓ Valor %d insertado en pila derecha\n", valor);
                } else {
                    printf("✗ Error al insertar\n");
                }
                break;
                
            case 3:
                resultado = sacardato_izq(&misPilas);
                if(resultado != -1){
                    printf("✓ Valor sacado de pila izquierda: %d\n", resultado);
                }
                break;
                
            case 4:
                resultado = sacardato_der(&misPilas);
                if(resultado != -1){
                    printf("✓ Valor sacado de pila derecha: %d\n", resultado);
                }
                break;
                
            case 5:
                mostrar_pila(&misPilas);
                break;
                
            case 6:
                printf("\n¡Hasta luego!\n");
                break;
                
            default:
                printf("\n✗ Opcion invalida\n");
        }
    } while(opcion != 6);
    
    return 0;
}
