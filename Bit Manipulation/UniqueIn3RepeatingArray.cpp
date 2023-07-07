#include <iostream>
using namespace std;

int getBit(int a, int pos)
{
    return (a & 1<<pos);
}

int setBit(int a, int pos)
{
    return (a | (1<<pos));
}

int unique(int arr[], int n)
{
    int result=0;
    for(int i=0;i<64;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(getBit(arr[j], i))
            sum++;
        }
        if(sum % 3 !=0)
        result = setBit(result, i);
    }
    return result;
}

int main()
{
    int arr[10]={5,5,5,6,9,6,6,7,7,7};
    cout<<unique(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}