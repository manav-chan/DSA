#include "bits/stdc++.h"
using namespace std;

class Solution {
private:
    void DFS(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited, int delrow[], int delcol[])
    {
        visited[row][col] = 1;

        int m = grid.size(), n = grid[0].size(); 
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i], ncol = col + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
            DFS(nrow, ncol, grid, visited, delrow, delcol);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(grid[i][j] == 1 && !visited[i][j])
                    DFS(i, j, grid, visited, delrow, delcol);
                }
            }
        }    
        int count = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                count ++;
            }
        }
        return count;
    }
};