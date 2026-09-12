class Solution {
public:
    int n,m;
    int Row[4] = {0,-1,0,1};
    int Col[4] = {-1,0,1,0};
    vector<vector<int>> visited;
    vector<vector<int>> dp;
    int f(int i, int j, vector<vector<int>> &matrix){
        if(dp[i][j] != -1) return dp[i][j];
        visited[i][j] = 1;
        int curr = matrix[i][j];
        int longest=1;
        for(int k=0;k<4;k++){
            int r = i + Row[k];
            int c = j + Col[k];
            if(r>=0 && c>=0 && r<n & c<m && visited[r][c] != 1 && matrix[r][c] > curr){
                longest = max(longest, 1 + f(r,c,matrix));
            }
        }
        visited[i][j] = 0;
        return dp[i][j] = longest;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n,vector<int>(m,-1));
        int result=0;
        visited.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result = max(result, f(i,j,matrix));
            }
        }
        return result;
    }
};
