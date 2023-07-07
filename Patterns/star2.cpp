#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter rows and columns\n";
    cin>>n;
    for(int i=1;i<=2*n;++i)
    {
        for(int j=1;j<=n-1+i;++j)
        {
            if(i>n)
            {
                i=2*n-i+1;
                if(j<=n-i)
                cout<<"  ";
                else
                cout<<"* ";
            }
            else
            {
                if(j<=n-i)
                cout<<"  ";
                else
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    return 0;
}