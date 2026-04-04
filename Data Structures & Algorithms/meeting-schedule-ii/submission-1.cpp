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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        map<int,int> mp;
        for(Interval &it : intervals){
            mp[it.start]++;
            mp[it.end]--;
        }

        int temp=0, rooms = 0;
        for(auto &it : mp){
            temp += it.second;
            rooms = max(rooms, temp); 
        }

        return rooms;
    }
};
