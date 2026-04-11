class Solution {
public:
    // This function returns the MAXIMUM ABSOLUTE SCORE Alice can get from piles[l...r]
    int f(int l, int r, vector<int>& piles, vector<vector<int>>& dp) {
        if (l > r) return 0;
        
        if (dp[l][r] != -1) return dp[l][r];
        
        // Deduce whose turn it is. 
        // Since the game starts with an EVEN number of piles, 
        // any time there is an EVEN number of piles left, it's Alice's turn.
        int remaining_piles = r - l + 1;
        bool is_alice_turn = (remaining_piles % 2 == 0);
        
        if (is_alice_turn) {
            // ALICE'S TURN: Alice wants to MAXIMIZE her own score.
            // If she takes a pile, we add its value to her total.
            int take_left = piles[l] + f(l + 1, r, piles, dp);
            int take_right = piles[r] + f(l, r - 1, piles, dp);
            
            return dp[l][r] = max(take_left, take_right);
        } 
        else {
            // BOB'S TURN: Bob wants to MINIMIZE Alice's score.
            // If Bob takes a pile, Alice gets 0 points for this turn.
            int take_left = 0 + f(l + 1, r, piles, dp);
            int take_right = 0 + f(l, r - 1, piles, dp);
            
            return dp[l][r] = min(take_left, take_right);
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        int total_stones = 0;
        for(int pile : piles) {
            total_stones += pile;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Calculate the absolute maximum stones Alice can guarantee for herself
        int alice_max_score = f(0, n - 1, piles, dp);
        
        // Bob gets whatever is left over
        int bob_score = total_stones - alice_max_score;
        
        return alice_max_score > bob_score;
    }
};