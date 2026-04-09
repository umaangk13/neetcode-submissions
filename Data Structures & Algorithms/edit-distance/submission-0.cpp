class Solution {
public:
    int f(int p1, int p2, string &word1, string &word2, vector<vector<int>> &dp){
        if(p1 < 0) return p2+1;
        if(p2 < 0) return p1+1;
        if(dp[p1][p2] != -1) return dp[p1][p2];
        if(word1[p1] == word2[p2]){
            return dp[p1][p2] = f(p1-1,p2-1,word1,word2,dp);
        }
        else{
            return dp[p1][p2] = 1+min(f(p1-1,p2-1,word1,word2,dp),
                                    min(f(p1,p2-1,word1,word2,dp),f(p1-1,p2,word1,word2,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,word1,word2,dp);
    }
};
