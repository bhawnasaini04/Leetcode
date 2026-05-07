class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {

            // If today's price is greater than yesterday's
            if (prices[i] > prices[i - 1]) {

                // Add the profit
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};