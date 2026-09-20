class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        unordered_set<long long> seen;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    long long need = (long long)target - nums[i] - nums[j] - nums[k];

                    if (seen.count(need)) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)need};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
            seen.insert(nums[i]);   // only earlier indices are in the set
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};