class Solution {
public:
    int f(int p1, int p2, string &s, string &t, vector<vector<int>> &dp){
        if(p1 == s.length() && p2 != t.length()) return 0;
        if(p2 == t.length()) return 1;
        if(dp[p1][p2] != -1) return dp[p1][p2];
        int take=0,nottake=0;
        if(s[p1] == t[p2]){
            take = f(p1+1,p2+1,s,t,dp);
            nottake = f(p1+1,p2,s,t,dp);
        }
        else{
            nottake = f(p1+1,p2,s,t,dp);
        }

        return dp[p1][p2] = take+nottake;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return f(0,0,s,t,dp);
    }
};
