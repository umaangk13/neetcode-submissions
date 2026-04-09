class Solution {
public:
    int f(vector<vector<int>> &dp,vector<int>& coins,int amount,int i){
        if(i==0){
            if(amount%coins[i] == 0) return amount/coins[i];
            return 1e9; 
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int notpick = 0 + f(dp,coins,amount,i-1);
        int pick = INT_MAX;
        if(coins[i] <= amount) pick = 1 + f(dp,coins,amount-coins[i],i);

        return dp[i][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int a = f(dp,coins,amount,coins.size()-1);
        if(a>=1e9) return -1;
        return a;
    }
};
