#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
    char email[50];
};

char* encontrarTelefone(struct Contato listaContatos[], int tamanhoLista, const char* nomeAlvo) {
    for (int i = 0; i < tamanhoLista; i++) {
        if (strcmp(listaContatos[i].nome, nomeAlvo) == 0) {
            return listaContatos[i].telefone;
        }
    }
    return NULL;
}

int main() {
    struct Contato listaContatos[3];

    for (int i = 0; i < 3; i++) {
        printf("Cadastro do Contato %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", listaContatos[i].nome);
        printf("Telefone: ");
        scanf("%s", listaContatos[i].telefone);
        printf("Email: ");
        scanf("%s", listaContatos[i].email);
    }

    char nomeAlvo[50];
    printf("\nDigite o nome do contato para buscar o número de telefone: ");
    scanf("%s", nomeAlvo);

    char* telefoneEncontrado = encontrarTelefone(listaContatos, 3, nomeAlvo);

    if (telefoneEncontrado != NULL) {
        printf("O número de telefone de %s é: %s\n", nomeAlvo, telefoneEncontrado);
    } else {
        printf("Contato não encontrado.\n");
    }

    return 0;
}
