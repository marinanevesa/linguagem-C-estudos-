#include <stdio.h>

int main() {
    float tortilla, tejuine, manzapane, pesos;

    scanf("%f %f %f %f", &tortilla, &tejuine, &manzapane, &pesos); //Le os valores e os pesos mexicanos de Dikson

    if (pesos >= tortilla + tejuine + manzapane) {  //Se o valor dos 3 produtos for menor ou igual aos pesos mexicanos imprime que ele pode comprar todos os produtos.
        printf("Dikson pode comprar tortilla, tejuine e mazapane\n");
    }
      
    else if (pesos >= tortilla + tejuine) {  //Se o if não foi possivel o codigo verifica se a tortilla mais o tejuine tem o valor menor ou iguas aos pesos de Dikson.
        printf("Dikson pode comprar tortilla e tejuine\n");
    }
      
    else if (pesos >= tortilla) {  //Se os dois if acima não foi possivel, verifica se o valor da tortilla é menor ou igual aos pesos de Dikson.
        printf("Dikson pode comprar tortilla\n");
    }
      
    else {  // Caso nenhum dos casos foi possivel, o programa imprime que ele não pode comprar nenhum produto.
        printf("Dikson nao pode comprar nada\n");
    }

    return 0;
}
