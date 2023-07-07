#include <iostream>
using namespace std;

void increment(int *c) //passing pointer
{
    (*c)++;
}

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int a=10;
    int b=20;
    swap(&a,&b);  // swap(aptr,bptr);
    cout<<a<<endl<<b<<endl;
    int c=1;
    increment(&c);
    cout<<c<<endl;
    return 0;
}