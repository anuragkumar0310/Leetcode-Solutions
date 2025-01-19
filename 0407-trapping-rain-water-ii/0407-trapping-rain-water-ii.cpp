class Solution {
public:
    int deltas[5] = {0, 1, 0, -1, 0};
    int trapRainWater(vector<vector<int>>& terrain) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        int width = terrain[0].size();
        int length = terrain.size();
        vector<vector<bool>> seen(length, vector<bool>(width, false));
        
        for(int i = 0; i < length; i++) {
            heap.push({terrain[i][0], i, 0});
            heap.push({terrain[i][width - 1], i, width - 1});
            seen[i][0] = true;
            seen[i][width - 1] = true;
        }
        
        for(int i = 0; i < width; i++) {
            heap.push({terrain[0][i], 0, i});
            heap.push({terrain[length - 1][i], length - 1, i});
            seen[0][i] = true;
            seen[length - 1][i] = true;
        }
        
        int totalWater = 0;
        while(!heap.empty()) {
            vector<int> current = heap.top();
            heap.pop();
            int height = current[0], row = current[1], col = current[2];
            
            for(int direction = 1; direction < 5; direction++) {
                int newRow = row + deltas[direction - 1];
                int newCol = col + deltas[direction];
                
                if(newRow >= 0 && newCol >= 0 && newRow < length && newCol < width && !seen[newRow][newCol]) {
                    seen[newRow][newCol] = true;
                    totalWater += max(0, height - terrain[newRow][newCol]);
                    heap.push({max(height, terrain[newRow][newCol]), newRow, newCol});
                }
            }
        }
        return totalWater;
    }
};
