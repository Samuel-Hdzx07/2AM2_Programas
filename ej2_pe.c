#include <stdio.h>

#define TAM 100

struct Cola{
    int arr[TAM];
    int *ptrm, *ptrs;
};


int escolallena(struct Cola *ptr){
    if(ptr->ptrm == ptr->arr + TAM)
        return 1;
    else
        return 0;
}

int escolavacia(struct Cola *ptr){
    if(ptr->ptrs == ptr->ptrm)
        return 1;
    else
        return 0;
}

int meterdato(struct Cola *ptrc, int datito){

    if(escolallena(ptrc)){
        printf("La cola esta llena, no se puede meter dato\n");
        return 0;
    }
    *ptrc->ptrm = datito;
    ptrc->ptrm = ptrc->ptrm + 1;
    return 1;

}


int sacardato(struct Cola *ptr, int *datito){
    if(escolavacia(ptr)){
        printf("La cola esta vacia, no se puede sacar dato\n");
        return 0;
    }

    *datito = *(ptr->ptrs);

    ptr->ptrs = ptr->ptrs + 1;

    return 1;

}

int mostrarCola(struct Cola *ptrz){

    if(escolavacia(ptrz)){
        printf("La cola esta vacia y no se puede mostrar nada");
        return 0;
    }

    int *aux = ptrz->ptrs;

    for(; aux < ptrz-> ptrm; aux++){
        printf("%d ", *aux);
    }

    printf("\n");

    return 1;
    
}

void menu(){
    int opc;
    printf("\n MENU DE COLA ESTATICA \n");
    printf("1. Meter dato \n"); 
    printf("2. Sacar dato \n");
    printf("3. Mostrar cola \n");
    printf("4. Salir \n");
    printf("Ingrese su opcion: ");
    
}

int main(){
    struct Cola colita, *ptrc;
    ptrc=(&colita);

    ptrc->ptrm = ptrc->arr;
    ptrc->ptrs = ptrc->arr;

    int midato;

    int opc;

    do{
        menu();
        scanf("%d", &opc);

        switch(opc){
            case 1:
                printf("Ingrese el dato a meter: ");
                scanf("%d", &midato);
                meterdato(ptrc, midato);
                break;
            case 2:
                sacardato(ptrc, &midato);
                printf("El dato sacado es: %d\n", midato);
                break;
            case 3:
                mostrarCola(ptrc);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while(opc != 4);
}