#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter rows and columns\n";
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n-1+i;++j)
        {
            if(j<=n-i)
            cout<<"  ";
            else
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;--i)
    {
        for(int j=1;j<=n-1+i;++j)
        {
            if(j<=n-i)
            cout<<"  ";
            else
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}