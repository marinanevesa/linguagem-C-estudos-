#include <stdio.h>

int main() {
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);

    char matriz[n][m];
    char novaMatriz[n][m];

    // Ler a matriz da televisão
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    // Corrigir o deslocamento
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int novoJ = (j - d + m) % m; // Calcula a nova posição da coluna considerando o deslocamento
            novaMatriz[i][novoJ] = matriz[i][j]; // Coloca o caractere na nova posição corrigida
        }
    }

    // Imprimir a matriz corrigida
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", novaMatriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
