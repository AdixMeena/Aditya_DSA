class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int m = t.size();

        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        vector<pair<char, int>> groups;
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            groups.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        for (int i = 1; i + 1 < groups.size(); i++) {
            if (groups[i].first == '1' &&
                groups[i - 1].first == '0' &&
                groups[i + 1].first == '0') {

                int lost = groups[i].second;

                if (i - 2 >= 0 && i + 2 < groups.size() &&
                    groups[i - 2].first == '1' &&
                    groups[i + 2].first == '1') {

                    int gain = groups[i - 1].second +
                               groups[i].second +
                               groups[i + 1].second;

                    ans = max(ans, ones - lost + gain);
                }
            }
        }

        return ans;
    }
};