#include <iostream>
using namespace std;

int main()
{
    int m,n;
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
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    int r_s=0, r_e=m-1, c_s=0, c_e= n-1;
    while(r_s<=r_e && c_s<=c_e)
    {
        if(r_s<=r_e && c_s<=c_e){
        for(int col= c_s; col<= c_e; col++)
        cout<<arr[r_s][col]<<" ";
        r_s++;
        }
        if(r_s<=r_e && c_s<=c_e){
        for(int row=r_s; row<=r_e; row++)
        cout<<arr[row][c_e]<<" ";
        c_e--;
        }
        if(r_s<=r_e && c_s<=c_e){
        for(int col=c_e; col>=c_s; col--)
        cout<<arr[r_e][col]<<" ";
        r_e--;
        }
        if(r_s<=r_e && c_s<=c_e){
        for(int row=r_e; row>=r_s; row--)
        cout<<arr[row][c_s]<<" ";
        c_s++;
        }
    }
    return 0;
}