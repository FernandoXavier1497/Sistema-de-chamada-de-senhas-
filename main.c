#include <stdio.h>
#include <stdlib.h>

/*Estrutura do No (cartao) */
typedef struct No {
    int numero;
    char prioridade;   /* 'C' ou 'P' */
    struct No *proximo;
} No;

/* Cabeca da lista (fila) */
No *head = NULL;

/* Contadores para numeracao automatica */
int contadorC = 0;    /* comum comeca em 1 */
int contadorP = 300;  /* prioritario comeca em 301 */

/* B) inserirSemPrioridade */
void inserirSemPrioridade(No *novo) {
    if (head == NULL) {
        head = novo;
        return;
    }
    No *atual = head;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
}

/* C) inserirComPrioridade */
void inserirComPrioridade(No *novo) {
    if (head == NULL) {
        head = novo;
        return;
    }

    /* Se o primeiro nao for P, o novo vira a cabeca */
    if (head->prioridade != 'P') {
        novo->proximo = head;
        head = novo;
        return;
    }

    No *atual = head;
    /* anda enquanto o proximo existir e for prioridade P */
    while (atual->proximo != NULL && atual->proximo->prioridade == 'P') {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

/* D) inserir */
void inserir() {
    char prioridade;

    printf("Digite a prioridade do cartao (P - prioritario / C - comum): ");
    scanf(" %c", &prioridade);

    if (prioridade != 'P' && prioridade != 'C') {
        printf("Prioridade invalida! Use apenas P ou C.\n");
        return;
    }

    int numero;
    if (prioridade == 'C') {
        contadorC++;
        numero = contadorC;
    } else {
        contadorP++;
        numero = contadorP;
    }

    No *novo = (No *) malloc(sizeof(No));
    novo->numero = numero;
    novo->prioridade = prioridade;
    novo->proximo = NULL;

    if (head == NULL) {
        head = novo;
    } else if (prioridade == 'C') {
        inserirSemPrioridade(novo);
    } else {
        inserirComPrioridade(novo);
    }

    printf("Cliente %c%d adicionado a fila.\n", prioridade, numero);
}

/*E) imprimirFilaClientes  */
void imprimirFilaClientes() {
    if (head == NULL) {
        printf("A fila de clientes esta vazia.\n");
        return;
    }

    printf("----- Fila de Clientes -----\n");
    No *atual = head;
    while (atual != NULL) {
        printf("%c%d\n", atual->prioridade, atual->numero);
        atual = atual->proximo;
    }
    printf("-----------------------------\n");
}

/* F) atenderCliente */
void atenderCliente() {
    if (head == NULL) {
        printf("Nao ha clientes na fila para atendimento.\n");
        return;
    }

    No *atendido = head;
    head = head->proximo;

    printf("Chamando cliente %c%d para atendimento.\n", atendido->prioridade, atendido->numero);

    free(atendido);
}

/* G) Menu */
int main() {
    int opcao;

    do {
        printf("\n____ MENU ____\n");
        printf("1 - Adicionar cliente a fila\n");
        printf("2 - Mostrar clientes na fila\n");
        printf("3 - Chamar cliente\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                inserir();
                break;
            case 2:
                imprimirFilaClientes();
                break;
            case 3:
                atenderCliente();
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}