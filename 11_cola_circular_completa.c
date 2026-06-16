#include <stdio.h>
#define MAX 5

// ESTRUCTURA DE COLA ESTATICA (CIRCULAR)
struct Cola {
    int datos[MAX];     // Arreglo para almacenar los datos
    int frente;         // Índice del primer elemento
    int final;          // Índice del último elemento
    int contador;       // Cantidad de elementos en la cola
};

// ==== FUNCIONES DE LA COLA ====

// Inicializar la cola
void inicializarCola(struct Cola *c) {
    c->frente = 0;
    c->final = -1;
    c->contador = 0;  // Cola vacía
}

// Verificar si la cola está vacía
int estaVacia(struct Cola *c) {
    return c->contador == 0;
}

// Verificar si la cola está llena
int estaLlena(struct Cola *c) {
    return c->contador == MAX;
}

// ENQUEUE: Insertar un elemento al final de la cola
int enqueue(struct Cola *c, int valor) {
    if (estaLlena(c)) {
        printf("ERROR: La cola esta llena. No se puede insertar %d\n", valor);
        return 0;  // Fallo
    }
    // Cola circular: cuando final llega al límite, vuelve al inicio
    c->final = (c->final + 1) % MAX;
    c->datos[c->final] = valor;
    c->contador++;
    printf("Enqueue: %d insertado exitosamente en posicion %d\n", valor, c->final);
    return 1;  // Éxito
}

// DEQUEUE: Eliminar y retornar el elemento del frente
int dequeue(struct Cola *c, int *valor) {
    if (estaVacia(c)) {
        printf("ERROR: La cola esta vacia. No se puede hacer dequeue\n");
        return 0;  // Fallo
    }
    *valor = c->datos[c->frente];  // Obtener el valor del frente
    printf("Dequeue: %d eliminado de la posicion %d\n", *valor, c->frente);
    // Cola circular: cuando frente llega al límite, vuelve al inicio
    c->frente = (c->frente + 1) % MAX;
    c->contador--;
    return 1;  // Éxito
}

// PEEK: Ver el elemento en el frente sin eliminarlo
int peek(struct Cola *c, int *valor) {
    if (estaVacia(c)) {
        printf("ERROR: La cola esta vacia\n");
        return 0;  // Fallo
    }
    *valor = c->datos[c->frente];
    return 1;  // Éxito
}

// Mostrar todos los elementos de la cola
void mostrarCola(struct Cola *c) {
    if (estaVacia(c)) {
        printf("La cola esta vacia\n");
        return;
    }
    printf("\n==== CONTENIDO DE LA COLA ====\n");
    printf("Frente -> ");
    
    int i = c->frente;
    int count = 0;
    while (count < c->contador) {
        printf("[%d] ", c->datos[i]);
        i = (i + 1) % MAX;  // Cola circular
        count++;
    }
    printf("<- Final\n");
    printf("Cantidad de elementos: %d\n", c->contador);
    printf("Frente en posicion: %d | Final en posicion: %d\n", c->frente, c->final);
    printf("================================\n\n");
}

// Mostrar estado interno de la cola (para debugging)
void mostrarEstadoInterno(struct Cola *c) {
    printf("\n==== ESTADO INTERNO DE LA COLA ====\n");
    printf("Arreglo completo: ");
    for (int i = 0; i < MAX; i++) {
        if (i == c->frente && i == c->final && c->contador > 0) {
            printf("[F,Fi:%d] ", c->datos[i]);  // Frente y Final en mismo lugar
        } else if (i == c->frente && c->contador > 0) {
            printf("[F:%d] ", c->datos[i]);  // Frente
        } else if (i == c->final && c->contador > 0) {
            printf("[Fi:%d] ", c->datos[i]);  // Final
        } else {
            printf("[%d] ", c->datos[i]);
        }
    }
    printf("\n");
    printf("Frente=%d | Final=%d | Contador=%d\n", c->frente, c->final, c->contador);
    printf("====================================\n\n");
}

// ==== MENÚ PRINCIPAL ====
int menu() {
    int opcion;
    printf("\n===== MENU COLA ESTATICA =====\n");
    printf("1. Enqueue (Insertar al final)\n");
    printf("2. Dequeue (Eliminar del frente)\n");
    printf("3. Peek (Ver frente)\n");
    printf("4. Mostrar cola\n");
    printf("5. Verificar si esta vacia\n");
    printf("6. Verificar si esta llena\n");
    printf("7. Mostrar estado interno\n");
    printf("8. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int main() {
    struct Cola miCola;
    struct Cola *ptrCola = &miCola;
    int valor, opcion;
    
    // Inicializar la cola
    inicializarCola(ptrCola);
    
    printf("*** IMPLEMENTACION DE COLA ESTATICA CIRCULAR ***\n");
    printf("Capacidad maxima: %d elementos\n", MAX);
    
    // Ciclo del menú
    for(;;) {
        opcion = menu();
        
        switch(opcion) {
            case 1:  // Enqueue
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                enqueue(ptrCola, valor);
                break;
                
            case 2:  // Dequeue
                if (dequeue(ptrCola, &valor)) {
                    printf("Valor eliminado: %d\n", valor);
                }
                break;
                
            case 3:  // Peek
                if (peek(ptrCola, &valor)) {
                    printf("Elemento en el frente: %d\n", valor);
                }
                break;
                
            case 4:  // Mostrar
                mostrarCola(ptrCola);
                break;
                
            case 5:  // Está vacía
                if (estaVacia(ptrCola)) {
                    printf("La cola ESTA VACIA\n");
                } else {
                    printf("La cola NO esta vacia. Tiene %d elementos\n", ptrCola->contador);
                }
                break;
                
            case 6:  // Está llena
                if (estaLlena(ptrCola)) {
                    printf("La cola ESTA LLENA\n");
                } else {
                    printf("La cola NO esta llena. Puede insertar %d elementos mas\n", MAX - ptrCola->contador);
                }
                break;
                
            case 7:  // Estado interno
                mostrarEstadoInterno(ptrCola);
                break;
                
            case 8:  // Salir
                printf("Saliendo del programa...\n");
                return 0;
                
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }
    
    return 0;
}

/*
 * CONCEPTOS CLAVE DE COLAS (QUEUE):
 * 
 * 1. FIFO (First In, First Out): El primero en entrar es el primero en salir
 * 2. FRENTE (Front): Índice del primer elemento (donde se elimina)
 * 3. FINAL (Rear): Índice del último elemento (donde se inserta)
 * 4. ENQUEUE: Operación para insertar un elemento al final
 * 5. DEQUEUE: Operación para eliminar el elemento del frente
 * 6. PEEK: Ver el elemento del frente sin eliminarlo
 * 7. COLA CIRCULAR: Usa el operador módulo (%) para reutilizar espacios
 *    - Evita el problema de la "falsa cola llena"
 *    - final = (final + 1) % MAX
 *    - frente = (frente + 1) % MAX
 * 8. CONTADOR: Lleva el conteo de elementos (más fácil que usar frente y final)
 * 
 * DIFERENCIA ENTRE COLA LINEAL Y CIRCULAR:
 * - Cola lineal: Desperdicia espacio cuando frente avanza
 * - Cola circular: Reutiliza espacios usando aritmética modular
 * 
 * APLICACIONES DE COLAS:
 * - Sistemas de impresión (print spooler)
 * - Procesamiento de tareas (task scheduler)
 * - Buffers de datos (ej: teclado, red)
 * - Algoritmos BFS (Breadth-First Search)
 * - Sistemas de atención al cliente
 */
