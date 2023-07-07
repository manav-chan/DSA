#include <iostream>
using namespace std;
int main()
{
    int a=1; //allocation of memory in stack
    int *p= new int(); // allocation of memory in heap
    *p=10;
    cout<<p<<endl<<*p<<endl;
    delete(p); // dangling pointer dellocation of memory
    // pointer is made in stack which points to memory address in heap

    p= new int[5];
    p[0]=30;
    cout<<p<<endl<<p[0]<<endl;
    delete[] p;
    p=NULL;
    return 0;
}