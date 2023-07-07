#include <iostream>
using namespace std;

//Sorted 2D Array

int main()
{
    int n,m,a;
    cout<<"Enter rows and columns\n";
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Enter element to be found\n";
    cin>>a;
    int i=0, j=m-1;
    while(i<n && j>=0)
    {
        if(a==arr[i][j])
        {
            cout<<"Element found\n";
            return 0;
        }
        else if(a>arr[i][j])
            i++;
        else
            j--;
    }
    cout<<"Element not found\n";
    return 0;
}