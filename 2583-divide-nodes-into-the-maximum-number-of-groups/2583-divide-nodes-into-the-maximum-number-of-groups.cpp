class Solution {
public:
    vector<int> rank, parent;

    int findYourParent(int node) {
        return parent[node] == node
                   ? node
                   : parent[node] = findYourParent(parent[node]);
    }

    void unionFindRank(int u, int v) {
        int pu = findYourParent(u), pv = findYourParent(v);
        if (pu != pv)
            rank[pv] < rank[pu]
                ? parent[pv] = pu
                : (rank[pu] < rank[pv] ? parent[pu] = pv
                                       : (parent[pv] = pu, rank[pu]++));
    }

    bool check_bipartite(int n, unordered_map<int, vector<int>>& mp) {
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int top = q.front(), parent_color = color[top];
                    q.pop();
                    for (int it : mp[top]) {
                        if (color[it] == -1)
                            q.push(it), color[it] = 1 - parent_color;
                        else if (color[it] == parent_color)
                            return false;
                    }
                }
            }
        }
        return true;
    }

    int bfs(int start, unordered_map<int, vector<int>>& mp, int n) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(start), dist[start] = 1;
        int maxLevel = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : mp[node])
                if (dist[neighbor] == -1)
                    dist[neighbor] = dist[node] + 1,
                    maxLevel = max(maxLevel, dist[neighbor]), q.push(neighbor);
        }
        return maxLevel;
    }

    int getMaxGroupsInComponent(vector<int>& nodes,
                                unordered_map<int, vector<int>>& mp, int n) {
        int maxGroups = 0;
        for (int node : nodes)
            maxGroups = max(maxGroups, bfs(node, mp, n));
        return maxGroups;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        rank.resize(n + 1, 0), parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        unordered_map<int, vector<int>> mp;
        for (auto it : edges)
            mp[it[0]].push_back(it[1]), mp[it[1]].push_back(it[0]),
                unionFindRank(it[0], it[1]);

        if (!check_bipartite(n, mp))
            return -1;

        unordered_map<int, vector<int>> components;
        for (int i = 1; i <= n; i++)
            components[findYourParent(i)].push_back(i);

        int totalGroups = 0;
        for (auto& component : components)
            totalGroups += getMaxGroupsInComponent(component.second, mp, n);

        return totalGroups;
    }
};
