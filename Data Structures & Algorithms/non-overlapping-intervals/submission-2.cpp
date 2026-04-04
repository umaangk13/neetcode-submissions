class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort the intervals. 
        // By default, C++ sorts a vector of vectors by the first element (start time).
        // If start times are equal, it sorts by the second element (end time).
        sort(intervals.begin(), intervals.end());
        
        int remove = 0;             // Counter for how many intervals we need to delete
        int n = intervals.size();   // Total number of intervals
        int i = 0;                  // Pointer for the current "reference" interval
        int j = 0;                  // Pointer to scan upcoming intervals
        
        // Step 2: Iterate through the intervals
        while(i < n) {
            int st = intervals[i][0];  // Start time of the reference interval (not strictly needed, but good for clarity)
            int end = intervals[i][1]; // End time of the reference interval
            j = i + 1;                 // Start checking the very next interval
            
            // Step 3: Check for overlaps. 
            // An overlap occurs if the next interval starts strictly BEFORE the reference interval ends.
            while(j < n && intervals[j][0] < end) {
                
                // Greedy Choice: If they overlap, we must remove one. 
                // We should always keep the interval that ends EARLIER to leave more room for future intervals.
                
                if(end < intervals[j][1]) {
                    // The reference interval ends EARLIER. 
                    // We conceptually keep the reference interval and "remove" the j-th interval.
                    // The 'end' variable stays the same.
                    remove++;
                    j++;    
                }
                else {
                    // The j-th interval ends EARLIER (or at the same time).
                    // We conceptually "remove" the reference interval and keep the j-th interval.
                    // We must update our reference 'end' to this new, earlier end time.
                    end = intervals[j][1];
                    remove++;
                    j++;
                }
            }
            
            // Step 4: Move 'i' to 'j'. 
            // 'j' is currently pointing to the first interval that DOES NOT overlap with our running 'end'.
            // This safely skips all the intervals we just conceptually removed.
            i = j;
        }
        
        // Step 5: Return the total number of removals required
        return remove;
    }
};