class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return false;   // Cycle found

        parent[pa] = pb;
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        // Find if any node has two parents
        vector<int> parentNode(n + 1, 0);

        vector<int> firstEdge;
        vector<int> secondEdge;

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (parentNode[v] == 0) {
                parentNode[v] = u;
            }
            else {
                // v has two parents
                firstEdge = {parentNode[v], v};
                secondEdge = {u, v};
                break;
            }
        }

        // DSU initialization
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Try all edges
        for (auto edge : edges) {

            // Skip second edge if a node has two parents
            if (!secondEdge.empty() &&
                edge[0] == secondEdge[0] &&
                edge[1] == secondEdge[1]) {
                continue;
            }

            if (!unite(edge[0], edge[1])) {

                // Cycle found
                if (!firstEdge.empty())
                    return firstEdge;

                return edge;
            }
        }

        // No cycle, so remove the second parent edge
        return secondEdge;
    }
};