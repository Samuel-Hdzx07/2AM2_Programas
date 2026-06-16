#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================
//                     ESTRUCTURA DEL NODO
// ============================================================================

typedef struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
} Nodo;

// Declaraciones anticipadas de funciones
int contarMayoresOIguales(Nodo *raiz, int valor);
int sumarMayoresOIguales(Nodo *raiz, int valor);

// ============================================================================
//                     CREACION Y LIBERACION
// ============================================================================

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error de memoria\n");
        return NULL;
    }
    nuevo->dato = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Liberar toda la memoria del árbol
void liberarArbol(Nodo *raiz) {
    if (raiz == NULL) return;
    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    free(raiz);
}

// ============================================================================
//                     INSERCION
// ============================================================================

// Insertar nodo en el árbol (ABB)
Nodo* insertar(Nodo *raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }
    
    if (valor < raiz->dato) {
        raiz->izq = insertar(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        raiz->der = insertar(raiz->der, valor);
    }
    // Si es igual, no insertamos (no duplicados)
    
    return raiz;
}

// ============================================================================
//                     RECORRIDOS
// ============================================================================

// Recorrido Inorden (Izq - Raiz - Der) -> Imprime en orden creciente
void inorden(Nodo *raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izq);
    printf("%d ", raiz->dato);
    inorden(raiz->der);
}

// Recorrido Preorden (Raiz - Izq - Der)
void preorden(Nodo *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->dato);
    preorden(raiz->izq);
    preorden(raiz->der);
}

// Recorrido Postorden (Izq - Der - Raiz)
void postorden(Nodo *raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izq);
    postorden(raiz->der);
    printf("%d ", raiz->dato);
}

// Recorrido inverso (descendente / decreciente)
void descendente(Nodo *raiz) {
    if (raiz == NULL) return;
    descendente(raiz->der);     // Primero derecha
    printf("%d ", raiz->dato);   // Luego raíz
    descendente(raiz->izq);     // Luego izquierda
}

// ============================================================================
//                     IMPRESIONES
// ============================================================================

// Imprimir el árbol completo
void imprimirArbol(Nodo *raiz) {
    if (raiz == NULL) {
        printf("Árbol vacío\n");
        return;
    }
    printf("Inorden: ");
    inorden(raiz);
    printf("\n");
}

// Imprimir nodos mayores a un número
void imprimirMayoresQue(Nodo *raiz, int numero) {
    if (raiz == NULL) return;
    
    if (raiz->dato > numero) {
        printf("%d ", raiz->dato);
    }
    
    imprimirMayoresQue(raiz->izq, numero);
    imprimirMayoresQue(raiz->der, numero);
}

// Imprimir nodos ligados al mayor
void imprimirNodosLigadosAlMayor(Nodo *raiz) {
    if (raiz == NULL) return;
    
    // El mayor está en el nodo más a la derecha
    Nodo *temp = raiz;
    while (temp->der != NULL) {
        temp = temp->der;
    }
    
    int mayor = temp->dato;
    
    // Ahora imprimir todos los nodos ligados al mayor
    imprimirMayoresQue(raiz, mayor - 1);
    printf("\n");
}

// ============================================================================
//                     CONTAR NODOS
// ============================================================================

// Contar total de nodos
int contarNodos(Nodo *raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
}

// Contar nodos hoja (sin hijos)
int contarHojas(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->izq == NULL && raiz->der == NULL) {
        return 1;
    }
    
    return contarHojas(raiz->izq) + contarHojas(raiz->der);
}

// Contar nodos internos (con al menos un hijo)
int contarNodosInternos(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    int internos = 0;
    if (raiz->izq != NULL || raiz->der != NULL) {
        internos = 1;
    }
    
    return internos + contarNodosInternos(raiz->izq) + contarNodosInternos(raiz->der);
}

// Contar nodos con dato par
int contarNodosPares(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    int pares = 0;
    if (raiz->dato % 2 == 0) {
        pares = 1;
    }
    
    return pares + contarNodosPares(raiz->izq) + contarNodosPares(raiz->der);
}

// Contar nodos con exactamente un hijo
int contarNodosUnHijo(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    int unHijo = 0;
    
    // Tiene hijo izquierdo pero no derecho, o viceversa
    if ((raiz->izq != NULL && raiz->der == NULL) || 
        (raiz->izq == NULL && raiz->der != NULL)) {
        unHijo = 1;
    }
    
    return unHijo + contarNodosUnHijo(raiz->izq) + contarNodosUnHijo(raiz->der);
}

// Contar nodos ligados al mayor (mayores o iguales al máximo)
int contarNodosLigadosAlMayor(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    // Encontrar el mayor
    Nodo *temp = raiz;
    while (temp->der != NULL) {
        temp = temp->der;
    }
    
    int mayor = temp->dato;
    
    // Contar nodos >= mayor
    return contarMayoresOIguales(raiz, mayor);
}

