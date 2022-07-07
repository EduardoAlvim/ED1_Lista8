#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Faça um programa que cadastre funcionários. Para cada funcionário devem ser
cadastrados nome e salário. Os dados devem ser armazenados em uma lista
simplemente encadeada. Posteriormente, o programa deve mostrar:
• o nome do funcionário que tem o maior salário (em caso de empate mostrar
todos);
• a média salarial de todos os funcionários juntos;
• a quantidade de funcionários com salário superior a um valor fornecido pelo
usuário. Caso nenhum funcionário satisfaça essa condição, mostrar mensagem.*/

typedef struct no
{
    char nome[30];
    float salario;
    struct no *prox;
} noptr;
noptr *inicio;

void insere_lista(noptr *novo, float s, char n[])
{
    novo->salario=s;
    strcpy(novo->nome,n);
    if(inicio==NULL)
        novo->prox = NULL;
    else
        novo->prox=inicio;
    inicio=novo;
}

void maior_sal()
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    float maior=0;
    while(p)
    {
        if(maior < p->salario)
        {
            maior = p->salario;
        }
        p = p->prox;
    }
    p=inicio;
    while(p)
    {
        if(maior == p->salario)
        {
            printf("\n%s",p->nome);
        }
        p = p->prox;
    }
    printf("\n");
}

void media()
{
    if(inicio==NULL)
    {
        printf("\nLista Vazia!!!");
        return;
    }
    noptr *p;
    p = inicio;
    float m, acm=0;
    int cont=0;
    while(p)
    {
        acm=acm+p->salario;
        cont++;
        p = p->prox;
    }
    m=acm/(float)cont;
    printf("\nMedia: %.2f",m);
}

void quant_sup(float s)
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
        if(p->salario > s){
            cont++;
        }
        p = p->prox;
    }
    if(cont > 0){
        printf("\nQuantidade de salario maiores que %.2f: %d",s,cont);
    }
    else{
        printf("\nNao existe salario maior que %.2f",s);
    }
}

void main()
{
    int resp=-1;
    inicio=NULL;
    noptr *info;
    float sal;
    char nome[30];
    do
    {
        printf("\n Menu\n1 Inserir funcionario; \n2 Mostrar o nome do funcionário que tem o maior salário; \n3 Mostrar a media salarial de todos os funcionários juntos\n4 Mostrar a quantidade de funcionários com salário superior a um valor;\n0 Sair \n");
        scanf("%d",&resp);
        if(resp == 1)
        {
            printf("\nDigite seu nome: ");
            fflush(stdin);
            gets(nome);
            fflush(stdin);
            printf("\nDigite seu salario: ");
            scanf("%f",&sal);
            info=(struct no *) malloc(sizeof(noptr));
            if(!info)
            {
                printf("\nSem Memoria!!!");
                return;
            }
            insere_lista(info,sal,nome);
        }
        else if(resp == 2)
        {
            maior_sal();
        }
        else if(resp == 3)
        {
            media();
        }
        else if(resp == 4)
        {
            printf("\nDigite um valor de salario: ");
            scanf("%f",&sal);
            quant_sup(sal);
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
