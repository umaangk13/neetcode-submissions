class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPoints = points.size(); // Renamed to avoid shadowing
        vector<int> visited(numPoints, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        int nodesConnected = 0, cost = 0; 
        
        // A tree of N nodes is complete when we have connected N nodes.
        while (nodesConnected < numPoints) {
            auto [c, currNode] = pq.top();
            pq.pop();
            
            if (visited[currNode] == 1) continue;
            
            visited[currNode] = 1; // mark the node as visited
            nodesConnected++;
            cost += c;
            
            int x1 = points[currNode][0];
            int y1 = points[currNode][1];
            
            // Loop through all points using the correct upper bound
            for (int i = 0; i < numPoints; i++) {
                if (visited[i] == 0) {
                    int x2 = points[i][0];
                    int y2 = points[i][1];
                    int dist = abs(x2 - x1) + abs(y2 - y1);
                    pq.push({dist, i});
                }
            }
        }
        return cost;
    }
};