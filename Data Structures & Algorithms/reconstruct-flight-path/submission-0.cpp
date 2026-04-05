class Solution {
public:
    // Min-Heap to automatically sort destinations lexically
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string airport) {
        // While there are still outgoing flights from this airport
        while(!adj[airport].empty()) {
            // 1. Get the smallest lexical destination
            string nextAirport = adj[airport].top();
            
            // 2. Remove the ticket so we don't use it again (Destructive Traversal)
            adj[airport].pop();
            
            // 3. Fly to that destination
            dfs(nextAirport);
        }
        // 4. Post-order: add the airport to the result once it has no outgoing flights left
        result.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph
        for(auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }

        // Start the DFS from JFK
        dfs("JFK");

        // The result is currently backwards because of post-order traversal, so reverse it
        reverse(result.begin(), result.end());
        
        return result;
    }
};