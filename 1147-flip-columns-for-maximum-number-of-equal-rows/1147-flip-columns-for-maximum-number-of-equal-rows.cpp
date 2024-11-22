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
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> patternCount;
        int maxCount = 0;
        
        int i = 0;
        while (i < matrix.size()) {
            string pattern = "";
            int j = 0;
            
            while (j < matrix[0].size()) {
                pattern += (matrix[i][0] == 1) ? 
                    to_string(matrix[i][j]) : 
                    to_string(1 - matrix[i][j]);
                j++;
            }
            
            patternCount[pattern] = patternCount[pattern] + 1;
            maxCount = (patternCount[pattern] > maxCount) ? 
                patternCount[pattern] : maxCount;
            i++;
        }
        
        return maxCount;
    }
};