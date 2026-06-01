class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if (s.size() < p.size())
            return result;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c : p)
            need[c - 'a']++;

        int k = p.size();

        for (int i = 0; i < s.size(); i++) {

            window[s[i] - 'a']++;

            if (i >= k)
                window[s[i - k] - 'a']--;

            if (window == need)
                result.push_back(i - k + 1);
        }

        return result;
    }
};