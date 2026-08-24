class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else {
                // '*' can be '(' or ')' or empty
                low--;
                high++;
            }

            // Even the maximum possible '(' is negative
            if (high < 0)
                return false;

            // We cannot have negative minimum
            if (low < 0)
                low = 0;
        }

        return low == 0;
    }
};