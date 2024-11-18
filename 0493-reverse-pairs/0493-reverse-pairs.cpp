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
private:
    ll calculatePairsAndMerge(vector<int>& nums, vector<int>& temp, int start, int mid, int end) {
        ll count = 0;
        int left = start;
        int right = mid + 1;
        int idx = start;
        
        int pairRight = mid + 1;
        int pairLeft = start;
        
        while (pairLeft <= mid) {
            while ((pairRight <= end) && ((ll)nums[pairLeft] > (ll)2 * nums[pairRight])) {
                pairRight++;
            }
            count += (pairRight - (mid + 1));
            pairLeft++;
        }
        
        while ((left <= mid) && (right <= end)) {
            temp[idx++] = (nums[left] <= nums[right]) ? nums[left++] : nums[right++];
        }
        
        while (left <= mid) {
            temp[idx++] = nums[left++];
        }
        
        while (right <= end) {
            temp[idx++] = nums[right++];
        }
        
        idx = start;
        while (idx <= end) {
            nums[idx] = temp[idx];
            idx++;
        }
        
        return count;
    }
    
    ll divideAndMerge(vector<int>& nums, vector<int>& temp, int start, int end) {
        ll inversions = 0;
        
        (start < end) ? (
            inversions = divideAndMerge(nums, temp, start, start + (end - start) / 2) +
                        divideAndMerge(nums, temp, start + (end - start) / 2 + 1, end) +
                        calculatePairsAndMerge(nums, temp, start, start + (end - start) / 2, end)
        ) : inversions = 0;
        
        return inversions;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int arraySize = nums.size();
        vector<int> tempArray(arraySize);
        return (arraySize < 2) ? 0 : divideAndMerge(nums, tempArray, 0, arraySize - 1);
    }
};