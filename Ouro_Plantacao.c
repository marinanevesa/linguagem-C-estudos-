
#include <stdio.h>
#include <stdlib.h>

//definição das structs:
typedef struct {
    int indice;
    float custo;
    float venda;
    float tempoCrescimento;
    float ouroPorDia;
} Planta;

//função que aloca um vetor de Plantas:
Planta* alocarPlantas(int n) {
    return (Planta*) malloc(n * sizeof(Planta));
}

//funcao que calcula o ouro por dia da planta:
float calcularOuroPorDia(float custo, float venda, int tempoCrescimento) {
    float vezesPlantada = 28 / tempoCrescimento;
    return (venda - custo) * (vezesPlantada / 28);
}

//funcao para definir o nome da planta: 
const char* obterNomeDaPlanta(int indice) {
    switch (indice) {
        case 1:
            return "rosa";
        case 2:
            return "margarida";
        case 3:
            return "girassol";
        case 4:
            return "lirio";
        case 5:
            return "dalia";
        case 6:
            return "hibisco";
        case 7:
            return "astromelia";
        case 8:
            return "azaleia";
        case 9:
            return "bonina";
        case 10:
            return "hortensia";
        case 11:
            return "mirtilo";
        case 12:
            return "abacaxi";
        case 13:
            return "acerola";
        case 14:
            return "uva";
        case 15:
            return "jabuticaba";
        case 16:
            return "tomate";
        case 17:
            return "oxicoco";
        case 18:
            return "carambola";
        case 19:
            return "cacau";
        case 20:
            return "figo";
        default:
            return "Desconhecida";
    }
}

int main() {
    int n;

    scanf("%d", &n); //o computador le os dados dado pelo usuario

    //alocação do vetor de plantas:
    Planta* plantas = alocarPlantas(n);

    // for para a leitura dos dados de cada planta e cálculo do ouro por dia:
    for (int i = 0; i < n; i++) {
        scanf("%d %f %f %f", &plantas[i].indice, &plantas[i].custo, &plantas[i].venda, &plantas[i].tempoCrescimento);
        plantas[i].ouroPorDia = calcularOuroPorDia(plantas[i].custo, plantas[i].venda, plantas[i].tempoCrescimento);
    }

    //printf dos resultados:
    for (int i = 0; i < n; i++) {
        const char* nomePlanta = obterNomeDaPlanta(plantas[i].indice);
        printf("%s: %.2f o/d\n", nomePlanta, plantas[i].ouroPorDia);
    }

    //liberação da memória
    free(plantas);

    return 0;
}
