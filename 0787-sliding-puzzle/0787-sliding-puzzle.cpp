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
    int ptr1 = left, ptr2 = mid + 1;
    vector<int> temp;
    
    while (ptr1 <= mid && ptr2 <= right) {
        temp.push_back(arr[ptr1] <= arr[ptr2] ? arr[ptr1++] : arr[ptr2++]);
    }
    
    while (ptr1 <= mid) temp.push_back(arr[ptr1++]);
    while (ptr2 <= right) temp.push_back(arr[ptr2++]);
    
    int idx = left;
    while (idx <= right) {
        arr[idx] = temp[idx - left];
        idx++;
    }
}

void customMergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        customMergeSort(arr, left, mid);
        customMergeSort(arr, mid + 1, right);
        mergeArrays(arr, left, mid, right);
    }
}

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& gameBoard) {
        string initState = "";
        int row = 0, col = 0;
        
        while (row < gameBoard.size()) {
            col = 0;
            while (col < gameBoard[0].size()) {
                initState += '0' + gameBoard[row][col];
                col++;
            }
            row++;
        }
        
        string targetState = "123450";
        vector<vector<int>> neighborMap = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        
        queue<pair<string, int>> bfsQueue;
        unordered_set<string> visitedStates;
        
        bfsQueue.push({initState, 0});
        visitedStates.insert(initState);
        
        while (!bfsQueue.empty()) {
            string currentState = bfsQueue.front().first;
            int moves = bfsQueue.front().second;
            bfsQueue.pop();
            
            if (currentState == targetState) {
                return moves;
            }
            
            int zeroPos = 0;
            while (zeroPos < currentState.length() && currentState[zeroPos] != '0') {
                zeroPos++;
            }
            
            int neighborIdx = 0;
            while (neighborIdx < neighborMap[zeroPos].size()) {
                string nextState = currentState;
                swap(nextState[zeroPos], nextState[neighborMap[zeroPos][neighborIdx]]);
                
                if (visitedStates.find(nextState) == visitedStates.end()) {
                    bfsQueue.push({nextState, moves + 1});
                    visitedStates.insert(nextState);
                }
                neighborIdx++;
            }
        }
        return -1;
    }
};