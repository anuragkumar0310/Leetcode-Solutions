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
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, INT_MAX), last(26, -1);
        int i = 0;
        
        while (i < s.length()) {
            int c = s[i] - 'a';
            first[c] = first[c] == INT_MAX ? i : first[c];
            last[c] = i;
            i++;
        }
        
        vector<pair<int, int>> ranges;
        i = 0;
        
        auto getEnd = [&](int start) -> pair<bool, int> {
            int end = last[s[start] - 'a'];
            int j = start;
            
            while (j <= end) {
                int c = s[j] - 'a';
                (first[c] < start) ? end = -1 : end = max(end, last[c]);
                j++;
                if (end == -1) break;
            }
            
            return {end != -1, end};
        };
        
        while (i < s.length()) {
            (i == first[s[i] - 'a']) ? [&]() {
                auto [valid, end] = getEnd(i);
                valid ? ranges.push_back({i, end}) : void();
            }() : void();
            i++;
        }
        
        sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
            return (a.second - a.first == b.second - b.first) ? 
                   a.first < b.first : a.second - a.first < b.second - b.first;
        });
        
        vector<string> result;
        vector<bool> used(s.length(), false);
        i = 0;
        
        while (i < ranges.size()) {
            bool canUse = true;
            int start = ranges[i].first, end = ranges[i].second;
            int j = start;
            
            while (j <= end) {
                canUse = used[j] ? false : canUse;
                j++;
            }
            
            (canUse) ? [&]() {
                result.push_back(s.substr(start, end - start + 1));
                j = start;
                while (j <= end) {
                    used[j] = true;
                    j++;
                }
            }() : void();
            i++;
        }
        
        return result;
    }
};