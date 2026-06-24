//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes globais

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 10 //capacidade de emprestimo
#define TAM_STRING 100

//Definição das estruturas (STRUCT)
//struct para gerenciar livros
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; //1 para sim, 0 para não
};

//struct para gerenciar emprestimos
struct Emprestimo
{
    int indiceLivro; //para saber qual livro da array 'biblioteca' foi emprestado
    char nomeUsuario[TAM_STRING];
};

//Função para limpar o buffer de entrada

void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);   
}

//Função principal do menu(main)
//agora com alocação dinamica de memoria, em vez de arrays estaticos, usamos ponteiros.
int main(){
    //atribuição de ponteiros
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    //usamos calloc no array de livros, para inicializar toda a memória com zeros.
    biblioteca = (struct Livro *) calloc(MAX_LIVROS,  sizeof(struct Livro));

    //usamos malloc para o array de emprestimos
    emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    //VERIFICAÇÃO da alocação de memoria.
    if(biblioteca == NULL || emprestimos == NULL){
        printf("ERRO: Falha ao alocar memoria.\n");
        return 1; // retorna 1 para indicar erro.
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;
    
    do{
        //exibir o menu de opções
        printf("===========================\n");
        printf("    LIBRARY SYSTEM \n");
        printf("===========================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar Emprestimo\n");
        printf("4 - Listar emprestimos\n");
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

                //Como o calloc zera tudo, precisamos ativar a disponibilidade do livro
                 biblioteca[totalLivros].disponivel = 1;

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
                    printf("status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
                }
                printf("---------------------------------\n");
            }
            printf("\nPressione Enter para continuar...");
            getchar();//Pausa para o usuario ler a mensagem antes de voltar a menu
            break;

        case 3 : //REALIZAR EMPRESTIMO
            printf("--- Realizar Emprestimo ---\n\n");

            if(totalEmprestimos >= MAX_EMPRESTIMOS){
                printf("Limites de emprestimos atingido!\n");
            } else {
                printf("Livros disponiveis: \n");
                int disponiveis = 0;
                for(int i = 0; i < totalLivros; i++){
                    if (biblioteca[i].disponivel){
                        printf("%d - %s\n", i + 1, biblioteca[i].nome);
                        disponiveis++;
                    }
                }

                if (disponiveis == 0) {
                    printf("Nenhum Livro disponivel para emprestimo.\n");
                } else {
                    printf("\n Digite o numero do livro que deseja emprestar: ");
                    int numLivro;
                    scanf("%d", &numLivro);
                    limparBufferEntrada();

                    int indice = numLivro - 1; // converte para o indice do array (0 a n-1)

                    //validação da escolha do usuário
                    if(indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel){
                    printf("Digite o nome do usuario que esta pegando o livro: ");
                    fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                    emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                    //registra o emprestimo
                    emprestimos[totalEmprestimos].indiceLivro = indice;

                    //atualiza o status do livro para indisponivel
                    biblioteca[indice].disponivel = 0;

                    totalEmprestimos++;
                    printf("\nEmprestimo realizado com sucesso!\n");
                } else {
                    printf("\nNumero de livro invalido ou livro indisponivel.\n");
                    
                }

            }
            printf("\nPressione Enter para continuar...");
            getchar();
            break;


        case 4 : //LISTAR EMPRESTIMOS
            printf("--- Lista de Emprestimos ---\n\n");
            if (totalEmprestimos == 0){
                printf("Nenhum emprestimo realizado");
            } else {
                for (int i = 0; i < totalEmprestimos; i++){
                    //Usa o indice armazenado no empréstimo para buscar o nome do livro.
                    int indiceLivro = emprestimos[i].indiceLivro;
                    printf("----------------------");
                    printf("EMPRESTIMO %d\n", i + 1);
                    printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                    printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                }
                printf("--------------------");
            }
        

        case 0: //SAIR
            printf("\nSaindo do Sistema...\n");
            break;    


        default: //OPÇÃO INVÁLIDA
            printf("\nOpção inválida! tente novamente. \n");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        }

    }
}while (opcao != 0);
    //Liberação da memória
free(biblioteca);
free(emprestimos);

printf("Memória liberada com sucesso.\n");

return 0;
}
