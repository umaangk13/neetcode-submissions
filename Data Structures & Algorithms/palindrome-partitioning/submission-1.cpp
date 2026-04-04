class Solution {
public:
    // bool palindrome(int left, int right, string &s){
    //     int l=left,r=right;
    //     while(l<=r){
    //         if(s[l] != s[r]){
    //             return false;
    //         }
    //         l++; r--;
    //     }
    //     return true;
    // }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> curr;
        f(0,s,curr,result,dp);
        return result;
    }
    void f(int idx, string &s, vector<string> &curr, vector<vector<string>> &result, vector<vector<bool>> &dp){
        if(idx == s.length()){
            result.push_back(curr);
            return;
        }

        int left = idx;
        for(int i=idx;i<s.length();i++){
            if(dp[idx][i]){ // O(1) check instead of O(N)
                curr.push_back(s.substr(left,i-left+1));
                f(i+1,s,curr,result,dp);
                curr.pop_back();
            }
        }
    }
};
