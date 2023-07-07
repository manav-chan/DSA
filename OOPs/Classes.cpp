#include <iostream>
using namespace std;

class student{
    string name;

    public: // private by default
    int age;
    bool gender;

    student()
    {
        cout<<"Default Constructor\n";
    }

    student(string s, int a, int g) // Parameterised constructor
    {
        name = s;
        age = a;
        gender = g;
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
    //student a("Manav",18,1);
    //a.getName();
    //a.printinfo();
    
    student arr[3]; // array of objects. We can also do: student a, student b, student c and then a.name = ...
    for(int i=0;i<3;i++)
    {
        string s;
        cout<<"Name ";
        cin>>s;
        arr[i].setName(s);
        cout<<"Age ";
        cin>>arr[i].age;
        cout<<"Gender ";
        cin>>arr[i].gender;
    }
    
    for(int i=0;i<3;i++)
    arr[i].printinfo();

    return 0;
}