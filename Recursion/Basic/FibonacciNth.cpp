#include <iostream>
using namespace std;

int fibonacci1(int n)
{
    if(n==1 || n==0)
    return n;
    return fibonacci1(n-1) + fibonacci1(n-2);
}

int fibonacci2(int a, int b, int n)
{
    if(n==2)
    return (b);
    fibonacci2(b, (a+b), (n-1));
}

int main()
{
    int n;
    cout<<"Enter n\n";
    cin>>n;
    cout<<fibonacci1(n)<<endl;
    cout<<fibonacci2(0,1,n)<<endl;
    return 0;
}