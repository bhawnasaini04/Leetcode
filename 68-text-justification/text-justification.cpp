#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLen = 0;

            // Step 1: find how many words fit
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Step 2: last line OR single word → left justified
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // fill remaining spaces
                line += string(maxWidth - line.size(), ' ');
            } 
            else {
                // Step 3: fully justify
                int totalSpaces = maxWidth - lineLen;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = spaceEach + (extra > 0 ? 1 : 0);
                        line += string(spaces, ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};