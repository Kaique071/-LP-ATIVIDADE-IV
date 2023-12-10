#include <stdio.h>

struct Aluno {
    char nome[50];
    char dataNascimento[11]; // DD/MM/AAAA
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}

void verificarStatus(struct Aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("Situação de %s: APROVADO!\n", aluno.nome);
    } else {
        printf("Situação de %s: REPROVADO!\n", aluno.nome);
    }
}

int main() {
    struct Aluno turma[5];

    for (int i = 0; i < 5; i++) {
        printf("Dados do Aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", turma[i].nome);
        printf("Data de Nascimento (DD/MM/AAAA): ");
        scanf("%s", turma[i].dataNascimento);
        printf("Nota da Prova 1: ");
        scanf("%f", &turma[i].nota1);
        printf("Nota da Prova 2: ");
        scanf("%f", &turma[i].nota2);

        turma[i].media = calcularMedia(turma[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("\nMédia de %s: %.2f\n", turma[i].nome, turma[i].media);
        verificarStatus(turma[i]);
    }

    return 0;
}
