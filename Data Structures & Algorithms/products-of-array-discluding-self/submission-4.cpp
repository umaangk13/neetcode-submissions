class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, prod_z = 1, count = 0;
        for(int num : nums){
            prod *= num;
            if(num != 0){
                prod_z *= num;
            }
            else count++;
        }
        if(count >= 2){
            vector<int> res(nums.size(),0);
            return res;
        }
        vector<int> result;
        for(int num : nums){
            if(num != 0) result.push_back(prod/num);
            else result.push_back(prod_z);
        }
        return result;
    }
};
