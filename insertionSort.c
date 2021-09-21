/***********************************************************************************
    Author:     Bruno Franciosi
    Program:    Insertion Sort.
            Insertion sort is a simple sorting algorithm that is 
            relatively efficient for small lists and mostly sorted lists.
            It works by taking elements from the list one by one and
            inserting them in their correct position into a new sorted list.
************************************************************************************/

#include <stdio.h>

#define maxArray 10

void showArray(int A[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int size){
    int lastOrd, aux, prev;

    for(lastOrd = 0; lastOrd < size-1; lastOrd++){
        aux = A[lastOrd+1];
        prev = lastOrd;

        while((prev >= 0) && (A[prev] > aux)){
            A[prev+1] = A [prev];
            prev--;
        }
        A[prev+1] = aux;
    }
}

int main(){
    int Array[maxArray];

    for(int i = 0; i < maxArray; i++){
        printf("Array[%d] = ", i+1);
        scanf("%d", &Array[i]);
    }

    printf("\nArray Before Insertion Sort\n");
    showArray(Array, maxArray);
    insertionSort(Array, maxArray);
    printf("\nArray After Insertion Sort\n");
    showArray(Array, maxArray);

    return 0;
}
