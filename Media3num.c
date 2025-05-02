#include <stdio.h>

int main(void) {
  int num1, num2, num3, media;
  printf("O programa acha a media entre 3 numero: \n");

  printf("Digite o primeiro numero: ");
  scanf("%d", &num1);

  printf("Digite o segundo numero: ");
  scanf("%d", &num2);

  printf("Digite o terceiro numero: ");
  scanf("%d", &num3);

  media = (num1 + num2 + num3 )/3;

  printf("A media entre os 3 numeros e: %d", media);
  
  return 0;
}