class Solution {
public:
    bool f(int idx, vector<int>& nums, vector<int> &dp){
        if(idx == nums.size()-1) return true;
        if(idx >= nums.size() || nums[idx] == 0) return false;
        if(dp[idx] != -1) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            if(f(idx+i,nums,dp)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return f(0,nums,dp);
        int n = nums.size();
        // dp[i] will be true (1) if we can reach the end from index i
        vector<int> dp(n, 0); 
        
        // Base case: We are already at the last index
        dp[n - 1] = 1; 

        // Work backwards from the second-to-last element
        for (int idx = n - 2; idx >= 0; idx--) {
            
            // Calculate the furthest we can safely jump without going out of bounds
            int furthestJump = min(idx + nums[idx], n - 1);
            
            // Try all possible jumps from this index
            for (int i = idx + 1; i <= furthestJump; i++) {
                if (dp[i] == 1) {
                    dp[idx] = 1; // If any reachable index can reach the end, this one can too
                    break;       // No need to check further jumps once we find a winning path
                }
            }
        }
        return dp[0];
    }
};
