#include <iostream>
using namespace std;
int main()
{ 
    int n;
    cin>>n;
    int ans[n+1];
    for(int i=0; i<=n; i++)
    {
        int c=i,a=0;
        while(c != 0)
        {
            c = c & (c-1);
            a++;
        }
            ans[i]=a;
    }
    cout<<"[";
    for(int i=0; i<=n; i++)
    {
        cout<<ans[i]<<",";
    }
    cout<<"\b]"<<endl;
    return 0;
}
