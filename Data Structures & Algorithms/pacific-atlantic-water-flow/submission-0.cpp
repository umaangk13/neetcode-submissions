class Solution {
public:
    int n=0,m=0;
    int Row[4] = {0,-1,0,1};
    int Col[4] = {-1,0,1,0};
    void bfs(queue<pair<int,int>> q, vector<vector<int>> &reach, vector<vector<int>>& heights){
        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nr = r + Row[k];
                int nc = c + Col[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m && reach[nr][nc] == 0 && heights[nr][nc] >= heights[r][c]){
                    reach[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(); m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m,0));
        vector<vector<int>> atlantic(n, vector<int>(m,0));

        queue<pair<int,int>> q1;
        for(int i=0;i<n;i++){
            pacific[i][0] = 1;
            q1.push({i,0});
        }
        for(int j=0;j<m;j++){
            pacific[0][j] = 1;
            q1.push({0,j});
        }
        bfs(q1,pacific,heights);

        queue<pair<int,int>> q2;
        for(int i=0;i<n;i++){
            atlantic[i][m-1] = 1;
            q2.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            atlantic[n-1][j] = 1;
            q2.push({n-1,j});
        }
        bfs(q2,atlantic,heights);
        
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
