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
    bool simulateProcess(vector<int>& nums, int curr, bool goRight) {
        vector<int> temp = nums;
        int n = nums.size();
        
        while (curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                goRight = !goRight;
            }
            curr += (goRight ? 1 : -1);
        }
        
        int sum = 0;
        int i = 0;
        while (i < n) {
            sum += temp[i];
            i++;
        }
        return sum == 0;
    }
    
    int countValidSelections(vector<int>& nums) {
        int validCount = 0;
        int n = nums.size();
        int pos = 0;
        
        while (pos < n) {
            validCount += (nums[pos] == 0) ? 
                         (simulateProcess(nums, pos, true) + 
                          simulateProcess(nums, pos, false)) : 0;
            pos++;
        }
        
        return validCount;
    }
};