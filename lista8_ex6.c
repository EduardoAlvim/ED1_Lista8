#include <stdio.h>
#include <stdlib.h>

//Faça uma função que receba dados inteiros e insira de forma ordenada na lista encadeada

typedef struct no
{
    int dado;
    struct no *prox;
} noptr;

void insere_lista(noptr **inicio,noptr *novo, int valor)
{
    noptr *p, *ant;
    novo->dado=valor;
    novo->prox=NULL;
    if(*inicio==NULL)
        *inicio=novo;
    else
    {
        p=*inicio;
        ant=*inicio;
        while(p->dado <= novo->dado && p->prox != NULL)
        {
            ant=p;
            p=p->prox;
        }
        if(p->dado <= novo->dado && p->prox ==  NULL)
        {
            p->prox=novo;
        }
        else if((*inicio)->dado == p->dado)
        {
            novo->prox=*inicio;
            *inicio=novo;
        }
        else if(p->dado >= novo->dado && p->dado >= (*inicio)->dado)
        {
            ant->prox=novo;
            novo->prox=p;
        }

    }
}

void lista_todos(noptr **inicio)
{
    if(*inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = *inicio;
    while(p != NULL)
    {
        printf("\nDados: %d",p->dado);
        p = p->prox;
    }
    printf("\n");
}

void main()
{
    noptr *inicio;
    inicio=NULL;
    noptr *info;
    int valor, resp;
    do
    {
        printf("\n Menu\n1 Inserir na lista \n2 Mostrar a lista\n0 Sair \n");
        scanf("%d",&resp);
        if(resp == 1)
        {
            printf("\nDigite um valor: ");
            scanf("%d",&valor);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(&inicio,info,valor);
        }
        else if(resp == 2)
        {
            lista_todos(&inicio);
        }
        else if(resp == 0)
        {
            printf("\nSaindo");
        }
        else
        {
            printf("\nComando invalido");
        }
    }
    while(resp != 0);
}
