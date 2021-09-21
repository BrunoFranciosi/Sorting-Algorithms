/***********************************************************************************
    Author:    Bruno Franciosi
    Program:   Selection Sort.
            Selection sort is noted for its simplicity, and also has performance
            advantages over more complicated algorithms in certain situations.
            The algorithm finds the minimum value, swaps it with the value in the
            first position, and repeats these steps for the remainder of the list.
            It does no more than n swaps, and thus is useful where swapping is very expensive.
************************************************************************************/

#include <stdio.h>

#define maxArray 10

void showArray(int A[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int V[], int size){
    int posord, smaller, possmaller, aux;

    for(posord = 0; posord < size-1; posord++){
        smaller = V[posord];
        possmaller = posord;

        for(int i = posord+1; i < size; i++){
            if(V[i] < smaller){
                smaller = V[i];
                possmaller = i;
           }
        }
        aux = V[posord];
        V[posord] = smaller;
        V[possmaller] = aux;
    }
}

int main(){
    int Array[maxArray];

    for(int i = 0; i < maxArray; i++){
        printf("Array[%d] = ", i+1);
        scanf("%d", &Array[i]);
    }

    printf("\nArray Before Selection Sort\n");
    showArray(Array, maxArray);
    selectionSort(Array, maxArray);
    printf("\nArray After Selection Sort\n");
    showArray(Array, maxArray);

    return 0;
}