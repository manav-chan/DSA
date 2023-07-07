#include <iostream>
using namespace std;

class base
{
    public:
    virtual void print()
    {
        cout<<"base print\n";
    }
};

class derived: public base
{
    public:
    void print()
    {
        cout<<"Derived print\n";
    }
};

int main()
{
    base *baseptr;
    derived d;
    baseptr = &d;

    baseptr -> print();

    return 0;
}