class Solution {
public:
    int f(int p1, int p2, string &text1, string &text2, vector<vector<int>> &dp){
        if(p1<0 || p2<0) return 0;
        if(dp[p1][p2] != -1) return dp[p1][p2];
        if(text1[p1] == text2[p2]){
            return dp[p1][p2] = 1+f(p1-1,p2-1,text1,text2,dp);
        }
        else{
            return dp[p1][p2] = max(f(p1,p2-1,text1,text2,dp), f(p1-1,p2,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(),-1));
        return f(text1.length()-1, text2.length()-1, text1, text2, dp);
    }
};
