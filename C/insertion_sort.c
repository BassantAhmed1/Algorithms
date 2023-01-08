#include <stdio.h>

void swap (int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort (int* arr,int len)      //O(n2) time complixity  //O(1)  space
{
    // int i=1 , j=0 , key=0;
    // for (;i<len;i++)          //O(n)
    // {
    //     Key = arr[i];
    //     j=i-1;
    //     while (j>=0 && arr[j]>key)                  //O(n)
    //     {
    //         arr[j+1] = arr[j];
    //         j--;
    //     }
    //     arr[j+1]=key;
    // }

    /*optimized function*/

    int i=1 , j=0 ;
    for (;i<len;i++) 
        for (j=i;j>0 && arr[j]<arr[j-1];j--)
            swap(&arr[j],&arr[j-1]);
}

void main()
{

    int arr [] = {20,30,10,5,40,60,50,55,30};
	insertion_sort(arr, sizeof(arr)/sizeof(int));
	
	int i=0;
	for (; i<sizeof(arr)/sizeof(int) ; i++)
	{
		printf("%d ",arr[i]);
	}
}
