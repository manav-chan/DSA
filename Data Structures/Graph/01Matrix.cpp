class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while(!q.empty())
        {
            int r = q.front().first.first, c = q.front().first.second;
            int d = q.front().second;
            ans[r][c] = d;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nrow = r + delrow[i], ncol = c + delcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] != 1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, d+1});
                }
            }
        }
        return ans;
    }
};