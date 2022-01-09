/***********************************************************************************
    Author:    Bruno Franciosi
    Program:   Heap Sort.
            Heapsort is a much more efficient version of selection sort. It also works
            by determining the largest (or smallest) element of the list, placing that
            at the end (or beginning) of the list, then continuing with the rest of
            the list, but accomplishes this task efficiently by using a data structure
            called a heap, a special type of binary tree. Once the data list has been
            made into a heap, the root node is guaranteed to be the largest
            (or smallest) element. When it is removed and placed at the end of the
            list, the heap is rearranged so the largest element remaining moves to the root.
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
/* Private Functions for HeapSort */
int indiceFilhoEsquerda(int indice){
    return 2 * indice + 1;
}

int indiceFilhoDireita(int indice){
    return 2 * indice + 2;
}

void remodelMaxHeap(int V[], int size, int indice){
   int maior, posMaior, aux, indiceFEsq, indiceFDir;

   maior = V[indice];
   posMaior = indice;
    
   indiceFEsq = indiceFilhoEsquerda(indice);
   indiceFDir = indiceFilhoDireita(indice);

   if (indiceFEsq  < size){
      if (V[indiceFEsq] > maior){
            maior = V[indiceFEsq];
            posMaior = indiceFEsq;
      }
      if (indiceFDir < size){
         if (V[indiceFDir] > maior){
                maior = V[indiceFDir];
                posMaior = indiceFDir;
         }
      }
   }
   if (posMaior != indice){
      aux = V[indice];
      V[indice] = maior;
      V[posMaior] = aux;

      remodelMaxHeap(V, size, posMaior);
    }
}

void criaMaxHeap(int V[], int size){    
   for (int i = (size - 2)/2; i > -1; i--){
      remodelMaxHeap(V, size, i);
    }
}
/*--------------------------------------------------------*/

void heapSort(int V[], int size){
   int aux;

   criaMaxHeap(V, size);

   for (int i = size - 1; i > 0; i--){
      aux = V[i];
      V[i] = V[0];
      V[0] = aux;
      remodelMaxHeap(V, i, 0);
   }   
}

int main(){
    int Array[maxArray];

    for(int i = 0; i < maxArray; i++){
        printf("Array[%d] = ", i+1);
        scanf("%d", &Array[i]);
    }

    printf("\nArray Before Heap Sort\n");
    showArray(Array, maxArray);
    heapSort(Array, maxArray);
    printf("\nArray After Heap Sort\n");
    showArray(Array, maxArray);

    return 0;
}