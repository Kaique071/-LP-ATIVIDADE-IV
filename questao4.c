#include <stdio.h>
#include <stdlib.h>

struct ContaBancaria {
    int numero;
    char titular[50];
    float saldo;
    char tipo[20];
};

void realizarDeposito(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de R$ %.2f realizado com sucesso.\n", valor);
}

void realizarSaque(struct ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Saldo insuficiente para o saque.\n");
    }
}

void mostrarSaldo(struct ContaBancaria conta) {
    printf("Saldo atual: R$ %.2f\n", conta.saldo);
}

int main() {
    struct ContaBancaria minhaConta = {123456, "Maria Oliveira", 1500.00, "poupança"};

    int opcao;
    float valor;

    do {
        printf("\nMenu:\n");
        printf("1 - Realizar depósito\n");
        printf("2 - Realizar saque\n");
        printf("3 - Consultar saldo\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para depósito: ");
                scanf("%f", &valor);
                realizarDeposito(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor para saque: ");
                scanf("%f", &valor);
                realizarSaque(&minhaConta, valor);
                break;
            case 3:
                mostrarSaldo(minhaConta);
                break;
            case 4:
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
