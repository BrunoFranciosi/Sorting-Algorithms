/***********************************************************************************
    Author:    Bruno Franciosi
    Program:   Quick Sort.
            Quicksort is a divide and conquer algorithm which relies on a partition
            operation: to partition an array, an element called a pivot is selected.
            All elements smaller than the pivot are moved before it and all greater
            elements are moved after it. This can be done efficiently in linear
            time and in-place. The lesser and greater sublists are then recursively sorted.
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
/* Private Functions for QuickSort */
void particiona(int V[], int start, int end, int *posDivisor){
   int divisor, i, aux, meio;

   meio = (start + end) / 2;

   aux = V[end];
   V[end] = V[meio];
   V[meio] = aux;


   divisor = V[end];
   *posDivisor = start;


   for (i = start; i < end; i++){
      if (V[i] < divisor){
         aux = V[i];
         V[i] = V[*posDivisor];
         V[*posDivisor] = aux;
         (*posDivisor)++;
      }
   }
 
   V[end] = V[*posDivisor];
   V[*posDivisor] = divisor;
}

void _quickSort(int V[], int start, int end){
   int posDivisor;

   if (end > start){
      particiona(V, start, end, &posDivisor);
              
      _quickSort(V, start, posDivisor - 1);
              
      _quickSort(V, posDivisor + 1, end);
    }
}
/*--------------------------------------------------------*/

void quickSort(int V[], int size){
   _quickSort(V, 0, size - 1);
}

int main(){
    int Array[maxArray];

    for(int i = 0; i < maxArray; i++){
        printf("Array[%d] = ", i+1);
        scanf("%d", &Array[i]);
    }

    printf("\nArray Before Quick Sort\n");
    showArray(Array, maxArray);
    quickSort(Array, maxArray);
    printf("\nArray After Quick Sort\n");
    showArray(Array, maxArray);

    return 0;
}