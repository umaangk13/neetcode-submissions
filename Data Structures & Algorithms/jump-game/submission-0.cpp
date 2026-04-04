class Solution {
public:
    bool f(int idx, vector<int>& nums){
        if(idx == nums.size()-1) return true;
        if(idx >= nums.size() || nums[idx] == 0) return false;

        for(int i=1;i<=nums[idx];i++){
            if(f(idx+i,nums)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return f(0,nums);
    }
};
