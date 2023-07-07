#include <iostream>
using namespace std;

class student{
    string name;

    public: // private by default
    int age;
    bool gender;

    student() // default constructor
    {
        cout<<"Default Constructor\n";
    }

    student(string s, int a, int g) // Parameterised constructor
    {
        cout<<"Parameterised constructor\n";
        name = s;
        age = a;
        gender = g;
    }

    student(student &a) // Copy Constructor
    {
        cout<<"Copy constructor\n";
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    ~student() // destructor 
    {
        cout<<"Destructor\n";
    }

    bool operator == (student &a)
    {
        if(name==a.name && age==a.age && gender==a.gender) // name is name of 2nd operand 
        return true;
        else
        return false;
    }

    void setName(string s)
    {   
        name = s;
    }

    void getName()
    {
        cout<<name<<"\n";
    }

    void printinfo()
    {
        cout<<"Name: "<<name<<"\n";
        cout<<"Age: "<<age<<"\n";
        cout<<"Gender: "<<gender<<"\n";
    }
};

int main()
{
    student a; 
    student b("Manav",18,1);
    //a.getName();
    //a.printinfo();
    
    student c = b; // or student c(a). Default copy constructor will be called if a user defined does not exist

    if(c == b)
    cout<<"Same\n";

    return 0;
}