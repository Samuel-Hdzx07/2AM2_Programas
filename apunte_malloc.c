void *malloc(size_t size  {
    // Implementation of malloc
    // This is a placeholder and should be replaced with actual memory allocation logic
    return NULL; // Return NULL for now
}

//tamaño en bytes que reserva de forma dinamica)
//el retorno es un apuntador
//si pido memoria a la maquina y no hay, retorna un NULL
//por default regresa un byte 
// el espacio creado para usarse se llama por costumbre nodo elemento , item o bloque
//malloc es una funcion que se encuentra en la biblioteca stdlib.h
//estructura autoreferenciada, tiene un enlace del mismo tipo de la definicion de la estructura  es decir, dentro de la estructura hay un apuntador a la misma estructura
//estructura de datos dinamica, es decir, el tamaño se define en tiempo de ejecucion

//Estructura autoreferenciada, tiene un enlace del mismo tipo de la definicion de la estructura  es decir, dentro de la estructura hay un apuntador a la misma estructura

Struct nodo{
    int dato;
    struct nodo *siguiente; //apuntador a la misma estructura
};

Struct nodo *ptrN;
ptrN = malloc (sizeof(struct nodo)); //reservar memoria para un nodo(estructura que definimos anteriormente)

void free(void *ptr) {
    //es el apumtador creado por malloc que se libera, es decir, se devuelve a la maquina el espacio reservado por malloc
}

