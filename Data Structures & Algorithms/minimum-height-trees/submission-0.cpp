class Solution {
public:
    int bfs(int node, vector<vector<int>> &adj){
        vector<int> visited(adj.size(),0);

        queue<int> q;
        q.push(node);
        visited[node] = 1;
        int height=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front(); q.pop();
                for(int num : adj[curr]){
                    if(visited[num] != 1){
                        visited[num] = 1;
                        q.push(num);
                    }
                }
            }
            height++;
        }
        return height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> heights(n,0);
        int minH=INT_MAX;
        for(int i=0;i<n;i++){
            heights[i] = bfs(i,adj);
            minH = min(minH, heights[i]);
        }

        vector<int> result;
        for(int i=0;i<n;i++){
            if(heights[i] == minH){
                result.push_back(i);
            }
        }

        return result;
    }
};