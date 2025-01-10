class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;
        int rows = matrix.size();
        int cols = matrix[0].size();
    
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        
        for(int row : zeroRows) {
            for(int j = 0; j < cols; j++) {
                matrix[row][j] = 0;
            }
        }
        
        for(int col : zeroCols) {
            for(int i = 0; i < rows; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};