class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1)
            return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        while (n > 2) {
            int size = q.size();
            n -= size;

            while (size--) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    degree[neighbor]--;

                    if (degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }

        vector<int> result;

        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};