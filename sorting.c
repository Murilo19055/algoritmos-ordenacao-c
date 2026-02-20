#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para imprimir o array
void printArray(int v[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// ================= BUBBLE SORT =================
void bubbleSort(int v[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// ================= SELECTION SORT =================
void selectionSort(int v[], int n) {
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++) {
        min = i;

        for(j = i + 1; j < n; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }

        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}

// ================= INSERTION SORT =================
void insertionSort(int v[], int n) {
    int i, j, key;

    for(i = 1; i < n; i++) {
        key = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

// ================= QUICK SORT =================
int partition(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    int j, temp;

    for(j = inicio; j < fim; j++) {
        if(v[j] < pivo) {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

void quickSort(int v[], int inicio, int fim) {
    if(inicio < fim) {
        int pos = partition(v, inicio, fim);
        quickSort(v, inicio, pos - 1);
        quickSort(v, pos + 1, fim);
    }
}

// ================= MERGE SORT =================
void merge(int v[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esquerda[n1], direita[n2];

    for(i = 0; i < n1; i++)
        esquerda[i] = v[inicio + i];

    for(j = 0; j < n2; j++)
        direita[j] = v[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while(i < n1 && j < n2) {
        if(esquerda[i] <= direita[j]) {
            v[k] = esquerda[i];
            i++;
        } else {
            v[k] = direita[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        v[k] = esquerda[i];
        i++;
        k++;
    }

    while(j < n2) {
        v[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int inicio, int fim) {
    if(inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

// ================= SHELL SORT =================
void shellSort(int v[], int n) {
    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap = gap/2) {
        for(i = gap; i < n; i++) {
            temp = v[i];
            j = i;

            while(j >= gap && v[j-gap] > temp) {
                v[j] = v[j-gap];
                j = j - gap;
            }

            v[j] = temp;
        }
    }
}

// ================= MAIN =================
int main() {
    int n = 10;
    int vetor[10];
    int i, opcao;

    srand(time(NULL));

    // Preenchendo com números aleatórios
    for(i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor original:\n");
    printArray(vetor, n);

    printf("\nEscolha o algoritmo:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Quick Sort\n");
    printf("5 - Merge Sort\n");
    printf("6 - Shell Sort\n");
    scanf("%d", &opcao);

    clock_t inicio = clock();

    if(opcao == 1)
        bubbleSort(vetor, n);
    else if(opcao == 2)
        selectionSort(vetor, n);
    else if(opcao == 3)
        insertionSort(vetor, n);
    else if(opcao == 4)
        quickSort(vetor, 0, n-1);
    else if(opcao == 5)
        mergeSort(vetor, 0, n-1);
    else if(opcao == 6)
        shellSort(vetor, n);
    else {
        printf("Opcao invalida!\n");
        return 0;
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nVetor ordenado:\n");
    printArray(vetor, n);

    printf("\nTempo de execucao: %f segundos\n", tempo);

    return 0;
}
