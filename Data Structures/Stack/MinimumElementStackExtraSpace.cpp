#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> ss; //supporting stack

void Push(int val)
{
    s.push(val);

    if(ss.empty() || val <= ss.top()) //equal important as after popping duplicate element, duplicate element is still min and we need it in ss
    ss.push(val);
}

int Pop()
{
    if(s.empty())
    return -1;

    int val = s.top();
    if(s.top() == ss.top())
    {
        s.pop();
        ss.pop();   
    }
    else
    s.pop();

    return val;
}

int Min()
{
    if(ss.empty())
    return -1;

    return ss.top();
}
