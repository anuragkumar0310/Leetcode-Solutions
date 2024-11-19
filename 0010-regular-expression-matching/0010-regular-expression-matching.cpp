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

void mergeArrays(vector<int>& arr, int left, int mid, int right) {
    int alpha = mid - left + 1;
    int beta = right - mid;
    
    vector<int> leftArr(alpha), rightArr(beta);
    
    int idx = 0;
    while(idx < alpha) { leftArr[idx] = arr[left + idx]; idx++; }
    
    idx = 0;
    while(idx < beta) { rightArr[idx] = arr[mid + 1 + idx]; idx++; }
    
    int gamma = 0, delta = 0, epsilon = left;
    
    while(gamma < alpha && delta < beta) {
        arr[epsilon++] = (leftArr[gamma] <= rightArr[delta]) ? leftArr[gamma++] : rightArr[delta++];
    }
    
    while(gamma < alpha) { arr[epsilon++] = leftArr[gamma++]; }
    while(delta < beta) { arr[epsilon++] = rightArr[delta++]; }
}

void mergeSortImpl(vector<int>& arr, int left, int right) {
    right > left ? (void)(
        mergeSortImpl(arr, left, (left + right) / 2),
        mergeSortImpl(arr, (left + right) / 2 + 1, right),
        mergeArrays(arr, left, (left + right) / 2, right)
    ) : void();
}

void mergeSort(vector<int>& arr) {
    mergeSortImpl(arr, 0, arr.size() - 1);
}

class Solution {
public:
    bool isMatch(string strInput, string ptrn) {
        vector<vector<bool>> dynMatrix(strInput.length() + 1, vector<bool>(ptrn.length() + 1, false));
        
        dynMatrix[0][0] = true;
        
        int ptrIdx = 0;
        while(ptrIdx < ptrn.length()) {
            dynMatrix[0][ptrIdx + 1] = ptrn[ptrIdx] == '*' ? dynMatrix[0][ptrIdx - 1] : false;
            ptrIdx++;
        }
        
        int strIdx = 0;
        while(strIdx < strInput.length()) {
            ptrIdx = 0;
            while(ptrIdx < ptrn.length()) {
                dynMatrix[strIdx + 1][ptrIdx + 1] = 
                    ptrn[ptrIdx] == '*' ? (
                        dynMatrix[strIdx + 1][ptrIdx - 1] || 
                        ((ptrn[ptrIdx - 1] == '.' || ptrn[ptrIdx - 1] == strInput[strIdx]) ? 
                            dynMatrix[strIdx][ptrIdx + 1] : false)
                    ) : (
                        (ptrn[ptrIdx] == '.' || ptrn[ptrIdx] == strInput[strIdx]) ? 
                            dynMatrix[strIdx][ptrIdx] : false
                    );
                ptrIdx++;
            }
            strIdx++;
        }
        
        return dynMatrix[strInput.length()][ptrn.length()];
    }
};