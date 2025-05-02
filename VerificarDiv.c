#include <stdio.h>

int main() {
  int num1, num2;
  printf("Verificar se o numero é divisivel por outro\n");

  printf ("Digite o numero no que deseja verificar: ");
  scanf ("%d", &num1);

  printf ("Digite o numero que deseja dividir: ");
  scanf ("%d", &num2);

  if (num1 % num2 ==0) {
  printf ("O numero %d eh divisivel por %d", num1, num2);
  }
  else {
    printf("O numero %d nao eh divisivel por %d", num1, num2);
  }
  return 0;
}