class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        // 1. Add all treasures to the queue simultaneously
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int Row[] = {0, -1, 0, 1};
        int Col[] = {-1, 0, 1, 0};
        
        // 2. Standard BFS
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + Row[k];
                int nc = c + Col[k];

                // Only visit if it's an empty land (INF value)
                // We use the grid itself to track "visited" (if it's not 2147483647, we've been there)
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
}
};
