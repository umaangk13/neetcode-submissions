class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int> &dp){
        if(idx == nums.size()-1) return 0;
        if(idx >= nums.size() || nums[idx] == 0) return 1e9;
        
        if(dp[idx] != -1) return dp[idx];
        
        int temp=1e9;
        for(int i=1;i<=nums[idx];i++){
            temp = min(temp, 1 + f(idx+i,nums,dp));
        }
        return dp[idx] = temp;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};
