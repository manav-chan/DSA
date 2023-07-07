#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of rows and columns\n";
    cin>>n;  
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n-1+i;++j)
        {                
            if(j<=n-i)
                cout<<"  ";
            else
            {    
                if(j>n)
                cout<<j-n+1<<" ";
                else
                cout<<n-j+1<<" ";
            }        
        }  
        cout<<endl;
    } 
    return 0;
}