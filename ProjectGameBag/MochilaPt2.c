#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VETOR 10

// ============================================================================
// ESTRUTURAS DE DADOS
// ============================================================================
typedef struct {
    char nome[30];
    char tipo[20];
    int quantity; // Nome amigável para evitar conflitos de escopo
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// Variáveis de controle para medição de performance (Requisito Não Funcional)
int compSequencial = 0;
int compBinaria = 0;

// ============================================================================
// DECLARAÇÃO DE FUNÇÕES (MODULARIZAÇÃO)
// ============================================================================
void limparBuffer();
void formatarString(char *str);

// Funções da Mochila em Vetor
void inserirVetor(Item vetor[], int *total);
void removerVetor(Item vetor[], int *total);
void listarVetor(Item vetor[], int total);
void buscarSequencialVetor(Item vetor[], int total, char *nomeAlvo);
void ordenarVetorSelection(Item vetor[], int total);
void buscarBinariaVetor(Item vetor[], int total, char *nomeAlvo);

// Funções da Mochila em Lista Encadeada
void inserirLista(No **topo);
void removerLista(No **topo);
void listarLista(No *topo);
void buscarLista(No *topo, char *nomeAlvo);
void liberarLista(No *topo);

// ============================================================================
// FLUXO PRINCIPAL DO JOGO (MENU INTERATIVO)
// ============================================================================
int main() {
    // Inicialização das duas estruturas em paralelo
    Item vetorMochila[MAX_VETOR];
    int totalVetor = 0;
    No *listaMochila = NULL; // Lista inicia vazia (ponteiro para o nada)

    int estruturaEscolhida = 0;
    int acao = 0;
    char termoBusca[30];

    do {
        printf("\n=========================================\n");
        printf("    LABORATÓRIO DE PERFORMANCE DE LOOT   \n");
        printf("=========================================\n");
        printf("[1] Mudar/Escolher Estrutura Atual\n");
        printf("[2] Cadastrar Novo Item\n");
        printf("[3] Remover Item por Nome\n");
        printf("[4] Listar Inventario Atual\n");
        printf("[5] Realizar Busca Sequencial (Ambas)\n");
        printf("[6] Ordenar + Busca Binaria (Apenas Vetor)\n");
        printf("[0] Finalizar Simulador\n");
        printf("-----------------------------------------\n");
        printf("Escolha uma operacao: ");
        
        if (scanf("%d", &acao) != 1) {
            printf("\nEntrada invalida! Use numeros.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        if (acao == 0) break;

        // Gerenciador de menu baseado na escolha do jogador
        switch (acao) {
            case 1:
                printf("\n[SISTEMA] Selecione a estrutura ativa:\n");
                printf("[1] Vetor (Lista Sequencial Estatica)\n");
                printf("[2] Lista Encadeada (Estrutura Dinamica)\n");
                printf("Escolha: ");
                scanf("%d", &estruturaEscolhida);
                limparBuffer();
                break;

            case 2:
                if (estruturaEscolhida == 2) {
                    inserirLista(&listaMochila);
                    listarLista(listaMochila);
                } else {
                    inserirVetor(vetorMochila, &totalVetor);
                    listarVetor(vetorMochila, totalVetor);
                }
                break;

            case 3:
                if (estruturaEscolhida == 2) {
                    removerLista(&listaMochila);
                    listarLista(listaMochila);
                } else {
                    removerVetor(vetorMochila, &totalVetor);
                    listarVetor(vetorMochila, totalVetor);
                }
                break;

            case 4:
                if (estruturaEscolhida == 2) listarLista(listaMochila);
                else listarVetor(vetorMochila, totalVetor);
                break;

            case 5:
                printf("\nDigite o nome do recurso para BUSCA SEQUENCIAL: ");
                fgets(termoBusca, sizeof(termoBusca), stdin);
                formatarString(termoBusca);
                
                printf("\n--- RESULTADO COMPARATIVO DE BUSCA ---");
                buscarSequencialVetor(vetorMochila, totalVetor, termoBusca);
                buscarLista(listaMochila, termoBusca);
                break;

            case 6:
                printf("\n[PROCESSO] Ordenando vetor via Selection Sort para habilitar algoritmo binario...\n");
                ordenarVetorSelection(vetorMochila, totalVetor);
                listarVetor(vetorMochila, totalVetor);

                printf("\nDigite o nome do recurso para BUSCA BINÁRIA: ");
                fgets(termoBusca, sizeof(termoBusca), stdin);
                formatarString(termoBusca);

                buscarBinariaVetor(vetorMochila, totalVetor, termoBusca);
                break;

            default:
                printf("\nAcao invalida no menu!\n");
        }
    } while (acao != 0);

    // Limpeza obrigatória de memória dinâmica antes de encerrar
    liberarLista(listaMochila);
    printf("\nSimulador encerrado com sucesso.\n");
    return EXIT_SUCCESS;
}

// ============================================================================
// FUNÇÕES AUXILIARES
// ============================================================================
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void formatarString(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// ============================================================================
// IMPLEMENTAÇÃO: MOCHILA EM VETOR
// ============================================================================
void inserirVetor(Item vetor[], int *total) {
    if (*total >= MAX_VETOR) {
        printf("\n[ALERTA] Vetor totalmente preenchido (%d/%d)!\n", *total, MAX_VETOR);
        return;
    }
    printf("\n--- CADASTRAR NO VETOR ---\n");
    printf("Nome do item: ");
    fgets(vetor[*total].nome, 30, stdin);
    formatarString(vetor[*total].nome);

    printf("Tipo do item: ");
    fgets(vetor[*total].tipo, 20, stdin);
    formatarString(vetor[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &vetor[*total].quantity);
    limparBuffer();

    (*total)++;
    printf("[SUCESSO] Guardado no slot %d do vetor.\n", *total);
}

void removerVetor(Item vetor[], int *total) {
    if (*total == 0) {
        printf("\n[INFO] O vetor esta vazio.\n");
        return;
    }
    char nomeRemover[30];
    printf("\nNome do item para REMOVER do vetor: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    formatarString(nomeRemover);

    int indiceAlvo = -1;
    for (int i = 0; i < *total; i++) {
        if (strcasecmp(vetor[i].nome, nomeRemover) == 0) {
            indiceAlvo = i;
            break;
        }
    }

    if (indiceAlvo != -1) {
        // Operação Shift Left: Reorganiza a estrutura sequencial
        for (int i = indiceAlvo; i < (*total) - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        (*total)--;
        printf("[SUCESSO] Item removido do vetor.\n");
    } else {
        printf("[AVISO] Item nao localizado no vetor.\n");
    }
}

void listarVetor(Item vetor[], int total) {
    printf("\n--- EXIBINDO INVENTÁRIO (VETOR) ---\n");
    if (total == 0) {
        printf("[Vazio] Nenhum dado no vetor.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        printf("Indice [%d] | %-12s | Tipo: %-10s | Qtd: %d\n", 
               i, vetor[i].nome, vetor[i].tipo, vetor[i].quantity);
    }
}

void buscarSequencialVetor(Item vetor[], int total, char *nomeAlvo) {
    compSequencial = 0; // Zera o contador global antes de iniciar
    int achou = 0;

    for (int i = 0; i < total; i++) {
        compSequencial++; // Registra a comparação realizada
        if (strcasecmp(vetor[i].nome, nomeAlvo) == 0) {
            printf("\n[VETOR - ACHADO] Slot %d | Qtd: %d\n", i, vetor[i].quantity);
            achou = 1;
            break;
        }
    }
    if (!achou) printf("\n[VETOR] Item nao localizado.\n");
    printf(">> Comparacoes feitas no Vetor (Sequencial): %d\n", compSequencial);
}

// Algoritmo de Ordenação por Seleção (Selection Sort)
void ordenarVetorSelection(Item vetor[], int total) {
    for (int i = 0; i < total - 1; i++) {
        int menorIndice = i;
        for (int j = i + 1; j < total; j++) {
            if (strcasecmp(vetor[j].nome, vetor[menorIndice].nome) < 0) {
                menorIndice = j;
            }
        }
        if (menorIndice != i) {
            Item temp = vetor[i];
            vetor[i] = vetor[menorIndice];
            vetor[menorIndice] = temp;
        }
    }
}

// Algoritmo de Busca Binária (Requer vetor ordenado)
void buscarBinariaVetor(Item vetor[], int total, char *nomeAlvo) {
    compBinaria = 0;
    int inicio = 0;
    int fim = total - 1;
    int meio;
    int achou = 0;

    while (inicio <= fim) {
        compBinaria++;
        meio = (inicio + fim) / 2;
        int resultadoComp = strcasecmp(vetor[meio].nome, nomeAlvo);

        if (resultadoComp == 0) {
            printf("\n[BINÁRIA - ACHADO] Slot %d | Nome: %s | Qtd: %d\n", 
                   meio, vetor[meio].nome, vetor[meio].quantity);
            achou = 1;
            break;
        } else if (resultadoComp < 0) {
            inicio = meio + 1; // Item está na metade direita
        } else {
            fim = meio - 1;    // Item está na metade esquerda
        }
    }
    if (!achou) printf("\n[BINÁRIA] Item nao localizado.\n");
    printf(">> Comparacoes feitas no Vetor (Busca Binaria): %d\n", compBinaria);
}

// ============================================================================
// IMPLEMENTAÇÃO: MOCHILA EM LISTA ENCADEADA
// ============================================================================

// Função para cadastrar um item na lista encadeada (Alocação Dinâmica)
void inserirLista(No **topo) {
    // Aloca dinamicamente o espaço para um novo nó isolado na memória RAM
    No *novoNo = (No *) malloc(sizeof(No));
    
    // Proteção caso o sistema operacional fique sem memória livre
    if (novoNo == NULL) {
        printf("\n[ERRO] Falha critica do sistema: Memoria RAM esgotada!\n");
        return;
    }

    printf("\n--- CADASTRAR NA LISTA ENCADEADA ---\n");
    printf("Nome do item: ");
    fgets(novoNo->dados.nome, 30, stdin);
    formatarString(novoNo->dados.nome);

    printf("Tipo do item: ");
    fgets(novoNo->dados.tipo, 20, stdin);
    formatarString(novoNo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novoNo->dados.quantity);
    limparBuffer();

    // Mecânica de Encadeamento: Insere o novo nó sempre no início da lista (O(1))
    novoNo->proximo = *topo; // O novo nó aponta para quem era o antigo primeiro colocado
    *topo = novoNo;          // O topo da mochila passa a apontar para este novo nó

    printf("[SUCESSO] Item encadeado com exito na memoria dinamica.\n");
}

// Função para remover um item específico da lista encadeada ajustando os elos
void removerLista(No **topo) {
    if (*topo == NULL) {
        printf("\n[INFO] A lista encadeada ja esta vazia.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nNome do item para REMOVER da Lista: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    formatarString(nomeRemover);

    No *atual = *topo;
    No *anterior = NULL;

    // Busca sequencial pelos elos da lista para achar o item alvo
    while (atual != NULL && strcasecmp(atual->dados.nome, nomeRemover) != 0) {
        anterior = atual;         // Salva o nó que veio antes
        atual = atual->proximo;   // Avança para o próximo nó da corrente
    }

    // Se o ponteiro atual não chegou ao fim da lista, significa que localizou o item
    if (atual != NULL) {
        if (anterior == NULL) {
            // Cenário A: O item a ser removido era o primeiríssimo da lista
            *topo = atual->proximo;
        } else {
            // Cenário B: O item está no meio ou fim. O anterior "pula" o atual.
            anterior->proximo = atual->proximo;
        }
        
        // Liberação Física: Remove o nó da memória RAM definitivamente
        free(atual); 
        printf("[SUCESSO] Item desalocado da lista com sucesso.\n");
    } else {
        printf("[AVISO] Item nao localizado na lista encadeada.\n");
    }
}

// Função para varrer e listar todos os elementos alocados na lista encadeada
void listarLista(No *topo) {
    printf("\n--- EXIBINDO INVENTÁRIO (LISTA ENCADEADA) ---\n");
    if (topo == NULL) {
        printf("[Vazia] Nenhum no criado na memoria dinamica ainda.\n");
        return;
    }

    No *atual = topo;
    int contador = 1;

    // Percorre a lista até encontrar o último ponteiro que aponta para NULL (fim)
    while (atual != NULL) {
        // Exibe o número do slot, o endereço real na RAM (%p) e para onde ele aponta
        printf("No [%d] (Endereco: %p) | %-12s | Proximo -> (%p)\n", 
               contador++, (void*)atual, atual->dados.nome, (void*)atual->proximo);
        atual = atual->proximo; // Avança o ponteiro de navegação
    }
}

// Função de busca sequencial na lista (Incapaz de fazer busca binária)
void buscarLista(No *topo, char *nomeAlvo) {
    int comparacoesLista = 0;
    No *atual = topo;
    int achou = 0;

    // Varre obrigatoriamente de forma linear, elemento por elemento
    while (atual != NULL) {
        comparacoesLista++; // Incrementa contador de testes para a análise empírica
        
        if (strcasecmp(atual->dados.nome, nomeAlvo) == 0) {
            printf("[LISTA - ACHADO] Nome: %s | Localizado em memoria dinamica.\n", atual->dados.nome);
            achou = 1;
            break; // Interrompe ao localizar o primeiro resultado válido
        }
        atual = atual->proximo;
    }

    if (!achou) {
        printf("[LISTA] Item nao localizado.\n");
    }
    printf(">> Comparacoes feitas na Lista Encadeada: %d\n", comparacoesLista);
}

// Função obrigatória de encerramento: Garante que o jogo não cause vazamento de memória (Memory Leak)
void liberarLista(No *topo) {
    No *atual = topo;
    while (atual != NULL) {
        No *proximo = atual->proximo; // Salva a referência do próximo antes de apagar o atual
        free(atual);                 // Deleta o nó atual da memória RAM
        atual = proximo;             // Passa para o próximo salvo
    }
}
