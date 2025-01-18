class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int result = INT_MAX;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        deque<array<int, 3>> deque;
        int deltaRow[5] = {0, 0, 0, 1, -1};
        int deltaCol[5] = {0, 1, -1, 0, 0};
        deque.push_front({0, 0, 0});
        while (!deque.empty()) {
            auto [cost, curRow, curCol] = deque.front();
            deque.pop_front();
            if (curRow == rows - 1 && curCol == cols - 1) {
                return cost;
            }
            if (visited[curRow][curCol]) continue;
            visited[curRow][curCol] = true;
            for (int direction = 1; direction <= 4; direction++) {
                int newRow = curRow + deltaRow[direction];
                int newCol = curCol + deltaCol[direction];
                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
                if (direction != grid[curRow][curCol]) {
                    deque.push_back({cost + 1, newRow, newCol});
                } else {
                    deque.push_front({cost, newRow, newCol});
                }
            }
        }
        return result;
    }
};
