class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int r = isWater.size(), c = isWater[0].size();
        const int d[5] = {0, 1, 0, -1, 0};
        vector<vector<int>> H(r, vector<int>(c, -1));
        queue<int> q;
        
        int i = 0;
        while (i < r) {
            int j = 0;
            while (j < c) {
                if (isWater[i][j]) {
                    int idx = (i << 10) + j;
                    H[i][j] = 0;
                    q.push(idx);
                }
                j++;
            }
            i++;
        }
        
        int h = 0;
        while (!q.empty()) {
            int qz = q.size(), a = 0;
            while (a < qz) {
                int idx = q.front(), i = idx >> 10, j = idx & ((1 << 10) - 1);
                q.pop();
                int b = 0;
                while (b < 4) {
                    int s = i + d[b], t = j + d[b + 1];
                    if (s >= 0 && s < r && t >= 0 && t < c && H[s][t] == -1) {
                        q.push((s << 10) + t);
                        H[s][t] = h + 1;
                    }
                    b++;
                }
                a++;
            }
            h++;
        }
        
        return H;
    }
};
