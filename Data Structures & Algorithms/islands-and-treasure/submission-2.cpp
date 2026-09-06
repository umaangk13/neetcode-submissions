class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }

        int Row[4] = {0,-1,0,1};
        int Col[4] = {-1,0,1,0};
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [r,c] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int row = r + Row[k];
                    int col = c + Col[k];
                    if(row>=0 && col>=0 && row<n && col<m && grid[row][col] == INT_MAX){
                        grid[row][col] = level;
                        q.push({row,col});
                    }
                }
            }
            level++;
        }
    }
};
