class Solution {
public:
    vector<bool> used;
    int target;
    bool backtrack(vector<int>& nums, int k, int currentSum, int start) {
        if (k == 0) return true;
        if (currentSum == target) return backtrack(nums, k - 1, 0, 0);

        for (int i = start; i < nums.size(); i++) {
            if (used[i] || currentSum + nums[i] > target) continue;
            used[i] = true;
            if (backtrack(nums, k, currentSum + nums[i], i + 1)) return true;
            used[i] = false;
            if (currentSum == 0) {  // Pruning
                return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        target = sum / k;
        sort(nums.rbegin(), nums.rend());
        used.assign(nums.size(), false);
        return backtrack(nums, k, 0, 0);
    }
    bool makesquare(vector<int>& matchsticks) {
        return canPartitionKSubsets(matchsticks,4);
    }
};