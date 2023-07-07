#include <stdio.h>

void rotate(int arr[], int n, int k)
{
    int help[n];
    for(int i=0;i<n;i++)
    help[i] = arr[i];

    for(int i=0; i<n; i++)
    {    
        if(i >= k)
        arr[i] = help[i-k];

        else
        arr[i] = help[n-k+i];
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    rotate(arr,n,k);
    printf("Rotated Array: ");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);

    return 0;
}