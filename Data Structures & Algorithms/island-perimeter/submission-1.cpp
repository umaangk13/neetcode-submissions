class Solution {
public:
    int n=0, m=0, peri=0;
    int Row[4] = {0,-1,0,1};
    int Col[4] = {-1,0,1,0};
    void dfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = -1;
        int ni=0,nj=0;
        for(int k=0;k<4;k++){
            ni = i+Row[k];
            nj = j+Col[k];
            if(ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj] == 0){
                peri++;
            }
            else if(grid[ni][nj] != -1){
                dfs(ni,nj,grid);
            }
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid);
                    break;
                }
            }
        }
        return peri;
    }
};