class Solution {
public:
    vector<vector<int>> dp;
    int f(int idx, int flag, vector<int> &prices){
        if(idx >= prices.size()) return 0;
        if(dp[idx][flag] != -1) return dp[idx][flag];
        int take=INT_MIN,nottake=INT_MIN;
        if(flag == 0){
            take = f(idx+1,1,prices) - prices[idx];
            nottake = f(idx+1,0,prices);
        }
        else{
            take = prices[idx] + f(idx+2,0,prices);
            nottake = f(idx+1,1,prices);
        }

        return dp[idx][flag] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));
        return f(0,0,prices);
    }
};
