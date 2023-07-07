class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        vector<int> adjRev[V];
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++)
        {
            for(auto x: graph[i])
            {
                adjRev[x].push_back(i);
                indegree[i] ++;
            }
        }    
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }

        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto x: adjRev[node])
            {
                indegree[x] --;
                if(indegree[x] == 0)
                q.push(x);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};