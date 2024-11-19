#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional> 
using namespace std;  
 
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        
        int n = s.length();
        vector<int> dp(n, 0);
        int maxLen = 0;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                }
                else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + ((i - dp[i-1] >= 2) ? dp[i - dp[i-1] - 2] : 0) + 2;
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        
        return maxLen;
    }
};
