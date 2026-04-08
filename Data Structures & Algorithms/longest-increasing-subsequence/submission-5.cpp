class Solution {
public:
    /* Binary Search approach O(nlogn) */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> elements;
        elements.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(elements.back() < nums[i]){
                elements.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(elements.begin(),elements.end(),nums[i]);
                int idx = it - elements.begin();
                elements[idx] = nums[i];
            }
        }
        return elements.size();
    }
};
