class Solution {
public:
    int f(int day, bool canBuy, vector<int>& prices, vector<vector<int>> &dp){
        if(day >= prices.size()) return 0;
        if(dp[day][canBuy] != -1) return dp[day][canBuy];
        int take=0,nottake=0;
        if(canBuy){
            take = f(day+1,!canBuy,prices,dp) - prices[day];
            nottake = f(day+1,canBuy,prices,dp);
        }
        else{
            take = prices[day] + f(day+2,!canBuy,prices,dp);
            nottake = f(day+1,canBuy,prices,dp);
        }
        return dp[day][canBuy] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,true,prices,dp);
    }
};
