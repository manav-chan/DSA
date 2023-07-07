class Solution {
private:
    bool DFS(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &check)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;

        for(auto x: graph[node])
        {
            if(!visited[x])
            {
                if(DFS(x, graph, visited, pathVisited, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(visited[x] == 1 && pathVisited[x] == 1)
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<bool> visited(n, 0);
        vector<bool> pathVisited(n, 0);
        vector<bool> check(n, 0);

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            DFS(i, graph, visited, pathVisited, check);
        }    
        vector<int> safeNodes;
        for(int i=0; i<n; i++)
        {
            if(check[i] == 1)
            safeNodes.push_back(i);
        }
        return safeNodes;
    }
};