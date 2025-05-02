#include <stdio.h>

typedef struct {
    int reprovacoes; // variável que guarda o número de reprovações do aluno
    double media;    // variável que guarda a média do aluno
} Aluno;

// função para qualificar alunos até o limite de bolsas:
void qualificarAteLimite(Aluno alunos[], int n, int b, int *qualificados, int *ultimoQualificado) {
    int alunosQualificados = 0;

    for (int i = 0; i < n; i++) {
        if (alunos[i].media > alunos[i].reprovacoes || (alunos[i].media > 8 && alunos[i].reprovacoes < 10)) {
            alunosQualificados++; // incrementa o número de alunos qualificados
            *ultimoQualificado = i; // atualiza a posição do último aluno qualificado

            if (alunosQualificados >= b) { // se o número de alunos qualificados atingir o máximo de bolsas
                break; // encerra o loop
            }
        }
    }

    *qualificados = alunosQualificados; // atualiza o número total de alunos qualificados
}

// em caso de empate, qualifica os alunos após o último qualificado:
void qualificarAposUltimo(Aluno alunos[], int n, int *qualificados, int *ultimoQualificado) {
    int ultimaReprovacao = alunos[*ultimoQualificado].reprovacoes;
    double ultimaMedia = alunos[*ultimoQualificado].media;

    for (int i = *ultimoQualificado + 1; i < n; i++) {
        if (alunos[i].media == ultimaMedia && alunos[i].reprovacoes == ultimaReprovacao) {
            (*qualificados)++;
            *ultimoQualificado = i; // Atualiza o último qualificado para a posição do novo aluno
        } else {
            break; // Se não houver mais empates, sai do loop
        }
    }
}



int main() {
    int b, n, qualificados = 0, ultimoQualificado = -1; 

    scanf("%d %d", &b, &n); // lê o número de bolsas disponíveis e o número total de alunos

    Aluno alunos[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &alunos[i].reprovacoes, &alunos[i].media); // lê o número de reprovações e a média de cada aluno
    }

    // função que qualifica os alunos até o limite de bolsas:
    qualificarAteLimite(alunos, n, b, &qualificados, &ultimoQualificado);

    if (qualificados > 0) { // se o número de qualificados for maior que 0:
        qualificarAposUltimo(alunos, n, &qualificados, &ultimoQualificado);
        // imprime o resultado:
        printf("%d alunos foram qualificados. O ultimo qualificado foi o aluno numero %d\n", qualificados, ultimoQualificado + 1);
    } else { // caso contrário, imprime que nenhum aluno foi qualificado
        printf("0 alunos foram qualificados.\n");
    }

    return 0;
}
