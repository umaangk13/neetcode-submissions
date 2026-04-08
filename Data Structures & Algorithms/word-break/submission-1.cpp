class Solution {
public:
    bool f(int idx, string &s, unordered_set<string> &set, vector<int> &dp){
        if(idx == s.length()) return true;
        if(dp[idx] != -1) return dp[idx]==1;

        for(int i=idx;i<s.length();i++){
            if(set.count(s.substr(idx,i-idx+1))>0 && f(i+1,s,set,dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(string s : wordDict){
            set.insert(s);
        }
        vector<int> dp(s.length(),-1);
        return f(0,s,set,dp);
    }
};
