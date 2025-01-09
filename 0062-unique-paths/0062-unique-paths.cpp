class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        int row = 1;
        while (row < m) {
            int col = 1;
            while (col < n) {
                dp[col] += dp[col - 1];
                col++;
            }
            row++;
        }
        return dp[n - 1];
    }
};
