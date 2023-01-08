#include <stdio.h>
#include <string.h>


void count_sort(int* nums,int len) {
    // int size = nums.size();
    int i=0,max_val=0,max_negval=0;

    for(i=0;i < len;i++)         //1-compute the max neg value
        if (nums[i]<max_negval)
            max_negval = nums[i];
        
    max_negval = ~max_negval + 1;
    for(i=0;i<len;i++)         //1-compute the max value
        if (nums[i]>max_val)
            max_val = nums[i];

    max_val += max_negval;

        //2- compute frequency
    int count[max_val+1] ;
    memset(count, 0, (max_val+1)*sizeof(int));
    for (i=0;i<len;i++)
        count [(nums[i]+max_negval)]+=1;

    //3-put the sorted elements back in the array
    int idx=0,j;
    for(i=0;i<=max_val;i++)
        for(j=0;j< count[i];j++)
            nums[idx++] = i-max_negval;
            
        // return nums;
}

void main()
{

    int arr [] = {-6,-10,-15,0,5,4,3,10,1,30};
	count_sort(arr, sizeof(arr)/sizeof(int));
	
	int i=0;
	for (; i<sizeof(arr)/sizeof(int) ; i++)
	{
		printf("%d ",arr[i]);
	}
}
