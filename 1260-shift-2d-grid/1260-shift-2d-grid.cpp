class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total;
        
        vector<vector<int>> result(m, vector<int>(n));
        for (int idx = 0; idx < total; idx++) {
            int srcIdx = ((idx - k) % total + total) % total; // handle negative mod
            result[idx / n][idx % n] = grid[srcIdx / n][srcIdx % n];
        }
        return result;
    }
};