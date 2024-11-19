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

void harmonicMerge(vector<int>& arr, int start, int mid, int end) {
    int phi = mid - start + 1;
    int psi = end - mid;
    
    vector<int> leftPart(phi), rightPart(psi);
    
    int idx = 0;
    while(idx < phi) {
        leftPart[idx] = arr[start + idx];
        idx++;
    }
    
    idx = 0;
    while(idx < psi) {
        rightPart[idx] = arr[mid + 1 + idx];
        idx++;
    }
    
    int sigma = 0, tau = 0, upsilon = start;
    
    while(sigma < phi && tau < psi) {
        arr[upsilon++] = (leftPart[sigma] <= rightPart[tau]) ? 
                        leftPart[sigma++] : rightPart[tau++];
    }
    
    while(sigma < phi) {
        arr[upsilon++] = leftPart[sigma++];
    }
    
    while(tau < psi) {
        arr[upsilon++] = rightPart[tau++];
    }
}

void harmonicSortImpl(vector<int>& arr, int start, int end) {
    end > start ? (
        harmonicSortImpl(arr, start, (start + end) / 2),
        harmonicSortImpl(arr, (start + end) / 2 + 1, end),
        harmonicMerge(arr, start, (start + end) / 2, end)
    ) : void();
}

void harmonicSort(vector<int>& arr) {
    harmonicSortImpl(arr, 0, arr.size() - 1);
}

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dpMatrix(s.length() + 1, vector<bool>(p.length() + 1, false));
        dpMatrix[0][0] = true;
        
        int patternIdx = 0;
        while(patternIdx < p.length()) {
            dpMatrix[0][patternIdx + 1] = p[patternIdx] == '*' ? 
                dpMatrix[0][patternIdx] : false;
            patternIdx++;
        }
        
        int strIdx = 0;
        while(strIdx < s.length()) {
            patternIdx = 0;
            while(patternIdx < p.length()) {
                dpMatrix[strIdx + 1][patternIdx + 1] = 
                    p[patternIdx] == '*' ? 
                    (dpMatrix[strIdx + 1][patternIdx] || dpMatrix[strIdx][patternIdx + 1]) :
                    ((p[patternIdx] == '?' || p[patternIdx] == s[strIdx]) ? 
                     dpMatrix[strIdx][patternIdx] : false);
                patternIdx++;
            }
            strIdx++;
        }
        
        return dpMatrix[s.length()][p.length()];
    }
};