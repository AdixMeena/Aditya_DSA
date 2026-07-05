class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const long long MOD = 1e9 + 7;
        const long long NEG = -1; // sentinel: unreachable

        vector<vector<long long>> dp(n, vector<long long>(n, NEG));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));

        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;

        // process in order of decreasing i, then decreasing j
        // (predecessors are (i+1,j), (i,j+1), (i+1,j+1), all "later")
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == n-1 && j == n-1) continue; // S already set
                if (board[i][j] == 'X') continue;

                long long best = NEG;
                long long ways = 0;

                // candidates: down, right, down-right
                int di[3] = {1, 0, 1};
                int dj[3] = {0, 1, 1};
                for (int d = 0; d < 3; d++) {
                    int ni = i + di[d], nj = j + dj[d];
                    if (ni >= n || nj >= n) continue;
                    if (dp[ni][nj] == NEG) continue;

                    long long cand = dp[ni][nj];
                    if (cand > best) {
                        best = cand;
                        ways = cnt[ni][nj];
                    } else if (cand == best) {
                        ways = (ways + cnt[ni][nj]) % MOD;
                    }
                }

                if (best == NEG) continue; // unreachable

                long long add = 0;
                if (board[i][j] != 'E' && board[i][j] != 'S') {
                    add = board[i][j] - '0';
                }

                dp[i][j] = best + add;
                cnt[i][j] = ways;
            }
        }

        if (dp[0][0] == NEG) return {0, 0};
        return {(int)dp[0][0], (int)cnt[0][0]};
    }
};