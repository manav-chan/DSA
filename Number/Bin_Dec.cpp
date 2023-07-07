#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    int i=0;
    float dec=0;
    cout<<"Enter Binary number\n";
    cin>>n;
    while(n>0)
    {
        int d=n%10;
        n=n/10;
        dec=dec+d*pow(2,i);
        i++;
    }
    cout<<dec<<endl;      
    return 0;  
}