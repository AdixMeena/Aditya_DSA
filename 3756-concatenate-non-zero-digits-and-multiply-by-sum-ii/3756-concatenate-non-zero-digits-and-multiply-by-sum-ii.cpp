class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int m = s.size();

        vector<long long> prefixVal(m + 1, 0);
        vector<long long> prefixCount(m + 1, 0);
        vector<long long> prefixSum(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            prefixVal[i + 1]   = prefixVal[i];
            prefixCount[i + 1] = prefixCount[i];
            prefixSum[i + 1]   = prefixSum[i];

            if (digit != 0) {
                prefixVal[i + 1]   = (prefixVal[i] * 10 + digit) % MOD;
                prefixCount[i + 1] = prefixCount[i] + 1;
                prefixSum[i + 1]   = prefixSum[i] + digit;
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long cnt = prefixCount[r + 1] - prefixCount[l];

            if (cnt == 0) {
                answer.push_back(0);
                continue;
            }

            long long xVal = ( (prefixVal[r + 1] - prefixVal[l] * pow10[cnt] % MOD) % MOD + MOD ) % MOD;
            long long sum  = prefixSum[r + 1] - prefixSum[l];

            long long ans = (xVal * (sum % MOD)) % MOD;
            answer.push_back((int)ans);
        }

        return answer;
    }
};