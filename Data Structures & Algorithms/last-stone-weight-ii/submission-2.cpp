class Solution {
public:
    int f(int idx, int target, vector<int> &stones, vector<vector<int>> &dp){
        if(idx < 0) return target;
        if(dp[idx][target] != -1) return dp[idx][target];
        int take=INT_MAX, nottake=INT_MAX;
        if(stones[idx] <= target) take = f(idx-1,target-stones[idx],stones,dp);
        nottake = f(idx-1,target,stones,dp);

        return dp[idx][target] = min(take,nottake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int totalWeight = accumulate(stones.begin(), stones.end(), 0);
        int target = totalWeight/2;
        // Rows = number of stones, Cols = target + 1 (for 0 to target capacities)
        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, -1));

        // f() returns the minimum leftover space from our 'target' knapsack
        int min_leftover = f(stones.size() - 1, target, stones, dp);
        
        // The actual sum of the subset we managed to fit into the knapsack
        int subset_sum = target - min_leftover;
        
        // The difference between the two piles of stones
        return totalWeight - 2 * subset_sum;
    }
};