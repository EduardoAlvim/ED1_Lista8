#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que cadastre produtos. Para cada produto devem ser
cadastrados código do produto, preço e quantidade estocada. Os dados devem ser
armazenados em uma lista simplesmente encadeada e não ordenada. Posteriormente,
receber do usuário a taxa de desconto (ex. Digitar 10 para taxa de desconto de 10%).
Aplicar a taxa digitada ao preco de todos os produtos cadastrados e finalmente
mostrar um relatório com o código e o novo preço. O final desse relatório deve
apresentar também a quantidade de produtos com quantidade estocada superior a
500.
*/

typedef struct no
{
    float prec;
    int cod,quant;
    struct no *prox;
} noptr;
noptr *inicio;

void insere_lista(noptr *novo, int c, int q,float p)
{
    novo->cod=c;
    novo->quant=q;
    novo->prec=p;
    if(inicio==NULL)
        novo->prox = NULL;
    else
        novo->prox=inicio;
    inicio=novo;
}

void desconto(float d)
{
    noptr *p;
    p = inicio;
    while(p)
    {
        p->prec = p->prec * (float)(d/100.0);
        p = p->prox;
    }
}

void relatorio()
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    int cont=0;
    while(p)
    {
        printf("\nCodigo: %d\nPreco: %.2f",p->cod,p->prec);
        if(p->quant >500)
        {
            cont++;
        }
        p = p->prox;
    }
    printf("\nQuantidade de produtos com quantidade estocada superior a 500: %d",cont);
    printf("\n");
}

void main()
{
    int resp=-1;
    inicio=NULL;
    noptr *info;
    float prec,desc;
    int cod,quant;
    do
    {
        printf("\n Menu\n1 Inserir produto; \n2 Inserir desconto; \n3 Relatorio\n0 Sair \n");
        scanf("%d",&resp);
        if(resp == 1)
        {
            printf("\nDigite o codigo: ");
            scanf("%d",&cod);
            printf("\nDigite a quantidade estocada: ");
            scanf("%d",&quant);
            printf("\nDigite o preco: ");
            scanf("%f",&prec);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(info,cod,quant,prec);
        }
        else if(resp == 2)
        {
            printf("\nDigite o desconto: ");
            scanf("%f",&desc);
            desconto(desc);
        }
        else if(resp == 3)
        {
            relatorio();
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
    while(resp!=0);
}
