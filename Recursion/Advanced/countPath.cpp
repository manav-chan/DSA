#include <iostream>
using namespace std;

int countsteps(int s, int e) // O(2^n)
{
    if(s == e)
    return 1;

    if(s > e)
    return 0;

    int count = 0;
    for(int i=1;i<=6;i++)
    count+= countsteps(s+i,e);

    return count;
}

int main()
{
    int s,e;
    cout<<"Enter starting and ending point\n";
    cin>>s>>e;
    cout<<countsteps(s-1,e-1);
    return 0;
}