//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool DFS(int src, vector<int> adj[], vector<int> &color, int col)
    {
        color[src] = 1 - col;
    
        for(auto x: adj[src])
        {
            if(color[x] == -1)
            {
                if(DFS(x, adj, color, color[src]) == false)
                return false;
            }
            else
            {
                if(color[x] == color[src])
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int> color(V, -1);
	    
	    for(int i=0; i<V; i++)
	    {
	        if(color[i] == -1)
	        {
	            if(DFS(i, adj, color, 1) == false)
	            return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends