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
    void mergeArrays(vector<int>& arr, int left, int mid, int right) {
        vector<int> tempLeft, tempRight;
        
        int ptr1 = left, ptr2 = 0;
        while(ptr2 < mid - left) {
            tempLeft.push_back(arr[ptr1]);
            ptr1++;
            ptr2++;
        }
        
        ptr1 = mid, ptr2 = 0;
        while(ptr2 < right - mid) {
            tempRight.push_back(arr[ptr1]);
            ptr1++;
            ptr2++;
        }
        
        int idx = left, leftPtr = 0, rightPtr = 0;
        while(leftPtr < tempLeft.size() && rightPtr < tempRight.size()) {
            arr[idx++] = (tempLeft[leftPtr] <= tempRight[rightPtr]) ? 
                         tempLeft[leftPtr++] : tempRight[rightPtr++];
        }
        
        while(leftPtr < tempLeft.size()) arr[idx++] = tempLeft[leftPtr++];
        while(rightPtr < tempRight.size()) arr[idx++] = tempRight[rightPtr++];
    }
    
    void mergeSortUtil(vector<int>& arr, int left, int right) {
        if(right - left <= 1) return;
        int mid = left + (right - left) / 2;
        mergeSortUtil(arr, left, mid);
        mergeSortUtil(arr, mid, right);
        mergeArrays(arr, left, mid, right);
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combinedArr;
        int ptr1 = 0, ptr2 = 0;
        
        while(ptr1 < nums1.size()) {
            combinedArr.push_back(nums1[ptr1]);
            ptr1++;
        }
        
        while(ptr2 < nums2.size()) {
            combinedArr.push_back(nums2[ptr2]);
            ptr2++;
        }
        
        mergeSortUtil(combinedArr, 0, combinedArr.size());
        
        int totalSize = combinedArr.size();
        return (totalSize % 2) ? 
               static_cast<double>(combinedArr[totalSize / 2]) : 
               (static_cast<double>(combinedArr[totalSize / 2 - 1]) + 
                static_cast<double>(combinedArr[totalSize / 2])) / 2.0;
    }
};