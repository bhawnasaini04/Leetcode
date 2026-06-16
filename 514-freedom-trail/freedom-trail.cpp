class Solution {
public:
    unordered_map<long long,int> memo;

    int dfs(string& ring, string& key,
            int pos, int idx) {

        if (idx == key.size())
            return 0;

        long long state =
            ((long long)pos << 32) | idx;

        if (memo.count(state))
            return memo[state];

        int n = ring.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (ring[i] == key[idx]) {

                int diff = abs(i - pos);
                int step = min(diff, n - diff);

                ans = min(ans,
                          step + 1 +
                          dfs(ring, key,
                              i, idx + 1));
            }
        }

        return memo[state] = ans;
    }

    int findRotateSteps(string ring,
                        string key) {

        return dfs(ring, key, 0, 0);
    }
};