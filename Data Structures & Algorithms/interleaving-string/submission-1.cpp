class Solution {
public:
    vector<vector<int>> dp;
    bool f(int p1, int p2, int p3, string &s1, string &s2, string &s3){
        if(p3 == s3.length()) return true;
        if(dp[p1][p2] != -1) return dp[p1][p2];
        if(p1 < s1.length() && p2 < s2.length() && s1[p1] == s2[p2] && s3[p3] == s1[p1]){
            return dp[p1][p2] = f(p1+1,p2,p3+1,s1,s2,s3) || f(p1,p2+1,p3+1,s1,s2,s3);
        }
        else if(p1 < s1.length() && s3[p3] == s1[p1]){
            return dp[p1][p2] = f(p1+1,p2,p3+1,s1,s2,s3);
        }
        else if(p2 < s2.length() && s3[p3] == s2[p2]){
            return dp[p1][p2] = f(p1,p2+1,p3+1,s1,s2,s3);
        }
        else return dp[p1][p2] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        dp.assign(s1.length()+1,vector<int>(s2.length()+1,-1));
        return f(0,0,0,s1,s2,s3);
    }
};
