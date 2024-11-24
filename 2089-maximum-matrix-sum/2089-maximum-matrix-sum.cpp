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
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }

template<class T> void chmax(T& a, const T& b) { a = max(a, b); }
template<class T> void chmin(T& a, const T& b) { a = min(a, b); }

void mergeSort(vector<int>& arr, int left, int right, vector<int>& temp) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, temp);
    mergeSort(arr, mid + 1, right, temp);
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int m = left; m <= right; ++m) arr[m] = temp[m];
}

class Solution {
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        ll totalSum = 0;
        int smallestAbs = INF, negativeCount = 0;
        int i = 0;
        while (i < matrix.size()) {
            int j = 0;
            while (j < matrix[i].size()) {
                int value = matrix[i][j];
                smallestAbs = abs(value) < smallestAbs ? abs(value) : smallestAbs;
                totalSum += value < 0 ? -value : value;
                negativeCount += value < 0 ? 1 : 0;
                j++;
            }
            i++;
        }
        return (negativeCount % 2 == 0) ? totalSum : totalSum - 2 * smallestAbs;
    }
};
