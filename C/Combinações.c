// Lista de elementos: 0 0 1 1 2 2 2 3 3 4 4 4 5 5 5 6 6 7 8 9

#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 100

/**
 * @brief Funcao auxiliar para gerar combinacoes.
 * 
 * @param arr Vetor de elementos.
 * @param data Vetor de dados temporarios.
 * @param start Indice de inicio.
 * @param end Indice final.
 * @param index Indice atual.
 * @param r Tamanho da combinacao.
 * @param fp Ponteiro para arquivo.
 */
void combinationUtil(int arr[], int data[], int start, int end, int index, int r, FILE *fp){
    if (index == r){
        for (int j=0; j<r; j++)
            fprintf(fp, "%d ", data[j]);
        fprintf(fp, "\n");
        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++){
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r, fp);
    }
}

/**
 * @brief Funcao para imprimir combinacoes.
 * 
 * @param arr Vetor de elementos.
 * @param n Tamanho do vetor de elementos.
 * @param r Tamanho da combinacao.
 * @param fp Ponteiro para arquivo.
 */
void printCombination(int arr[], int n, int r, FILE *fp){
    int data[r];

    combinationUtil(arr, data, 0, n-1, 0, r, fp);
}

/**
 * @brief Funcao principal.
 * 
 * @return int 
 */
int main(){
    int arr[MAX_ELEMENTS];
    int n, r;
    FILE *fp;

    fp = fopen("combinations.txt", "w");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    printf("Digite os elementos: ");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Digite o tamanho da combinacao: ");
    scanf("%d", &r);

    printf("Todas as combinacoes possiveis: \n");
    printCombination(arr, n, r, fp);

    fclose(fp);
    return 0;
}