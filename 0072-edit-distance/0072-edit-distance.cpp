class Solution {
    int solve(int index1, int index2, string& word1, string& word2, vector<vector<int>>& dp) {
        if(index1 < 0) return index2 + 1;
        if(index2 < 0) return index1 + 1;
        
        if(dp[index1][index2] != -1) return dp[index1][index2];
        
        if(word1[index1] == word2[index2]) {
            dp[index1][index2] = solve(index1-1, index2-1, word1, word2, dp);
            return dp[index1][index2];
        }
        
        int insertion = solve(index1, index2-1, word1, word2, dp);
        int deletion = solve(index1-1, index2, word1, word2, dp);
        int replacement = solve(index1-1, index2-1, word1, word2, dp);
        
        dp[index1][index2] = min(insertion, min(deletion, replacement)) + 1;
        return dp[index1][index2];
    }
    
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(n1-1, n2-1, word1, word2, dp);
    }
};