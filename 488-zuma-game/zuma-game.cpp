class Solution {
public:
    unordered_map<string, int> memo;

    int getId(char c) {
        if (c == 'R') return 0;
        if (c == 'Y') return 1;
        if (c == 'B') return 2;
        if (c == 'G') return 3;
        return 4; // W
    }

    string removeGroups(string s) {
        while (true) {
            string next = "";
            bool removed = false;

            for (int i = 0; i < s.size();) {
                int j = i;

                while (j < s.size() && s[j] == s[i])
                    j++;

                if (j - i >= 3) {
                    removed = true;
                } else {
                    next += s.substr(i, j - i);
                }

                i = j;
            }

            if (!removed)
                return s;

            s = next;
        }
    }

    int dfs(string board, vector<int>& hand) {

        board = removeGroups(board);

        if (board.empty())
            return 0;

        int total = 0;
        for (int x : hand)
            total += x;

        if (total == 0)
            return 1000000;

        // Memoization key
        string key = board + "#";

        for (int x : hand)
            key += char('0' + x);

        if (memo.count(key))
            return memo[key];

        int ans = 1000000;

        int n = board.size();

        for (int i = 0; i <= n; i++) {

            char left = (i > 0) ? board[i - 1] : '#';
            char right = (i < n) ? board[i] : '#';

            for (char c : string("RYBGW")) {

                int id = getId(c);

                if (hand[id] == 0)
                    continue;

                /*
                    We only need useful insertion positions.

                    Case 1:
                    c touches the same color.

                    Case 2:
                    c is inserted between two equal colors.

                    Example:
                    RR -> RBR

                    This second case is essential for the
                    test case:
                    RRWWRRBBRR + WB
                */

                bool useful = false;

                if (left == c || right == c)
                    useful = true;

                if (left != '#' && right != '#' && left == right)
                    useful = true;

                if (!useful)
                    continue;

                // Same color inserted inside the same run
                // produces duplicate states, so skip duplicates.
                if (i > 0 && i < n &&
                    board[i - 1] == board[i] &&
                    board[i] == c) {
                    continue;
                }

                hand[id]--;

                string next =
                    board.substr(0, i) +
                    c +
                    board.substr(i);

                int result = dfs(next, hand);

                if (result != 1000000)
                    ans = min(ans, result + 1);

                hand[id]++;
            }
        }

        return memo[key] = ans;
    }

    int findMinStep(string board, string handString) {

        vector<int> hand(5, 0);

        for (char c : handString)
            hand[getId(c)]++;

        int ans = dfs(board, hand);

        return ans == 1000000 ? -1 : ans;
    }
};