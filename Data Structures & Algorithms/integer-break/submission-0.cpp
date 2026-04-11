class Solution {
public:
    int f(int k, int target, vector<int> &dp){
        if(target == 0 && k >= 2) return 1;
        if(dp[target] != -1) return dp[target];
        int total=0;
        for(int i=1;i<=target;i++){
            total = max(total, i*f(k+1,target-i,dp));
        }

        return dp[target] = total;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return f(0,n,dp);
    }
};