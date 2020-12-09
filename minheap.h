/*Grupo:
Bruno dos Santos Alves
Carlos Linhares Machado
Humberto dos Santos Chaves Junior
Layla de Oliveira Sampaio da Silva */
#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

typedef struct elemento* ElementoHeap;
int getChave(ElementoHeap ele);
void* getInfo(ElementoHeap ele);
void InicializarVetorHeap(ElementoHeap* heap, int tamMax);
ElementoHeap InicializarElem(ElementoHeap ele,int chave, void* info);
ElementoHeap DestruirElem(ElementoHeap ele);
void DestuirVetorHeap(ElementoHeap* heap, int tamMax);
int IndiceFilhoEsq(int x,int totalElementos);
int IndiceFilhoDir(int x,int totalElementos);
int IndicePai(int x,int totalElementos);
void AjustarSubindo(ElementoHeap* heap, int pos,int totalElementos);
void Inserir (ElementoHeap* heap, ElementoHeap x,int* totalElementos);
void AjustarDescendo(ElementoHeap* heap,int pos,int* totalElementos);
int Remover(ElementoHeap* heap, int *totalElementos);
void ImprimirChaves(ElementoHeap* heap, int totalElementos);

#endif
