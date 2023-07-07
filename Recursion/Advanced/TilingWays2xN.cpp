#include <iostream>
using namespace std;

int Tiling(int n, int i) //Correct
{
    if(i == n-1)
    return 1;

    if(i == n-2)
    return 2;

    if(i > n-1)
    return 0;

    return Tiling(n,i+1) + Tiling(n,i+2);
}

int Tilingdidi(int n) //Fibonacci
{
    if(n==0 || n==1)
    return n;

    return Tilingdidi(n-1) + Tilingdidi(n-2);
}

int main()
{
    int n;
    cout<<"Enter columns\n";
    cin>>n;
    cout<<Tiling(n,0)<<"\n";
    cout<<Tilingdidi(n)<<"\n";
    return 0;
}