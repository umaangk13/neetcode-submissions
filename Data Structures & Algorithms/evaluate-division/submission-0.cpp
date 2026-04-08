class Solution {
public:
    // DFS now returns the calculated value. Returns -1.0 if no path is found.
    double dfs(int node, int target, vector<vector<pair<int,double>>>& adj, vector<int>& visited) {
        if (node == target) return 1.0;
        visited[node] = 1;

        for (auto& it : adj[node]) {
            int nextNode = it.first;
            double wt = it.second;
            
            if (visited[nextNode] != 1) {
                // Recursively search down this path
                double result = dfs(nextNode, target, adj, visited);
                
                // If the path successfully reached the target, multiply and return!
                if (result != -1.0) {
                    return result * wt;
                }
            }
        }

        return -1.0; // Dead end
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> mp;
        int idx = 0;
        
        // 1. Build the mapping of Strings -> Integer IDs
        for (auto& it : equations) {
            if (mp.find(it[0]) == mp.end()) {
                mp[it[0]] = idx++;
            }
            if (mp.find(it[1]) == mp.end()) {
                mp[it[1]] = idx++;
            }
        }

        // 2. Build the Graph
        vector<vector<pair<int, double>>> adj(idx);
        for (int i = 0; i < equations.size(); i++) {
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            double wt = values[i];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 1.0 / wt}); // Add the reverse edge
        }

        // 3. Process the Queries
        vector<double> result;
        for (auto& q : queries) {
            string srcStr = q[0];
            string targetStr = q[1];

            // If either node doesn't exist in our graph, the answer is -1.0
            if (mp.find(srcStr) == mp.end() || mp.find(targetStr) == mp.end()) {
                result.push_back(-1.0);
            } else {
                int src = mp[srcStr];
                int target = mp[targetStr];
                
                // Create a fresh visited array for each query
                vector<int> visited(idx, 0); 
                
                // Run the DFS
                result.push_back(dfs(src, target, adj, visited));
            }
        }

        return result;
    }
};