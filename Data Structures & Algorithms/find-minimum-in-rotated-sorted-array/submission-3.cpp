class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid = l + (r - l) / 2;
            // If mid is greater than the rightmost element, 
            // the rotation/minimum MUST be to the right of mid.
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } 
            // Otherwise, the right side is sorted properly, 
            // meaning the minimum is at mid or to the left of mid.
            else {
                r = mid;
            }
        }
        // When l == r, we have narrowed down to the minimum element.
        return nums[l];
    }
};
