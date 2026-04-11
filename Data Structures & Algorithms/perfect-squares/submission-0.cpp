class Solution {
public:
    int f(int idx, int target, vector<int> &sq, vector<vector<int>> &dp){
        if(target == 0) return 0;
        if(idx < 0) return 1e9;

        if(dp[idx][target] != -1) return dp[idx][target];
        int take=1e9, nottake=1e9;
        if(sq[idx] <= target) take = 1+f(idx, target-sq[idx], sq, dp);
        nottake = f(idx-1, target, sq, dp);

        return dp[idx][target] = min(take,nottake);
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1;i<=n;i++){
            if(i*i > n){
                break;
            }
            sq.push_back(i*i);
        }
        vector<vector<int>> dp(sq.size(), vector<int>(n+1,-1));
        return f(sq.size()-1,n,sq,dp);
    }
};