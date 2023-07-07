#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter sentence size\n";
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cout<<"Enter sentence\n";
    cin.getline(arr,n);
    int c=0,start=0,mxstart=0;
    int mx=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == ' ' || arr[i]== '\0')
        {
            if(c>mx)
            {
                mx=c;
                mxstart=start;
            }
            start=i+1;
            c=0;
        }
        else 
        {
            c++;
        }
        if(arr[i]== '\0')
        break;
    }
    cout<<mx<<endl;
    for(int i=0;i<mx;i++)
    {
        cout<<arr[mxstart+i];
    }
    return 0;
} 