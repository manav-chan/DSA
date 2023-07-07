#include <iostream>
using namespace std;

int countMaze2d(int n, int i, int j) // O(2^n)
{
    if(i == n-1 && j == n-1)
    return 1;

    if(i > n-1 || j > n-1)
    return 0;

    return countMaze2d(n,i+1,j) + countMaze2d(n,i,j+1);
}

int main()
{
    int n;
    cout<<"Enter n\n";
    cin>>n;
    cout<<countMaze2d(n,0,0);
    return 0;
}