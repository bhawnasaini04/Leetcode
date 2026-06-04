class Solution {
public:
    string licenseKeyFormatting(
        string s,
        int k) {

        string temp;

        for (char c : s) {
            if (c != '-')
                temp += toupper(c);
        }

        string result;
        int cnt = 0;

        for (int i = temp.size() - 1;
             i >= 0;
             i--) {

            if (cnt == k) {
                result += '-';
                cnt = 0;
            }

            result += temp[i];
            cnt++;
        }

        reverse(
            result.begin(),
            result.end()
        );

        return result;
    }
};