#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    //getline(cin, str);
    //cout<<str<<endl;
    string str1(10, 'M');
    cout<<str1<<endl;
    string s1= "abc";
    string s2= "ABC";
    cout<<s2.compare(s1)<<endl;
    string a="dsajewfdknv";
    sort(a.begin(), a.end());
    cout<<a<<endl;
    return 0;
}