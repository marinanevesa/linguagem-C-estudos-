#include <stdio.h>

int main() {
  char nome[50];
  int num1, num2, media1, media2, media3, rec, sub, passou, presenca, mediafinal;
  
  printf ("O programa verifica se a pessoa passou ou não no semenstre com a nota media de 5.0\n");
  
  printf ("Digite o nome do aluno: "); 
  scanf ("%s", nome);

  printf ("Digita quanto de presenca o aluno tem: ");
  scanf (" %d", &presenca);

  printf ("Digita a nota 1: ");
  scanf (" %d", &num1);

  printf ("Digita a nota 2: ");
  scanf (" %d", &num2);

  printf ("Digita a nota da substitutiva: ");
  scanf (" %d", &sub);

  media1= (num1+num2)/2;
  media2= (num1+sub)/2;
  media3= (sub+num2)/2;
    
  if (media1 > media2) {
    mediafinal = media1;
  } 
  else if (media2 > media1) {
    mediafinal = media2;
  } 
  else {
    mediafinal = media3;
  }

  printf ("Nome: %s\n", nome);
  printf ("Presenca: %d\n", presenca);
  printf ("Media final: %d\n", mediafinal );

if (mediafinal < 5 && presenca < 75) {
  printf ("O aluno foi reprovado");
}
else if (mediafinal < 5 && presenca >= 75) { 
printf ("O aluno foi reprovado mas tem direito de fazer a recuperação");
}
else {
printf ("O aluno foi aprovado");
}
  
  return 0;
}