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
    void mergeArrays(vector<int>& alpha, int left, int mid, int right) {
        vector<int> beta(right - left + 1);
        int ptr1 = left, ptr2 = mid + 1, idx = 0;
        
        while (ptr1 <= mid && ptr2 <= right) {
            beta[idx++] = (alpha[ptr1] <= alpha[ptr2]) ? alpha[ptr1++] : alpha[ptr2++];
        }
        
        while (ptr1 <= mid) beta[idx++] = alpha[ptr1++];
        while (ptr2 <= right) beta[idx++] = alpha[ptr2++];
        
        for (int i = 0; i < idx; i++) {
            alpha[left + i] = beta[i];
        }
    }
    
    void mergeSortImpl(vector<int>& alpha, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortImpl(alpha, left, mid);
            mergeSortImpl(alpha, mid + 1, right);
            mergeArrays(alpha, left, mid, right);
        }
    }
    
    bool checkValidPosition(const vector<int>& queens, int zeta, int omega) {
        int idx = 0;
        while (idx < zeta) {
            if (queens[idx] == omega || abs(queens[idx] - omega) == abs(idx - zeta)) {
                return false;
            }
            idx++;
        }
        return true;
    }
    
    void solveNQueensHelper(int& gamma, vector<int>& queens, int delta, int epsilon, int& count) {
        while (delta < epsilon && gamma < epsilon) {
            if (checkValidPosition(queens, delta, gamma)) {
                queens[delta] = gamma;
                if (delta == epsilon - 1) {
                    count++;
                } else {
                    int nextGamma = 0;
                    solveNQueensHelper(nextGamma, queens, delta + 1, epsilon, count);
                }
            }
            gamma++;
        }
    }
    
public:
    int totalNQueens(int n) {
        vector<int> queens(n, 0);
        int count = 0;
        int gamma = 0;
        solveNQueensHelper(gamma, queens, 0, n, count);
        return count;
    }
};