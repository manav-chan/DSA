#include <iostream>
using namespace std;
int main()
{
    int a,sum=0;
    cout<<"Enter a number between 1 & 4\n";
    for(int i=0;i<4;i++)
    {
        cin>>a;
        cout<<5-a<<endl;
        sum+=a+(5-a);
        cout<<"Sum: "<<sum<<endl;
    }
    cout<<"You Lose\n"; //Good Night Khushi
    return 0;
}