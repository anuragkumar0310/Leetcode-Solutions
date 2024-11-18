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
    void nextPermutation(vector<int>& nums) {
        if (findNextPermutation(nums)) return;
        reverse(nums.begin(), nums.end());
    }
    
private:
    bool findNextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i < 0) return false;
        
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        
        swap(nums[i], nums[j]);
        
        auto left = nums.begin() + i + 1;
        auto right = nums.end() - 1;
        
        while (left < right) {
            swap(*left, *right);
            left++;
            right--;
        }
        
        return true;
    }
};