#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// ==========================================
// DEFINIÇÃO DA STRUCT E ESTRUTURA DO INVENTÁRIO
// ==========================================

// Struct que representa as propriedades de um item 
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Funções obrigatórias do sistema - modularizado atravéz da void
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);

// Função auxiliar para limpar o buffer do teclado e remover o '\n' do fgets
void limparString(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// ==========================================
// FLUXO DE EXECUÇÃO PRINCIPAL
// ==========================================
int main() {
    // Vetor de structs para armazenar até 10 itens (lista de struct)
    Item mochila[MAX_ITENS];

    // Variável de controle para rastrear o número atual de itens inseridos
    int totalItens = 0; 
    int opcao;

    //menu de opções
    do {
        printf("\n=========================================\n");
        printf("       SISTEMA DE INVENTÁRIO (MOCHILA)   \n");
        printf("=========================================\n");
        printf("Capacidade atual: %d/%d itens registrados.\n", totalItens, MAX_ITENS);
        printf("-----------------------------------------\n");
        printf("[1] Cadastrar Item\n");
        printf("[2] Remover Item\n");
        printf("[3] Buscar Item por Nome\n");
        printf("[4] Listar Todos os Itens\n");
        printf("[0] Sair do Jogo\n");
        printf("Escolha uma acao estrategica: ");
        
        //validação de entrada
        if (scanf("%d", &opcao) != 1) {  
            printf("\nOpcao invalida! Digite um numero.\n");
            while (getchar() != '\n'); // Limpa buffer em caso de entrada de texto
            continue;
            }
            while (getchar() != '\n'); // Limpa o '\n' deixado pelo scanf em caso de valor certo

        switch (opcao) {
            case 1:
                inserirItem(mochila, &totalItens); //alterar valor da variavel totalItens
                listarItens(mochila, totalItens); // Listagem obrigatória após operação
                break;
            case 2:
                removerItem(mochila, &totalItens); //alterar valor da variavel totalItens
                listarItens(mochila, totalItens); // Listagem obrigatória após operação
                break;
            case 3:
                buscarItem(mochila, totalItens);
                break;
            case 4:
                listarItens(mochila, totalItens);
                break;
            case 0:
                printf("\nFechando mochila. Boa sorte na sobrevivencia!\n");
                break;
            default:
                printf("\nAcao desconhecida! Preste atencao no menu.\n");
        }
    } while (opcao != 0);

    return EXIT_SUCCESS;
}

// ==========================================
// IMPLEMENTAÇÃO DAS FUNÇÕES
// ==========================================

// Função para cadastrar um novo item no inventário
void inserirItem(Item mochila[], int *total) {
    // Verifica requisito de usabilidade e limite máximo do vetor
    if (*total >= MAX_ITENS) {
        printf("\n[ALERTA] Sua mochila esta cheia! Remova algo antes de coletar mais loot.\n");
        return;
    }

    printf("\n--- CADASTRANDO NOVO ITEM ---\n");
    
    printf("Nome do item: ");
    fgets(mochila[*total].nome, 30, stdin); //aqui acontece a manipulação na struct e no contador
    limparString(mochila[*total].nome);

    printf("Tipo (ex: arma, municao, cura): ");
    fgets(mochila[*total].tipo, 20, stdin);
    limparString(mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    while (getchar() != '\n'); // Limpa buffer

    // Incrementa o contador de itens totais por referência
    (*total)++;
    printf("\n[SUCESSO] Item guardado com sucesso!\n");
}

// Função para remover um item deslocando os elementos subsequentes
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("\n[INFO] A mochila ja esta completamente vazia.\n");
        return;
    }
    
    char nomeBusca[30];
    int encontrado = -1;

    printf("\n--- REMOVENDO ITEM ---\n");
    printf("Digite o nome exato do item que deseja descartar: ");
    fgets(nomeBusca, 30, stdin);
    limparString(nomeBusca);

     // Busca sequencial para encontrar o índice do item a ser removido
    for (int i = 0; i < *total; i++) {
        if (strcasecmp(mochila[i].nome, nomeBusca) == 0) { // strcasecmp ignora maiúsculas/minúsculas
            encontrado = i;
            break;
        }
    }

    // Se o item foi localizado, reorganiza a lista sequencial (Shift Left)
    if (encontrado != -1) {
        for (int i = encontrado; i < (*total) - 1; i++) {
            mochila[i] = mochila[i + 1];
        }
        (*total)--; // Reduz o tamanho lógico da lista
        printf("\n[SUCESSO] Item '%s' foi removido e descartado.\n", nomeBusca);
    } else {
        printf("\n[ERRO] Item '%s' nao foi encontrado na mochila.\n", nomeBusca);
    }
}

// Função de Busca Sequencial exigida pelo escopo do projeto
void buscarItem(Item mochila[], int total) {
    if (total == 0) {
        printf("\n[INFO] Nenhum item para buscar. Mochila vazia.\n");
        return;
    }
 char nomeBusca[30];
    int encontrado = 0;

    printf("\n--- BUSCA SEQUENCIAL DE LOOT ---\n");
    printf("Digite o nome do item que esta procurando: ");
    fgets(nomeBusca, 30, stdin);
    limparString(nomeBusca);

    // Varre o vetor posição por posição (Complexidade O(n))
    for (int i = 0; i < total; i++) {
        if (strcasecmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n[ITEM LOCALIZADO]");
            printf("\nPosicao na mochila: Slot %d", i + 1);
            printf("\nNome: %s", mochila[i].nome);
            printf("\nTipo: %s", mochila[i].tipo);
            printf("\nQuantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break; // Para a execução ao achar o primeiro resultado correspondente
        }
    }

    if (!encontrado) {
        printf("\n[!] O item '%s' nao esta nos seus compartimentos.\n", nomeBusca);
    }
}

// Função de listagem de dados (Executada no menu e após inserções/remoções)
void listarItens(Item mochila[], int total) {
    printf("\n--- CONTEÚDO ATUAL DA MOCHILA ---\n");
    if (total == 0) {
        printf("[Vazia] Voce nao possui recursos coletados ainda.\n");
        return;
    }

    // Varre e imprime de forma limpa cada struct no vetor
    for (int i = 0; i < total; i++) {
        printf("Slot [%d] | Nome: %-15s | Tipo: %-10s | Qtd: %d\n", 
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

