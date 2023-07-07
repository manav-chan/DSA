class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        int t[n+1][amount+1];
        
        for(int i=0; i<=amount; i++)
            t[0][i] = INT_MAX - 1;
        for(int i=1; i<=n; i++)
            t[i][0] = 0;
        
        for(int i=1, j=1; j<=amount; j++)
        {
            if(j % coins[0] == 0)
                t[i][j] = j/coins[0];
            else
                t[i][j] = INT_MAX - 1;
        }
        
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(coins[i-1] <= j)
                    t[i][j] = min(t[i][j-coins[i-1]] + 1, t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        if(t[n][amount] > amount)
            return -1;
        
        return t[n][amount];
    }
};