class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = 2;
        int numOfOnes = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        int Row[4] = {0,-1,0,1};
        int Col[4] = {1,0,-1,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int row = r + Row[k];
                int col = c + Col[k];
                if(row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col] == 1){
                    numOfOnes++;
                    grid[row][col] = 2;
                    q.push({row,col});
                }
            }
        }
        return numOfOnes;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    result = max(result,bfs(i,j,grid));
                }
            }
        }
        return result;
    }
};
