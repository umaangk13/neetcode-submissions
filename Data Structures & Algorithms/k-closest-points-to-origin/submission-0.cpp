class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,pair<int,int>>> maxHeap;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            int distsq = x*x + y*y;
            maxHeap.push({distsq,{x,y}});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while(!maxHeap.empty()){
            auto it = maxHeap.top(); maxHeap.pop();
            result.push_back({it.second.first,it.second.second});
        }
        return result;
    }
};
