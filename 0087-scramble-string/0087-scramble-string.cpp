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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != s2.length()) return false;

        if (s1 == s2) return true;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return solve(0, 0, n, s1, s2, dp);
    }

private:
    bool solve(int i1, int i2, int len, const string &s1, const string &s2, vector<vector<vector<int>>> &dp) {
        if (len == 1) return s1[i1] == s2[i2];

        if (dp[i1][i2][len] != -1) return dp[i1][i2][len];

        bool result = false;
        for (int k = 1; k < len && !result; ++k) {
            result = (solve(i1, i2, k, s1, s2, dp) && solve(i1 + k, i2 + k, len - k, s1, s2, dp)) ||
                     (solve(i1, i2 + len - k, k, s1, s2, dp) && solve(i1 + k, i2, len - k, s1, s2, dp));
        }

        dp[i1][i2][len] = result;
        return result;
    }
};
