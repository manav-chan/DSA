class Solution {
private:
    void BFS(int src, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        queue<int> q;
        visited[src] = 1;
        q.push(src);

        int n = isConnected.size();
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int i=0; i<n; i++)
            {
                if(isConnected[node][i] && !visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int provinces = 0;
        int n = isConnected.size();
        vector<bool> visited(n);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                provinces ++;
                BFS(i, isConnected, visited);
            }
        }    
        return provinces;
    }
};