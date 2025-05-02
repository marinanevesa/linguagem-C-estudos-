#include <stdio.h>

int main() {
  int pode_empilhar(int m1, int m2) {
    return (m1 <= m2);
}

int main() {
    int moedas[16];
    printf("Digite as 16 moedas: ");
    for (int i = 0; i < 16; i++) {
        scanf("%d", &moedas[i]);
    }

    int pilhas[4][8]; 
    int topo[4] = {0};
    for (int i = 0; i < 16; i++) {
        int empilhou = 0;
        for (int j = 0; j < 4; j++) {
            if (topo[j] == 0 || pode_empilhar(moedas[i], pilhas[j][topo[j]-1])) {
                pilhas[j][topo[j]] = moedas[i];
                topo[j]++;
                empilhou = 1;
                break;
            }
        }
        if (!empilhou) {
            break;
        }
    }

    printf("Moedas em cada pilha:\n");
    for (int j = 0; j < 4; j++) {
        printf("Pilha %d: ", j+1);
        for (int i = 0; i < topo[j]; i++) {
            printf("%d ", pilhas[j][i]);
        }
        printf("\n");
    }

    return 0;
}