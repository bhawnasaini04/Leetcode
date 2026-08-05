class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<int> mask(n, 0);

        // Create bitmask for each word
        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                mask[i] |= (1 << (ch - 'a'));
            }
        }

        int ans = 0;

        // Compare every pair of words
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // No common characters
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans,
                              (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return ans;
    }
};