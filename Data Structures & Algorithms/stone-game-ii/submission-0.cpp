class Solution {
public:
    // Added a 3D DP table: dp[is_alice_turn][idx][M]
    int f(int idx, int is_alice_turn, int M, vector<int>& piles, vector<vector<vector<int>>>& dp){
        if(idx >= piles.size()) return 0;
        
        // Return cached result if it exists
        if(dp[is_alice_turn][idx][M] != -1) return dp[is_alice_turn][idx][M];

        if (is_alice_turn) {
            int stones = -1; // Start small for max()
            int temp = 0;
            
            // Limit is 2*M, AND ensure we don't go out of bounds
            for(int i = 1; i <= 2 * M && idx + i - 1 < piles.size(); i++){
                temp += piles[idx + i - 1];
                
                // Pass max(M, i) directly, do NOT modify local M
                stones = max(stones, temp + f(idx + i, 0, max(M, i), piles, dp));
            }

            return dp[is_alice_turn][idx][M] = stones;
        } 
        else {
            int stones = 1e9; // Start huge for min()
            
            for(int i = 1; i <= 2 * M && idx + i - 1 < piles.size(); i++){
                // Bob doesn't collect stones, so no 'temp' is added here.
                // He just wants to minimize Alice's future score.
                stones = min(stones, f(idx + i, 1, max(M, i), piles, dp));
            }

            return dp[is_alice_turn][idx][M] = stones;
        }
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // M can theoretically grow up to N, so we size the M dimension as n + 1
        // Dimensions: [2] for turn, [n] for index, [n+1] for M
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        
        return f(0, 1, 1, piles, dp);
    }
};