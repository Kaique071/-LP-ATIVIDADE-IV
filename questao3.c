#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

void efetuarCompra(struct Produto *item) {
    int quantidadeCompra;

    printf("Quantidade desejada para compra: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= item->quantidadeEstoque) {
        printf("Compra realizada com sucesso!\n");
        item->quantidadeEstoque -= quantidadeCompra;
    } else {
        printf("Quantidade inválida ou estoque insuficiente.\n");
    }
}

void exibirEstoque(struct Produto item) {
    printf("Nome do produto: %s\n", item.nome);
    printf("Preço unitário: R$ %.2f\n", item.preco);
    printf("Quantidade em estoque: %d\n", item.quantidadeEstoque);
}

int main() {
    struct Produto meuItem = {"Sapato", 79.99, 30};

    int escolha;

    do {
        printf("\nOpções:\n");
        printf("1 - Efetuar uma compra\n");
        printf("2 - Consultar o estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                efetuarCompra(&meuItem);
                break;
            case 2:
                exibirEstoque(meuItem);
                break;
            case 3:
                printf("Encerrando o programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}
