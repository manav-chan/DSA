#include <stdio.h>
#define MAX 50
void binarySearch(int[], int, int);
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
		
		binarySearch(arr, n, key);
	}
	return 0;
}		

void binarySearch(int arr[], int n, int key)
{
	int low = 0, high = n-1, mid, flag = 0, count = 0;
	while(low <= high)
	{
		count++;
		mid = (low + high)/2;
		if(arr[mid] == key)
		{
			flag = 1;
			break;
		}
		else if(key < arr[mid])
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
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
