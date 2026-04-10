class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base case: If pattern is empty, string must also be empty
        if (j == 0) return i == 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        // If we encounter a '*', it modifies the preceding character (p[j - 2])
        if (j >= 2 && p[j - 1] == '*') {
            // Check if the character BEFORE the '*' matches the current string character
            bool match = (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            
            // Option 1: Ignore the "char*" completely (matches 0 times) -> move j back by 2
            // Option 2: The char matches, so we consume 1 char from s (i-1) and keep the '*' (j)
            return dp[i][j] = f(i, j - 2, s, p, dp) || (match && f(i - 1, j, s, p, dp));
        } 
        // Normal character or '.' match
        else {
            bool match = (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
            return dp[i][j] = match && f(i - 1, j - 1, s, p, dp);
        }
    }

    bool isMatch(string s, string p) {
        // dp table sized by lengths rather than max index
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        
        return f(s.length(), p.length(), s, p, dp);
    }
};