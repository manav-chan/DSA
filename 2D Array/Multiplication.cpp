#include <iostream>
using namespace std;

int main()
{
    int m,n,a,b;
    cout<<"First Matrix\n";
    cout<<"Enter rows and columns\n";
    cin>>m>>n;
    int arr[m][n];
    cout<<"Enter array elements\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Second Matrix\n";
    cout<<"Enter rows and columns\n";
    cin>>a>>b;
    if(n!=a)
    {
        cout<<"Invalid Array\n";
        return 0;
    }
    int brr[a][b];
    cout<<"Enter array elements\n";
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>brr[i][j];
        }
    }
    int mul[m][b];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<b;j++)
        {
            int sum=0;
            for(int k=0;k<a;k++)
            {
                sum+=arr[i][k]*brr[k][j];
            }
            mul[i][j]=sum;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<mul[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}