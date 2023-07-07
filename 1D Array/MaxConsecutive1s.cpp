#include <iostream>
#include <vector>
using namespace std;

int maxConsecutive(vector<int> a, int k)
{
    int zeroct = 0, i = 0, ans = 0;
    for(int j=0;j<a.size();j++)
    {
        if(a[j] == 0)
        zeroct++;

        if(zeroct > k) // can use while also
        {
            if(a[i] == 0)
            zeroct--;

            i++;
        }
        ans = max(ans, j-i+1);
    }
    return ans;
}

int main()
{
    vector<int> a = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout<<maxConsecutive(a,k)<<"\n";
    return 0;
}