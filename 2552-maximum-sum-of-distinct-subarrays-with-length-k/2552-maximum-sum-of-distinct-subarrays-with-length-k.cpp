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

void mergeArrays(vector<int>& arr, int alpha, int beta, int gamma) {
    vector<int> leftPart(beta - alpha + 1);
    vector<int> rightPart(gamma - beta);
    
    int idx1 = 0;
    while(idx1 < leftPart.size()) {
        leftPart[idx1] = arr[alpha + idx1];
        idx1++;
    }
    
    int idx2 = 0;
    while(idx2 < rightPart.size()) {
        rightPart[idx2] = arr[beta + 1 + idx2];
        idx2++;
    }
    
    int omega = 0, sigma = 0, delta = alpha;
    
    while(omega < leftPart.size() && sigma < rightPart.size()) {
        arr[delta++] = (leftPart[omega] <= rightPart[sigma]) ? leftPart[omega++] : rightPart[sigma++];
    }
    
    while(omega < leftPart.size()) {
        arr[delta++] = leftPart[omega++];
    }
    
    while(sigma < rightPart.size()) {
        arr[delta++] = rightPart[sigma++];
    }
}

void customMergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        customMergeSort(arr, start, mid);
        customMergeSort(arr, mid + 1, end);
        mergeArrays(arr, start, mid, end);
    }
}

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long currentSum = 0;
        map<int, int> elementCount;
        
        int windowStart = 0;
        int windowEnd = 0;
        
        while(windowEnd < nums.size()) {
            currentSum += nums[windowEnd];
            elementCount[nums[windowEnd]]++;
            
            if(windowEnd - windowStart + 1 == k) {
                maxSum = elementCount.size() == k ? max(maxSum, currentSum) : maxSum;
                currentSum -= nums[windowStart];
                elementCount[nums[windowStart]]--;
                elementCount[nums[windowStart]] == 0 ? elementCount.erase(nums[windowStart]) : elementCount[nums[windowStart]];
                windowStart++;
            }
            
            windowEnd++;
        }
        
        return maxSum;
    }
};