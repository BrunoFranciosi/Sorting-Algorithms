/***********************************************************************************
    Author:     Bruno Franciosi
    Program:    Merge Sort.
            Merge sort takes advantage of the ease of merging already sorted lists
            into a new sorted list. It starts by comparing every
            two elements (i.e., 1 with 2, then 3 with 4...) and swapping them if the
            first should come after the second. It then merges each of the resulting
            lists of two into lists of four, then merges those lists of four, and so on;
            until at last two lists are merged into the final sorted list.
************************************************************************************/

#include <stdio.h>

#define maxArray 10

void showArray(int A[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

/*--------------------------------------------------------*/
/* Private functions for MergeSort */
void merge(int V[], int start, int half, int end){
    int A1[maxArray], A2[maxArray];
    int tam1 = 0, tam2 = 0, i, j, k, biggest;

    for (i = start; i < half + 1; i++)
        A1[tam1++] = V[i];    

    for (i = half + 1; i < end + 1; i++)
        A2[tam2++] = V[i];
    
    biggest = abs(A1[tam1-1]) + abs(A2[tam2-1]) + 1;

    A1[tam1] = biggest;
    A2[tam2] = biggest;

    i = j = 0;

    for (k = start; k < end + 1; k++)
        if (A1[i] < A2[j])
            V[k] = A1[i++];
        else
            V[k] = A2[j++];
            
}

void _mergeSort(int V[], int start, int end){   
    int half;

    if (end - start > 0){
        half = (start + end)/2;

        _mergeSort(V, start, half);

        _mergeSort(V, half+1, end);

        merge(V, start, half, end);
    }
}
/*--------------------------------------------------------*/

void mergeSort(int V[], int size){
    _mergeSort(V, 0, size-1);
}

int main(){
    int Array[maxArray];

    for(int i = 0; i < maxArray; i++){
        printf("Array[%d] = ", i+1);
        scanf("%d", &Array[i]);
    }

    printf("\nArray Before Merge Sort\n");
    showArray(Array, maxArray);
    mergeSort(Array, maxArray);
    printf("\nArray After Merge Sort\n");
    showArray(Array, maxArray);

    return 0;
}