class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (char c : s1)
            cnt1[c - 'a']++;

        for (int i = 0; i < m; i++) {

            cnt2[s2[i] - 'a']++;

            if (i >= n)
                cnt2[s2[i - n] - 'a']--;

            if (cnt1 == cnt2)
                return true;
        }

        return false;
    }
};