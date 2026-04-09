class Solution {
public:
    int n=0,m=0;
    int Row[4] = {0,-1,0,1};
    int Col[4] = {-1,0,1,0};
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &visited, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];
        visited[i][j] = 1;
        int res=0;
        for(int k=0;k<4;k++){
            int r = i + Row[k];
            int c = j + Col[k];
            if(r<n && c<m && r>=0 && c>=0 && visited[r][c] != 1 && matrix[r][c] > matrix[i][j]){
                res = max(res, f(r,c,matrix,visited,dp));
            }
        }
        visited[i][j] = 0;
        return dp[i][j] = 1+res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> visited(n,vector<int>(m,0));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result = max(result, f(i,j,matrix,visited,dp));
            }
        }
        return result;
    }
};
