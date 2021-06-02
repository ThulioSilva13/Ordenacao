#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cenario1.h"
#include "cenario2.h"
#include <time.h>
void criaVetInt(int* vetor, int tamanho);
void criaVetRegistro(Item* vetor, int tamanho);
int main(){
    
    //declaração de variáveis
    int tamanho, i, escolha, tipoVet,compara=0, movimenta=0;
    float tempo=0;
    int mediacompara, mediaMovimenta;
    float mediaTempo;
    FILE *arquivo;
    char arq[20];

    // leitura do tamanho do vetor
    printf("Digite o tamanho: ");
    scanf("%d",&tamanho);

    // leitura de qual é o cenario desejado
    printf("digite o tipo de vetor desejado: \n");
    printf("1 - vetor de inteiros\n");
    printf("2 - vetor de registro\n");
    scanf("%d", &tipoVet);

    //declaração dos vetores
    int *vetor;
    Item *vet;
    if(tipoVet == 1){
        vetor = (int *) malloc(sizeof(int) * tamanho);
    }else{
        vet = (Item *) malloc(sizeof(Item) * tamanho);
    }
    // leitura do método de ordenação desejado
    printf("digite o método desejado:\n");
    printf("1 - Bolha\n");
    printf("2 - Seleção\n");
    printf("3 - Inserção\n");
    printf("4 - ShellSort\n");
    printf("5 - QuickSort\n");
    printf("6 - MergeSort\n");
    printf("7 - HeapSort\n");
    scanf("%d", &escolha);

    // métodos de oredenação sendo executados
    if(escolha == 1){
        //chama o bolha
        printf("------------\n");
        printf("Método bolha\n");
        printf("------------\n");
        for(i=0; i<5; i++){
            if(tipoVet == 1){
                criaVetInt(vetor, tamanho);
                BolhaInt(vetor, tamanho, &compara, &movimenta, &tempo);
            }else{
                criaVetRegistro(vet, tamanho);
                BolhaRegistro(vet, tamanho, &compara, &movimenta, &tempo);
            }
        }
    }else if(escolha == 2){
        //chama o Seleção
        printf("--------------\n");
        printf("Método selecao\n");
        printf("--------------\n");
        for(i=0; i<5; i++){
            if(tipoVet == 1){
                criaVetInt(vetor, tamanho);
                SelecaoInt(vetor, tamanho, &compara, &movimenta, &tempo);
            }else{
                criaVetRegistro(vet, tamanho);
                SelecaoRegistro(vet, tamanho, &compara, &movimenta, &tempo);
            }
        }    
    }else if(escolha == 3){
        //chama o inserção
        printf("--------------\n");
        printf("Método isercao\n");
        printf("--------------\n");
        for(i=0; i<5; i++){
            if(tipoVet == 1){
                criaVetInt(vetor, tamanho);
                InsercaoInt(vetor, tamanho, &compara, &movimenta, &tempo);
            }else{
                criaVetRegistro(vet, tamanho);
                InsercaoRegistro(vet, tamanho, &compara, &movimenta, &tempo);
            }
        }
    }else if(escolha == 4){
        //chama o Shellsort
        printf("-----------------\n");
        printf("Método ShellSort\n");
        printf("-----------------\n");
        for(i=0; i<5; i++){
            if(tipoVet == 1){
                criaVetInt(vetor, tamanho);
                ShellSortInt(vetor, tamanho, &compara, &movimenta, &tempo);
            }else{
                criaVetRegistro(vet, tamanho);
                ShellSortRegistro(vet, tamanho, &compara, &movimenta, &tempo);
            }
        }
    }else if(escolha == 5){
        //chama o QuickSort
        printf("-----------------\n");
        printf("Método QuickSort\n");
        printf("-----------------\n");
        for(i=0; i<5; i++){
            if(tipoVet == 1){
                criaVetInt(vetor, tamanho);
                QuickSortInt(vetor, tamanho, &compara, &movimenta, &tempo);
            }else{
                criaVetRegistro(vet, tamanho);
                QuickSortRegistro(vet, tamanho, &compara, &movimenta, &tempo);
            }
        }
    }else if(escolha == 6){
        //chama o MergeSort
        printf("----------------\n");
        printf("Método MergeSort\n");
        printf("----------------\n");
        for(i=0; i<5; i++){
            if(tipoVet == 1){
                criaVetInt(vetor, tamanho);
                MergeSortInt(vetor, 0, tamanho, &compara, &movimenta, &tempo);
            }else{
                criaVetRegistro(vet, tamanho);
                MergeSortRegistro(vet, 0, tamanho, &compara, &movimenta, &tempo);
            }
        }
    }else if(escolha == 7){
        //chama o HeapSort
        printf("---------------\n");
        printf("Método HeapSort\n");
        printf("---------------\n");
        for(i=0; i<5; i++){
            if(tipoVet == 1){
                criaVetInt(vetor, tamanho);
                HeapSortInt(vetor, tamanho, &compara, &movimenta, &tempo);
            }else{
                criaVetRegistro(vet, tamanho);
                HeapSortRegistro(vet, tamanho, &compara, &movimenta, &tempo);
            }
        }
    }
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ",vetor[i]);
    }
    printf("\n");
    printf("Numero de comparacoes: %d\n",compara/5);
    printf("Numero de movimentacoes: %d\n", movimenta/5);
    printf("%.2f\n",tempo/5);
    
    //calculo das médias
    mediacompara = compara/5;
    mediaMovimenta = movimenta/5;
    mediaTempo = tempo/5;

    // escrita no arquivo
    printf("digite o nome do arquivo: ");
    scanf("%s", arq);
    arquivo = fopen(arq, "a");
    if (arquivo == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
    }else{
        printf("O arquivo foi aberto com sucesso!\n");
    }
    if(escolha == 1){
        fprintf(arquivo, "Bolha\n");
    }else if(escolha == 2){
        fprintf(arquivo, "Selecao\n");
    }else if(escolha == 3){
        fprintf(arquivo, "Insercao\n");
    }else if(escolha == 4){
        fprintf(arquivo, "Shellsort\n");
    }else if(escolha == 5){
        fprintf(arquivo, "Quicksort\n");
    }else if(escolha == 6){
        fprintf(arquivo, "Mergesort\n");
    }else if(escolha == 7){
        fprintf(arquivo, "Heapsort\n");
    }

    fprintf(arquivo, "tamanho: %d\n", tamanho);
    fprintf(arquivo, "media de comparacao: %d\n", mediacompara);
    fprintf(arquivo, "media de movimentacao: %d\n", mediaMovimenta);
    fprintf(arquivo, "media de tempo: %f\n", mediaTempo);
    fprintf(arquivo, "\n");
    return 0;
}

// função para criar vetor de inteiros
void criaVetInt(int* vetor, int tamanho){
    int i;
    srand(time(NULL));
    for(i=0; i<tamanho; i++){
        vetor[i] = rand()%tamanho;
    }
}

//função para cria vetor de registros
void criaVetRegistro(Item* vetor, int tamanho){
    int i, j;
    srand(time(NULL));
    for(i=0; i<tamanho; i++){
        vetor[i].valor1 = rand()%tamanho;
        vetor[i].valor2 = rand()%tamanho;
        vetor[i].valor3 = rand()%tamanho;
        vetor[i].valor4 = rand()%tamanho;
        vetor[i].Chave = rand()%tamanho;
        for(j=0; j<200; j++){
            vetor[i].caracter1[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter2[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter3[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter4[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter5[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter6[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter7[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter8[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter9[j] = 'a' + (char)(rand()%26);
            vetor[i].caracter10[j] = 'a' + (char)(rand()%26);
        }
    }
}