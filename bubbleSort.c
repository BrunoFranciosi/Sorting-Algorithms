/***********************************************************************************
    Author:    Bruno Franciosi
    Program:   Bubble Sort.
            Bubble sort is a simple sorting algorithm. The algorithm starts at the
            beginning of the data set. It compares the first two elements, and if the 
            first is greater than the second, it swaps them. It continues doing this
            for each pair of adjacent elements to the end of the data set. It then
            starts again with the first two elements, repeating until no swaps have
            occurred on the last pass.
************************************************************************************/

#include <stdio.h>

#define maxArray 10

void showArray(int A[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int size){
    int lastOrd, next, aux;

    for(lastOrd = size-1; lastOrd > 0; lastOrd--){
        for(next = 0; next < lastOrd; next++){
            if(A[next] > A[next+1]){
                aux = A[next];
                A[next] = A[next+1];
                A[next+1] = aux;
            }
        }
    }
}

int main(){
    int Array[maxArray];

    for(int i = 0; i < maxArray; i++){
        printf("Array[%d] = ", i+1);
        scanf("%d", &Array[i]);
    }

    printf("\nArray Before Bubble Sort\n");
    showArray(Array, maxArray);
    bubbleSort(Array, maxArray);
    printf("\nArray After Bubble Sort\n");
    showArray(Array, maxArray);

    return 0;
}