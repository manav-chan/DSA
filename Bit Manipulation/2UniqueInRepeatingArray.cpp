#include <iostream>
using namespace std;

int checkBit(int a, int pos)
{
    return (a & 1<<pos);
}

void unique(int arr[], int n)
{
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum=xorsum ^ arr[i];
    }
    //cout<<xorsum<<endl;
    int pos=0, setbit=0, tempsum=xorsum;
    while(setbit != 1)
    {
        setbit= xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    pos=pos-1;
    int newxorsum=0;
    for(int i=0;i<n;i++)
    {
        if(checkBit(arr[i], pos))
        newxorsum = newxorsum ^ arr[i]; 
    }
    cout<<newxorsum<<","<<(newxorsum ^ tempsum)<<endl;
}

int main()
{
    int arr[8]={1,2,3,1,2,3,6,9};
    unique(arr,8);
    return 0;
}