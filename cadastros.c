#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PESSOAS 100
#define TAM_NOME 50

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    char sexo;
};

int main() {
    struct Pessoa pessoas[MAX_PESSOAS];
    int qtd = 0;
    int opcao;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Listar pessoas\n");
        printf("3. Buscar pessoa por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            while(getchar() != '\n');
            opcao = 0;
            continue;
        }

        if (opcao == 1) {
            if (qtd >= MAX_PESSOAS) {
                printf("Limite de pessoas atingido!\n");
                continue;
            }
            printf("Nome: ");
            while(getchar() != '\n');
            fgets(pessoas[qtd].nome, TAM_NOME, stdin);
            pessoas[qtd].nome[strcspn(pessoas[qtd].nome, "\n")] = 0;

            int idadeValida = 0;
            do {
                printf("Idade: ");
                if (scanf("%d", &pessoas[qtd].idade) != 1 || pessoas[qtd].idade < 0 || pessoas[qtd].idade > 120) {
                    printf("Idade invalida! Digite um valor entre 0 e 120.\n");
                    while(getchar() != '\n');
                } else {
                    idadeValida = 1;
                }
            } while (!idadeValida);

            char sexo;
            int sexoValido = 0;
            do {
                printf("Sexo (M/F): ");
                while(getchar() != '\n');
                sexo = getchar();
                sexo = toupper(sexo);
                if (sexo == 'M' || sexo == 'F') {
                    pessoas[qtd].sexo = sexo;
                    sexoValido = 1;
                } else {
                    printf("Sexo invalido! Digite M ou F.\n");
                }
            } while (!sexoValido);

            qtd++;
            printf("Pessoa cadastrada com sucesso!\n");

        } else if (opcao == 2) {
            system("clear");
            printf("\n=== LISTA DE PESSOAS ===\n");
            for (int i = 0; i < qtd; i++) {
                printf("%d. Nome: %s | Idade: %d | Sexo: %c\n", i+1, pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
            }
            if (qtd == 0) printf("Nenhuma pessoa cadastrada.\n");

        } else if (opcao == 3) {
            char busca[TAM_NOME];
            int encontrou = 0;
            printf("Digite o nome para buscar: ");
            while(getchar() != '\n');
            fgets(busca, TAM_NOME, stdin);
            busca[strcspn(busca, "\n")] = 0;
            for (int i = 0; i < qtd; i++) {
                if (strstr(pessoas[i].nome, busca) != NULL) {
                    system("clear");
                    printf("Encontrado: Nome: %s | Idade: %d | Sexo: %c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
                    encontrou = 1;
                }
            }
            if (!encontrou) printf("Nenhuma pessoa encontrada com esse nome.\n");

        } else if (opcao == 4) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
