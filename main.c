///GRUPO:
///Bruno dos Santos Alves
///Carlos Linhares Machado
///Humberto dos Santos Chaves Junior
///Layla de Oliveira Sampaio da Silva
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>
#include "minheap.h"
typedef struct pes
{
    int idade;
    char nome[30];
} Pessoa;
void ImprimirPessoas(ElementoHeap* heap, int totalElementos)
{
    Pessoa* p = NULL;
        for(int i = 0; i < totalElementos; i++)
        {
            p =(Pessoa*)getInfo(heap[i]);
            printf("%d ",getChave(heap[i]));
            printf("%s\n",p->nome);
            p=NULL;
        }
}
int menu()
{
    int r;
    while(r <= 0 || r >5)
    {
        system("cls");
        printf("-----------------------HEAP-------------------------");
        printf("\n1.Adicionar elemento\n2.Remover elemento\n3.Imprimir\n4.Imprimir todos dados\n5.Sair\n" );
        scanf(" %d",&r);
        fflush(stdin);
    }
    return r;
}

int main()
{
    setlocale(LC_ALL,"");
    ElementoHeap heap[30];//Cria um vetor de ponteiros para ElementoHeap
    InicializarVetorHeap(heap,30);//Faz todas as posições do vetor serem NULL
    int totalElementos = 0;
    ElementoHeap ele = NULL;
    Pessoa* p;
    int chaveAux,f;
    while(1)
    {
        f = menu();
        switch (f)
        {
        case 1:
            p = (Pessoa*)malloc(sizeof(Pessoa));
            printf("Digite o nome da pessoa a ser adicionada ao heap:\n");
            scanf("%s",&(p->nome));
            printf("Digite a idade da pessoa a ser adicionada ao heap:\n");
            scanf("%d",&(p->idade));
            ele = InicializarElem(ele,p->idade,p);
            Inserir(heap,ele,&totalElementos);
            ele=NULL;
            p=NULL;
            break;
        case 2:
            chaveAux = Remover(heap,&totalElementos);
            printf("o número removido foi: %d\n",chaveAux);
            break;
        case 3:
            break;
        case 4:
            ImprimirPessoas(heap,totalElementos);
            break;
        case 5:
            DestuirVetorHeap(heap,30);
            exit(1);

            break;
        }
        ImprimirChaves(heap,totalElementos);
        printf("\nAperte qualquer tecla para continuar:\n");
        fflush(stdin);
        getchar();
        fflush(stdin);
        system("cls");
    }
}
