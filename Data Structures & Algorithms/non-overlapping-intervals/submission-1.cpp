class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int remove=0, n=intervals.size(), i=0, j=0;
        while(i < n){
            int st = intervals[i][0];
            int end = intervals[i][1];
            j = i+1;
            while(j < n && intervals[j][0] < end){
                if(end < intervals[j][1]){
                    remove++;
                    j++;    
                }
                else{
                    end = intervals[j][1];
                    remove++;
                    j++;
                }
            }
            i=j;
        }
        return remove;
    }
};
