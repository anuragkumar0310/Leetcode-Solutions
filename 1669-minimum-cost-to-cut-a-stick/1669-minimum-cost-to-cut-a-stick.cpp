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
    void mergeProcess(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int idx1 = left, idx2 = mid + 1, idx3 = left;
        
        while ((idx1 <= mid) && (idx2 <= right)) {
            temp[idx3++] = (arr[idx1] <= arr[idx2]) ? arr[idx1++] : arr[idx2++];
        }
        
        while (idx1 <= mid) {
            temp[idx3++] = arr[idx1++];
        }
        
        while (idx2 <= right) {
            temp[idx3++] = arr[idx2++];
        }
        
        idx1 = left;
        while (idx1 <= right) {
            arr[idx1] = temp[idx1];
            idx1++;
        }
    }
    
    void mergeSortUtil(vector<int>& arr, vector<int>& temp, int left, int right) {
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            mergeSortUtil(arr, temp, left, mid);
            mergeSortUtil(arr, temp, mid + 1, right);
            mergeProcess(arr, temp, left, mid, right);
            return;
        }
    }
    
    void customSort(vector<int>& arr) {
        vector<int> temp(arr.size());
        mergeSortUtil(arr, temp, 0, arr.size() - 1);
    }
    
    int calculateMinCost(vector<int>& positions, vector<vector<int>>& memo, int start, int end) {
        while (start + 1 >= end) {
            return 0;
        }
        
        while (memo[start][end] != -1) {
            return memo[start][end];
        }
        
        int minCostValue = INT_MAX;
        int currentPos = start + 1;
        
        while (currentPos < end) {
            int currentCost = positions[end] - positions[start] +
                            calculateMinCost(positions, memo, start, currentPos) +
                            calculateMinCost(positions, memo, currentPos, end);
            minCostValue = (currentCost < minCostValue) ? currentCost : minCostValue;
            currentPos++;
        }
        
        return memo[start][end] = minCostValue;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> positions;
        positions.push_back(0);
        
        int idx = 0;
        while (idx < cuts.size()) {
            positions.push_back(cuts[idx]);
            idx++;
        }
        
        positions.push_back(n);
        customSort(positions);
        
        vector<vector<int>> memo(positions.size(), vector<int>(positions.size(), -1));
        return calculateMinCost(positions, memo, 0, positions.size() - 1);
    }
};