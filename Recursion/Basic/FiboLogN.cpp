#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long Fibo(int n, long long t[])
{
    if(n == 0 || n == 1)
    return n;

    if(t[n] != -1)
    return t[n];

    if(n % 2 == 1)
    return t[n] = pow(Fibo((n+1)/2, t), 2) + pow(Fibo((n+1)/2, t), 2);
    else
    return t[n] = 2*(Fibo(n/2, t) * Fibo(n/2 - 1, t)) + pow(Fibo(n/2, t), 2);
}

int fib(int n)
{
    if(n==0 || n==1)
    return n;

    return fib(n-1) + fib(n-2);
}

int main()
{
    int num;
    cout<<"Enter number: ";
    cin>>num;
    long long t[num+1];
    memset(t, -1, sizeof(t));
    long long res = Fibo(num, t);
    cout<<"Result: "<<res<<endl;
    cout<<fib(num)<<endl;
    return 0;
}