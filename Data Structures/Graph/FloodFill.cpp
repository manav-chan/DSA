class Solution {
private:
    void DFS(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int stColor, int newColor, int delrow[], int delcol[])
    {
        ans[row][col] = newColor;
        int m = image.size(), n = image[0].size();

        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i], ncol = col + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == stColor && ans[nrow][ncol] != newColor)
            DFS(nrow, ncol, ans, image, stColor, newColor, delrow, delcol);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int stColor = image[sr][sc];
        vector<vector<int>> ans = image; // copying image matrix

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        DFS(sr, sc, ans, image, stColor, color, delrow, delcol);
        return ans;
    }
};