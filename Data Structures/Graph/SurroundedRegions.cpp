class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<bool>> &visited, int delrow[], int delcol[])
    {
        visited[row][col] = 1;
        
        int m = board.size(), n = board[0].size();
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i], ncol = col + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && visited[nrow][ncol] == 0)
            dfs(nrow, ncol, board, visited, delrow, delcol);
        }
    }
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(board[i][j] == 'O' && !visited[i][j])
                    dfs(i, j, board, visited, delrow, delcol);
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 'O' && visited[i][j] == 0)
                board[i][j] = 'X';
            }
        }
    }
};