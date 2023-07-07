#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number\n";
    cin>>n;
    if(n && !(n & (n-1))) // n&& for 0 input
    cout<<"Power of 2\n";
    else
    cout<<"Not power of 2\n";
    return 0;
}
