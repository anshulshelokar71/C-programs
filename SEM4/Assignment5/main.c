#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 2048

typedef struct heap
{
    int *arr;
    int heapSize;
    int maxSize;
} Heap;

int parent(int i)
{
    return (i - 1) / 2;
}

int lChild(int i)
{
    return (2 * i + 1);
}

int rChild(int i)
{
    return (2 * i + 2);
}

Heap* init_heap(int n){
    Heap*heap = (Heap*)malloc(sizeof(Heap));
    heap->arr=(int *)malloc(sizeof(int)*n);
    heap->heapSize=0;
    heap->maxSize=n;
    return heap;
}

void maxHeapify(Heap*heap, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l < heap->heapSize && heap->arr[l] > heap->arr[largest])
    {
        largest = l;
    }
    if (r < heap->heapSize && heap->arr[r] > heap->arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[largest];
        heap->arr[largest] = temp;
        maxHeapify(heap, largest);
    }
    
}
void minHeapify(Heap*heap, int i)
{
    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l < heap->heapSize && heap->arr[l] < heap->arr[smallest])
    {
        smallest = l;
    }
    if (r < heap->heapSize && heap->arr[r] < heap->arr[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        minHeapify(heap, smallest);
    }
    
}
Heap* create_maxHeap(Heap*heap){
    for(int i = heap->heapSize/2-1;i>=0;i--){
        maxHeapify(heap,i);
    }
    return heap;
}

Heap* create_minHeap(Heap*heap){
    for(int i = heap->heapSize/2-1;i>=0;i--){
        minHeapify(heap,i);
    }
    return heap;
}

Heap* Sort_maxHeap(Heap*heap){
    create_maxHeap(heap);
    int originalSize = heap->heapSize;

    for (int i = originalSize - 1; i > 0; i--) {
        int temp = heap->arr[0];
        heap->arr[0] = heap->arr[i];
        heap->arr[i] = temp;
        heap->heapSize--;
        maxHeapify(heap, 0);
    }

    heap->heapSize = originalSize;
    return heap;
}

Heap* Sort_minHeap(Heap*heap){
    create_minHeap(heap);
    int originalSize = heap->heapSize;

    for (int i = originalSize - 1; i > 0; i--) {
        int temp = heap->arr[0];
        heap->arr[0] = heap->arr[i];
        heap->arr[i] = temp;
        heap->heapSize--;
        minHeapify(heap, 0);
    }

    heap->heapSize = originalSize;
    return heap;
}


void insertKey(Heap*heap,int x) { 

        if (heap->heapSize == heap->maxSize) { 
            printf("\nOverflow: Could not insertKey\n"); 
            return; 
        } 
  

        heap->heapSize++; 
        int i = heap->heapSize - 1; 
        heap->arr[i] = x; 
   
    } 

void display(Heap *heap){
    for(int i =0;i<heap->heapSize;i++){
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}

int main(){

    printf("Enter the number of elements:");
    int n;
    scanf("%d",&n);
    Heap* h=init_heap(n);
    srand(time(0));
    for(int i = 0;i<n;i++){
        insertKey(h,rand()%100);
    }
    int c;
    printf("Enter 1 for max heap\n");
    printf("Enter 2 for min heap\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        h=Sort_maxHeap(h);
        display(h); 
        break;
    case 2:
        h=Sort_minHeap(h);
        display(h);
        break;
    default:
        break;
    }


    return 0;
}