#include <stdio.h>

int main() {
    float numero, maior, menor;
    int quantidade;

  quantidade = 0; //zeramos "quantidade" para o programa rodar corretamente.

    do {
        scanf("%f", &numero);
        if (numero >= 0) {  //verifica se o numero é positivo.
            quantidade++;  //contando quantos numeros validos foram digitados.
            if (quantidade == 1) { //Se a quantidade for apenas 1, o maior, menor e o numero são iguais.
                maior = menor = numero;
            } else {
                if (numero > maior) {  //se o numero for maior que o maior, o maior recebe o numero.
                    maior = numero;
                } else if (numero < menor) {  //Se o caso não for o maior, o numero é menor
                    menor = numero;
                }
            }
        }
    } while (numero >= 0); //enquanto o numero for maior ou igual a zero, o programa vai rodar desde o "Do" até o "While"

    // Printf dos resultados
    printf("%d\n", quantidade);
    if (quantidade > 0) {
        printf("%.2f\n", maior);
        printf("%.2f\n", menor);
      
    } else {  //caso não tenha nenhum numero positivo
        printf("Nenhum numero positivo foi digitado.\n");
    }

    return 0;
}
