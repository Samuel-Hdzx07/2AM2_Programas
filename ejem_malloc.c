// #include <stdio.h>

// struct nodo{
//     int dato;
//     struct nodo *ptrSiguiente; //apuntador a la misma estructura
// };

// int main(){
//     struct nodo *ptrReferencia,*ptrNuevo,*ptrRecorrer,*ptrBasura;
//     ptrReferencia = NULL; //inicializamos el apuntador a NULL
//     ptrNuevo = (struct nodo *)malloc(sizeof(struct nodo)); //reservamos memoria para un nuevo nodo
//     printf("Ingrese un numero: ");
//     scanf("%d", &ptrNuevo->dato); //asignamos el dato al nuevo
//     ptrNuevo->ptrSiguiente = NULL; //inicializamos el apuntador siguiente a NULL
//     ptrReferencia = ptrNuevo; //hacemos que el apuntador de referencia apunte al nuevo nodo
//     return 0;
//     ptrNuevo = (struct nodo *)malloc(sizeof(struct nodo)); //reservamos memoria para un nuevo nodo
//     printf("Ingrese un numero: ");
//     scanf("%d", &ptrNuevo->dato); //asignamos el dato al nuevo
//     ptrNuevo->ptrSiguiente = NULL; //inicializamos el apuntador siguiente a NULL
//     //Ahoranhcemos el enlace del nuevo nodo al nodo de referencia
//     ptrNuevo->ptrSiguiente = ptrReferencia; //hacemos que el nuevo nodo apunte al nodo de referencia
//     ptrReferencia = ptrNuevo; //hacemos que el apuntador de referencia apunte al nuevo nodo
//     ptrNuevo = (struct nodo *)malloc(sizeof(struct nodo)); //reservamos memoria para un nuevo nodo
//     printf("Ingrese un numero: ");
//     scanf("%d", &ptrNuevo->dato); //asignamos el dato al nuevo
//     ptrNuevo->ptrSiguiente = NULL; //inicializamos el apuntador siguiente a NULL
//     ptrRecorrer = ptrReferencia; //hacemos que el apuntador de recorrer apunte al nodo de referencia
//     while(ptrRecorrer != NULL){ //recorremos la lista hasta el final
//         printf("%d\n", ptrRecorrer->dato); //imprimimos el dato del nodo actual
//         ptrRecorrer = ptrRecorrer->ptrSiguiente; //hacemos que el apuntador de recorrer apunte al siguiente nodo
//     }
    
// }

// //
#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *ptrSiguiente;
};

int main(){
    struct nodo *ptrReferencia,*ptrNuevo,*ptrRecorrer,*ptrBasura;

    ptrReferencia = NULL; 

    // PRIMER NODO
    ptrNuevo = (struct nodo *)malloc(sizeof(struct nodo));
    printf("Ingrese un numero: ");
    scanf("%d", &ptrNuevo->dato);
    ptrNuevo->ptrSiguiente = NULL;
    ptrReferencia = ptrNuevo;

    // SEGUNDO NODO
    ptrNuevo = (struct nodo *)malloc(sizeof(struct nodo));
    printf("Ingrese un numero: ");
    scanf("%d", &ptrNuevo->dato);
    ptrNuevo->ptrSiguiente = ptrReferencia;
    ptrReferencia = ptrNuevo;

    // TERCER NODO
    ptrNuevo = (struct nodo *)malloc(sizeof(struct nodo));
    printf("Ingrese un numero: ");
    scanf("%d", &ptrNuevo->dato);
    ptrNuevo->ptrSiguiente = ptrReferencia;
    ptrReferencia = ptrNuevo;

    // RECORRER E IMPRIMIR
    printf("\nLista:\n");
    ptrRecorrer = ptrReferencia;
    while(ptrRecorrer != NULL){
        printf("%d\n", ptrRecorrer->dato);
        ptrRecorrer = ptrRecorrer->ptrSiguiente;
    }

    // BORRAR / LIBERAR MEMORIA
    while(ptrReferencia != NULL){
        ptrBasura = ptrReferencia;
        ptrReferencia = ptrReferencia->ptrSiguiente;
        free(ptrBasura);
    }

    return 0;
}