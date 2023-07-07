#include <iostream>
using namespace std;

bool check(int** a, int x, int y, int n)
{
    if(x < n && y < n && a[x][y] == 1)
    return true;
    else
    return false;
}

bool RatMaze(int** a, int x, int y, int n, int** sol) // O(2^n)
{
    if(x == n-1 && y == n-1)
    {
        sol[x][y] = 1;
        return true;
    }

    if(check(a,x,y,n))
    {
        sol[x][y] = 1;
        if(RatMaze(a,x+1,y,n,sol))
        return true;

        if(RatMaze(a,x,y+1,n,sol))
        return true;

        sol[x][y] = 0; // backtracking
        return false;
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter size of 2d array\n";
    cin>>n;

    int** arr = new int*[n]; // dynamic array allocation
    for(int i=0;i<n;i++)
    arr[i] = new int[n];

    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }

    int** sol = new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i] = new int[n];
        for(int j=0;j<n;j++)
        sol[i][j] = 0;
    }

    cout<<"Maze\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";

        cout<<"\n";
    }

    if(RatMaze(arr,0,0,n,sol))
    {
        cout<<"Path\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<sol[i][j]<<' ';

            cout<<"\n";
        }
    }
    else
    cout<<"No Path\n";

    return 0;
}