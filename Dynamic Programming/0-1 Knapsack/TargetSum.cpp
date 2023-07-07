#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
    
    int subsetSum(vector<int> &arr, int n, int sum)
    {
        int t[n+1][sum+1];
        t[0][0] = 1;
        
        for(int i=1; i<=sum; i++)
            t[0][i] = 0;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        sum += nums[i];
        
        if(abs(target) > sum || (sum+target)%2 == 1)
            return 0;
        
        return subsetSum(nums,nums.size(),(sum+target)/2);
    }
};