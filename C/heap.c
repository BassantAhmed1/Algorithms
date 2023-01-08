#include <stdio.h>

#define Left(idx)     2*idx +1
#define Right(idx)    2*idx+2
#define Parent(idx)   idx/2

void swap (int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int * arr, int size , int i)
{
    int left = Left(i);
    int right = Right(i);
    int largest = i;
    
    if (left < size && arr[left]>arr[i])
    {
        largest = left;
        if (right < size &&arr[right]>arr[largest])
            largest=right;
    }
    else if (right < size && arr[right]>arr[i])
        largest = right;
        
    if (largest != i)
    {
        swap (&arr[i], &arr[largest]);
        max_heapify(arr , size,largest);
    }
    
}

void min_heapify(int * arr, int size , int i)
{
    int left = Left(i);
    int right = Right(i);
    int smallest = i;
   
    if (left < size && arr[left]<arr[i])
    {
        smallest = left;
        if (right < size &&arr[right]<arr[smallest])
            smallest=right;
    }
    else if (right < size && arr[right]<arr[i])
        smallest = right;
        
    if (smallest != i)
    {
        swap (&arr[i], &arr[smallest]);
        max_heapify(arr , size,smallest);
    }
    
}

void build_max_heap (int *heap , int size )
{
    int i= size/2;
    for (;i>=0 ; i--)
        max_heapify(heap , size , i);
}

void heap_sort (int *arr , int size)
{
    int i=size-1;
    build_max_heap(arr , size);
    for (;i>0;i--)
    {
        swap (&arr[0],&arr[i]);
        size--;
        max_heapify(arr,size , 0);
    }
}
int main()
{
    int arr [] = {4,1,3,2,16,9,10,14,8,7};
    
    int i=0 , size = sizeof(arr)/sizeof(int);
    heap_sort(arr,size);
    for (;i<size;i++)
        printf("%d ",arr[i]);

    return 0;
}
