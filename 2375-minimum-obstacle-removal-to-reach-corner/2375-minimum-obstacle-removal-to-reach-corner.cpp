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
    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
     
        vector<vector<int>> obstacleCount(rows, vector<int>(cols, INF));
        

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > processQueue;
        
       
        obstacleCount[0][0] = 0;
        processQueue.push({0, {0, 0}});
        
        while (!processQueue.empty()) {
            int currentObstacles = processQueue.top().first;
            int currentX = processQueue.top().second.first;
            int currentY = processQueue.top().second.second;
            processQueue.pop();
            
            
            if (currentX == rows - 1 && currentY == cols - 1) {
                return currentObstacles;
            }
            
            REP(i, 4) {
                int nextX = currentX + directions[i].first;
                int nextY = currentY + directions[i].second;
            
                if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols) {
                    int newObstacleCount = currentObstacles + grid[nextX][nextY];
                    
                    if (newObstacleCount < obstacleCount[nextX][nextY]) {
                        obstacleCount[nextX][nextY] = newObstacleCount;
                        processQueue.push({newObstacleCount, {nextX, nextY}});
                    }
                }
            }
        }
        
        
        return -1;
    }
};


class MergeSortUtility {
private:
    void mergeSortedSubarrays(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftSubarray(n1), rightSubarray(n2);
        
        REP(i, n1) leftSubarray[i] = arr[left + i];
        REP(j, n2) rightSubarray[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            arr[k++] = (leftSubarray[i] <= rightSubarray[j]) ? 
                leftSubarray[i++] : rightSubarray[j++];
        }
        
        while (i < n1) arr[k++] = leftSubarray[i++];
        while (j < n2) arr[k++] = rightSubarray[j++];
    }
    
    void recursiveMergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            recursiveMergeSort(arr, left, mid);
            recursiveMergeSort(arr, mid + 1, right);
            mergeSortedSubarrays(arr, left, mid, right);
        }
    }

public:
    void performMergeSort(vector<int>& arr) {
        recursiveMergeSort(arr, 0, arr.size() - 1);
    }
};