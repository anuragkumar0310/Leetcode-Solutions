class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& state) {
        if (state[node] != 0) {
            return state[node] == 2;
        }
        
        state[node] = 1;
        
        for (int neighbor : graph[node]) {
            if (state[neighbor] == 1 || !dfs(graph, neighbor, state)) {
                return false;
            }
        }
        
        state[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> safeNodes;
        
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, state)) {
                safeNodes.push_back(i);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};