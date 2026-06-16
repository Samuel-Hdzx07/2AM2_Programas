#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char pila[MAX];
int tope = -1;

void push(char x) {
    pila[++tope] = x;
}

char pop() {
    if (tope == -1)
        return -1;
    return pila[tope--];
}

char peek() {
    if (tope == -1)
        return -1;
    return pila[tope];
}

int prioridad(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infijoAPostfijo(char infijo[]) {
    char postfijo[MAX];
    int i, j = 0;

    for(i = 0; infijo[i] != '\0'; i++) {

        if(isalnum(infijo[i])) {
            postfijo[j++] = infijo[i];
        }

        else if(infijo[i] == '(') {
            push(infijo[i]);
        }

        else if(infijo[i] == ')') {
            while(peek() != '(') {
                postfijo[j++] = pop();
            }
            pop();
        }

        else {
            while(tope != -1 &&
                  prioridad(peek()) >= prioridad(infijo[i])) {
                postfijo[j++] = pop();
            }
            push(infijo[i]);
        }
    }

    while(tope != -1) {
        postfijo[j++] = pop();
    }

    postfijo[j] = '\0';

    printf("\nExpresion Postfija: %s\n", postfijo);
}

int main() {
    char infijo[MAX];

    printf("Ingrese una expresion infija: ");
    scanf("%s", infijo);

    infijoAPostfijo(infijo);

    return 0;
}