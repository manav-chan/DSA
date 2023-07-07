#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> st;

    public:
    void push(int val)
    {
        st.push(val);
    }

    int pop()
    {
        if(st.empty())
        {
            cout<<"Queue underflow\n";
            return -1;
        }

        int x = st.top();
        st.pop();

        if(st.empty())
        return x;

        int val = pop();
        st.push(x);
        return val;
    }

    bool empty()
    {
        if(st.empty())
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
    q.push(4);

    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";

    cout<<q.empty()<<"\n";

    return 0;
}

