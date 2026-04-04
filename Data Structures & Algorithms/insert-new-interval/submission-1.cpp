class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;

        while(i<intervals.size()){
            if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
                i++;
            }
            else{
                break;
            }
        }
        
        int newSt = newInterval[0];
        int newEnd = newInterval[1];
        while(i<intervals.size()){
            if(intervals[i][0] <= newInterval[1]){
                newSt = min(newSt,intervals[i][0]);
                newEnd = max(newEnd,intervals[i][1]);
            }
            else{
                break;
            }
            i++;
        }
        result.push_back({newSt,newEnd});

        while(i<intervals.size()){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
