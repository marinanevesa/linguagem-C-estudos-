
// Programa que le um numero k e mostra as
// k primeiras linhas do Triangulo de Pascal:
// 1         -> linha 0
// 1 1       -> linha 1
// 1 2 1     -> linha 2
// 1 3 3 1   -> linha 3
// 1 4 6 4 1 -> linha 4
// ...

#include <stdio.h>
#include <stdlib.h>

// -------------------------------------------
// Funcao principal.

int main() {
  int linhas,i,j,**Triang;

  // Le a quantidade de linhas
  do {
    printf("Digite o numero de linhas do Triangulo de Pascal que voce quer ver: ");
    scanf("%d", &linhas);
  } while(linhas < 1);

  // Aloca a "matriz triangular" que vai armazenar o Triangulo de Pascal
  Triang = (int **) malloc(linhas*sizeof(int *));

  if (Triang == NULL) {
    printf("Deu errado\n");
    return(-1);
  }
 int n;
  for (i = 0; i <  n; i++) {
    Triang[i] = (int *) malloc((i+1)*sizeof(int));

    if (Triang[i] == NULL) {
      printf("Deu errado\n");
      return(-1);
    } 
  }

  // Calcula o Triangulo de Pascal.
  // Coloca 1s na primeira coluna e na diagonal.
  for (i = 0; i < linhas; i++) {
    Triang[i][0] = 1;
    Triang[i][i] = 1;
  }

  // Coloca os elementos internos.
  for (i = 2; i < linhas; i++) {
    for (j = 1; j <= i-1; j++) { 
      Triang[i][j] = Triang[i-1][j] + Triang[i-1][j-1];
    }
  }

  // Mostra o Triangulo de Pascal
  for (i = 0; i < linhas; i++) {
    for (j = 0; j <= i; j++) { 
      printf("%4d ", Triang[i][j]);
    }
    printf("\n");
  }

  return(42);
}
