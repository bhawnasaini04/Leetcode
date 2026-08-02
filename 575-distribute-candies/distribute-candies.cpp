class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;

        for (int candy : candyType) {
            st.insert(candy);
        }

        return min((int)st.size(), (int)candyType.size() / 2);
    }
};