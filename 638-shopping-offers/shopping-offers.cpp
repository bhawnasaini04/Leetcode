class Solution {
public:
    map<vector<int>, int> memo;

    int solve(vector<int>& price,
              vector<vector<int>>& special,
              vector<int>& needs) {

        if (memo.count(needs))
            return memo[needs];

        // Buy everything normally
        int cost = 0;

        for (int i = 0; i < needs.size(); i++) {
            cost += needs[i] * price[i];
        }

        // Try every special offer
        for (auto& offer : special) {

            bool canUse = true;

            for (int i = 0; i < needs.size(); i++) {
                if (offer[i] > needs[i]) {
                    canUse = false;
                    break;
                }
            }

            if (!canUse)
                continue;

            // Apply the offer
            vector<int> newNeeds = needs;

            for (int i = 0; i < needs.size(); i++) {
                newNeeds[i] -= offer[i];
            }

            // Offer price is the last element
            int offerCost = offer.back();

            cost = min(
                cost,
                offerCost + solve(price, special, newNeeds)
            );
        }

        return memo[needs] = cost;
    }

    int shoppingOffers(vector<int>& price,
                       vector<vector<int>>& special,
                       vector<int>& needs) {

        return solve(price, special, needs);
    }
};