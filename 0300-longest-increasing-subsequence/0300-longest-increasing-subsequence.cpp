class Solution {
public:

    int f(int i, int j, vector<int>& seq, int n, vector<vector<int>>& dp) {

        if(i == n) 
        return 0;
        
        if(dp[i][j+1] != -1) return dp[i][j+1];    
        int len = 0 + f(i+1, j, seq, n, dp);

        if(j == -1 || seq[i] > seq[j]) {
            len = max(len, 1 + f(i+1, i, seq, n, dp));
        }
        return dp[i][j+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, n, dp);
    }
};
