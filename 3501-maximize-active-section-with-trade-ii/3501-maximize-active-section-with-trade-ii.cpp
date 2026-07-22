#include <bits/stdc++.h>
using namespace std;

struct Group {
    int start;
    int length;
};

class SparseTable {
public:
    SparseTable(const vector<int>& nums)
        : n(nums.size()), st(bit_width((unsigned)n) + 1, vector<int>(n + 1)) {
        copy(nums.begin(), nums.end(), st[0].begin());
        for (int i = 1; i <= bit_width((unsigned)n); ++i)
            for (int j = 0; j + (1 << i) <= n; ++j)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    // Returns max(nums[l..r]).
    int query(int l, int r) const {
        const int i = bit_width((unsigned)(r - l + 1)) - 1;
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }

private:
    const int n;
    vector<vector<int>> st; // st[i][j] := max(nums[j..j + 2^i - 1])
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        const int n = s.length();
        const int ones = count(s.begin(), s.end(), '1');
        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n);
        getZeroGroups(s, zeroGroups, zeroGroupIndex);

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        const SparseTable st(getZeroMergeLengths(zeroGroups));
        vector<int> ans;

        for (const vector<int>& query : queries) {
            const int l = query[0];
            const int r = query[1];
            const int left = zeroGroupIndex[l] == -1
                                  ? -1
                                  : (zeroGroups[zeroGroupIndex[l]].length -
                                     (l - zeroGroups[zeroGroupIndex[l]].start));
            const int right = zeroGroupIndex[r] == -1
                                   ? -1
                                   : (r - zeroGroups[zeroGroupIndex[r]].start + 1);

            const int startAdj = zeroGroupIndex[l] + 1;
            const int endAdj = (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1) - 1;

            int activeSections = ones;
            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r])
                activeSections = max(activeSections, ones + left + right);
            else if (startAdj <= endAdj)
                activeSections = max(activeSections, ones + st.query(startAdj, endAdj));

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <= (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1))
                activeSections = max(activeSections,
                                      ones + left + zeroGroups[zeroGroupIndex[l] + 1].length);

            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1)
                activeSections = max(activeSections,
                                      ones + right + zeroGroups[zeroGroupIndex[r] - 1].length);

            ans.push_back(activeSections);
        }

        return ans;
    }

private:
    void getZeroGroups(const string& s, vector<Group>& zeroGroups, vector<int>& zeroGroupIndex) {
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    ++zeroGroups.back().length;
                else
                    zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex[i] = zeroGroups.size() - 1;
        }
    }

    vector<int> getZeroMergeLengths(const vector<Group>& zeroGroups) {
        vector<int> zeroMergeLengths;
        for (int i = 0; i + 1 < (int)zeroGroups.size(); ++i)
            zeroMergeLengths.push_back(zeroGroups[i].length + zeroGroups[i + 1].length);
        return zeroMergeLengths;
    }
};