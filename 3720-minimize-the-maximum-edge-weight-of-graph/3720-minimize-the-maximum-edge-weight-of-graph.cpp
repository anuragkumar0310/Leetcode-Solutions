class Solution {
public:
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1, n2 = right - mid;
        vector<int> L(n1), R(n2);
        int i = 0;
        while (i < n1) {
            L[i] = arr[left + i];
            i++;
        }
        i = 0;
        while (i < n2) {
            R[i] = arr[mid + 1 + i];
            i++;
        }
        i = 0; int j = 0, k = left;
        while (i < n1 && j < n2) {
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        }
        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
    }
    int dfs(int node, int threshold, vector<vector<pair<int, int>>>& adj, vector<int>& visited) {
        int result = visited[node] = 1;
        int i = 0;
        while (i < adj[node].size()) {
            int neighbor = adj[node][i].first, weight = adj[node][i].second;
            if (weight <= threshold && !visited[neighbor])
                result += dfs(neighbor, threshold, adj, visited);
            i++;
        }
        return result;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);
        int i = 0;
        while (i < edges.size()) {
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            i++;
        }
        int low = 1, high = 1000001;
        while (low < high) {
            int mid = (low + high) / 2;
            vector<int> visited(n);
            if (dfs(0, mid, adj, visited) == n)
                high = mid;
            else
                low = mid + 1;
        }
        return low == 1000001 ? -1 : low;
    }
};