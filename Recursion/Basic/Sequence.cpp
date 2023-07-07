#include <iostream>
using namespace std;
void decseries(int n)
{
    if(n==1)
    {
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<" ";
    decseries(n-1);
}

void incseries(int n)
{
    if(n==1)
    {
        cout<<"1 ";
        return;
    }
    incseries(n-1);
    cout<<n<<" ";    
}  

int main()
{
    decseries(5);
    incseries(5);
    return 0;
}