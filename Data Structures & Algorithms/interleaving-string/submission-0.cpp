class Solution {
public:
    bool f(int p1, int p2, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        // We calculate p3 on the fly
        int p3 = p1 + p2;
        
        if(p3 == s3.length()) return true;
        if(dp[p1][p2] != -1) return dp[p1][p2];
        
        bool first = false, second = false;
        
        if(p1 < s1.length() && s1[p1] == s3[p3]) {
            first = f(p1 + 1, p2, s1, s2, s3, dp);
        }
        if(p2 < s2.length() && s2[p2] == s3[p3]) {
            second = f(p1, p2 + 1, s1, s2, s3, dp);
        }
        
        return dp[p1][p2] = first || second;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        
        // Only a 2D array is needed
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        
        return f(0, 0, s1, s2, s3, dp);
    }
};