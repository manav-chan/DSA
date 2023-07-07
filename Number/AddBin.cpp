#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(int a, int b)
{
    string s="";
    int carr=0;
    while(a>0 && b>0)
    {
        if(a%2==0 && b&2==0)
        {
            s+=to_string(carr);
            carr=0;
        }
        else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0))
        {
            if(carr==1)
            {
            s+='0';
            carr=1;
            }
            else
            s+='1';
        }
        else
        {
            s+=to_string(carr);
            carr=1;
        }
        a/=10;
        b/=10;
    }
    while(a>0)
    {
        if(a%2==1)
        {
            if(carr==1)
            {
                s+='0';
                carr=1;
            }
            else
            s+=to_string(1);
        }
        else
        {
            s+=to_string(carr);
            carr=0;
        }
        a/=10;
    }
    while(b>0)
    {
        if(b%2==1)
        {
            if(carr==1)
            {
                s+='0';
                carr=1;
            }
            else
            s+='1';
        }
        else
        {
            s+=to_string(carr);
            carr=0;
        }
        b/=10;
    }
    if(carr==1)
    s+='1';
    reverse( s.begin(), s.end() );
    return s;
}

int main()
{
    int a,b;
    cout<<"Enter 2 binary numbers\n";
    cin>>a>>b;
    cout<<add(a,b)<<endl;
    return 0;
}