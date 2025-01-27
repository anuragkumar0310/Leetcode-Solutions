class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, set<pair<int, int>> &s, int start) {
        visited[node] = 1;
        if (start != -1) 
         s.insert({start, node});

        int i = 0;
        while (i < adj[node].size()) {
            int neighbor = adj[node][i];

            if (!visited[neighbor]) 
              dfs(neighbor, adj, visited, s, start);
            i++;
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &pre, vector<vector<int>> &q) {
        vector<vector<int>> adj(n);
        int i = 0;
        while (i < pre.size()) {
            adj[pre[i][0]].push_back(pre[i][1]);
            i++;
        }
        set<pair<int, int>> s;
        i = 0;
        while (i < n) {
            vector<bool> visited(n, 0);
            dfs(i, adj, visited, s, i);
            i++;
        }
        vector<bool> result(q.size(), 0);
        i = 0;
        while (i < q.size()) {
            if (s.find({q[i][0], q[i][1]}) != s.end()) 
              result[i] = 1;
            i++;
        }
        return result;
    }
};
