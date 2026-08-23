class Solution {
public:

    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        int rows = forest.size();
        int cols = forest[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, false));

        queue<pair<int, int>> q;

        q.push({sr, sc});
        visited[sr][sc] = true;

        int distance = 0;

        int direction[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto current = q.front();
                q.pop();

                int r = current.first;
                int c = current.second;

                if (r == tr && c == tc)
                    return distance;

                for (int i = 0; i < 4; i++) {

                    int nr = r + direction[i][0];
                    int nc = c + direction[i][1];

                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols &&
                        forest[nr][nc] != 0 &&
                        !visited[nr][nc]) {

                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            distance++;
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {

        int rows = forest.size();
        int cols = forest[0].size();

        vector<pair<int, pair<int, int>>> trees;

        // Store all trees
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (forest[i][j] > 1) {
                    trees.push_back({
                        forest[i][j],
                        {i, j}
                    });
                }
            }
        }

        // Sort trees by height
        sort(trees.begin(), trees.end());

        int currentRow = 0;
        int currentCol = 0;
        int answer = 0;

        // Visit trees one by one
        for (auto tree : trees) {

            int treeRow = tree.second.first;
            int treeCol = tree.second.second;

            int distance = bfs(
                forest,
                currentRow,
                currentCol,
                treeRow,
                treeCol
            );

            // Tree cannot be reached
            if (distance == -1)
                return -1;

            answer += distance;

            currentRow = treeRow;
            currentCol = treeCol;
        }

        return answer;
    }
};