class Solution {
public:
    // adj is a list of lists containing pairs: {neighbor_node, edge_weight}
    vector<int> dijkstra(int numNodes, int source, vector<vector<pair<int, int>>>& adj) {
        // 1. Initialize distances to Infinity
        vector<int> dist(numNodes, INT_MAX); 
        dist[source] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            // Optimization: If we already found a better path to this node, skip it
            if (currentDist > dist[currNode]) continue;
            
            // 4. Look at all neighbors (Relaxation step)
            for (auto& edge : adj[currNode]) {
                int nextNode = edge.first;
                int weight = edge.second;
                
                // If taking the path through 'currNode' is shorter
                if (currentDist + weight < dist[nextNode]) {
                    dist[nextNode] = currentDist + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // FIXED: Size is n + 1 to accommodate 1-based indexing
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
        }
        
        // Pass n + 1 so Dijkstra creates a large enough distance array
        vector<int> dist = dijkstra(n + 1, k, adj);
        
        int minTime = -1;
        
        // Start checking at node 1, completely ignoring index 0
        for(int i = 1; i <= n; i++){
            // (Using the exact literal you used in Dijkstra to prevent INT_MAX mismatch issues)
            if(dist[i] == INT_MAX){
                return -1; // A real node was unreachable
            }
            minTime = max(minTime, dist[i]);
        }
        
        return minTime;
    }
};