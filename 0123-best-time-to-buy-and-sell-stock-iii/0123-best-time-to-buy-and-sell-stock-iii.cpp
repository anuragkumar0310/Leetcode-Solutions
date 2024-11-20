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
    void mergeArrayParts(vector<int>& alpha, int start, int mid, int end) {
        vector<int> beta(end - start + 1);
        int ptr1 = start, ptr2 = mid + 1, ptr3 = 0;
        
        while (ptr1 <= mid && ptr2 <= end) {
            beta[ptr3++] = (alpha[ptr1] <= alpha[ptr2]) ? alpha[ptr1++] : alpha[ptr2++];
        }
        
        while (ptr1 <= mid) beta[ptr3++] = alpha[ptr1++];
        while (ptr2 <= end) beta[ptr3++] = alpha[ptr2++];
        
        ptr3 = 0;
        while (ptr3 < beta.size()) {
            alpha[start + ptr3] = beta[ptr3];
            ptr3++;
        }
    }
    
    void customMergeSort(vector<int>& alpha, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            customMergeSort(alpha, start, mid);
            customMergeSort(alpha, mid + 1, end);
            mergeArrayParts(alpha, start, mid, end);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> profitLeft(len, 0);
        vector<int> profitRight(len, 0);
        
        int minPrice = prices[0];
        int idx = 1;
        
        while (idx < len) {
            minPrice = (prices[idx] < minPrice) ? prices[idx] : minPrice;
            profitLeft[idx] = (prices[idx] - minPrice > profitLeft[idx - 1]) ? 
                              prices[idx] - minPrice : profitLeft[idx - 1];
            idx++;
        }
        
        int maxPrice = prices[len - 1];
        idx = len - 2;
        
        while (idx >= 0) {
            maxPrice = (prices[idx] > maxPrice) ? prices[idx] : maxPrice;
            profitRight[idx] = (maxPrice - prices[idx] > profitRight[idx + 1]) ? 
                               maxPrice - prices[idx] : profitRight[idx + 1];
            idx--;
        }
        
        int maxTotalProfit = profitRight[0];
        idx = 1;
        
        while (idx < len) {
            maxTotalProfit = (profitLeft[idx - 1] + profitRight[idx] > maxTotalProfit) ?
                             profitLeft[idx - 1] + profitRight[idx] : maxTotalProfit;
            idx++;
        }
        
        return maxTotalProfit;
    }
};

