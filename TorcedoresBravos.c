#include <stdio.h>

int main() {
    int num_torcedores, i, j, torcedores_bravos = 0;

    // O programa le quantas pessoas estão na fila.
    scanf("%d", &num_torcedores);

    // O programa declara um vetor com o tamanho da quantidade de torcedores.
    int altura_torcedores[num_torcedores];

    // Leitura das alturas dos torcedores
    for (i = 0; i < num_torcedores; i++) {
        scanf("%d", &altura_torcedores[i]);
    }

    // O programa define quantos torecedores estão bravos, verificando cada um e para quando acha um maior que ele e adiciona 1 na conta, quando não ha nenhum ele adiciona 0 a conta.
    for (i = 0; i < num_torcedores; i++) {
        int bloqueado = 0;
        for (j = 0; j < i; j++) {
            if (altura_torcedores[j] > altura_torcedores[i]) {
                bloqueado = 1;
                break;
            }
        }
        if (bloqueado) {
            torcedores_bravos++;
        }
    }

    // Impressão do resultado
    printf("%d\n", torcedores_bravos);

    return 0;
}
