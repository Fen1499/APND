#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
    Pilha p;
    int a=0;
    int patual;         ///Valor tirado do topo da pilha
    char tupla[3];      ///Regra da função de transição [estado,apnd,pilha]
    char apnd[80];      ///Automato de pilha não deterministico
    char estado = '1';  ///Estado atual
    char inpilha = 'I'; ///Inicio da pilha
    char estfim;        ///Estado final, lido do arquivo
    FILE* ft;           ///Arquivo com o estado final e função de transição

    p = pilha_inicizalizar(p);
    ft = fopen("ft.txt","r");
    PUSH(p,inpilha);

    printf("APND:\n");
    fscanf(stdin,"%s",apnd);
    apnd[strlen(apnd)] = '0';
    fscanf(ft,"%c",&estfim);fgetc(ft);

    while(!feof(ft))
    {
        p = POP(p,&patual);
        fscanf(ft,"%c%c%c",&tupla[0],&tupla[1],&tupla[2]);
        printf("[%c][%c][%c]\n",tupla[0],tupla[1],tupla[2]);                 ///Regra lida do arquivo
        printf("{%c}{%c}{%c}\n\n",estado,apnd[a],patual);                   ///Regra que ele precisa encontrar
        if(estado == tupla[0] && apnd[a] == tupla[1] && patual == tupla[2])///Encoutrou a regra entra aqui
        {
            fscanf(ft,"%c",&estado);
            char aux;
            fscanf(ft,"%c",&aux);
            while(aux != '\n')
            {
                if(aux != '0')p = PUSH(p,aux);///0 signigica vazio
                fscanf(ft,"%c",&aux);
            }
            a++;
            rewind(ft);fgetc(ft);fgetc(ft);
        }
        else///Se não encontrar a regra, entra aqui
        {   ///pra ler o resto da linha e procura na proxima linha
            char aux;
            do
            {
                fscanf(ft,"%c",&aux);
            }while(aux != '\n');
            p = PUSH(p,patual);

        }
        if(estado == estfim){printf("cadeia aceita");break;} ///Se ele chegar no estado final acaba
    }
        if(estado != estfim){printf("cadeia nao aceita");}  ///Se ele chegar em eof vem pra ca e acaba
    Pdestroy(p);
    fclose(ft);
}
