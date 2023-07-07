class Solution {
private:
    void BFS(pair<int, int> p, vector<vector<char>>& grid, vector<vector<bool>> &visited)
    {
        queue<pair<int, int>> q;
        visited[p.first][p.second] = 1;
        q.push(p);

        int n = grid.size(), m = grid[0].size();
        while(!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();

            int i = node.first, j = node.second;
            // if(i!=0 && grid[i-1][j] == '1' && !visited[i-1][j]) 
            // {
            //     visited[i-1][j] = 1;
            //     q.push(make_pair(i-1, j));
            // }
            // if(j!=0 && grid[i][j-1] == '1' && !visited[i][j-1])
            // {
            //     visited[i][j-1] = 1;
            //     q.push(make_pair(i, j-1));
            // }
            // if(i!=n-1 && grid[i+1][j] == '1' && !visited[i+1][j])
            // {
            //     visited[i+1][j] = 1;
            //     q.push(make_pair(i+1, j));
            // }
            // if(j!=m-1 && grid[i][j+1] == '1' && !visited[i][j+1])
            // {
            //     visited[i][j+1] = 1;
            //     q.push(make_pair(i, j+1));
            // }

            for(int delrow = -1; delrow <= 1; delrow++)
            {
                for(int delcol = -1; delcol <=1; delcol++)
                {
                    // if(delrow == delcol || delrow == 1 && delcol == -1 || delrow == -1 && delcol == 1) if 4 directions then uncomment
                    // continue;

                    int rownbr = i + delrow, colnbr = j + delcol;
                    if(rownbr >= 0 && rownbr < n && colnbr >= 0 && colnbr < m && grid[rownbr][colnbr] == '1' && !visited[rownbr][colnbr])
                    {
                        visited[rownbr][colnbr] = 1;
                        q.push(make_pair(rownbr, colnbr));
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) // for 8 directions
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,0));
        int islands = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    islands ++;
                    BFS(make_pair(i, j), grid, visited);
                }
            }
        }
        return islands;
    }
};