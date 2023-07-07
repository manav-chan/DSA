#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter rows and columns\n";
    cin>>n;
    int arr[n][n];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    cout<<"Transpose of array:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}