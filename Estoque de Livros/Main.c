#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura (struct) para representar um livro
struct Livro {
    char titulo[50];
    int quantidade;
    float preco;
};

int main() {
    // Lista (array) criada para armazenar até 5 livros no estoque
    struct Livro estoque[5];
    int totalLivros = 0;
    int opcao;

    do {
        // Exibição do menu principal
        printf("\n=== SISTEMA DE ESTOQUE DE LIVROS ===\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Limpa o caractere 'enter' pendente no buffer após o scanf de número
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                if (totalLivros < 5) {
                    printf("\n-- Cadastro de Novo Livro --\n");
                    
                    printf("Digite o titulo do livro: ");
                    // fgets lê a string com espaços de forma segura
                    fgets(estoque[totalLivros].titulo, 50, stdin);
                    
                    // Remove a quebra de linha (\n) que o fgets costuma capturar no final
                    estoque[totalLivros].titulo[strcspn(estoque[totalLivros].titulo, "\n")] = 0;

                    printf("Digite a quantidade em estoque: ");
                    scanf("%d", &estoque[totalLivros].quantidade);

                    printf("Digite o preco unitario (R$): ");
                    scanf("%f", &estoque[totalLivros].preco);

                    // Incrementa o contador de livros cadastrados
                    totalLivros++;
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Erro: O estoque esta cheio (limite de 5 livros)!\n");
                }
                break;

            case 2:
                if (totalLivros == 0) {
                    printf("\nNenhum livro cadastrado no estoque ainda.\n");
                } else {
                    printf("\n--- LISTA DE LIVROS NO ESTOQUE ---\n");
                    for (int i = 0; i < totalLivros; i++) {
                        printf("Livro %d:\n", i + 1);
                        printf("  Titulo: %s\n", estoque[i].titulo);
                        printf("  Quantidade: %d\n", estoque[i].quantidade);
                        printf("  Preco: R$ %.2f\n", estoque[i].preco);
                        printf("----------------------------------\n");
                    }
                }
                break;

            case 3:
                printf("\nSaindo do sistema. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
