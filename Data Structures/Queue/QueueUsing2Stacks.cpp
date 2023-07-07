#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int val)
    {
        s1.push(val);
    }

    int pop()
    {
        if(s1.empty() && s2.empty())
        {
            cout<<"Stack Underflow\n";
            return -1;
        }

        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();

        return topval;
    }

    bool empty()
    {
        if(s1.empty() && s2.empty())
        return true;

        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.pop()<<"\n";
    q.push(4);
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";

    cout<<q.empty()<<"\n";

    return 0;
}