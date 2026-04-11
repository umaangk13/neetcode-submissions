class Solution {
public:
    int f(int target, vector<int>& nums){
        if(target == 0) return 1;

        int total=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > target) break;
            total += f(target-nums[i],nums);
        }

        return total;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return f(target,nums);
    }
};