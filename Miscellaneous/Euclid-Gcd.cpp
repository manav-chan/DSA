#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c=a%b;
    while(c != 0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}