class Solution {
public:
    int f(int left, string &s, vector<int> &dp){
        if(left == s.length()) return 1;
        if(dp[left] != -1) return dp[left];
        int ways=0;
        for(int right=left;right<s.length();right++){
            string substr = s.substr(left,right-left+1);
            if(substr[0] != '0' && substr.length() <= 2 && stoi(substr) <= 26){
                ways += f(right+1,s,dp);
            }
        }
        return dp[left] = ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return f(0,s,dp);
    }
};
