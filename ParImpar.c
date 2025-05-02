#include <stdio.h>

int main(void) {
  int n1;
  printf(" O programa verifica se o numero é par ou impar\n");
  printf("Digite o numero: ");
  scanf("%d", &n1);
  if(n1 % 2 == 0) {
    printf("O numero eh par");
  }
  else {
    printf("O numero eh impar");
  }
  return 0;
}