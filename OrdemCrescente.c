#include <stdio.h>

int main() {
    int a, b, c, x; 

    scanf("%d %d %d", &a, &b, &c);

    printf("Sequencia original: %d %d %d\n", a, b, c);  // Imprime a sequência original dada usuário.

    // Os If abaixo verificam quais as variaveis maiores e coloca elas na sequencia 

    if (a > b) {  // Se A for maior que B, troca os valores de A e B.
        x = a;
        a = b;
        b = x;
    }

    if (a > c) {  // Se A for maior que C, troca os valores de A e C.
        x = a;
        a = c;
        c = x;
    }

    if (b > c) {  // Se B for maior que C, troca os valores de B e C.
        x = b;
        b = c;
        c = x;
    }

    printf("Sequencia ordenada: %d %d %d\n", a, b, c);  // Imprime a sequência ordenada das variaveis

    return 0; 
}
