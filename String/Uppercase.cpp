#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    // for(int i=0;i<str.length();i++)
    // {
    //     if(str[i]>=97 && str[i]<=122)
    //     str[i]-=32;
    // }
    // cout<<str<<endl;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str<<endl;
    return 0;
}