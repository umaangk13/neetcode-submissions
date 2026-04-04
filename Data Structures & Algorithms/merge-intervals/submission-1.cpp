class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;

        int n = intervals.size(), i=0, j=0;
        while(i < n){
            int st = intervals[i][0];
            int end = intervals[i][1];
            j = i+1;
            while(j < n){
                if(intervals[j][0] <= end){
                    end = max(end,intervals[j][1]);
                }
                else{
                    break;
                }
                j++;
            }
            result.push_back({st,end});
            i = j;
        }

        return result;
    }
};
