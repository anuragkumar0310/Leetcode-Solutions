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
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], current_sum = nums[0], index = 1;
        while (index < nums.size()) {
            current_sum = current_sum > 0 ? current_sum + nums[index] : nums[index];
            max_sum = max_sum > current_sum ? max_sum : current_sum;
            index++;
        }
        return max_sum;
    }

    void merge_sort(vector<int>& array) {
        if (array.size() < 2) return;
        vector<int> left(array.begin(), array.begin() + array.size() / 2);
        vector<int> right(array.begin() + array.size() / 2, array.end());
        merge_sort(left);
        merge_sort(right);
        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) 
            array[k++] = left[i] <= right[j] ? left[i++] : right[j++];
        while (i < left.size()) array[k++] = left[i++];
        while (j < right.size()) array[k++] = right[j++];
    }
};

