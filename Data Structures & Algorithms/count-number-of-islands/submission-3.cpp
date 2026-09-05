class Solution {
public:
    int Row[4] = {0,-1,0,1};
    int Col[4] = {-1,0,1,0};
    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '2';
        for(int k=0;k<4;k++){
            int r = i + Row[k];
            int c = j + Col[k];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == '1'){
                dfs(r,c,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> visited(n, vector<int>(m,));

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
