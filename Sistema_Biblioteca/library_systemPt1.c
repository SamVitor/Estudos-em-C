//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes

#define MAX_LIVROS 50
#define TAM_STRING 100

//Definição da estrutura (STRUCT)
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

//Função para limpar o buffer de entrada

void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
   
}

//Função principal do menu(main)

int main(){
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    //Laço do menu principal

    do{
        //exibir o menu de opções
        printf("===========================\n");
        printf("    BIBLIOTECA - PARTE 1 \n");
        printf("===========================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");
        printf("===========================\n");
        printf("Escolha uma opção: ");

        //Lê a opção do usuario
        scanf("%d", &opcao);
        limparBufferEntrada();//Limpar o \n deixado pelo scanf//

        // --- Processamento das opções ---//

        switch (opcao)
        {
        case 1: //Cadastrar Livro
            printf("---Cadastro de Novo Livro---\n");
            if (totalLivros < MAX_LIVROS){

                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("digite o nome do autor: \n");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite a editora: \n");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                
                //o strcsp conta o tamanho da variavel
                //e troca o enter(\n) pelo caractere nulo(\0)
                //exibindo o fim correto da string adicionada pelo teclado
                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                printf("Digite a edição: \n");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBufferEntrada();

                totalLivros++;

                printf("Livro cadastrado com sucesso!\n");
            } else{
                printf("Biblioteca esta cheia! não e possivel cadastros novos");
            }
            
            printf("\nPressione Enter para continuar...");
            getchar();//Pausa para o usuario ler a mensagem antes de voltar a menu
            break;

        case 2 : //LISTAGEM DE LIVROS
            printf("--- Lista de Livros Cadastrados\n");

            if(totalLivros == 0){
                printf("Nenhum Livro cadastrado ainda.\n");
            } else {
                for (int i = 0; i < totalLivros; i++) {
                    printf("---------------------------------\n");
                    printf("LIVRO %d\n", i + 1);
                    printf("Nome: %s\n",biblioteca[i].nome);
                    printf("Autor: %s\n",biblioteca[i].autor);
                    printf("Editora: %s\n",biblioteca[i].editora);
                    printf("Edição: %d\n",biblioteca[i].edicao);
                }
                printf("---------------------------------\n");
            }
            printf("\nPressione Enter para continuar...");
            getchar();//Pausa para o usuario ler a mensagem antes de voltar a menu
            break;
            
        case 0: //SAIR
            printf("\nSaindo do Sistema...\n");
            break;    


        default: //OPÇÃO INVÁLIDA
            printf("\nOpção inválida! tente novamente. \n");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        }

    }while (opcao != 0);
    return 0; //fim do programa
}
