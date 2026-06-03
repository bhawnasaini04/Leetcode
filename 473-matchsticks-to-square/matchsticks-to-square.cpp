class Solution {
public:
    bool dfs(vector<int>& matchsticks,
             vector<int>& sides,
             int index,
             int target) {

        if (index == matchsticks.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        int stick = matchsticks[index];

        for (int i = 0; i < 4; i++) {

            if (sides[i] + stick > target)
                continue;

            sides[i] += stick;

            if (dfs(matchsticks,
                    sides,
                    index + 1,
                    target))
                return true;

            sides[i] -= stick;

            // Pruning
            if (sides[i] == 0)
                break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = accumulate(
            matchsticks.begin(),
            matchsticks.end(),
            0
        );

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(),
             matchsticks.rend());

        vector<int> sides(4, 0);

        return dfs(matchsticks,
                   sides,
                   0,
                   target);
    }
};