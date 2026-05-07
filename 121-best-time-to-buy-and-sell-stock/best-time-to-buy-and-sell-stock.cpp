class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {

            // Keep track of minimum buying price
            minPrice = min(minPrice, prices[i]);

            // Calculate profit if sold today
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};