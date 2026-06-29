#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *proximo;
};

struct Descritor{
    struct No *inicio;
    struct No *fim;
    int quantidade;
};

int estavazia(struct Descritor *lista){
    return (lista->fim == NULL);
}

void imprimir(struct Descritor *lista){
    if(estavazia(lista)){
        printf("A lista está vazia");
    }else{
        for(struct No *auxiliar = lista->inicio; auxiliar != NULL; auxiliar = auxiliar ->proximo){
            printf("%d ",auxiliar->valor);
        }
    }

}

void InserirNoInicio(struct Descritor *lista){
    struct No *novo = (struct no*) malloc(sizeof(struct No));
    printf("\nInsira o valor: ");
    scanf("%d",&novo->valor);
    if(estavazia(lista)){
        novo->proximo = NULL;
        lista->fim = novo;
    }else{
        novo->proximo = lista->inicio;
    }
    lista->inicio = novo;
    lista->quantidade++;
}

void InserirNoFim(struct Descritor *lista){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    printf("Insira o valor");
    scanf("%d",&novo->valor);
    if(estavazia(lista)){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    novo->proximo = NULL;
    lista->quantidade++;
}

void RemoverDoInicio(struct Descritor *lista){
    struct no *remover = lista->inicio;
    if (estavazia(lista)){
        printf("A lista está vazia\n");
        system("pause");
        return;
    }
    if(lista->quantidade == 1){
        lista->inicio = NULL;
        lista->fim = NULL;
    }else{
        lista->inicio = lista->inicio->proximo;
    }
    free(remover);
    lista->quantidade--;
}

void RemoverDoFim(struct Descritor *lista){
    struct no *remover  = lista->fim;
    if(estavazia(lista)){
        printf("A lista está vazia");
        system("pause");
        return;
    }
    if(lista->quantidade == 1){
        lista->inicio = NULL;
        lista->fim = NULL;
    }else{
        struct No *penultimo = lista->inicio;
        while (penultimo->proximo != remover){
            penultimo = penultimo->proximo; 
        }
        lista->fim = penultimo;
        lista->fim->proximo = NULL;
    }
    free(remover);
    lista->quantidade--;
}

void LiberarMemoria(struct Descritor *lista){
    struct No *remover = lista->inicio;
    while (remover != NULL){
        struct No *proximo = remover->proximo;
        free(remover);
        remover = proximo;
    }
    
}


int main(){
    struct Descritor *lista = (struct Descritor *) malloc(sizeof(struct Descritor));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;
    InserirNoInicio(lista);
}

