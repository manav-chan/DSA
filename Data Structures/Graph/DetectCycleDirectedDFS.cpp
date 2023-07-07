//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool DFS(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited)
    {
        visited[src] = 1;
        pathVisited[src] = 1;
        
        for(auto x: adj[src])
        {
            if(!visited[x])
            {
                if(DFS(x, adj, visited, pathVisited) == true)
                return true;
            }
            else
            {
                if(visited[x] == 1 && pathVisited[x] == 1)
                return true;
            }
        }
        pathVisited[src] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, 0);
        vector<bool> pathVisited(V, 0);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(DFS(i, adj, visited, pathVisited) == true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends