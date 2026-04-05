class DSU {
    vector<int> parent;
    vector<int> size;

public:
    // Constructor: Initialize n isolated sets
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1); // Initially, every set has a size of 1
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Every node is its own parent initially
        }
    }

    // Find the ultimate parent (root) with Path Compression
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        // Path Compression: attach directly to the ultimate parent
        return parent[node] = findUPar(parent[node]); 
    }

    // Merge two sets by Size
    void unionBySize(int u, int v) {
        int rootU = findUPar(u);
        int rootV = findUPar(v);

        // If they have the same root, they are already in the same set
        if (rootU == rootV) return;

        // Attach the smaller tree to the larger tree
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);
        vector<int> result(2);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(dsu.findUPar(u) == dsu.findUPar(v)){
                result = {u,v};
            }
            else{
                dsu.unionBySize(u,v);
            }
        }
        return result;
    }
};
