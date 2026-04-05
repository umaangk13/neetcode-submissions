class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '0';

        int Row[] = {0,-1,0,1};
        int Col[] = {-1,0,1,0};

        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto it = q.front(); q.pop();
            for(int k=0;k<4;k++){
                int r = it.first + Row[k];
                int c = it.second + Col[k];
                if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == '1'){
                    grid[r][c] = '0';
                    q.push({r,c});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    result++;
                    bfs(i,j,grid);
                }
            }
        }
        return result;
    }
};