// Función auxiliar: contar nodos mayores o iguales a un valor
int contarMayoresOIguales(Nodo *raiz, int valor) {
    if (raiz == NULL) return 0;
    
    int contador = 0;
    if (raiz->dato >= valor) {
        contador = 1;
    }
    
    return contador + contarMayoresOIguales(raiz->izq, valor) + 
           contarMayoresOIguales(raiz->der, valor);
}

// ============================================================================
//                     SUMAR NODOS
// ============================================================================

// Sumar todos los nodos
int sumarNodos(Nodo *raiz) {
    if (raiz == NULL) return 0;
    return raiz->dato + sumarNodos(raiz->izq) + sumarNodos(raiz->der);
}

// Sumar nodos hoja
int sumarHojas(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->izq == NULL && raiz->der == NULL) {
        return raiz->dato;
    }
    
    return sumarHojas(raiz->izq) + sumarHojas(raiz->der);
}

// Sumar nodos internos
int sumarNodosInternos(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    int suma = 0;
    if (raiz->izq != NULL || raiz->der != NULL) {
        suma = raiz->dato;
    }
    
    return suma + sumarNodosInternos(raiz->izq) + sumarNodosInternos(raiz->der);
}

// Sumar nodos con dato par
int sumarNodosPares(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    int suma = 0;
    if (raiz->dato % 2 == 0) {
        suma = raiz->dato;
    }
    
    return suma + sumarNodosPares(raiz->izq) + sumarNodosPares(raiz->der);
}

// Sumar nodos ligados al mayor
int sumarNodosLigadosAlMayor(Nodo *raiz) {
    if (raiz == NULL) return 0;
    
    // Encontrar el mayor
    Nodo *temp = raiz;
    while (temp->der != NULL) {
        temp = temp->der;
    }
    
    int mayor = temp->dato;
    
    // Sumar nodos >= mayor
    return sumarMayoresOIguales(raiz, mayor);
}

// Función auxiliar: sumar nodos mayores o iguales a un valor
int sumarMayoresOIguales(Nodo *raiz, int valor) {
    if (raiz == NULL) return 0;
    
    int suma = 0;
    if (raiz->dato >= valor) {
        suma = raiz->dato;
    }
    
    return suma + sumarMayoresOIguales(raiz->izq, valor) + 
           sumarMayoresOIguales(raiz->der, valor);
}

// Sumar nodos mayores a un número
int sumarMayoresQue(Nodo *raiz, int numero) {
    if (raiz == NULL) return 0;
    
    int suma = 0;
    if (raiz->dato > numero) {
        suma = raiz->dato;
    }
    
    return suma + sumarMayoresQue(raiz->izq, numero) + 
           sumarMayoresQue(raiz->der, numero);
}

// ============================================================================
//                     BUSCAR Y OBTENER EXTREMOS
// ============================================================================

// Buscar un elemento en el árbol
int buscar(Nodo *raiz, int valor) {
    if (raiz == NULL) return 0;
    
    if (raiz->dato == valor) return 1;
    if (valor < raiz->dato) return buscar(raiz->izq, valor);
    return buscar(raiz->der, valor);
}

// Obtener el elemento mayor
int obtenerMayor(Nodo *raiz) {
    if (raiz == NULL) return -2147483648; // INT_MIN
    
    while (raiz->der != NULL) {
        raiz = raiz->der;
    }
    
    return raiz->dato;
}

// Obtener el elemento menor
int obtenerMenor(Nodo *raiz) {
    if (raiz == NULL) return 2147483647; // INT_MAX
    
    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }
    
    return raiz->dato;
}

// ============================================================================
//                     ELIMINACION
// ============================================================================

// Encontrar el nodo con el mayor valor en un subárbol
Nodo* encontrarMayor(Nodo *raiz) {
    if (raiz == NULL) return NULL;
    while (raiz->der != NULL) {
        raiz = raiz->der;
    }
    return raiz;
}

// Encontrar el nodo con el menor valor en un subárbol
Nodo* encontrarMenor(Nodo *raiz) {
    if (raiz == NULL) return NULL;
    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }
    return raiz;
}

