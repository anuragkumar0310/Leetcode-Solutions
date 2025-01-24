class Solution {
public:
    vector<vector<vector<string>>> dp;

    vector<string> generate(int open, int close, int n) {
        if (open == n && close == n) {
            return {""};
        }
        if (!dp[open][close].empty()) {
            return dp[open][close];
        }
        vector<string> result;

        if (open < n) {
            vector<string> openRes = generate(open + 1, close, n);
            for (const string &s : openRes) {
                result.push_back("(" + s);
            }
        }
        if (close < open) {
            vector<string> closeRes = generate(open, close + 1, n);
            for (const string &s : closeRes) {
                result.push_back(")" + s);
            }
        }
        return dp[open][close] = result;
    }
    vector<string> generateParenthesis(int n) {
        dp = vector<vector<vector<string>>>(n + 1, vector<vector<string>>(n + 1));
        return generate(0, 0, n);
    }
};
