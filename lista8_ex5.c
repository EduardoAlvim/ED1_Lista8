#include <stdio.h>
#include <stdlib.h>

/*Faça uma função que una duas listas encadeadas, no final da primeira, coloque a
segunda. Mostre o resultado.
*/

typedef struct no
{
    int dado;
    struct no *prox;
} noptr;

void insere_lista(noptr **inicio,noptr *novo, int valor)
{
    novo->dado=valor;
    if(inicio==NULL)
        novo->prox = NULL;
    else
    {
        novo->prox=*inicio;
        *inicio=novo;
    }
}

void unir(noptr **i1,noptr *i2)
{
    noptr *p;
    noptr *q;
    p=*i1;
    q=i2;
    while(q){
    while(p->prox!=NULL)
        p=p->prox;
    p->prox=p;
    q=q->prox;
    }

}

void lista_todos(noptr *inicio)
{
    if(inicio == NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    while(p != NULL)
    {
        printf("\nDados: %d",p->dado);
        p = p->prox;
    }
    printf("\n");
}

void main()
{
    noptr *ini1, *ini2;
    ini1=NULL;
    ini2=NULL;
    noptr *info;
    int valor, resp;
    do
    {
        printf("\n Menu\n1 Inserir na lista 1; \n2 Inserir na lista 2; \n3 Unir na listas\n4 Mostrar lista 1\n0 Sair \n");
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
            insere_lista(&ini1,info,valor);
        }
        else if(resp == 2)
        {
            printf("\nDigite um valor: ");
            scanf("%d",&valor);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(&ini2,info,valor);
        }
        else if(resp == 3)
        {
            unir(&ini1,ini2);
        }
        else if(resp == 4)
        {
            lista_todos(ini1);
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

