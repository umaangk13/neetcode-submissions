class Solution {
public:
    vector<vector<int>> dp;
    int f(int left, int right, const vector<int>& nums) {
        // No balloons left between left and right
        if (left > right) return 0;

        if (dp[left][right] != -1) return dp[left][right];

        int max_coins = 0;
        // k is the LAST balloon burst in the close range [left, right]
        for (int k = left; k <= right; ++k) {
            int coins = nums[left-1] * nums[k] * nums[right+1]
                      + f(left, k-1, nums)
                      + f(k+1, right, nums);

            max_coins = max(max_coins, coins);
        }

        return dp[left][right] = max_coins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Pad boundaries with 1: [1, nums[0], ..., nums[n-1], 1]
        vector<int> padded(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            padded[i + 1] = nums[i];
        }

        dp.assign(n+2, vector<int>(n+2,-1));

        return f(1, n, padded);
    }
};
