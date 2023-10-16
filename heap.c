#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->size == 0) return NULL;
  
  return pq->heapArray->data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq == NULL) return;
  if (data == NULL) return;
  if (priority < 0) return;

  if (pq->size == pq->capac){
    pq->capac = pq->capac * 2+1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));  
  }

  int k = pq->size;
  pq->heapArray[k].data = data;
  pq->heapArray[k].priority = priority;

  while (k > 0){
    int padre = (k - 1) / 2;
    if (priority > pq->heapArray[padre].priority){
      heapElem aux = pq->heapArray[k];
      pq->heapArray[k] = pq->heapArray[padre];
      pq->heapArray[padre] = aux;
      k = padre;
    }
    else break;
  }

  pq->size++;
}

void heapify_down(Heap* pq, int k){
  int hijoIzq = 2 * k + 1;
  int hijoDer = 2 * k + 2;
  int maxIndice = k;

  if (hijoIzq < pq->size && pq->heapArray[hijoIzq].priority > pq->heapArray[maxIndice].priority) maxIndice = hijoIzq;

  if (hijoDer < pq->size && pq->heapArray[hijoDer].priority > pq->heapArray[maxIndice].priority) maxIndice = hijoDer;

  if (maxIndice != k){
    heapElem aux = pq->heapArray[k];
    pq->heapArray[k] = pq->heapArray[maxIndice];
    pq->heapArray[maxIndice] = aux;

    heapify_down(pq, maxIndice); 
  }
}

void heap_pop(Heap* pq){
  if (pq->size <= 0) return;

  pq->heapArray[0] = pq->heapArray[pq->size-1];
  heapify_down(pq, 0);
  
  if(pq->capac > 3 && pq->size < pq->capac / 2){
    pq->capac /= 2;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }
}


Heap* createHeap()
{
  Heap * newHeap = (Heap *) malloc(sizeof(Heap));
  newHeap->heapArray = (heapElem *) malloc(3*sizeof(heapElem));

  newHeap->capac = 3;
  newHeap->size = 0;
  
  return newHeap;
}
