    #include <stdio.h>
    #define MAX 5

    struct Pila{
        int dato[MAX];
        int top;
    };

    int pila_llena(struct Pila *ptrP){

        if(ptrP->top == MAX-1){
            return 1;
        }
        else{
            return 0;
        }

    }

    int pila_vacia(struct Pila *ptrP){

        if(ptrP->top == -1){
            return 1;
        }
        else{
            return 0;
        }

    }

    int push(struct Pila *ptrPi, int datito){

        if(pila_llena(ptrPi)){
            printf("La pila esta llena, no se puede insertar el dato %d\n", datito);
            return 0;
        }
        else{

            ptrPi->top = ptrPi->top + 1;
            ptrPi->dato[ptrPi->top] = datito;

            return 1;
        }

    }

    int pop(struct Pila *ptrPi){

        int datito;

        if(pila_vacia(ptrPi)){
            printf("La pila esta vacia, no se puede eliminar\n");
            return 0;
        }
        else{

            datito = ptrPi->dato[ptrPi->top];
            ptrPi->top = ptrPi->top - 1;

            return datito;
        }

    }

    int mostrar_Pila(struct Pila *ptrPi){

        if(pila_vacia(ptrPi)){
            printf("La pila esta vacia, no se puede mostrar\n");
            return 0;
        }
        else{

            printf("La pila tiene estos datos:");

            for(int t = ptrPi->top; t >= 0; t--){
                printf(" %d", ptrPi->dato[t]);
            }

            printf("\n");
        }

        return 1;
    }

    int menu(){

        int opcion;

        printf("\n MENU DE PILA ESTATICA \n");
        printf("1. Meter dato \n");
        printf("2. Sacar dato \n");
        printf("3. Mostrar pila\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        return opcion;
    }

    int main(){

        struct Pila miPila;
        miPila.top = -1;

        int opcion;
        int valor;

        do{

            opcion = menu();

            switch(opcion){

                case 1:
                    printf("Ingrese el dato a meter: ");
                    scanf("%d", &valor);
                    push(&miPila, valor);
                    break;

                case 2:
                    valor = pop(&miPila);
                    if(valor != 0){
                        printf("El dato eliminado es: %d\n", valor);
                    }
                    break;

                case 3:
                    mostrar_Pila(&miPila);
                    break;

                case 4:
                    printf("Saliendo del programa...\n");
                    break;

                default:
                    printf("Opcion invalida. Intente de nuevo.\n");
            }

        }while(opcion != 4);

        return 0;
    }