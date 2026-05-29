class Solution {
public:
    unordered_map<int,
    unordered_set<int>> dp;

    bool canCross(vector<int>& stones) {

        dp[0].insert(0);

        unordered_set<int> stoneSet(
            stones.begin(),
            stones.end()
        );

        for(int stone : stones) {

            for(int jump : dp[stone]) {

                for(int step=jump-1;
                    step<=jump+1;
                    step++) {

                    if(step > 0 &&
                       stoneSet.count(
                       stone+step)) {

                        dp[stone+step]
                        .insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};