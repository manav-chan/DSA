//Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        vector<int> mp(101);
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            mp[nums[i]] ++;
        }

        int count = 0;
        for(int i=0; i<101; i++)
        {
            if(mp[i] != 0 && i+k <= 100)
            {
                count += mp[i] * mp[i+k];
            }
        }
        return count;
    }
};