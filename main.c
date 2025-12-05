#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    struct No *prox;
} No;

No* inserir(No *lista, char *nome) {
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (lista == NULL) {
        return novo;
    }

    No *aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    return lista;
}

No* removerNome(No *lista, char *nome) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return lista;
    }

    No *atual = lista;
    No *ant = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Nome nao encontrado!\n");
        return lista;
    }

    if (ant == NULL) { 
        lista = lista->prox; 
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    return lista;
}

No* removerFIFO(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return lista;
    }

    No *temp = lista;
    lista = lista->prox;
    free(temp);

    return lista;
}

void imprimir(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No *aux = lista;
    printf("\n--- LISTA ---\n");
    while (aux != NULL) {
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
}

void ordenarSelection(No *lista) {
    if (lista == NULL) return;

    No *i, *j;
    char temp[50];

    for (i = lista; i->prox != NULL; i = i->prox) {
        No *menor = i;
        for (j = i->prox; j != NULL; j = j->prox) {
            if (strcmp(j->nome, menor->nome) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            strcpy(temp, i->nome);
            strcpy(i->nome, menor->nome);
            strcpy(menor->nome, temp);
        }
    }
}

int main() {
    No *lista = NULL;
    int op;
    char nome[50];

    do {
        printf("\n1 - Inserir nome\n");
        printf("2 - Remover nome\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Ordenar lista\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                printf("Digite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                if (strlen(nome) == 0) {
                    printf("Nome invalido!\n");
                } else {
                    lista = inserir(lista, nome);
                }
                break;

            case 2:
                printf("Digite o nome para remover (ENTER para FIFO): ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                if (strlen(nome) == 0) {
                    lista = removerFIFO(lista);
                } else {
                    lista = removerNome(lista, nome);
                }
                break;

            case 3:
                imprimir(lista);
                break;

            case 4:
                ordenarSelection(lista);
                printf("Lista ordenada!\n");
                break;

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}
