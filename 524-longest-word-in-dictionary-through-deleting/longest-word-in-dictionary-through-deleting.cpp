class Solution {
public:
    bool isSubsequence(string s,
                       string t) {

        int i = 0;

        for (char c : t) {

            if (i < s.size() &&
                s[i] == c)
                i++;
        }

        return i == s.size();
    }

    string findLongestWord(
        string s,
        vector<string>& dictionary) {

        string ans;

        for (string word : dictionary) {

            if (isSubsequence(word, s)) {

                if (word.size() > ans.size() ||
                   (word.size() == ans.size() &&
                    word < ans))
                    ans = word;
            }
        }

        return ans;
    }
};