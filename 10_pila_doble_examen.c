//HERNANDEZ BARRIOS SAMUEL RODRIGO 2AM2
    
    #include <stdio.h>
    #define TAM 10

    struct Pilas{
        int arreglo[TAM];
        int *ptrIzq;
        int *ptrDer;
    };

    int pilaIzq_llena(struct Pilas *ptr){
        if(ptr->ptrIzq == ptr->ptrDer - 1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int pilaDer_llena(struct Pilas *ptr){
        if(ptr->ptrDer == ptr->ptrIzq + 1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int pilaIzq_vacia(struct Pilas *ptr){
        if(ptr->ptrIzq == ptr->arreglo - 1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int pilaDer_vacia(struct Pilas *ptr){
        if(ptr->ptrDer == ptr->arreglo + TAM){
            return 1;
        }
        else{
            return 0;
        }
    }

    int pushIzq(struct Pilas *ptr, int datito){
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

    int pushDer(struct Pilas *ptr, int datito){
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

    int popIzq(struct Pilas *ptr){
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

    int popDer(struct Pilas *ptr){
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

    int mostrarPilas(struct Pilas *ptr){
        int *aux;
        
        printf("CONTENIDO DE LAS PILAS\n");
        printf("[ ");
            if(!pilaIzq_vacia(ptr)){
            for(aux = ptr->arreglo; aux <= ptr->ptrIzq; aux++){
                printf("%d ", *aux);
            }
        }

        if(!pilaDer_vacia(ptr)){
            for(aux = ptr->ptrDer; aux < ptr->arreglo + TAM; aux++){
                printf("%d ", *aux);
            }
        }
        
        printf("]\n");
        
        return 1;
    }

    void funcTolower(char *ptr){

        for(; *ptr != '\0'; ptr++){
        if(*ptr >= 'A' && *ptr <= 'Z'){
                *ptr = *ptr + 32;
        };
        };
    };

    void funcDefs(){
        printf("-Una funcion es una porcion de codigo que realiza una tarea especifica y puede ser llamada las veces que el usuario crea necesarias, facilita el codigo ya que se programan y se pueden llamar las veces que uno quiera\n");
        printf("-Un apuntador es una variable mas pero que en vez de guardar un valor, este guarda como valor, la direccion de memoria de otra variable y el contenido de esta\n");
        printf("-Las estructuras de datos son tipos de variables definidas por el usuario con ciertas caracteristicas especificas, agrupa varias variables y sirve como molde para encapsular distintos tipos de datos\n");
    };


    int menu(){
        int opcion;
        
        printf("\n MENU DE PILAS ENCONTRADAS \n");
        printf("1. Insertar por izquierda\n");
        printf("2. Insertar por derecha\n");
        printf("3. Sacar por izquierda\n");
        printf("4. Sacar por derecha\n");
        printf("5. Mostrar contenido de las pilas\n");
        printf("6. Usar la funcion Tolower\n");
        printf("7. Definiciones de apuntador, funcion y estructuras\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        return opcion;
    }

    int main(){
        struct Pilas pilas, *ptrP;
        ptrP = &pilas;
        char cadena[20];
        char *ptrCad;

        ptrCad= cadena;
        
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
                    printf("Ingresa una cadena de texto");
                    getchar();
                    fgets(cadena, 20, stdin);
                    funcTolower(ptrCad);
                    printf("La cadena en minusculas es: %s", cadena);
                    break;
                
                case 7:
                    funcDefs();
                    break;
                    
                case 8:
                    printf("Saliendo...\n");
                    break;
                    
                default:
                    printf("Opcion invalida\n");
            }
            
        }while(opcion != 8);
        
        return 0;
    }
