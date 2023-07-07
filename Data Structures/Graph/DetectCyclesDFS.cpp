//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool DFS(int src, int parent, vector<int> adj[], vector<bool> &visited)
    {
        visited[src] = 1;
        
        for(auto x: adj[src])
        {
            if(!visited[x])
            {
                if(DFS(x, src, adj, visited) == true)
                return true;
            }
            else if(visited[x] == 1 && parent != x)
            return true;
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
                if(DFS(i, -1, adj, visited))
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