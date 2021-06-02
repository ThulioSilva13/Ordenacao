#ifndef CENARIO1_H_INCLUDED
#define CENARIO1_H_INCLUDED
#include "time.h"

//Bubble sort
void BolhaInt (int* vetor, int n, int* compara, int* movimenta, float* tempo);

//Select sort
void SelecaoInt (int* vetor, int n, int* compara, int* movimenta, float* tempo);

//Insert sort
void InsercaoInt (int* vetor, int n, int* compara, int* movimenta, float* tempo);

//Shell sort
void ShellSortInt (int* vetor, int n, int* compara, int* movimenta, float* tempo);

//Quick sort
void ParticaoInt(int Esq, int Dir,int *i, int *j, int* vetor, int* compara, int* movimenta, float* tempo);
void OrdenaInt(int Esq, int Dir, int* vetor, int* compara, int* movimenta, float* tempo);
void QuickSortInt(int* vetor, int n, int* compara, int* movimenta, float* tempo);

//Merge sort
void MergeSortInt(int *vetor, int posicaoInicio, int posicaoFim, int* compara, int* movimenta, float* tempo);

//Heap sort
void criaHeapInt(int *vetor, int i, int f, int* compara, int* movimenta, float* tempo);
void HeapSortInt(int *vetor, int n, int* compara, int* movimenta, float* tempo);

#endif