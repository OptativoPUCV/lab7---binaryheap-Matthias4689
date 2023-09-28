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

}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap * newHeap = (Heap *) malloc(sizeof(Heap));
  newHeap->heapArray = (heapElem *) malloc(3*sizeof(heapElem));

  newHeap->capac = 3;
  newHeap->size = 0;
  
  return newHeap;
}
