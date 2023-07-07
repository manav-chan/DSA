#include <iostream>
#include <math.h>
using namespace std;
int max(int a,int b,int c)
{
    if(a>b&&a>c)
    return a;
    else if(b>c&&b>a)
    return b;
    else
    return c;
}

int main()
{
    int a,b,c;
    cout<<"Enter numbers\n";
    cin>>a>>b>>c;
    cout<<max(a,b,c)<<endl;
    //if(c*c==a*a+b*b||a*a==b*b+c*c||b*b==c*c+a*a)
    float d=pow(max(a,b,c),2);
    if(d==a*a+b*b+c*c-d)
    cout<<"Pythagorean Triplet\n";
    else
    cout<<"No Triplet\n";
    return 0;
}