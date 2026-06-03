class Solution {
public:
    unordered_map<int, bool> memo;

    bool dfs(int usedMask,
             int currentSum,
             int maxNum,
             int target) {

        if (memo.count(usedMask))
            return memo[usedMask];

        for (int i = 1; i <= maxNum; i++) {

            int bit = 1 << (i - 1);

            if (!(usedMask & bit)) {

                if (currentSum + i >= target)
                    return memo[usedMask] = true;

                if (!dfs(usedMask | bit,
                         currentSum + i,
                         maxNum,
                         target))
                    return memo[usedMask] = true;
            }
        }

        return memo[usedMask] = false;
    }

    bool canIWin(int maxChoosableInteger,
                 int desiredTotal) {

        if (desiredTotal <= 0)
            return true;

        int total =
            maxChoosableInteger *
            (maxChoosableInteger + 1) / 2;

        if (total < desiredTotal)
            return false;

        return dfs(
            0,
            0,
            maxChoosableInteger,
            desiredTotal
        );
    }
};