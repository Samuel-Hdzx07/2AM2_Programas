#include <stdio.h>
#define MAX 5

// ESTRUCTURA DE PILA ESTATICA
struct Pila {
    int datos[MAX];     // Arreglo para almacenar los datos
    int tope;           // Indice del elemento superior (-1 si está vacía)
};

// ==== FUNCIONES DE LA PILA ====

// Inicializar la pila
void inicializarPila(struct Pila *p) {
    p->tope = -1;  // -1 indica pila vacía
}

// Verificar si la pila está vacía
int estaVacia(struct Pila *p) {
    return p->tope == -1;
}

// Verificar si la pila está llena
int estaLlena(struct Pila *p) {
    return p->tope == MAX - 1;
}

// PUSH: Insertar un elemento en la pila
int push(struct Pila *p, int valor) {
    if (estaLlena(p)) {
        printf("ERROR: La pila esta llena. No se puede insertar %d\n", valor);
        return 0;  // Fallo
    }
    p->tope++;                  // Incrementar el tope
    p->datos[p->tope] = valor;  // Insertar el valor
    printf("Push: %d insertado exitosamente\n", valor);
    return 1;  // Éxito
}

// POP: Eliminar y retornar el elemento del tope
int pop(struct Pila *p, int *valor) {
    if (estaVacia(p)) {
        printf("ERROR: La pila esta vacia. No se puede hacer pop\n");
        return 0;  // Fallo
    }
    *valor = p->datos[p->tope];  // Obtener el valor del tope
    p->tope--;                    // Decrementar el tope
    printf("Pop: %d eliminado exitosamente\n", *valor);
    return 1;  // Éxito
}

// PEEK: Ver el elemento en el tope sin eliminarlo
int peek(struct Pila *p, int *valor) {
    if (estaVacia(p)) {
        printf("ERROR: La pila esta vacia\n");
        return 0;  // Fallo
    }
    *valor = p->datos[p->tope];
    return 1;  // Éxito
}

// Mostrar todos los elementos de la pila
void mostrarPila(struct Pila *p) {
    if (estaVacia(p)) {
        printf("La pila esta vacia\n");
        return;
    }
    printf("\n==== CONTENIDO DE LA PILA ====\n");
    printf("Tope -> ");
    for (int i = p->tope; i >= 0; i--) {
        printf("[%d] ", p->datos[i]);
    }
    printf("<- Fondo\n");
    printf("Cantidad de elementos: %d\n", p->tope + 1);
    printf("================================\n\n");
}

// ==== MENÚ PRINCIPAL ====
int menu() {
    int opcion;
    printf("\n===== MENU PILA ESTATICA =====\n");
    printf("1. Push (Insertar)\n");
    printf("2. Pop (Eliminar)\n");
    printf("3. Peek (Ver tope)\n");
    printf("4. Mostrar pila completa\n");
    printf("5. Verificar si esta vacia\n");
    printf("6. Verificar si esta llena\n");
    printf("7. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int main() {
    struct Pila miPila;
    struct Pila *ptrPila = &miPila;
    int valor, opcion;
    
    // Inicializar la pila
    inicializarPila(ptrPila);
    
    printf("*** IMPLEMENTACION DE PILA ESTATICA ***\n");
    printf("Capacidad maxima: %d elementos\n", MAX);
    
    // Ciclo del menú
    for(;;) {
        opcion = menu();
        
        switch(opcion) {
            case 1:  // Push
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                push(ptrPila, valor);
                break;
                
            case 2:  // Pop
                if (pop(ptrPila, &valor)) {
                    printf("Valor eliminado: %d\n", valor);
                }
                break;
                
            case 3:  // Peek
                if (peek(ptrPila, &valor)) {
                    printf("Elemento en el tope: %d\n", valor);
                }
                break;
                
            case 4:  // Mostrar
                mostrarPila(ptrPila);
                break;
                
            case 5:  // Está vacía
                if (estaVacia(ptrPila)) {
                    printf("La pila ESTA VACIA\n");
                } else {
                    printf("La pila NO esta vacia. Tiene %d elementos\n", ptrPila->tope + 1);
                }
                break;
                
            case 6:  // Está llena
                if (estaLlena(ptrPila)) {
                    printf("La pila ESTA LLENA\n");
                } else {
                    printf("La pila NO esta llena. Puede insertar %d elementos mas\n", MAX - ptrPila->tope - 1);
                }
                break;
                
            case 7:  // Salir
                printf("Saliendo del programa...\n");
                return 0;
                
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }
    
    return 0;
}

/*
 * CONCEPTOS CLAVE DE PILAS (STACK):
 * 
 * 1. LIFO (Last In, First Out): El último en entrar es el primero en salir
 * 2. TOPE: Índice que apunta al elemento superior de la pila
 * 3. PUSH: Operación para insertar un elemento (tope++)
 * 4. POP: Operación para eliminar el elemento del tope (tope--)
 * 5. PEEK: Ver el elemento del tope sin eliminarlo
 * 6. PILA VACÍA: tope == -1
 * 7. PILA LLENA: tope == MAX - 1
 * 
 * APLICACIONES DE PILAS:
 * - Evaluación de expresiones matemáticas
 * - Llamadas recursivas (call stack)
 * - Función "deshacer" en editores
 * - Navegación hacia atrás en navegadores
 */
