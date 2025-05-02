#include <stdio.h>
#include <math.h>

// Definição da estrutura para representar uma pessoa
struct Pessoa {
    double altura;
    double forca;
    double idade;
    char tipo;
};

double calculo(struct Pessoa p1, struct Pessoa p2) { //função que calcula a pontuação da dupla

    if (p1.tipo == 'F' && p2.tipo == 'B') {      // Se a primeria pessoa for flyer e a segunda for base
        return p1.altura * p2.idade * (p2.forca + p1.forca);}  // calcula a pontuação da dupla

    else if (p2.tipo == 'F' && p1.tipo == 'B') {  // Se  a primeira pessoa for base e a segunda for flyer.
        return p2.altura * p1.idade * (p1.forca + p2.forca);} 

    else {  //Se não for nenhum dos dois
        return 0;}
}

int main() {
    int n, i, j;
    scanf("%d", &n); // PO programa le a quantidade de pessoas no time

    struct Pessoa p[n];

    for (i = 0; i < n; i++) {
        scanf("%lf %lf %lf %c", &p[i].altura, &p[i].forca, &p[i].idade, &p[i].tipo);
    } //O programa le as informações dadas pelo usuario

    double mx = 0;
    double a = 0.001; // O programa considera duas pontuações como iguais

    for (i = 0; i < n; i++) {  //Calcula todas as pontuações possiveis
        for (j = i + 1; j < n; j++) {
            double pont = calculo(p[i], p[j]);
            if (pont > mx) {  //se a pontuação atual for maior que a maxima ela atualiza a maxima para a atual
                mx = pont; }
        }
    }

    printf("%.2lf\n", mx);  //imprime o resultado

    return 0;
}
