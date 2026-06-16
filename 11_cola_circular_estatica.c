#include <stdio.h>
#define TAM 5

struct Cola{
    int arreglo[TAM];
    int *ptrm, *ptrs;
};

    int esColavacia(struct Cola *ptrvac){

        if(ptrvac->ptrs == ptrvac->ptrm){
            return 1;
        }
        else{
            return 0;
        }
    };

    int esColallena(struct Cola *ptrllen){

        int *ptrsig = ptrllen->ptrm + 1;

        if(ptrsig == ptrllen->arreglo +TAM)
            ptrsig = ptrllen->arreglo;

        //significa que esta llena
        if(ptrsig == ptrllen->ptrs){
            return 1;
        }
        else{
            return 0;
        }

    };

    int meterdato(struct Cola *ptrc, int datito){
        if(esColallena(ptrc)){
            printf("La cola esta llena, no se puede meter dato\n");
            return 0;
        }

        *ptrc->ptrm = datito;
        ptrc->ptrm = ptrc->ptrm + 1;

        if(ptrc-> ptrm == ptrc-> arreglo +TAM)
            ptrc->ptrm = ptrc->arreglo;

        return 1;

    };

    int sacarDato(struct Cola *ptrsac, int *datito){

        if(esColavacia(ptrsac)){
            printf("La cola esta vacia, no se puede sacar dato\n");
            return 0;
        }

        *datito=*(ptrsac->ptrs);
        ptrsac->ptrs = ptrsac->ptrs + 1;

        if(ptrsac->ptrs == ptrsac->arreglo + TAM)
            ptrsac->ptrs = ptrsac->arreglo;

         // esto funciona si ambos punteros estan en un lugar y ya no hay contenido en las casillas pasadas, los punteros los coloca al inicio del arreglo
        if(ptrsac->ptrs == ptrsac->ptrm){
            ptrsac->ptrs = ptrsac->arreglo;
            ptrsac->ptrm = ptrsac->arreglo;
        }

        return 1;

    };

    int mostrarCola(struct Cola *ptrc){
        if(esColavacia(ptrc)){
            printf("La cola esta vacia, no se puede mostrar nada\n");
            return 0;
        }

        int *aux = ptrc->ptrs;

        printf("La cola tiene estos datos: ");

        for(;aux!=ptrc->ptrm;){
            printf("%d ", *aux);

            aux++;
            
             if(aux == ptrc->arreglo + TAM)
            aux = ptrc->arreglo;
        }
        printf("\n");

        return 1;

    };

    int menu(){
        int opcion;

        printf("\n MENU DE COLA ESTATICA CIRCULAR \n");
        printf("1. Meter dato \n");
        printf("2. Sacar dato \n");
        printf("3. Mostrar cola\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        return opcion;
    };

int main(){

    struct Cola cola, *ptrco;
    ptrco=&cola;
    //lo pone al inicio del arreglo tanto el ptrm como el ptrs
    ptrco -> ptrm = ptrco -> arreglo;
    ptrco -> ptrs = ptrco -> arreglo;

    int midato;
    int opc;

    do{
        opc = menu();
        switch(opc){
            case 1:
                printf("Ingrese el dato a meter: ");
                scanf("%d", &midato);
                meterdato(ptrco, midato);
                break;
            case 2:
                if(sacarDato(ptrco, &midato))
                    printf("Dato sacado: %d\n", midato);
                break;
            case 3:
                mostrarCola(ptrco);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    }while(opc != 4);

    return 0;
}