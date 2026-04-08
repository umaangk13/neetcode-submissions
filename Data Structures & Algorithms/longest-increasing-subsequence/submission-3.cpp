class Solution {
public:
    int f(int idx, int prevIdx, vector<int>& nums, vector<vector<int>> &dp){
        // Base case: No more elements to look at, so the length going forward is 0.
        if(idx == nums.size()) return 0; 
        
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        
        // Option 1: Don't take the current element
        int nottake = f(idx+1, prevIdx, nums, dp); 
        
        // Option 2: Take the current element (if valid)
        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[idx]){
            // Add 1 HERE, representing the element we just took, 
            // plus whatever the longest valid sequence is after this.
            take = 1 + f(idx+1, idx, nums, dp); 
        }
        
        // Cache and return the max of the two options
        return dp[idx][prevIdx+1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};
