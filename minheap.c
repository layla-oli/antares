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
struct elemento
{
    int chave;
    void*info;
};
int getChave(ElementoHeap ele)
{
    return ele->chave;
}
void* getInfo(ElementoHeap ele)
{
    return ele->info;
}
void InicializarVetorHeap(ElementoHeap* heap, int tamMax)
{
    for(int i = 0; i < tamMax;i++)
        heap[i]=NULL;
}

ElementoHeap InicializarElem(ElementoHeap ele,int chave, void* info)
{
    if(ele==NULL)
    {
        ele=(ElementoHeap)malloc(sizeof(struct elemento));
    }
    ele->info= info;
    ele->chave=chave;
    return ele;
}

ElementoHeap DestruirElem(ElementoHeap ele)
{
    if(ele!=NULL)
    {
        if(ele->info!=NULL)
            free(ele->info);
       free(ele);
    }
    return NULL;
}
void DestuirVetorHeap(ElementoHeap* heap, int tamMax)
{
      for(int i = 0; i < tamMax; i++)
                DestruirElem(heap[i]);
}
int IndiceFilhoEsq(int x,int totalElementos)
{
    int ind = (2 * x) + 1;
    if( x >= totalElementos || ind >= totalElementos)
        return -1;
    else
        return ind;
}

int IndiceFilhoDir(int x,int totalElementos)
{
    int ind = (2 * x) + 2;
    if( x >= totalElementos || ind >= totalElementos)
        return -1;
    else
        return ind;
}

int IndicePai(int x,int totalElementos)
{
    if( x <= 0 || x >= totalElementos)
        return -1;
    else
    {
        int ind = (int)floor((x-1)/2);
        return ind;
    }

}

void AjustarSubindo(ElementoHeap* heap, int pos,int totalElementos)
{
    if(pos != -1)
    {
        int pai = IndicePai(pos,totalElementos);
        if (pai != -1)
        {
            if(heap[pos]->chave < heap[pai]->chave)
            {
                ElementoHeap aux = heap[pos];
                heap[pos] = heap[pai];
                heap[pai] = aux;
                AjustarSubindo(heap,pai,totalElementos);
            }
        }
    }
}

void Inserir (ElementoHeap* heap, ElementoHeap x,int* totalElementos)
{
    heap[*totalElementos] = x;
    (*totalElementos)++;
    AjustarSubindo(heap,(*totalElementos)-1,totalElementos);
}

void AjustarDescendo(ElementoHeap* heap,int pos,int* totalElementos)
{
    if(pos != -1 && IndiceFilhoEsq(pos,(*totalElementos))!=-1)
    {
        int indiceMenorFilho=IndiceFilhoEsq(pos,(*totalElementos));

        if(IndiceFilhoDir(pos,(*totalElementos))!= -1 && heap[IndiceFilhoDir(pos,(*totalElementos))]->chave < heap[indiceMenorFilho]->chave )
            indiceMenorFilho=IndiceFilhoDir(pos,(*totalElementos));

        if(heap[indiceMenorFilho]->chave < heap[pos]->chave)
        {
            ElementoHeap aux = heap[pos];
            heap[pos] = heap[indiceMenorFilho];
            heap[indiceMenorFilho] = aux;
            AjustarDescendo(heap,indiceMenorFilho,totalElementos);
        }
    }
}

int Remover(ElementoHeap* heap, int *totalElementos)
{
    if((*totalElementos) == 0)
        return -1;
    else
    {
        int retorno = heap[0]->chave;
        free(heap[0]);
        //heap[0]=NULL;
        heap[0]= heap[(*totalElementos)-1];
        (*totalElementos)--;
        AjustarDescendo(heap,0,totalElementos);
        return retorno;
    }
}
void ImprimirChaves(ElementoHeap* heap, int totalElementos)
{
     printf("HEAP: |");
        for(int i = 0; i < totalElementos; i++)
        {
            printf("%d|",heap[i]->chave);
        }
        printf("\n");
}
