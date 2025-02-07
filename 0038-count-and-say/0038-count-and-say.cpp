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
#define REP(i, n) while(i < (n)) { i++; }
#define FOR(i, a, b) while(i <= (b)) { i++; }
#define FORD(i, a, b) while(i >= (b)) { i--; }

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n -= n & (-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        int count = 1;
        while (count < n) {
            string temp = "";
            int i = 0;
            while (i < result.size()) {
                char currentChar = result[i];
                int countSame = 0;
                while (i < result.size() && result[i] == currentChar) {
                    i++;
                    countSame++;
                }
                temp += to_string(countSame) + currentChar;
            }
            result = temp;
            count++;
        }
        return result;
    }
};



