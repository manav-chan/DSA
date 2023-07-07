#include <iostream>
using namespace std;

int main()
{
    int arr[5][3];
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<"Enter element\n";
            cin>>arr[i][j];
        }
    }

    cout<<"Matrix : \n";
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<3; j++)
        cout<<arr[i][j]<<"\t";

        cout<<"\n";
    }

    cout<<"Even numbers rowwise:\n";
    for(int i=0; i<5; i++)
    {
        cout<<"Row "<<i+1<<": ";
        for(int j=0; j<3; j++)
        {
            if(arr[i][j] % 2 == 0)
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Even numbers columnwise:\n";
    for(int j=0; j<3; j++)
    {
        cout<<"Column "<<j+1<<": ";
        for(int i=0; i<5; i++)
        {
            if(arr[i][j] % 2 == 0)
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
