#include <iostream>
using namespace std;

char nextAlphab(char arr[], int n, char key)
{
    int start = 0, end = n-1;
    char res = '#';
    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid] == key)
        start = mid+1;

        else if(arr[mid] < key)
        start = mid+1;

        else if(arr[mid] > key)
        {
            res = arr[mid];
            end = mid-1;
            if(end >= start && arr[end] < key)
            break;
        }
    }
    return res;
}

int main()
{
    char arr[] = {'a','b','c','e','e','e','g'};
    int n = sizeof(arr)/sizeof(arr[0]);
    char key = 'e';

    cout<<nextAlphab(arr,n,key)<<"\n";
    return 0;
}