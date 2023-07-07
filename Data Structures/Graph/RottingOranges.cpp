class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
                else
                visited[i][j] = 0;
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        int time = 0;
        while(!q.empty())
        {
            int r = q.front().first.first, c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(t, time);

            for(int i=0; i<4; i++)
            {
                int nrow = r + delrow[i], ncol = c + delcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 1)
                {
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == 0)
                return -1;
            }
        }
        return time;
    }
};