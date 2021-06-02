#ifndef CENARIO2_H_INCLUDED
#define CENARIO2_H_INCLUDED
#include "cenario1.h"
typedef struct Item
{
    int Chave;
    char caracter1 [200];
    char caracter2 [200];
    char caracter3 [200];
    char caracter4 [200];
    char caracter5 [200];
    char caracter6 [200];
    char caracter7 [200];
    char caracter8 [200];
    char caracter9 [200];
    char caracter10 [200];
    double valor1;
    double valor2;
    double valor3;
    double valor4;
}Item;

//Bubble sort
void BolhaRegistro (Item* v, int n, int* compara, int* movimenta, float* tempo);

//Select sort
void SelecaoRegistro (Item* v, int n, int* compara, int* movimenta, float* tempo);

//Insert sort
void InsercaoRegistro (Item* v, int n, int* compara, int* movimenta, float* tempo);

//Shell sort
void ShellSortRegistro (Item* A, int n, int* compara, int* movimenta, float* tempo);

//Quick sort
void ParticaoRegistro (int Esq, int Dir,int *i, int *j, Item *A, int* compara, int* movimenta, float* tempo);
void OrdenaRegistro (int Esq, int Dir, Item *A, int* compara, int* movimenta, float* tempo);
void QuickSortRegistro (Item *A, int n, int* compara, int* movimenta, float* tempo);

//Merge sort
void MergeSortRegistro(Item *v, int posicaoInicio, int posicaoFim, int* compara, int* movimenta, float* tempo);

//Heap sort
void criaHeapRegistro(Item *v, int i, int f, int* compara, int* movimenta, float* tempo);
void HeapSortRegistro(Item *v, int n, int* compara, int* movimenta, float* tempo);

#endif