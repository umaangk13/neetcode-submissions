class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;

        // 1. Count only fresh oranges and push initial rotten oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    freshCount++;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        // Edge case: If there are no fresh oranges to begin with, time is 0.
        if (freshCount == 0) return 0;

        int Row[] = {0, -1, 0, 1};
        int Col[] = {-1, 0, 1, 0};
        int time = 0;

        // 2. Multi-Source BFS
        while(!q.empty()){
            int size = q.size();
            bool rottedAny = false; // Flag to check if any rotting happened this minute

            while(size--){
                auto [r,c] = q.front(); q.pop();
                
                for(int k = 0; k < 4; k++) {
                    int nr = r + Row[k];
                    int nc = c + Col[k];
                    
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
                        // Mark as rotten IMMEDIATELY to prevent duplicate queue pushes
                        grid[nr][nc] = 2; 
                        freshCount--;     // One less fresh orange in the world
                        q.push({nr, nc});
                        rottedAny = true; // We successfully rotted something this minute
                    }
                }
            }
            // Only increment time if we actually rotted an orange during this level
            if(rottedAny) time++;
        }

        // 3. If freshCount isn't 0, some oranges were unreachable
        return freshCount == 0 ? time : -1;
    }
};