//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void DFS(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<pair<int, int>> &shape, int baseRow, int baseCol)
    {
        visited[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol});
        
        int m = grid.size(), n = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0 ,1};
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i], ncol = col + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
            {
                DFS(nrow, ncol, grid, visited, shape, baseRow, baseCol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        set<vector<pair<int, int>>> st;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int, int>> shape;
                    DFS(i, j, grid, visited, shape, i, j);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends