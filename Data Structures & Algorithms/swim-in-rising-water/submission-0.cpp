class DSU {
public:
    vector<int> parent;
    vector<int> size;
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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0];
        vector<vector<int>> submerged(n, vector<int>(n, 0));
        DSU dsu(n * n);

        int Row[] = {-1, 0, 1, 0};
        int Col[] = {0, 1, 0, -1};

        vector<pair<int,int>> loc(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                loc[grid[i][j]] = {i,j};
            }
        }

        int time=0;
        while(dsu.findUPar(0) != dsu.findUPar((n*n)-1)){
            auto [i,j] = loc[time];
            submerged[i][j] = 1;

            for (int k = 0; k < 4; k++) {
                int dr = i + Row[k];
                int dc = j + Col[k];

                // Union with neighbors ONLY if they are already submerged
                if (dr >= 0 && dr < n && dc >= 0 && dc < n &&
                    submerged[dr][dc] == 1) {
                    dsu.unionBySize(i * n + j, dr * n + dc);
                }
            }
            time++;
        }
        return time - 1;
    }
};
