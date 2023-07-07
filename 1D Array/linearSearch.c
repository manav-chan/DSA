#include <stdio.h>
#define MAX 50

int main()
{
	int arr[MAX], n, t, i, key, flag = 0, count;
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
		
		count = 0;
		flag = 0;
		for(i=0; i<n; i++)
		{
			count++;
			if(arr[i] == key)
			{
				flag = 1;
				break;
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
	return 0;
}		
