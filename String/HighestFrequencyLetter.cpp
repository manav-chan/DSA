#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    int mx=0;
    int c=1;
    char a;
    getline(cin, str);
    sort(str.begin(), str.end());
    for(int i=1;i<str.length();i++)
    {
        if(str[i]==str[i-1])
        c++;
        else
        {
            if(c>mx)
            {
                mx=c;
                a=str[i-1];
            }
            c=1;
        }
    }
    cout<<a<<" "<<mx<<endl;
    // int c=0;
    // int arr[26];
    // for(int i=0;i<26;i++)
    // {
    //     arr[str[i]-'a']= arr[str[i]-'a']++;
    // }
    // for(int i =0;i<26;i++)
    // {

    // }
    return 0;
}