// Eliminar un nodo específico
Nodo* eliminarNodo(Nodo *raiz, int valor) {
    if (raiz == NULL) return NULL;
    
    if (valor < raiz->dato) {
        raiz->izq = eliminarNodo(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        raiz->der = eliminarNodo(raiz->der, valor);
    } else {
        // Encontré el nodo a eliminar
        
        // Caso 1: Sin hijos (hoja)
        if (raiz->izq == NULL && raiz->der == NULL) {
            free(raiz);
            return NULL;
        }
        
        // Caso 2: Un solo hijo
        if (raiz->izq == NULL) {
            Nodo *temp = raiz->der;
            free(raiz);
            return temp;
        }
        if (raiz->der == NULL) {
            Nodo *temp = raiz->izq;
            free(raiz);
            return temp;
        }
        
        // Caso 3: Dos hijos
        // Encontrar el mayor del subárbol izquierdo (predecesor inorden)
        Nodo *temp = encontrarMayor(raiz->izq);
        raiz->dato = temp->dato;
        raiz->izq = eliminarNodo(raiz->izq, temp->dato);
    }
    
    return raiz;
}

// Eliminar el nodo menor
Nodo* eliminarMenor(Nodo *raiz) {
    if (raiz == NULL) {
        printf("Árbol vacío\n");
        return NULL;
    }
    
    int menor = obtenerMenor(raiz);
    return eliminarNodo(raiz, menor);
}

// Eliminar el nodo mayor
Nodo* eliminarMayor(Nodo *raiz) {
    if (raiz == NULL) {
        printf("Árbol vacío\n");
        return NULL;
    }
    
    int mayor = obtenerMayor(raiz);
    return eliminarNodo(raiz, mayor);
}

// Eliminar todas las hojas
Nodo* eliminarHojas(Nodo *raiz) {
    if (raiz == NULL) return NULL;
    
    if (raiz->izq == NULL && raiz->der == NULL) {
        free(raiz);
        return NULL;
    }
    
    raiz->izq = eliminarHojas(raiz->izq);
    raiz->der = eliminarHojas(raiz->der);
    
    return raiz;
}

// Eliminar todos los nodos con exactamente un hijo
Nodo* eliminarNodosUnHijo(Nodo *raiz) {
    if (raiz == NULL) return NULL;
    
    // Primero procesamos los subárboles
    raiz->izq = eliminarNodosUnHijo(raiz->izq);
    raiz->der = eliminarNodosUnHijo(raiz->der);
    
    // Verificar si el nodo actual tiene un solo hijo
    if ((raiz->izq != NULL && raiz->der == NULL) || 
        (raiz->izq == NULL && raiz->der != NULL)) {
        
        Nodo *hijo = (raiz->izq != NULL) ? raiz->izq : raiz->der;
        free(raiz);
        return hijo;
    }
    
    return raiz;
}

// Eliminar todos los nodos con dos hijos
Nodo* eliminarNodosDosHijos(Nodo *raiz) {
    if (raiz == NULL) return NULL;
    
    raiz->izq = eliminarNodosDosHijos(raiz->izq);
    raiz->der = eliminarNodosDosHijos(raiz->der);
    
    if (raiz->izq != NULL && raiz->der != NULL) {
        // Encontrar el mayor del subárbol izquierdo
        Nodo *temp = encontrarMayor(raiz->izq);
        raiz->dato = temp->dato;
        raiz->izq = eliminarNodo(raiz->izq, temp->dato);
    }
    
    return raiz;
}

void arbolEspejo(Nodo *raiz) {
    if (raiz == NULL)
        return;

    Nodo *temp = raiz->izq;
    raiz->izq = raiz->der;
    raiz->der = temp;

    arbolEspejo(raiz->izq);
    arbolEspejo(raiz->der);
}

// ============================================================================
//                     MENU PRINCIPAL
// ============================================================================

void mostrarMenu() {
    printf("\n========== ARBOL BINARIO DE BUSQUEDA ==========\n");
    printf("1.  Insertar nodo\n");
    printf("2.  Imprimir árbol (Inorden)\n");
    printf("3.  Recorrido Inorden\n");
    printf("4.  Recorrido Preorden\n");
    printf("5.  Recorrido Postorden\n");
    printf("6.  Imprimir descendente (Decreciente)\n");
    printf("7.  Contar nodos totales\n");
    printf("8.  Contar hojas\n");
    printf("9.  Contar nodos internos\n");
    printf("10. Contar nodos pares\n");
    printf("11. Contar nodos con un hijo\n");
    printf("12. Contar nodos ligados al mayor\n");
    printf("13. Sumar todos los nodos\n");
    printf("14. Sumar hojas\n");
    printf("15. Sumar nodos internos\n");
    printf("16. Sumar nodos pares\n");
    printf("17. Sumar nodos ligados al mayor\n");
    printf("18. Buscar elemento\n");
    printf("19. Obtener elemento mayor\n");
    printf("20. Obtener elemento menor\n");
    printf("21. Imprimir nodos mayores a un número\n");
    printf("22. Sumar nodos mayores a un número\n");
    printf("23. Imprimir nodos ligados al mayor\n");
    printf("24. Eliminar nodo específico\n");
    printf("25. Eliminar nodo menor\n");
    printf("26. Eliminar nodo mayor\n");
    printf("27. Eliminar todas las hojas\n");
    printf("28. Eliminar nodos con un hijo\n");
    printf("29. Eliminar nodos con dos hijos\n");
    printf("30. Convertir a árbol espejo\n");
    printf("31. Salir\n");
    printf("=============================================\n");
    printf("Selecciona una opción: ");
}

int main() {
    Nodo *arbol = NULL;
    int opcion, valor, numero;
    
    while (1) {
        mostrarMenu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("Ingresa el valor a insertar: ");
                scanf("%d", &valor);
                arbol = insertar(arbol, valor);
                printf("Nodo insertado\n");
                break;
                
            case 2:
                imprimirArbol(arbol);
                break;
                
            case 3:
                printf("Inorden: ");
                inorden(arbol);
                printf("\n");
                break;
                
            case 4:
                printf("Preorden: ");
                preorden(arbol);
                printf("\n");
                break;
                
            case 5:
                printf("Postorden: ");
                postorden(arbol);
                printf("\n");
                break;
                
            case 6:
                printf("Descendente: ");
                descendente(arbol);
                printf("\n");
                break;
                
            case 7:
                printf("Total de nodos: %d\n", contarNodos(arbol));
                break;
                
            case 8:
                printf("Total de hojas: %d\n", contarHojas(arbol));
                break;
                
            case 9:
                printf("Total de nodos internos: %d\n", contarNodosInternos(arbol));
                break;
                
            case 10:
                printf("Total de nodos pares: %d\n", contarNodosPares(arbol));
                break;
                
            case 11:
                printf("Total de nodos con un hijo: %d\n", contarNodosUnHijo(arbol));
                break;
                
            case 12:
                printf("Total de nodos ligados al mayor: %d\n", contarNodosLigadosAlMayor(arbol));
                break;
                
            case 13:
                printf("Suma de todos los nodos: %d\n", sumarNodos(arbol));
                break;
                
            case 14:
                printf("Suma de hojas: %d\n", sumarHojas(arbol));
                break;
                
            case 15:
                printf("Suma de nodos internos: %d\n", sumarNodosInternos(arbol));
                break;
                
            case 16:
                printf("Suma de nodos pares: %d\n", sumarNodosPares(arbol));
                break;
                
            case 17:
                printf("Suma de nodos ligados al mayor: %d\n", sumarNodosLigadosAlMayor(arbol));
                break;
                
            case 18:
                printf("Ingresa el valor a buscar: ");
                scanf("%d", &valor);
                if (buscar(arbol, valor)) {
                    printf("Elemento ENCONTRADO\n");
                } else {
                    printf("Elemento NO ENCONTRADO\n");
                }
                break;
                
            case 19:
                if (contarNodos(arbol) == 0) {
                    printf("Árbol vacío\n");
                } else {
                    printf("Elemento mayor: %d\n", obtenerMayor(arbol));
                }
                break;
                
            case 20:
                if (contarNodos(arbol) == 0) {
                    printf("Árbol vacío\n");
                } else {
                    printf("Elemento menor: %d\n", obtenerMenor(arbol));
                }
                break;
                
            case 21:
                printf("Ingresa el número: ");
                scanf("%d", &numero);
                printf("Nodos mayores a %d: ", numero);
                imprimirMayoresQue(arbol, numero);
                printf("\n");
                break;
                
            case 22:
                printf("Ingresa el número: ");
                scanf("%d", &numero);
                printf("Suma de nodos mayores a %d: %d\n", numero, sumarMayoresQue(arbol, numero));
                break;
                
            case 23:
                printf("Nodos ligados al mayor: ");
                imprimirNodosLigadosAlMayor(arbol);
                break;
                
            case 24:
                printf("Ingresa el nodo a eliminar: ");
                scanf("%d", &valor);
                arbol = eliminarNodo(arbol, valor);
                printf("Nodo eliminado (si existía)\n");
                break;
                
            case 25:
                arbol = eliminarMenor(arbol);
                printf("Nodo menor eliminado (si existía)\n");
                break;
                
            case 26:
                arbol = eliminarMayor(arbol);
                printf("Nodo mayor eliminado (si existía)\n");
                break;
                
            case 27:
                arbol = eliminarHojas(arbol);
                printf("Todas las hojas han sido eliminadas\n");
                break;
                
            case 28:
                arbol = eliminarNodosUnHijo(arbol);
                printf("Nodos con un hijo eliminados\n");
                break;
                
            case 29:
                arbol = eliminarNodosDosHijos(arbol);
                printf("Nodos con dos hijos eliminados\n");
                break;
            
            case 30:
                arbolEspejo(arbol);
                printf("Árbol convertido a espejo correctamente\n");
                break;
            case 31:
                printf("Liberando memoria...\n");
                liberarArbol(arbol);
                printf("¡Hasta luego!\n");
                return 0;
                
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
