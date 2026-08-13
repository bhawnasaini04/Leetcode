class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        // {value, list number, index inside list}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int currentMax = INT_MIN;

        // Put the first element of every list into heap
        for (int i = 0; i < nums.size(); i++) {

            pq.push({nums[i][0], i, 0});

            currentMax = max(currentMax, nums[i][0]);
        }

        int bestLeft = 0;
        int bestRight = INT_MAX;

        while (pq.size() == nums.size()) {

            vector<int> current = pq.top();
            pq.pop();

            int currentMin = current[0];
            int listIndex = current[1];
            int elementIndex = current[2];

            // Check current range
            if (currentMax - currentMin <
                    bestRight - bestLeft) {

                bestLeft = currentMin;
                bestRight = currentMax;
            }

            // Move to next element of this list
            if (elementIndex + 1 < nums[listIndex].size()) {

                int nextValue =
                    nums[listIndex][elementIndex + 1];

                pq.push({
                    nextValue,
                    listIndex,
                    elementIndex + 1
                });

                currentMax = max(currentMax, nextValue);
            }
            else {
                // One list is finished
                break;
            }
        }

        return {bestLeft, bestRight};
    }
};