class Solution {
public:
    int f(vector<vector<int>> &dp,vector<int>& coins,int amount,int i){
        if(i==0){
            if(amount%coins[i] == 0) return 1;
            else return 0; 
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int notpick = f(dp,coins,amount,i-1);
        int pick = 0;
        if(coins[i] <= amount) pick = f(dp,coins,amount-coins[i],i);

        return dp[i][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int a = f(dp,coins,amount,coins.size()-1);
        return a;
    }
};
