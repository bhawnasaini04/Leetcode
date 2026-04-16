class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;              // pointers for s and p
        int star = -1;                // last position of '*'
        int match = 0;                // position in s when '*' was seen

        while (i < s.size()) {

            // Case 1: direct match or '?'
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // Case 2: '*'
            else if (j < p.size() && p[j] == '*') {
                star = j;
                match = i;
                j++; // move pattern pointer
            }
            // Case 3: mismatch but we had previous '*'
            else if (star != -1) {
                j = star + 1;  // reset pattern after '*'
                match++;
                i = match;     // let '*' absorb more characters
            }
            // Case 4: no match and no '*'
            else {
                return false;
            }
        }

        // remaining characters in pattern must all be '*'
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};