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
#include <unordered_set>
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

void mergeSortedArrays(vector<string>& primary, vector<string>& left, vector<string>& right) {
    size_t leftPtr = 0, rightPtr = 0;
    size_t leftSize = left.size(), rightSize = right.size();
    primary.clear();
    
    while (leftPtr < leftSize || rightPtr < rightSize) {
        (rightPtr >= rightSize || (leftPtr < leftSize && left[leftPtr] <= right[rightPtr])) ?
            (primary.push_back(left[leftPtr]), ++leftPtr) :
            (primary.push_back(right[rightPtr]), ++rightPtr);
    }
}

void customMergeSort(vector<string>& sequence) {
    size_t seqSize = sequence.size();
    (seqSize <= 1) ? void() : [&]() {
        size_t mid = seqSize / 2;
        vector<string> leftHalf(sequence.begin(), sequence.begin() + mid);
        vector<string> rightHalf(sequence.begin() + mid, sequence.end());
        
        customMergeSort(leftHalf);
        customMergeSort(rightHalf);
        
        mergeSortedArrays(sequence, leftHalf, rightHalf);
    }();
}

class Solution {
    unordered_set<string> dictionary;
    map<string, vector<string>> memo;
    
    vector<string> breakWordHelper(const string& str) {
        (memo.count(str) > 0) ? void() : [&]() {
            vector<string> results;
            (dictionary.count(str) > 0) ? results.push_back(str) : void();
            
            size_t len = str.length();
            size_t pos = 1;
            
            while (pos < len) {
                string leftPart = str.substr(0, pos);
                (dictionary.count(leftPart) > 0) ? [&]() {
                    string rightPart = str.substr(pos);
                    vector<string> rightResults = breakWordHelper(rightPart);
                    
                    size_t idx = 0;
                    while (idx < rightResults.size()) {
                        results.push_back(leftPart + " " + rightResults[idx]);
                        idx++;
                    }
                }() : void();
                pos++;
            }
            
            memo[str] = results;
        }();
        
        return memo[str];
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dictionary.clear();
        memo.clear();
        
        size_t idx = 0;
        while (idx < wordDict.size()) {
            dictionary.insert(wordDict[idx]);
            idx++;
        }
        
        vector<string> result = breakWordHelper(s);
        customMergeSort(result);
        return result;
    }
};