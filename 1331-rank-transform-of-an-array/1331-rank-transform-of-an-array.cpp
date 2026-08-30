class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> rank;
        int r = 1;
        for (int num : sorted) {
            if (rank.find(num) == rank.end()) {
                rank[num] = r++;
            }
        }
        
        vector<int> result;
        result.reserve(arr.size());
        for (int num : arr) {
            result.push_back(rank[num]);
        }
        
        return result;
    }
};