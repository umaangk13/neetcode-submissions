class Solution {
public:
    vector<vector<int>> dp;

    int f(int p1, int p2, string &word1, string &word2) {
        // Base cases: if one string is exhausted, cost is the length of the other prefix
        if (p1 < 0) return p2 + 1; // Insert remaining word2[0...p2]
        if (p2 < 0) return p1 + 1; // Delete remaining word1[0...p1]

        if (dp[p1][p2] != -1) return dp[p1][p2];

        if (word1[p1] == word2[p2]) {
            return dp[p1][p2] = f(p1 - 1, p2 - 1, word1, word2);
        }

        // 1 + min(delete, insert, replace)
        int del = f(p1 - 1, p2, word1, word2);
        int ins = f(p1, p2 - 1, word1, word2);
        int rep = f(p1 - 1, p2 - 1, word1, word2);

        return dp[p1][p2] = 1 + min({del, ins, rep});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if (n == 0) return m;
        if (m == 0) return n;

        dp.assign(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2);
    }
};