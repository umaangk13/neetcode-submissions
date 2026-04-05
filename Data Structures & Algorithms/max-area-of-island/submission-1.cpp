class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        // Base case: out of bounds or water
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0; // Mark visited
        
        // Sum current cell (1) + all 4 directions
        return 1 + dfs(i + 1, j, grid, n, m) + 
                   dfs(i - 1, j, grid, n, m) + 
                   dfs(i, j + 1, grid, n, m) + 
                   dfs(i, j - 1, grid, n, m);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid, n, m));
                }
            }
        }
        return maxArea;
    }
};