#include <stdio.h>
#include <math.h>
#define MAX 50


void jumpSearch(int[], int, int);
int linearSearch(int[], int, int, int, int*);

int main()
{
	int arr[MAX], n, t, i, key;
	printf("Enter number of test cases: ");
	scanf("%d", &t);
	
	while(t--)
	{
		printf("Enter size of array: ");
		scanf("%d", &n);
		printf("Enter array elements: ");

		for(i=0; i<n; i++)
			scanf("%d", &arr[i]);
		
		printf("Enter key: ");
		scanf("%d", &key);
		
		jumpSearch(arr, n, key);
	}
	return 0;
}		

void jumpSearch(int arr[], int n, int key)
{
	int blockSize = 2, start = 0, end = blockSize - 1, flag = 0, count = 0;
	while(start < n)
	{
		count++;
		if(end < n && arr[end] == key)
		{
			flag = 1;
			break;
		}
		else if(end < n && arr[end] > key)
		{
			if(linearSearch(arr, start, end, key, &count) == 1)
			{
				flag = 1;
			}
			break;
		}
		else
		{
			if(end >= n)
			{
				end = n-1;
				count--;
			}
			else
			{
				start = end + 1;
				end += blockSize;
			}
		}
	}
	if(flag == 1)
	{
		printf("Key found\nComparisons: %d\n\n", count);
	}
	else
	{
		printf("Key not found\nComparisons: %d\n\n", count);
	}
}

int linearSearch(int arr[], int start, int end, int key, int *count)
{
	int i;
	for(i=start; i<=end; i++)
	{
		(*count)++; 
		if(arr[i] == key)
			return 1;
	}
	return 0;
}
