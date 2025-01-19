class Solution {
public:
    vector<vector<vector<int>>> dp;
    int totalStrings;
    
    pair<int, int> countZerosOnes(string& s) {
        int zeros = 0, ones = 0;
        for(char c : s) {
            if(c == '0') zeros++;
            else ones++;
        }
        return {zeros, ones};
    }
    
    int solve(int idx, vector<string>& strs, int m, int n, int currZeros, int currOnes) {
        if(idx == totalStrings) 
        return 0;

        if(dp[idx][currZeros][currOnes] != -1) 
        return dp[idx][currZeros][currOnes];
        
        auto [zeros, ones] = countZerosOnes(strs[idx]);
        int result = solve(idx + 1, strs, m, n, currZeros, currOnes);
        
        if(currZeros + zeros <= m && currOnes + ones <= n) {
            result = max(result, 1 + solve(idx + 1, strs, m, n, currZeros + zeros, currOnes + ones));
        }
        
        return dp[idx][currZeros][currOnes] = result;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        totalStrings = strs.size();
        dp.resize(601, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(0, strs, m, n, 0, 0);
    }
};