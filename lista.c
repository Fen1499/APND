#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
    int info;
    struct lista* prox;
};

Lista lista_inicializar(Lista l)
{
    l = (Lista)malloc(sizeof(struct lista));
    return l;
}

Lista inserir_inicio(Lista l,int a)
{
    Lista aux;
    aux = (Lista)malloc(sizeof(struct lista));

    aux->info = a;
    aux->prox = l;
    return aux;
}

Lista inserir_fim(Lista L,int x)
{
    Lista aux;
    aux = (Lista)malloc(sizeof(struct lista));
    if(L == NULL)
    {
        aux->info = x;
        aux->prox = L;
        return aux;
    }

    if(L->prox == NULL)
    {
        aux->info = x;
        aux->prox = L->prox;
        L->prox = aux;
        return L;
    }

    else
    {
        inserir_fim(L->prox,x);
        return L;
    }
}

Lista remover_posicao(Lista l,int n,int* x)
{
    Lista aux;
    aux = (Lista)malloc(sizeof(struct lista));

    if(n>0)
    {
        l->prox = remover_posicao(l->prox,n-1,x);
    }
    else
    {
        *x = l->info;
        aux = l;
        l = l->prox;
        free(aux);
    }

    return l;
}

Lista lista_destruir(Lista l)
{
    if(l!=NULL)
    {
        l = lista_destruir(l->prox);
        free(l);
    }
    return l;
}

void lista_imprimir(Lista l)
{
    while(l!=NULL)
    {
        printf("[%d]",l->info);
        l = l->prox;
    }
    printf("\n");
}
