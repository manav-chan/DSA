#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Sum3(vector<int> a, int target)
{
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        int low = i+1;
        int high = a.size()-1;
        while(low < high)
        {
            if(a[low]+a[high] == target - a[i])
            return true;

            else if(a[low]+a[high] < target - a[i])
            low++;

            else
            high--;
        }
    }
    return false;
}

int main()
{
    vector<int> a = {12,3,7,1,6,9};
    cout<<Sum3(a,24)<<"\n";
    return 0;
}