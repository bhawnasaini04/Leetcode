class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool lower = false, upper = false, digit = false;

        for (char c : password) {
            if (islower(c)) lower = true;
            else if (isupper(c)) upper = true;
            else if (isdigit(c)) digit = true;
        }

        int missing = (!lower) + (!upper) + (!digit);

        vector<int> groups;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && password[j] == password[i])
                j++;
            if (j - i >= 3)
                groups.push_back(j - i);
            i = j;
        }

        // Case 1: Length < 6
        if (n < 6) {
            return max(missing, 6 - n);
        }

        int replace = 0;
        for (int len : groups)
            replace += len / 3;

        // Case 2: Length <= 20
        if (n <= 20) {
            return max(missing, replace);
        }

        // Case 3: Length > 20
        int deleteCount = n - 20;

        vector<int> cnt(3, 0);
        for (int len : groups)
            cnt[len % 3]++;

        int del = deleteCount;

        // Delete from groups where len % 3 == 0
        int use = min(cnt[0], del);
        replace -= use;
        del -= use;

        // Delete from groups where len % 3 == 1
        use = min(cnt[1] * 2, del);
        replace -= use / 2;
        del -= use;

        // Delete remaining from groups where len % 3 == 2
        replace -= del / 3;

        return deleteCount + max(missing, replace);
    }
};