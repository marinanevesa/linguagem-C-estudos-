#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, simetrico = 1, i, j, somalinha = 0, somacoluna = 0, linha = 0, coluna = 0, diferenca;

    scanf("%d", &N); // O programa le o N, e define o tamanho da matriz.

  int matriz[N][N];
  
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);} // Lendo cada valor dado pelo usuario.
    }

    for (i = 0; i < N; i++) { // Verifica se a matriz é simétrica em relação a diagonal.
        for (j = i + 1; j < N; j++) {
            if (matriz[i][j] != matriz[j][i]) { // O programa verifica se os elementos fora da diagonal são iguais.
                simetrico = 0; // Caso não forem iguais, a matriz não é simétrica.
                break;}
        }

        if (!simetrico) 
          break;}   // Se a matriz não for simétrica, interrompe a verificação.
    

    for (i = 0; i < N; i++) {
        linha = 0;
        coluna = 0;
      
        for (j = 0; j < N; j++) {
            linha += matriz[i][j]; // Somando os elementos da linha i.
            coluna += matriz[j][i];}  // Somando os elementos da coluna i.

        if (i == 0) { 
            somalinha = linha; // define somalinha como linha.
            somacoluna = coluna;} //define somacoluna como coluna.
          
        else {
            if (linha > somalinha) 
              somalinha = linha; //caso a linha for maior que somalinha, define somalinha como linha.
            if (coluna < somacoluna) 
              somacoluna = coluna; } //caso a coluna for menor que somacoluna, define somacoluna como coluna.
    }

    // Verifica se a matriz é simétrica e imprime o resultado
    if (simetrico) {
        diferenca = somalinha - somacoluna; // Calcula a diferença.
        printf("A matriz eh simetrica , com diferenca %d\n", diferenca);
    } else {
        printf("A matriz nao eh simetrica\n");
    }

    return 0;
}
