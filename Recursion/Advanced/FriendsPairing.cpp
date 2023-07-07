#include <iostream>
using namespace std;

int Pairing(int n) // O(2^n)
{
    if(n == 0 || n == 1 || n == 2)
    return n;

    return Pairing(n-1) + Pairing(n-2)*(n-1); //single + paired
}

int main()
{
    int n;
    cout<<"Enter total people\n";
    cin>>n;
    cout<<Pairing(n)<<"\n";
    return 0;
}