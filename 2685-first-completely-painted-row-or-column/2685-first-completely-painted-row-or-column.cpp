class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size(), N = m * n;
        vector<int> idx(N + 1);
        int i = 0;
        

        while (i < N) idx[arr[i]] = i, i++;

        vector<int> to_i(N), to_j(N);
        i = 0;
        

        while (i < m) {
            int j = 0;
            while (j < n) {
                int pos = idx[mat[i][j]];
                to_i[pos] = i, to_j[pos] = j;
                j++;
            }
            i++;
        }

        vector<int> row(m), col(n);
        i = 0;

        while (i < N) {
            int pos = idx[arr[i]];
            (++row[to_i[pos]] == n || ++col[to_j[pos]] == m) ? i : i++;
            if (row[to_i[pos]] == n || col[to_j[pos]] == m) return i;
        }

        return -1;
    }
};
