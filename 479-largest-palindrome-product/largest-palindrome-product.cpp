class Solution {
public:
    int largestPalindrome(int n) {

        if (n == 1)
            return 9;

        long upper = pow(10, n) - 1;
        long lower = pow(10, n - 1);

        for (long left = upper; left >= lower; left--) {

            string s = to_string(left);
            string rev = s;
            reverse(rev.begin(), rev.end());

            long palindrome =
                stol(s + rev);

            for (long x = upper;
                 x * x >= palindrome;
                 x--) {

                if (palindrome % x == 0)
                    return palindrome % 1337;
            }
        }

        return -1;
    }
};