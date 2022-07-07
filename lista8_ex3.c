#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que cadastre alunos. Para cada aluno devem ser cadastrados
nome e nota final. Os dados devem ser armazenados em uma lista encadeada. Em
seguida, o programa deve mostrar apenas o nome dos alunos aprovados, ou seja, alunos
com nota final de no mínimo 7. Se nenhum aluno estiver aprovado, mostrar mensagem.*/

typedef struct no
{
    char nome[30];
    float nota;
    struct no *prox;
} noptr;
noptr *inicio;

void insere_lista(noptr *novo, float nt, char n[])
{
    novo->nota=nt;
    strcpy(novo->nome,n);
    if(inicio==NULL)
        novo->prox = NULL;
    else
        novo->prox=inicio;
    inicio=novo;
}

void listar_aprovados()
{
    int cont=0;
    noptr *p;
    p=inicio;
    while(p)
    {
        if(p->nota >= 7.0)
        {
            printf("\n%s",p->nome);
            cont++;
        }
        p=p->prox;
    }
    if(cont == 0)
    {
        printf("\nNenhum aluno passou");
    }
}

void main()
{
    inicio=NULL;
    noptr *info;
    float nota=0;
    char nome[30];
    do
    {
        printf("\nDigite a nota: ");
        scanf("%f",&nota);
        if(nota > 0){
        printf("\nDigite seu nome: ");
        fflush(stdin);
        gets(nome);
        info=(struct no *) malloc(sizeof(noptr));
        if(!info)
        {
            printf("\nSem Memoria!!!");
            return;
        }
        insere_lista(info,nota,nome);
        }
    }
    while(nota > 0);
    printf("\nAlunos que passaram: ");
    listar_aprovados();
}
