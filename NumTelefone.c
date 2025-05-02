#include <stdio.h>
#include <stdbool.h>

int main() {

  const int vetor = 11;    // Vetor definido do tamanho de numeros de celular. 
  int numero[vetor], i, ddd, temDigitoNaoZero = 0;

  for (i = 0; i < vetor; i++) {
    scanf("%1d", &numero[i]); }  // O programa le os numeros de celular.

  ddd = numero[0] * 10 + numero[1]; 

  if (ddd < 11 || ddd > 19) {  // O programa verifica se os DDDs estão entre 11 a 19.
    printf("O numero nao existe\n"); }
    
  else if (numero[2] != 9) {  // O programa verifica se o terceiro numero digitado é 9.
    printf("O numero nao existe\n"); }
    
  else if (numero[3] < 5 || numero[3] > 9) { //O programa verifica se o quarto numero digitado esta entre 5 e 9.
    printf("O numero nao existe\n");}
    
  else {  // O programa verifica se tem pelo menos um digito diferente de 0.
    for (i = 4; i < vetor; i++) {
      if (numero[i] != 0) {
        temDigitoNaoZero = 1;
        break;}}

    if (temDigitoNaoZero) { //if e else para iprimir se existe ou não o numero de telefone. 
      printf("O numero existe\n"); }
      
    else {
      printf("O numero nao existe\n");} }

  return 0;
}

