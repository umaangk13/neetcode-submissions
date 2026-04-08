class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Base case: If there is only 1 node, it is the root of the MHT
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        // Build the adjacency list and record the degree of each node
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        
        // Find all initial leaf nodes (degree == 1) and push them to the queue
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remainingNodes = n;
        
        // Keep trimming leaves until 2 or fewer nodes remain
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size; // Subtract the number of leaves we are about to remove
            
            while (size--) {
                int leaf = q.front();
                q.pop();
                
                // For each neighbor of the leaf, decrease its degree
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    // If the neighbor becomes a new leaf, add it to the queue
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // The remaining nodes in the queue are the centers of the graph
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};