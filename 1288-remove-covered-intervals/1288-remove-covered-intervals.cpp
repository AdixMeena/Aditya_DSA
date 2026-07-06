class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // same start -> larger end first
            return a[0] < b[0]; // sort by start ascending
        });

        int count = 0;
        int maxEnd = 0;

        for (auto& interval : intervals) {
            int end = interval[1];
            if (end > maxEnd) {
                count++;
                maxEnd = end;
            }
            // else: covered, skip
        }

        return count;
    }
};