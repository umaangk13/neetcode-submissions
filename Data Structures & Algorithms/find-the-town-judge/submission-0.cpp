class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDeg(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto &it : trust){
            adj[it[0]].push_back(it[1]);
            inDeg[it[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(inDeg[i] == n-1 && adj[i].empty()){
                return i;
            }
        }
        return -1;
    }
};