#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
};

float calcularMediaSalarios(struct Funcionario equipe[], int tamanho, const char* cargoAlvo) {
    int count = 0;
    float totalSalarios = 0.0;

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(equipe[i].cargo, cargoAlvo) == 0) {
            totalSalarios += equipe[i].salario;
            count++;
        }
    }

    if (count > 0) {
        return totalSalarios / count;
    } else {
        return 0.0;
    }
}

int main() {
    struct Funcionario time[] = {
        {"Ana", "Desenvolvedor", 5500.0},
        {"Bernardo", "Analista", 6000.0},
        {"Clara", "Desenvolvedor", 5200.0},
        {"Daniel", "Gerente", 7500.0},
        {"Elena", "Desenvolvedor", 4800.0},
    };

    const char cargoDesejado[] = "Desenvolvedor";
    float mediaSalarios = calcularMediaSalarios(time, sizeof(time) / sizeof(time[0]), cargoDesejado);

    if (mediaSalarios > 0) {
        printf("A média salarial dos %ss é: R$ %.2f\n", cargoDesejado, mediaSalarios);
    } else {
        printf("Não há %ss na equipe.\n", cargoDesejado);
    }

    return 0;
}
