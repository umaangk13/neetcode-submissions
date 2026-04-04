class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        int q = queries.size();
        vector<pair<int,int>> sortedQueries(q);
        for(int i = 0; i < q; i++) sortedQueries[i] = {queries[i], i};
        sort(sortedQueries.begin(), sortedQueries.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        
        vector<int> ans(q, -1);
        int i = 0; // interval pointer
        
        for(auto& [query, idx] : sortedQueries){
            // add all intervals whose start <= query
            while(i < intervals.size() && intervals[i][0] <= query){
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++;
            }
            
            // remove intervals whose end < query
            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }
            
            // answer is top of heap
            if(!minHeap.empty()){
                ans[idx] = minHeap.top().first;
            }
        }
        
        return ans;
    }
};