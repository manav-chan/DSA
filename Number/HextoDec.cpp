#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    string s;
    int x=0;
    int ans=0;
    cout<<"Enter Hexadecimal\n";
    cin>>s;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            ans+=(s[i]-'0')*pow(16,x);
            x++;
        }
        else if(s[i]>='A' && s[i]<='F')
        {
            ans+=(s[i]+10-'A')*pow(16,x);
            x++;
        }
    }
    cout<<"Decimal: "<<ans<<endl;
    return 0;
}