class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int r = g.size(), c = g[0].size(), t = 0;
        bool v[250] = {false};
        for (int i = 0; i < r; i++) {
            int x = accumulate(g[i].begin(), g[i].end(), 0);
            if (x > 1) {
                t += x;
                v[i] = true;
            }
        }
        for (int j = 0; j < c; j++) {
            int y = 0, z = 0;
            for (int i = 0; i < r; i++) {
                if (g[i][j] == 1) {
                    z++;
                    if (v[i]) y++;
                }
            }
            if (z > 1) t += z - y;
        }
        return t;
    }
};
