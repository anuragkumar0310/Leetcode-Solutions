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
    int minCut(string s) {
        int length = s.length();
        vector<vector<bool>> palindromeMatrix(length, vector<bool>(length, false));
        vector<int> minCutDP(length, 0);
        
        int idx = 0;
        while (idx < length) {
            int minCutValue = idx;
            int j = 0;
            
            while (j <= idx) {
                palindromeMatrix[j][idx] = (s[j] == s[idx] && (idx - j <= 2 || palindromeMatrix[j+1][idx-1]));
                
                minCutValue = palindromeMatrix[j][idx] 
                    ? (j > 0 ? min(minCutValue, minCutDP[j-1] + 1) : 0) 
                    : minCutValue;
                j++;
            }
            
            minCutDP[idx] = minCutValue;
            idx++;
        }
        
        return minCutDP[length-1];
    }
};

