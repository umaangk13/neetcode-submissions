class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findUPart(int node){
        if(parent[node] == node) return node; // FIXED: == instead of =
        return parent[node] = findUPart(parent[node]); // Path compression
    }
    void unionBySize(int u, int v){
        int prt_u = findUPart(u);
        int prt_v = findUPart(v);
        if(prt_u == prt_v) return;

        if(rank[prt_u] < rank[prt_v]){
            parent[prt_u] = prt_v;
        }
        else if(rank[prt_u] > rank[prt_v]){
            parent[prt_v] = prt_u;
        }
        else{
            parent[prt_v] = prt_u;
            rank[prt_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);

        // Step 1: Map each unique email to its first-seen account index
        // and union the accounts if the email is seen again.
        unordered_map<string, int> exist;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(exist.find(mail) != exist.end()){
                    dsu.unionBySize(i, exist[mail]);
                }
                else{
                    exist[mail] = i;
                }
            }
        }
        
        // Step 2: Group unique emails by their ultimate parent account index
        vector<vector<string>> mergedMail(n);
        for(auto it : exist){
            string mail = it.first;
            int node = dsu.findUPart(it.second);
            mergedMail[node].push_back(mail);
        }

        // Step 3: Format the output (Add names and sort emails)
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            // If this index isn't a parent/has no emails, skip it
            if(mergedMail[i].size() == 0) continue; 
            
            // Sort the emails alphabetically
            sort(mergedMail[i].begin(), mergedMail[i].end()); 
            
            vector<string> temp;
            temp.push_back(accounts[i][0]); // Push the account Name
            
            // Push all the sorted emails
            for(auto mail : mergedMail[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};