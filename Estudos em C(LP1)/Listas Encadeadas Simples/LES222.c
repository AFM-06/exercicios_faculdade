#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista
struct No {
    int valor;                // Valor armazenado no nó
    struct No *proximo;       // Ponteiro para o próximo nó da lista
};

// Estrutura descritor que contém metadados da lista
struct Descritor {
    struct No *inicio;        // Ponteiro para o primeiro nó da lista
    struct No *fim;           // Ponteiro para o último nó da lista
    int quantidade;           // Quantidade de nós na lista
};

//----------------------------------------------------------------------------------------
// Função que verifica se a lista está vazia
int estavazia(struct Descritor *lista) {
    return (lista->fim == NULL); // Se não houver fim, então a lista está vazia
}

//----------------------------------------------------------------------------------------
// Função para imprimir os elementos da lista
void imprimir(struct Descritor *lista) {
    if (estavazia(lista)) {
        printf("A lista está vazia");
    } else {
        // Percorre a lista do início até o final
        for (struct No *auxiliar = lista->inicio; auxiliar != NULL; auxiliar = auxiliar->proximo) {
            printf("%d ", auxiliar->valor);
        }
    }
}

//----------------------------------------------------------------------------------------
// Função para inserir um nó no início da lista
void InserirNoInicio(struct Descritor *lista) {
    struct No *novo = (struct No*) malloc(sizeof(struct No)); // Aloca memória para novo nó
    printf("\nInsira o valor: ");
    scanf("%d", &novo->valor); // Recebe valor

    if (estavazia(lista)) {
        // Se a lista estiver vazia, novo será o único elemento
        novo->proximo = NULL;
        lista->fim = novo; // Também é o último
    } else {
        novo->proximo = lista->inicio; // Novo aponta para o antigo início
    }

    lista->inicio = novo; // Atualiza o início da lista
    lista->quantidade++;  // Incrementa a quantidade
}

//----------------------------------------------------------------------------------------
// Função para inserir um nó no fim da lista
void InserirNoFim(struct Descritor *lista) {
    struct No *novo = (struct No*) malloc(sizeof(struct No)); // Aloca novo nó
    printf("Insira o valor");
    scanf("%d", &novo->valor); // Recebe valor
    novo->proximo = NULL;      // Novo fim sempre aponta para NULL

    if (estavazia(lista)) {
        // Se a lista estiver vazia, novo é o início e fim
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo; // O atual último nó aponta para o novo
        lista->fim = novo;          // Atualiza o ponteiro fim
    }

    lista->quantidade++; // Incrementa contador
}

//----------------------------------------------------------------------------------------
// Função para remover um nó do início da lista
void RemoverDoInicio(struct Descritor *lista) {
    struct No *remover = lista->inicio; // Guarda ponteiro para o nó a remover

    if (estavazia(lista)) {
        printf("A lista está vazia\n");
        system("pause");
        return;
    }

    if (lista->quantidade == 1) {
        // Se houver apenas um nó, esvazia a lista
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->inicio = lista->inicio->proximo; // Move o início para o próximo nó
    }

    free(remover);           // Libera memória do nó removido
    lista->quantidade--;     // Decrementa contador
}

//----------------------------------------------------------------------------------------
// Função para remover um nó do final da lista
void RemoverDoFim(struct Descritor *lista) {
    struct No *remover = lista->fim;

    if (estavazia(lista)) {
        printf("A lista está vazia");
        system("pause");
        return;
    }

    if (lista->quantidade == 1) {
        // Lista com um único elemento
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        // Percorre até o penúltimo nó
        struct No *penultimo = lista->inicio;
        while (penultimo->proximo != remover) {
            penultimo = penultimo->proximo;
        }

        lista->fim = penultimo;      // Atualiza fim
        lista->fim->proximo = NULL;  // Novo fim aponta para NULL
    }

    free(remover);           // Libera o nó antigo do final
    lista->quantidade--;     // Decrementa contador
}

//----------------------------------------------------------------------------------------
// Função para liberar toda a memória da lista
void LiberarMemoria(struct Descritor *lista) {
    struct No *remover = lista->inicio;
    while (remover != NULL) {
        struct No *proximo = remover->proximo; // Guarda próximo nó
        free(remover);                         // Libera nó atual
        remover = proximo;                     // Vai para o próximo
    }
}

//----------------------------------------------------------------------------------------
// Função principal
int main() {
    // Cria e inicializa a lista
    struct Descritor *lista = (struct Descritor *) malloc(sizeof(struct Descritor));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;

    // Insere um elemento no início para testar
    InserirNoInicio(lista);
}
