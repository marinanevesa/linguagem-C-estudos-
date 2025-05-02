#include <stdio.h>

int main (void) {
  int n1, i, numfatorial=; 

  printf ("O programa mostra calcula o fatoria do numero digitado\n");
  printf("Digite o numero: ");

  scanf ("%d", &n1);

for (i=1; i<=n1; i++){
  numfatorial *= i;
}
  
printf("O fatorial de %d eh %d", n1, numfatorial);
  
return 0;
}