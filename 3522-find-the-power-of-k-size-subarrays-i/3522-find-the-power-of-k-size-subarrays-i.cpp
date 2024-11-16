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
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> results;
        int n = nums.size();
        int i = 0;
        
        while (i <= n - k) {
            int maxVal = nums[i];
            int j = i;
            bool isConsecutive = true;
            
            while (j < i + k - 1) {
                isConsecutive = isConsecutive && (nums[j + 1] == nums[j] + 1);
                maxVal = nums[j + 1] > maxVal ? nums[j + 1] : maxVal;
                j++;
            }
            
            int minVal = maxVal;
            j = i;
            
            while (j < i + k) {
                minVal = nums[j] < minVal ? nums[j] : minVal;
                j++;
            }
            
            bool isSorted = true;
            j = i;
            
            while (j < i + k - 1) {
                isSorted = isSorted && (nums[j] <= nums[j + 1]);
                j++;
            }
            
            results.push_back((isConsecutive && isSorted && maxVal - minVal == k - 1) ? maxVal : -1);
            i++;
        }
        
        return results;
    }
};