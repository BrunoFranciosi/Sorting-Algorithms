/***********************************************************************************
    Author:    Bruno Franciosi
    Program:   Shell Sort.
            Shellsort improves upon insertion sort by moving out of order elements
            more than one position at a time. So, by first sorting elements far
            away, and progressively shrinking the gap between the elements to sort,
            the final sort computes much faster. One implementation can be described
            as arranging the data sequence in a two-dimensional array and then
            sorting the columns of the array using insertion sort.
************************************************************************************/

#include <stdio.h>

#define maxArray 10

void showArray(int A[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void shellSort(int A[], int size){
    int lastOrd, aux, prev, desl;

    desl = size/2;
    while(desl > 0){
        for(lastOrd = 0; lastOrd < size-desl; lastOrd++){
            aux = A[lastOrd + desl];
            prev = lastOrd;

            while((prev >= 0) && (A[prev] > aux)){
                A[prev + desl] = A[prev];
                prev = prev - desl;
            }
            A[prev + desl] = aux;
        }
        desl = desl/2;
    }
}

int main(){
    int Array[maxArray];

    for(int i = 0; i < maxArray; i++){
        printf("Array[%d] = ", i+1);
        scanf("%d", &Array[i]);
    }

    printf("\nArray Before Shell Sort\n");
    showArray(Array, maxArray);
    shellSort(Array, maxArray);
    printf("\nArray After Shell Sort\n");
    showArray(Array, maxArray);

    return 0;
}