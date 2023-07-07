#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter rows and columns\n";
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=2*n-i;++j)
        {
            if((i==1||i==n)&&j>=n-i+1)
            cout<<"*";
            else 
            {
            if(j<=n-i||(j>n-i+1&&j<2*n-i))
            cout<<" ";
            else
            cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}