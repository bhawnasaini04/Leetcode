class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        // Store indices of same values
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1)
                    return steps;

                // Jump to same value indices
                for (int next : mp[arr[curr]]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }

                // Clear to avoid repeated processing
                mp[arr[curr]].clear();

                // Jump left
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Jump right
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
            }

            steps++;
        }

        return -1;
    }
};