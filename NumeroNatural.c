#include <stdio.h>

int main() {
    int N, i, j, k;
  
    k = 1;
  
    scanf("%d", &N);

    if (N < 1) { //se o numero for menor de 1 o programa ja para de rodar e avisa que o numero eh invalido.
        printf("Este nao eh um numero natural valido\n");
    }
    else {  //imprimindo o triangulo 
      for (i = 0; i < N; i++) {
          for (j = 0; j <= i; j++) {
            printf("%3d ", k++);
          }
          printf("\n");
      }
    }
  
    return 0;
}
