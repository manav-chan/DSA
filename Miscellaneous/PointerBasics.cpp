#include <iostream>
using namespace std;
int main()
{
    //Pointer basics
    int a = 1;
    int* b;
    b = &a;
    cout<<b<<endl;
    cout<<*b<<endl;
    *b=20;
    cout<<a<<endl;

    //Increment of pointers
    b++;
    cout<<b<<endl;

    //Character pointer
    char x= 'b';
    char *y;
    y= &x;
    cout<<y<<endl;
    cout<<++y<<endl;

    //Array as a pointer
    int arr[]={1,2,3};
    cout<<arr<<endl;
    int *ptr= arr;
    for(int i=0;i<3;i++)
    {
        cout<<*ptr<<endl;
        ptr++;
    }
    for(int i=0;i<3;i++)
    {
        cout<<*(arr+i)<<endl;
        ptr++;
    }
    
    //Pointer to Pointer
    int c=5;
    int *d=&c;
    cout<<*d<<endl;
    int **e=&d;
    cout<<*e<<endl;
    cout<<**e<<endl;

    return 0;
}