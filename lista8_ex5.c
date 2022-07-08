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
noptr *ini1, *ini2;

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

void mostra_maior(noptr **i1,noptr *i2)
{
    noptr *p;
    p=*i1;
    while(n){
    while(p->prox!=NULL)
        p=p->prox;
    p->prox=novo;
    }

}
void main()
{
    ini1=NULL;
    ini2=NULL;
    noptr *info;
    int valor, resp;
    do
    {
        printf("\n Menu\n1 Inserir na lista 1; \n2 Inserir na lista 2; \n3 Mostrar a maior lista\n0 Sair \n");
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
            mostra_maior(ini1,ini2);
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
