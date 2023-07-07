#include <iostream>
using namespace std;
int main()
{
    int n;
    int c=1;
    cout<<"Enter rows and columns\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            cout<<" ";
        }
        int a=i;
        for(int k=1;k<=i+1;k++)
        {
        cout<<c<<" ";
        c=c*a--/k;   
        }
    cout<<endl;
    c=1;
    }  
    return 0;
}