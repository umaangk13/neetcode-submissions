class Solution {
public:
    vector<vector<int>> dp;
    int f(int p1, int p2, string &s, string &t){
        if(p2 == t.length()) return 1;
        else if(p1 == s.length()) return 0;

        if(dp[p1][p2] != -1) return dp[p1][p2];
        int nottake = f(p1+1,p2,s,t);
        int take=0;
        if(s[p1] == t[p2]){
            take = f(p1+1,p2+1,s,t);
        }
        return dp[p1][p2] = take+nottake;
    }
    int numDistinct(string s, string t) {
        dp.assign(s.length(), vector<int>(t.length(),-1));
        return f(0,0,s,t);
    }
};
