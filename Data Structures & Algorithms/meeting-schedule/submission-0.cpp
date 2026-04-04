/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            // If the start times are exactly the same, sort by the end time
            if (a.start == b.start) {
                return a.end < b.end;
            }
            // Otherwise, sort strictly by the start time
            return a.start < b.start;
        });

        int n=intervals.size(),i=0,j=0;
        while(i < n){
            j=i+1;
            while(j < n && intervals[j].start < intervals[i].end){
                return false;
            }
            i++;
        }
        return true;
    }
};
