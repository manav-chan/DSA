//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfsTopo(int node, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &st)
    {
        visited[node] = 1;
        
        for(auto x: adj[node])
        {
            if(!visited[x.first])
            dfsTopo(x.first, adj, visited, st);
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        vector<pair<int, int>> adj[N];
        for(auto edge: edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        stack<int> st;
        vector<bool> visited(N, 0);
        for(int i=0; i<N; i++)
        {
            if(!visited[i])
            dfsTopo(i, adj, visited, st);
        }
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto x: adj[node])
            {
                if(dist[x.first] > dist[node] + x.second)
                dist[x.first] = dist[node] + x.second;  
            }
        }
        for(int i=0; i<N; i++)
        {
            if(dist[i] == 1e9)
            dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends