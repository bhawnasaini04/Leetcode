class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false, seenDot = false, seenExp = false;
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                seenDigit = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            }
            else if (s[i] == '.') {
                if (seenDot || seenExp)
                    return false;
                seenDot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (seenExp || !seenDigit)
                    return false;
                seenExp = true;
                seenDigit = false; // need digits after e
            }
            else {
                return false;
            }
        }
        
        return seenDigit;
    }
};