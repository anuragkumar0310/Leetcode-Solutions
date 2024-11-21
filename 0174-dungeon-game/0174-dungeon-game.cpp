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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[m-1][n-1] = max(1 - dungeon[m-1][n-1], 1);
        
        int i = m - 1, j = n - 2;
        while (j >= 0) {
            dp[m-1][j] = max(dp[m-1][j+1] - dungeon[m-1][j], 1);
            j--;
        }
        
        i = m - 2, j = n - 1;
        while (i >= 0) {
            dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 1);
            i--;
        }
        
        i = m - 2;
        while (i >= 0) {
            j = n - 2;
            while (j >= 0) {
                int minHealth = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(minHealth, 1);
                j--;
            }
            i--;
        }
        
        return dp[0][0];
    }
};

