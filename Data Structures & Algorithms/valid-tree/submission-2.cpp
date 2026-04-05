class Solution {
public:
    bool dfs(int i, int prev, int start, vector<int> &visited, vector<vector<int>> &adjList){
        visited[i] = 1;
        for(int neigh : adjList[i]){
            if(visited[neigh] == 1 && neigh != prev){
                return false;
            }
            else if(visited[neigh] != 1 && !dfs(neigh,i,start,visited,adjList)){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        vector<vector<int>> adjList(n);
        vector<int> visited(n,0);
        for(auto &it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        // 1. Run exactly ONE DFS starting from node 0
        if(!dfs(0, -1, 0, visited, adjList)){
            return false;
        }
        
        // 2. Check if that single DFS was able to reach every node
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                return false; // It's disconnected!
            }
        }
        return true;
    }
};
