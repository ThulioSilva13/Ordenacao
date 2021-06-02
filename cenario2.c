#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cenario2.h"
//nos chama função eu passei sem ponteiro, se der erro é isso

//Bubble sort
void BolhaRegistro(Item* v, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, j;
    Item aux;
    for( i = 0 ; i < n-1 ; i++ )
    {
        for( j = 1 ; j < n-i ; j++ ){
             *compara = *compara+1;
            if ( v[j].Chave < v[j-1].Chave ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux; 
                *movimenta = *movimenta+3;
            }
        }
     }
     clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Select sort
void SelecaoRegistro (Item* v, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, j, Min;
    Item aux;
    for (i = 0; i < n - 1; i++)
    {
        Min = i;
        for (j = i + 1 ; j < n; j++){
            *compara = *compara+1;
            if ( v[j].Chave < v[Min].Chave){
                Min = j;
            } 
        }
            aux = v[Min];
            v[Min] = v[i];
            v[i] = aux;
            *movimenta = *movimenta+3;
    }
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Insert sort
void InsercaoRegistro (Item* v, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i,j;
    Item aux;
    for (i = 1; i < n; i++)
    {
        aux = v[i];
        j = i - 1;
        *compara= *compara+1;
        while ( ( j >= 0 ) && ( aux.Chave < v[j].Chave ) )
        {
            v[j + 1] = v[j];
            *movimenta = *movimenta+1;
            j--;
        }
        v[j + 1] = aux;
        *movimenta = *movimenta+1;
    }
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Shell sort
void ShellSortRegistro (Item* A, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, j;
    int h = 1;
    Item aux;
    do h = h * 3 + 1;
    while (h < n);
    do
    {
        h = h/3;
        for( i = h ; i < n ; i++ )
        {
            aux = A[i]; j = i;
            *movimenta = *movimenta+2;
            while (A[j - h].Chave > aux.Chave)
            {
                A[j] = A[j - h]; j -= h;
                *compara = *compara+1;
                if (j < h) break;
            }
            A[j] = aux;
        }
    } while (h != 1);
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Quick sort
void ParticaoRegistro (int Esq, int Dir,int *i, int *j, Item *A, int* compara, int* movimenta, float* tempo){
    Item pivo, aux;
    *i = Esq; *j = Dir;
    pivo = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (pivo.Chave > A[*i].Chave)
        {
            *compara = *compara+1;
            (*i)++;
        }
        while (pivo.Chave < A[*j].Chave)
        {
            *compara = *compara+1;
            (*j)--;
        }
        if (*i <= *j)
        {
            *compara = *compara+1;
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;
            (*i)++;
            (*j)--;
            *movimenta = *movimenta+3;
        }
        *compara = *compara+1;
    } while (*i <= *j);
}

void OrdenaRegistro (int Esq, int Dir, Item *A, int* compara, int* movimenta, float* tempo){
    int i,j;
    ParticaoRegistro(Esq, Dir, &i, &j, A, compara, movimenta, tempo);
    if (Esq < j)
    {
        *compara = *compara+1;
        OrdenaRegistro(Esq, j, A, compara, movimenta, tempo);
    }
    if (i < Dir)
    {
        *compara = *compara+1;
        OrdenaRegistro(i, Dir, A, compara, movimenta, tempo);
    }
}

void QuickSortRegistro (Item *A, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    OrdenaRegistro(0, n-1, A, compara, movimenta, tempo);
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Merge sort
void MergeSortRegistro(Item *v, int posicaoInicio, int posicaoFim, int* compara, int* movimenta, float* tempo) {
    clock_t inicio = clock();
    int i, j, k, metadeTamanho, *vetorTemp;
    *compara = *compara+1;
    if(posicaoInicio == posicaoFim) {
        return;
    }
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    //se o código der erro é por causa disso aqui
    MergeSortRegistro(v, posicaoInicio, metadeTamanho, compara, movimenta, tempo);
    MergeSortRegistro(v, metadeTamanho + 1, posicaoFim, compara, movimenta, tempo);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        *compara = *compara+1;
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = v[j].Chave;
            *movimenta = *movimenta+1;
            j++;
            k++;
        }
        else {
            *compara = *compara+1;
            if (j == posicaoFim + 1) {
                vetorTemp[k] = v[i].Chave;
                *movimenta = *movimenta+1;
                i++;
                k++;
            }
            else {
                *compara = *compara+1;
                if (v[i].Chave < v[j].Chave) {
                    vetorTemp[k] = v[i].Chave;
                    *movimenta = *movimenta+1;
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = v[j].Chave;
                    *movimenta = *movimenta+1;
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        v[i].Chave = vetorTemp[i - posicaoInicio];
        *movimenta = *movimenta+1;
    }
    free(vetorTemp);
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}

//Heap sort
void criaHeapRegistro(Item *v, int i, int f, int* compara, int* movimenta, float* tempo){
    int aux = v[i].Chave;
    int j = i * 2 + 1;
    while (j <= f)
    {
        *compara = *compara+1;
        if (j<f)
        {
            *compara = *compara+1;
            if (v[j].Chave < v[j+1].Chave)
            {
                j++;
            }
            
        }
        *compara = *compara+1;
        if (aux < v[j].Chave)
        {
            v[i].Chave = v[j].Chave;
            i = j;
            j = 2 * i + 1;
            *movimenta = *movimenta+1;
        }
        else
        {
            j = f + 1;
        }
    }
    v[i].Chave = aux;  
 }

void HeapSortRegistro(Item *v, int n, int* compara, int* movimenta, float* tempo){
    clock_t inicio = clock();
    int i, aux;
    for (i = (n-1)/2; i >=0; i--)
    {
        criaHeapRegistro(v, i, n-1, compara, movimenta, tempo);
    }
    for (i = n-1; i >= 0; i--)
    {
        aux = v[0].Chave;
        v[0].Chave = v[i].Chave;
        v[i].Chave = aux;
        *movimenta = *movimenta+3;
        criaHeapRegistro(v, 0, i-1, compara, movimenta, tempo);
    } 
    clock_t fim = clock();
    *tempo = *tempo + (fim - inicio);
}
