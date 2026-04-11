class Solution {
public:
    int f(int idx, int is_alice_turn, vector<int>& stoneValue, vector<vector<int>>& dp){
        if(idx >= stoneValue.size()) return 0;
        
        // Return cached result if it exists (Checking against -1e9 now)
        if(dp[idx][is_alice_turn] != -1e9) return dp[idx][is_alice_turn];

        if (is_alice_turn) {
            int stones = -1e9; // FIX 2: Start extremely small for max()
            int temp = 0;
            
            for(int i = 0; i <= 2 && idx + i < stoneValue.size(); i++){
                temp += stoneValue[idx + i];
                stones = max(stones, temp + f(idx + i + 1, 0, stoneValue, dp));
            }

            return dp[idx][is_alice_turn] = stones;
        } 
        else {
            int stones = 1e9; // 1e9 is perfect here for min()
            
            for(int i = 0; i <= 2 && idx + i < stoneValue.size(); i++){
                stones = min(stones, f(idx + i + 1, 1, stoneValue, dp));
            }

            return dp[idx][is_alice_turn] = stones;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        
        // FIX 3: Initialize memoization array with -1e9
        vector<vector<int>> dp(n, vector<int>(2, -1e9)); 
        
        // FIX 1: Pass 1 so Alice takes the first turn
        int alice_score = f(0, 1, stoneValue, dp);
        
        int bob_score = total - alice_score;
        int alice_score_diff = alice_score - bob_score;
        
        if(alice_score_diff > 0) return "Alice";
        else if(alice_score_diff < 0) return "Bob";
        else return "Tie";
    }
};