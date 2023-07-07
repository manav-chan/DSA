#include <iostream>
#include <math.h>
using namespace std;

int kthSymbol(int n, int k)
{
    if(n==1 && k==1)
    return 0;

    int mid = pow(2,n-1)/2;
    if(k <= mid)
    return kthSymbol(n-1,k);
    else
    return kthSymbol(n-1,k-mid);
}

int main()
{
    int n,k;
    n = 4, k = 6;
    cout<<kthSymbol(n,k)<<"\n";
    return 0;
}
/*
0
0 1
0 1 1 0
0 1 1 0 1 0 0 1

if 0 then 0 1, if 1 then 1 0, 1 indexing, if n and k are 1 then 0
*/