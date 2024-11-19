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
    unsigned long long calculateSubsequences(const string& source, const string& target) {
        size_t srcLen = source.length(), tgtLen = target.length();
        vector<vector<unsigned long long>> dynMatrix(tgtLen + 1, vector<unsigned long long>(srcLen + 1, 0));
        
        size_t srcIdx = 0;
        while (srcIdx <= srcLen) {
            dynMatrix[0][srcIdx] = 1;
            srcIdx++;
        }
        
        size_t tgtIdx = 1;
        while (tgtIdx <= tgtLen) {
            srcIdx = 1;
            while (srcIdx <= srcLen) {
                dynMatrix[tgtIdx][srcIdx] = 
                    (source[srcIdx - 1] == target[tgtIdx - 1]) ?
                    dynMatrix[tgtIdx - 1][srcIdx - 1] + dynMatrix[tgtIdx][srcIdx - 1] :
                    dynMatrix[tgtIdx][srcIdx - 1];
                srcIdx++;
            }
            tgtIdx++;
        }
        
        return dynMatrix[tgtLen][srcLen];
    }
    
    int numDistinct(string s, string t) {
        return static_cast<int>(calculateSubsequences(s, t));
    }
};

void mergeArrays(vector<int>& alpha, vector<int>& beta, vector<int>& gamma) {
    size_t p1 = 0, p2 = 0;
    size_t n1 = alpha.size(), n2 = beta.size();
    
    while (p1 < n1 || p2 < n2) {
        (p2 >= n2 || (p1 < n1 && alpha[p1] <= beta[p2])) ?
            (gamma.push_back(alpha[p1]), p1++) :
            (gamma.push_back(beta[p2]), p2++);
    }
}

void customMergeSort(vector<int>& dataArray) {
    size_t arraySize = dataArray.size();
    (arraySize <= 1) ? void() : [&]() {
        size_t midPoint = arraySize / 2;
        vector<int> leftSection(dataArray.begin(), dataArray.begin() + midPoint);
        vector<int> rightSection(dataArray.begin() + midPoint, dataArray.end());
        
        customMergeSort(leftSection);
        customMergeSort(rightSection);
        
        dataArray.clear();
        mergeArrays(leftSection, rightSection, dataArray);
    }();
}