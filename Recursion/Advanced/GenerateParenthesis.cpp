#include <iostream>
#include <vector>
using namespace std;

static int count=0;
void generateBrace(string ans, int open, int close, vector<string> &v)
{
    if(open == 0 && close == 0)
    {
        v.push_back(ans);
        count++;
        return;
    }

    if(open != 0)
    generateBrace(ans+'(',open-1,close,v);

    if(close > open)
    generateBrace(ans+')',open,close-1,v);
}

int main()
{
    int n = 3;
    int open,close;
    open = close = n;
    string ans = "(";
    open--;

    vector<string> v;
    generateBrace(ans,open,close,v);

    for(auto i:v)
    cout<<i<<endl;
    cout<<count<<endl;
    return 0;
}