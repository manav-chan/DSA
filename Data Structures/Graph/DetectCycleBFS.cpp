//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detectCycle(int src, vector<int> adj[], vector<bool> &visited)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;
        
        while(!q.empty())
        {
            int node = q.front().first, parent = q.front().second;
            q.pop();
            
            for(auto x: adj[node])
            {
                if(!visited[x])
                {
                    q.push({x, node});
                    visited[x] = 1;
                }
                else if(visited[x] == 1 && x != parent)
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        // Code here
        vector<bool> visited(V, 0);
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(detectCycle(i, adj, visited))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends