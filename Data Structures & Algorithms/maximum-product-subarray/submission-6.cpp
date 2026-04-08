class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        for(int num : nums){
            res = max(res,num);
        }
        int currMax=1,currMin=1;

        for(int num : nums){
            if(num == 0){
                currMax = 1; currMin = 1;
                continue;
            }
            int temp = currMax;
            currMax = max(num * currMax, max(num * currMin, num));
            currMin = min(num * temp, min(num * currMin, num));
            res = max(res, currMax);
        }

        return res;
    }
};
