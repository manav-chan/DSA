#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if((n & (n-1)) != 0)
    {
        cout<<"Not Power"<<endl;
        return 0;
    }
    int c=0;
    while (n>1)
    {
        n = n >> 1;
        c++;
    }
    if (c%2 == 0)
    {
        cout<<"Power of 4"<<endl;
        return 1;
    }
    else 
    {
        cout<<"Not power"<<endl;
        return 0;
    }
}