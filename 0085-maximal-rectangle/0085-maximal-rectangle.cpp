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
typedef long long ll; 

template<class T> void chmax(T & a, const T & b) { a = max(a, b); } 
template<class T> void chmin(T & a, const T & b) { a = min(a, b); } 

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0), left(cols, 0), right(cols, cols);
        int max_area = 0, row = 0;
        
        while (row < rows) {
            int col = 0, cur_left = 0, cur_right = cols;

            while (col < cols) 
                heights[col] = matrix[row][col] == '1' ? heights[col] + 1 : 0, col++;

           
            col = 0;
            while (col < cols) 
                left[col] = matrix[row][col] == '1' ? max(left[col], cur_left) : (cur_left = col + 1, 0), col++;

           
            col = cols - 1;
            while (col >= 0) 
                right[col] = matrix[row][col] == '1' ? min(right[col], cur_right) : (cur_right = col, cols), col--;

          
            col = 0;
            while (col < cols) 
                max_area = max(max_area, (right[col] - left[col]) * heights[col]), col++;
            row++;
        }
        return max_area;
    }
};

