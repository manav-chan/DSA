#include <iostream>
using namespace std;

int updatebit(int a, int b, int c)
{
    if(c==1)
    setbit(a,b);
    else
    clearbit(a,b);
}

int clearbit(int a, int b)
{
    return (a & ~(1<<b));
}

int setbit(int a, int b)
{
    return (a | (1<<b));
}

int getbit(int a, int b)
{
    return ((a & (1<<b)) != 0); 
}

int main()
{
    int n,a;
    cout<<"Enter number\n";
    cin>>n;
    cout<<"Enter index\n";
    cin>>a;
    cin>>c;
    //cout<<getbit(n,a)<<endl;
    //cout<<setbit(n,a)<<endl;
    cout<<clearbit(n,a)<<endl;
    cout<<updatebit(n,a,c)<<endl;
    return 0;
}