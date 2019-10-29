#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

struct pilha
{
    Lista l;
    int topo;
};

Pilha pilha_inicizalizar(Pilha p)
{
    p = (Pilha)malloc(sizeof (struct pilha));
    lista_inicializar(p->l);
    p->l = NULL;
    p->topo = -1;
    return p;
}

Pilha PUSH(Pilha p,int x)
{
    p->l = inserir_fim(p->l,x);
    p->topo++;
    return p;
}

Pilha POP(Pilha p,int *x)
{
    if(p->l == NULL)
        {
            printf("Pilha vazia\n");
            return p;
        }
    p->l = remover_posicao(p->l,p->topo,x);
    p->topo--;
    return p;
}

Pilha Pdestroy(Pilha p)
{
    p->l = lista_destruir(p->l);
    free(p);
    return p;
}

void Pimprimir(Pilha p)
{
    lista_imprimir(p->l);
}
