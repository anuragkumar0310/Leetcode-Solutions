class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    bfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1') {
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
    }
};
