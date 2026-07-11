class Solution {
public:
    vector<int> parent, rank_;
    
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression
            x = parent[x];
        }
        return x;
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank_.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        for (auto& e : edges) {
            unite(e[0], e[1]);
        }
        
        vector<long long> nodeCount(n, 0), edgeCount(n, 0);
        
        for (int v = 0; v < n; v++) {
            nodeCount[find(v)]++;
        }
        
        for (auto& e : edges) {
            edgeCount[find(e[0])]++;
        }
        
        int result = 0;
        for (int v = 0; v < n; v++) {
            if (find(v) == v) {
                long long k = nodeCount[v];
                if (edgeCount[v] == k * (k - 1) / 2) {
                    result++;
                }
            }
        }
        
        return result;
    }
};