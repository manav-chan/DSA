#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter word length\n";
    cin>>n;
    char arr[n+1];
    cout<<"Enter word\n";
    cin>>arr;
    for(int i=0;i<n/2;i++)
    {
        if(arr[i] != arr[n-i-1])
        {
            cout<<"Word is not pallindrome\n";
            return 0;
        }
    }
    cout<<"Word is pallindrome\n";
    return 1;
}