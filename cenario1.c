#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cenario2.h"

//Bubble sort
void BolhaInt (int* vetor, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, j, aux;
    for( i = 0 ; i < n-1 ; i++ )
    {
        for( j = 1 ; j < n-i ; j++ ){
            *compara = *compara+1;
            if (vetor[j]< vetor[j-1]){
                aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
                *movimenta = *movimenta+3; 
            }
        }
    } 
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Select sort
void SelecaoInt (int* vetor, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, j, Min, aux;
    for (i = 0; i < n - 1; i++)
    {
        Min = i;
        for (j = i + 1 ; j < n; j++){
            *compara = *compara+1;
            if ( vetor[j]< vetor[Min]){
                Min = j;
            } 
        }
            aux = vetor[Min];
            vetor[Min] = vetor[i];
            vetor[i] = aux;
            *movimenta = *movimenta+3;
    }
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Insert sort
void InsercaoInt (int* vetor, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i,j, aux;
    for (i = 1; i < n; i++)
    {
        aux = vetor[i];
        j = i - 1;
        *compara = *compara+1;
        while ( ( j >= 0 ) && ( aux < vetor[j]) )
        {
            vetor[j + 1] = vetor[j];
            *movimenta = *movimenta+1;  
            j--;
        }
        vetor[j + 1] = aux;
        *movimenta = *movimenta+1;
    }
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Shell sort
void ShellSortInt (int* vetor, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, j, aux;
    int h = 1;
    do h = h * 3 + 1;
    while (h < n);
    do
    {
        h = h/3;
        for( i = h ; i < n ; i++ )
        {
            aux = vetor[i];
            j = i;
            *movimenta = *movimenta+2;
            while (vetor[j - h] > aux)
            {
                vetor[j] = vetor[j - h];
                j -= h;
                *compara = *compara+1;
                if (j < h)
                {
                    break;
                }  
            }
            vetor[j] = aux;
        }
    } while (h != 1);
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Quick sort
void ParticaoInt(int Esq, int Dir,int *i, int *j, int* vetor, int* compara, int* movimenta, float* tempo){
    int pivo, aux;
    *i = Esq; *j = Dir;
    pivo = vetor[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (pivo > vetor[*i])
        {
            *compara = *compara+1;
            (*i)++;
            
        }
        while (pivo < vetor[*j])
        {
            *compara = *compara+1;
            (*j)--;
        }
        if (*i <= *j)
        {
            *compara = *compara+1;
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i)++; 
            (*j)--;
            *movimenta = *movimenta+3;
        }
        *compara = *compara+1;
    } while (*i <= *j);
}

void OrdenaInt(int Esq, int Dir, int* vetor, int* compara, int* movimenta, float* tempo){
    int i,j;
    ParticaoInt(Esq, Dir, &i, &j, vetor, compara, movimenta, tempo);
    if (Esq < j)
    {
        *compara = *compara+1;
        OrdenaInt(Esq, j, vetor, compara, movimenta, tempo);
    }
    if (i < Dir)
    {
        *compara = *compara+1;
        OrdenaInt(i, Dir, vetor, compara, movimenta, tempo);
    }
}

void QuickSortInt(int* vetor, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    OrdenaInt(0, n-1, vetor, compara, movimenta, tempo);
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Merge sort
void MergeSortInt(int *vetor, int posicaoInicio, int posicaoFim, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, j, k, metadeTamanho, *vetorTemp;
    *compara = *compara+1;
    if(posicaoInicio == posicaoFim)
    {
        return;
    }
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    MergeSortInt(vetor, posicaoInicio, metadeTamanho, compara, movimenta, tempo);
    MergeSortInt(vetor, metadeTamanho + 1, posicaoFim, compara, movimenta, tempo);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        *compara = *compara+1;
        if (i == metadeTamanho + 1 ) {
            vetorTemp[k] = vetor[j];
            *movimenta = *movimenta+1;
            j++;
            k++;
        }
        else {
            *compara = *compara+1;
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                *movimenta = *movimenta+1;
                i++;
                k++;
            }
            else {
                *compara = *compara+1;
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    *movimenta = *movimenta+1;
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    *movimenta = *movimenta+1;
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
        *movimenta = *movimenta+1;
    }
    free(vetorTemp);
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Heap sort
void criaHeapInt(int *vetor, int i, int f, int* compara, int* movimenta, float* tempo){
    int aux = vetor[i];
    int j = i * 2 + 1;
    while (j <= f)
    {
        *compara = *compara+1;
        if (j<f)
        {
            *compara = *compara+1;
            if (vetor[j] < vetor[j+1])
            {
                j++;
            }
            
        }
        *compara = *compara+1;
        if (aux < vetor[j])
        {
            vetor[i] = vetor[j];
            i = j;
            j = 2 * i + 1;
            *movimenta = *movimenta+1;
        }
        else
        {
            j = f + 1;
        }
    }
    vetor[i] = aux;  
 }

void HeapSortInt(int *vetor, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, aux;
    for (i = (n-1)/2; i >=0; i--)
    {
        criaHeapInt(vetor, i, n-1, compara, movimenta, tempo);
    }
    for (i = n-1; i >= 0; i--)
    {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        *movimenta = *movimenta+3;
        criaHeapInt(vetor, 0, i-1, compara, movimenta, tempo);
    } 
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}
