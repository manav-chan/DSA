#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char dest, char help) //O(2^n)
{
    if(n == 0)
    return;
    
    TowerOfHanoi(n-1,source,help,dest);
    cout<<"Move from "<<source<<" to "<<dest<<"\n";
    TowerOfHanoi(n-1,help,dest,source);
}

int main()
{
    TowerOfHanoi(3,'A','C','B');
    return 0;
}