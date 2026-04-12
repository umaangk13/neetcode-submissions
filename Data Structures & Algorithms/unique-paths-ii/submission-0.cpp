class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i<0 || j<0 || j>=obstacleGrid[0].size() || i>=obstacleGrid.size()
            || obstacleGrid[i][j] == 1) return 0;
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = f(i+1,j,obstacleGrid,dp) + f(i,j+1,obstacleGrid,dp); 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return f(0,0,obstacleGrid,dp);
    }
};