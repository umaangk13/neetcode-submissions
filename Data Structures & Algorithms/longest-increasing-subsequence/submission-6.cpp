class Solution {
public:
    vector<vector<int>> dp;

    int f(int idx, int lastidx, vector<int>& nums) {
        if (idx == nums.size()) return 0;

        // lastidx + 1 maps -1 to 0, 0 to 1, ..., n-1 to n
        if (dp[idx][lastidx + 1] != -1) return dp[idx][lastidx + 1];

        // Option 1: Do not take nums[idx]
        int notTake = f(idx + 1, lastidx, nums);

        // Option 2: Take nums[idx] if valid
        int take = 0;
        if (lastidx == -1 || nums[idx] > nums[lastidx]) {
            take = 1 + f(idx + 1, idx, nums);
        }

        return dp[idx][lastidx + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return f(0, -1, nums);
    }
};