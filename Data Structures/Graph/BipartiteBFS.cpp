class Solution {
private:
    bool BFS(int src, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto x: graph[node])
            {
                if(color[x] == -1)
                {
                    color[x] = 1 - color[node];
                    q.push(x);
                }
                else
                {
                    if(color[x] == color[node])
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(!BFS(i, graph, color))
                return false;
            }
        }
        return true;
    }
};