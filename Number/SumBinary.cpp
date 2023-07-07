#include <iostream>
#include <math.h>
using namespace std;

int bin_dec(int n)
{
    int ans = 0, i = 0;
    while(n != 0)
    {
        int d = n % 10;
        ans+= d * pow(2,i++);
        n/= 10;
    }
    return ans;
}

int DecToBin(int n)
{
    int a;
    int ans=0;
    int i;
    for(i=0;pow(2,i)<=n;i++)
    {   
        continue;
    }
    i=i-1;
    while(i>=0)
    {
        a=pow(2,i);
        ans=ans*10+n/a;
        n=n%a;
        i--;
    }
    return ans;
}

int main()
{
    int a,b;
    cout<<"Enter 2 binary numbers\n";
    cin>>a>>b;
    //cout<<bin_dec(a)<<" "<<bin_dec(b);
    int sum = bin_dec(a) + bin_dec(b);
    cout<<"Sum :"<<DecToBin(sum)<<endl;
    return 0;
}