class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);

        // 1. Build graph and in-degrees
        for (auto& it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            inDeg[it[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        // Use array of unordered_sets to track ALL prerequisites for each node
        vector<unordered_set<int>> prereqs(numCourses);
        
        // 2. Process Kahn's Algorithm
        while (!q.empty()) {
            int curr = q.front(); 
            q.pop();
            
            for (int nextNode : adj[curr]) {
                // The current node is a prerequisite for the next node
                prereqs[nextNode].insert(curr);
                
                // CRITICAL: Transitivity. All prerequisites of 'curr' 
                // are also prerequisites of 'nextNode'
                for (int ancestor : prereqs[curr]) {
                    prereqs[nextNode].insert(ancestor);
                }
                
                inDeg[nextNode]--;
                if (inDeg[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }

        // 3. Answer Queries
        vector<bool> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int prereqCourse = queries[i][0];
            int targetCourse = queries[i][1];
            
            // Check if prereqCourse exists in the set of prerequisites for targetCourse
            result[i] = prereqs[targetCourse].count(prereqCourse) > 0;
        }
        
        return result;
    }
};