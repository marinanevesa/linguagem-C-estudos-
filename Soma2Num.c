#include <stdio.h>

int main(void) {
  int n1, n2, n3;
  
  printf("O programa soma dois numeros\n");
  printf("Digite os dois numeros: ");
  
  scanf("%d %d" , &n1, &n2);
  
  n3 = n1 + n2; 
  
  printf("A soma entre %d e %d eh %d", n1, n2, n3);

  
  return 0;
}