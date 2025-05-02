#include <stdio.h>
#include <stdlib.h>

// calcula a pontuação de uma posição
int pontuacao(int quantidadeDeLama, int concentracaoDePessoas, int intensidadeDoSom) {
    return (100 - quantidadeDeLama) * (100 - concentracaoDePessoas) * intensidadeDoSom;
}

// encontra a melhor posição do show
void melhorPosicao(int **quantidadeDeLama, int **concentracaoDePessoas, int **intensidadeDoSom, int n) {
    int i, j, melhorPontuacao = 0, melhorI = 0, melhorJ = 0, pontuacaoAtual;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            pontuacaoAtual = pontuacao(quantidadeDeLama[i][j], concentracaoDePessoas[i][j], intensidadeDoSom[i][j]);
            if (pontuacaoAtual > melhorPontuacao) {
                melhorPontuacao = pontuacaoAtual;
                melhorI = i + 1; // ajusta para começar em 1
                melhorJ = j + 1; // ajusta para começar em 1
            }
        }
    }

    printf("a melhor posicao fica em (%d, %d) com pontuacao %d.\n", melhorI, melhorJ, melhorPontuacao);
}

int main() {
    int n, m, i, j, k;

    scanf("%d %d", &n, &m);//o usuário digita o tamanho da matriz e o número de shows

    // aloca matriz quantidadeDeLama
    int **quantidadeDeLama = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        quantidadeDeLama[i] = (int *)malloc(n * sizeof(int));

        for (j = 0; j < n; j++) {  // o usuário digita os valores da matriz quantidadeDeLama
            scanf("%d", &quantidadeDeLama[i][j]);
        }
    }

    // aloca matrizes concentracaoDePessoas e intensidadeDoSom
    int ***concentracaoDePessoas = (int ***)malloc(m * sizeof(int **));
    int ***intensidadeDoSom = (int ***)malloc(m * sizeof(int **));
    for (k = 0; k < m; k++) {
        concentracaoDePessoas[k] = (int **)malloc(n * sizeof(int *));
        intensidadeDoSom[k] = (int **)malloc(n * sizeof(int *));
        for (i = 0; i < n; i++) {
            concentracaoDePessoas[k][i] = (int *)malloc(n * sizeof(int));
        }
        for (i = 0; i < n; i++) {
            intensidadeDoSom[k][i] = (int *)malloc(n * sizeof(int));
        }
    }


    for (k = 0; k < m; k++) {  // o computador lê todas as matrizes de concentração de pessoas
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &concentracaoDePessoas[k][i][j]);
            }
        }
    }


    for (k = 0; k < m; k++) {  // o computador lê todas as matrizes de intensidade do som
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &intensidadeDoSom[k][i][j]);
            }
        }
    }

    for (k = 0; k < m; k++) {  // encontra a melhor posição para cada show
        printf("No show %d, ", k + 1); // ajusta para começar em 1
        melhorPosicao(quantidadeDeLama, concentracaoDePessoas[k], intensidadeDoSom[k], n);
    }

    return 0;
}
