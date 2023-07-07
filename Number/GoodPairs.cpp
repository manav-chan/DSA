class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int count = 0;
        unordered_map<int,int> map;
        
        for(int i:nums)
        {
            count += map[i]++;
        }
        return count;
    }
};
//  if number appears n times, no. of good pairs
//  is n * (n-1) / 2