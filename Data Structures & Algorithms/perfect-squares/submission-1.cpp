class Solution {
public:
    int f(int target, vector<int> &dp){
        if(target == 0) return 0;

        if(dp[target] != -1) return dp[target];
        int res = target;
        for (int i = 1; i * i <= target; i++) {
            res = min(res, 1 + f(target - i * i,dp));
        }

        return dp[target] = res;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};