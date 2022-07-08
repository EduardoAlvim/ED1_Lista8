#include <stdio.h>
#include <stdlib.h>

/*Faça uma função que compare duas listas encadeadas e retorne para o programa
principal qual é a maior e quantos elementos ela tem.
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

void mostra_maior(noptr *i1,noptr *i2)
{
    int cont1=0,cont2=0;
    noptr *p;
    p=i1;
    while(p)
    {
        cont1++;
        p=p->prox;
    }
    p=i2;
    while(p)
    {
        cont2++;
        p=p->prox;
    }
    if(cont1 > cont2)
        printf("\nA lista 1 e a maior e tem %d elementos",cont1);
    else if(cont1 < cont2)
        printf("\nA lista 2 e a maior e tem %d elementos",cont2);
    else
        printf("\nAs duas listas sao iguais e tem %d elementos",cont1);
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
