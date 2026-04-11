class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }

        int lcs=0;
        for(int num : nums){
            if(set.count(num-1) > 0) continue;
            else{
                int temp=num,count=0;
                while(set.count(temp) > 0){
                    count++;
                    temp++;
                }
                lcs = max(lcs, count);
            }
        }
        return lcs;
    }
};
