class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
      
        // dp[i][j] represents the maximum score difference (current player - opponent)
        // when playing optimally on piles from index i to j
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
      
        // Recursive function with memoization to calculate the maximum score difference
        // Parameters: i - left boundary index, j - right boundary index
        // Returns: maximum score difference the current player can achieve
        auto calculateMaxDifference = [&](this auto&& calculateMaxDifference, int i, int j) -> int {
            // Base case: no piles left to choose
            if (i > j) {
                return 0;
            }
          
            if (dp[i][j] != 0) {
                return dp[i][j];
            }
      
            int takeLeft = piles[i] - calculateMaxDifference(i + 1, j);
            int takeRight = piles[j] - calculateMaxDifference(i, j - 1);
          
            return dp[i][j] = max(takeLeft, takeRight);
        };
      
        return calculateMaxDifference(0, n - 1) > 0;
    }
};