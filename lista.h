typedef struct lista* Lista;

Lista lista_inicializar(Lista l);
Lista inserir_inicio(Lista l,int a);
Lista inserir_fim(Lista l,int a);
Lista remover_posicao(Lista l,int n,int* x);
Lista lista_destruir(Lista l);
void lista_imprimir(Lista l);
