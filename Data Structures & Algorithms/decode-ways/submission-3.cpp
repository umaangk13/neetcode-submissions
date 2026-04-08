class Solution {
public:
    int f(int left, string &s, vector<int>& dp) {
        // Base case: Reached the end of the string, found 1 valid way
        if (left == s.length()) return 1;
        
        // A string starting with '0' is invalid
        if (s[left] == '0') return 0;
        
        // If we've already calculated this subproblem, return the cached result
        if (dp[left] != -1) return dp[left];
        
        // 1-digit jump
        int ways = f(left + 1, s, dp);
        
        // 2-digit jump (Only if there are at least 2 characters left and it forms 10-26)
        if (left + 1 < s.length()) {
            if (s[left] == '1' || (s[left] == '2' && s[left + 1] <= '6')) {
                ways += f(left + 2, s, dp);
            }
        }
        
        // Cache the result before returning
        return dp[left] = ways;
    }
    
    int numDecodings(string s) {
        // Initialize dpization table with -1
        vector<int> dp(s.length(), -1);
        return f(0, s, dp);
    }
};