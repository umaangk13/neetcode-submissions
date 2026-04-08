class Solution {
public:
    bool f(int idx, int sum1, int &totalsum, vector<int>& nums, vector<vector<int>> &dp){
        if(idx == nums.size()){
            return sum1 == totalsum/2;
        }
        if(dp[idx][sum1] != -1) return dp[idx][sum1];

        return dp[idx][sum1] = f(idx+1,sum1+nums[idx],totalsum,nums,dp) || f(idx+1,sum1,totalsum,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num : nums){
            sum += num;
        }
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return f(0,0,sum,nums,dp);
    }
};
