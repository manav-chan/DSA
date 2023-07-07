#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number\n";
    cin>>n;
    int c=0;
    while(n)
    {
        c++;
        n= n & (n-1);
    }
    cout<<c<<endl;
    return 0;
}