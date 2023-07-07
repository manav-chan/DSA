#include <iostream>
#include <math.h>
#include <string>
using namespace std;

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

int DecToOct(int n)
{
    int a;
    int ans=0;
    int i;
    for(i=0;pow(8,i)<=n;i++)
    {   
        continue;
    }
    while(i>=0)
    {
        a=pow(8,i-1);
        ans=ans*10+n/a;
        n=n%a;
        i--;
        if(i-1==-1)
        break;
    }
    return ans;
}

string DectoHex(int n)
{
    string ans="";
    int i;
    for(i=0 ; pow(16,i)<=n ; i++)
    {
        continue;
    }
    i=i-1;
    while(i>=0)
    {
        int a=n/pow(16,i);
        n=n%a;
        if(a<=9)
        {
            ans=ans+ to_string(a);
        }
        else
        {
            ans=ans+ (char)('A'-10+a);
        }
        i--;
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter number\n";
    cin>>n;
    cout<<"Binary: "<<DecToBin(n)<<endl;
    cout<<"Octal: "<<DecToOct(n)<<endl;
    cout<<"Hexa: "<<DectoHex(n)<<endl;
    return 0;
}
