#include <iostream>
using namespace std;

int Knapsack(int value[], int weights[], int n, int W) // returns maximum value ; O(2^n)
{
    if(n == 0 || W == 0)
    return 0;

    if(weights[n-1] > W)
    return Knapsack(value,weights,n-1,W);

    return max(Knapsack(value,weights,n-1,W-weights[n-1])+value[n-1] , Knapsack(value,weights,n-1,W));
}

int main()
{
    int n,w;

    cout<<"Enter number of items\n";
    cin>>n;

    int value[n],weights[n];

    cout<<"Enter values\n";
    for(int i=0;i<n;i++)
    cin>>value[i];

    cout<<"Enter weights\n";
    for(int i=0;i<n;i++)
    cin>>weights[i];

    cout<<"Enter total capacity\n";
    cin>>w;

    cout<<Knapsack(value,weights,n,w)<<"\n";
    
    return 0;
}