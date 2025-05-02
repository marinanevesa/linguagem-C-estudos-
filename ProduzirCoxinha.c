#include <stdio.h>

int main() {
    int n_ingredientes, i, consegueProduzir, coxinhas_possiveis;

  
    // Iniciando o codigo com quantos ingredientes tem na receita.
    do {
        scanf("%d", &n_ingredientes);
    } while (n_ingredientes < 1 || n_ingredientes > 1000);

    // declarando as variaveis: ingredienteDaReceita, ingredienteDoSinmber. Para que os "for" saibam quantas vezes deverão rodar.
    int ingredienteDaReceita[n_ingredientes], ingredienteDoSinmber[n_ingredientes];

    // quantidade de cada ingrediente da receita.
    for (i = 0; i < n_ingredientes; i++) {
        scanf("%d", &ingredienteDaReceita[i]);
    }

    // Quantidade de ingredientes que o usuario possui.
    for (i = 0; i < n_ingredientes; i++) {
        scanf("%d", &ingredienteDoSinmber[i]);
    }

    // Calculo da quantidade de coxinhas podem ser feitas.
    consegueProduzir = ingredienteDoSinmber[0] / ingredienteDaReceita[0];
    for (i = 1; i < n_ingredientes; i++) {
        coxinhas_possiveis = ingredienteDoSinmber[i] / ingredienteDaReceita[i];
        if (coxinhas_possiveis < consegueProduzir) {
            consegueProduzir = coxinhas_possiveis;
        }
    }

    // Print da quantidade maxima de coxinhas que podem ser produzidas.
    printf("%d ", consegueProduzir);

    return 0;
}
