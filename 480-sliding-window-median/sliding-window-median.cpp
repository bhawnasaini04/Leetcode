class Solution {
public:
    vector<double> medianSlidingWindow(
        vector<int>& nums,
        int k) {

        multiset<int> low, high;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                high.insert(*low.rbegin());
                low.erase(prev(low.end()));
            }

            while (low.size() < high.size()) {
                low.insert(*high.begin());
                high.erase(high.begin());
            }
        };

        vector<double> result;

        for (int i = 0; i < nums.size(); i++) {

            if (low.empty() ||
                nums[i] <= *low.rbegin())
                low.insert(nums[i]);
            else
                high.insert(nums[i]);

            balance();

            if (i >= k) {

                if (low.find(nums[i - k]) != low.end())
                    low.erase(low.find(nums[i - k]));
                else
                    high.erase(high.find(nums[i - k]));

                balance();
            }

            if (i >= k - 1) {

                if (k & 1)
                    result.push_back(*low.rbegin());
                else
                    result.push_back(
                        ((double)*low.rbegin() +
                         *high.begin()) / 2.0
                    );
            }
        }

        return result;
    }
};