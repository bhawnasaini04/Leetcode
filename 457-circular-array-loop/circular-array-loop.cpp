class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                continue;

            int slow = i;
            int fast = i;
            bool dir = nums[i] > 0;

            while (true) {

                int nextSlow = nextIndex(nums, slow);
                int nextFast = nextIndex(nums, fast);

                if ((nums[nextSlow] > 0) != dir ||
                    (nums[nextFast] > 0) != dir)
                    break;

                nextFast = nextIndex(nums, nextFast);

                if ((nums[nextFast] > 0) != dir)
                    break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {

                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }
            }

            int j = i;

            while ((nums[j] > 0) == dir &&
                   nums[j] != 0) {

                int next = nextIndex(nums, j);
                nums[j] = 0;
                j = next;
            }
        }

        return false;
    }
};