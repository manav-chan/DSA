#include <iostream>
#include <queue>
using namespace std;

class stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    stack()
    {
        N = 0;
    }

    void push(int val)
    {
        q2.push(val);
        N++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1; //swapping elements of queue
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        if(q1.empty())
        {
            cout<<"No element to delete\n";
            return;
        }
        q1.pop();
        N--;
    }

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return N;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<"\n";
    st.pop();
    st.pop();
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.size()<<"\n";
    st.pop();

    return 0;
}