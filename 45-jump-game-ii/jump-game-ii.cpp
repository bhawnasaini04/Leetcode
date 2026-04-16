class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;   // end of current jump range
        int farthest = 0;     // farthest we can reach

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // when we reach end of current range, we must jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // early exit if we already reach end
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};