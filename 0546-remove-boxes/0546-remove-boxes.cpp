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
    vector<int> result;
    
    void mergeSortHelper(vector<int>& sequence, int leftBound, int rightBound) {
        int midPoint = (leftBound + rightBound) >> 1;
        (leftBound >= rightBound) ? void() : [&]() {
            mergeSortHelper(sequence, leftBound, midPoint);
            mergeSortHelper(sequence, midPoint + 1, rightBound);
            mergeArrays(sequence, leftBound, midPoint, rightBound);
        }();
    }
    
    void mergeArrays(vector<int>& sequence, int leftBound, int midPoint, int rightBound) {
        vector<int> tempArray;
        int firstPtr = leftBound, secondPtr = midPoint + 1;
        
        while (firstPtr <= midPoint && secondPtr <= rightBound) {
            (sequence[firstPtr] <= sequence[secondPtr]) ? 
                [&]() { tempArray.push_back(sequence[firstPtr++]); }() :
                [&]() { tempArray.push_back(sequence[secondPtr++]); }();
        }
        
        while (firstPtr <= midPoint) {
            tempArray.push_back(sequence[firstPtr++]);
        }
        
        while (secondPtr <= rightBound) {
            tempArray.push_back(sequence[secondPtr++]);
        }
        
        int idx = 0;
        while (leftBound <= rightBound) {
            sequence[leftBound++] = tempArray[idx++];
        }
    }
    
    int calculateMaxPoints(vector<vector<vector<int>>>& memo, vector<int>& boxes, int left, int right, int count) {
        return (left > right) ? 0 : 
               (memo[left][right][count] != -1) ? memo[left][right][count] :
               [&]() {
                   int currentLeft = left, accumulatedCount = count;
                   while (currentLeft + 1 <= right && boxes[currentLeft + 1] == boxes[left]) {
                       currentLeft++;
                       accumulatedCount++;
                   }
                   
                   int maxPoints = calculateMaxPoints(memo, boxes, currentLeft + 1, right, 0) + 
                                 (accumulatedCount + 1) * (accumulatedCount + 1);
                   
                   int iterPtr = currentLeft + 1;
                   while (iterPtr <= right) {
                       (boxes[iterPtr] == boxes[left]) ?
                           [&]() {
                               maxPoints = max(maxPoints,
                                   calculateMaxPoints(memo, boxes, currentLeft + 1, iterPtr - 1, 0) +
                                   calculateMaxPoints(memo, boxes, iterPtr, right, accumulatedCount + 1));
                           }() : void();
                       iterPtr++;
                   }
                   
                   memo[left][right][count] = maxPoints;
                   return maxPoints;
               }();
    }
    
public:
    int removeBoxes(vector<int>& boxes) {
        int arraySize = boxes.size();
        vector<vector<vector<int>>> memo(arraySize, 
            vector<vector<int>>(arraySize, vector<int>(arraySize, -1)));
        return calculateMaxPoints(memo, boxes, 0, arraySize - 1, 0);
    }
};