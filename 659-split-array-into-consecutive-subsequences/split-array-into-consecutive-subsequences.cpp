class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> frequency;
        unordered_map<int, int> ending;

        // Count frequency of every number
        for (int num : nums) {
            frequency[num]++;
        }

        for (int num : nums) {
            if (frequency[num] == 0) {
                continue;
            }

            // Use this number
            frequency[num]--;

            // Try to add it to an existing sequence
            if (ending[num - 1] > 0) {
                ending[num - 1]--;
                ending[num]++;
            }
            // Otherwise start a new sequence num, num+1, num+2
            else if (frequency[num + 1] > 0 && frequency[num + 2] > 0) {
                frequency[num + 1]--;
                frequency[num + 2]--;

                ending[num + 2]++;
            }
            else {
                return false;
            }
        }

        return true;
    }
};