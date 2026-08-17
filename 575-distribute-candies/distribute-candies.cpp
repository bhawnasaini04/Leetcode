class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        unordered_set<int> candyTypes;

        for (int candy : candyType) {
            candyTypes.insert(candy);
        }

        int differentTypes = candyTypes.size();
        int candiesForSister = candyType.size() / 2;

        return min(differentTypes, candiesForSister);
    }
};