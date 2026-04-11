class Solution {
public:
    bool f(int l, int r, int alice_turn, int alice, int total, vector<int> &piles, vector<vector<int>> &dp){
        if(l>r) return alice>total-alice;
        if(dp[l][r] != -1) return dp[l][r];
        if(alice_turn){
            return dp[l][r] = f(l+1,r,0,alice+piles[l],total,piles,dp) || f(l,r-1,0,alice+piles[r],total,piles,dp);
        }
        else{
            return dp[l][r] = f(l+1,r,1,alice,total,piles,dp) || f(l,r-1,1,alice,total,piles,dp);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size(), total = 0;
        for(int pile : piles){
            total += pile;
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,1,0,total,piles,dp);

        // if(alice > total-alice) return true;
        // else return false;
    }
};