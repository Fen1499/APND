typedef struct pilha* Pilha;

Pilha pilha_inicizalizar(Pilha p);
Pilha POP(Pilha p,int *x);
Pilha PUSH(Pilha p,int x);
Pilha Pdestroy(Pilha p);
void Pimprimir(Pilha p);
