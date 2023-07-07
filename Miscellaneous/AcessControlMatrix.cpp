#include <iostream>
using namespace std;

int main()
{
    int **arr;
    int users, files;
    cin>>users>>files;

    arr = (int**)malloc(users * sizeof(int*));
    for(int i=0;i<users;i++)
    arr[i] = (int*)malloc(files * sizeof(int));

    for(int i=0;i<users;i++)
    {
        for(int j=0;j<files;j++)
        {
            int val = (rand() %10) %3;
            arr[i][j] = val;
        }
    }

    cout<<"ACESS CONTROL MATRIX\n";
    cout<<"\t";
    for(int i=0;i<files;i++)
    cout<<"F"<<i+1<<"\t";

    cout<<"\n";

    for(int i=0;i<users;i++)
    {
        cout<<"U"<<i+1<<"\t";
        for(int j=0;j<files;j++)
        {
            switch(arr[i][j])
            {
                case 0:
                cout<<"Read\t";
                break;
                case 1:
                cout<<"Write\t";
                break;
                case 2:
                cout<<"Ex\t";
                break;
            }
        }
        cout<<"\n";
    }

    return 0;
}