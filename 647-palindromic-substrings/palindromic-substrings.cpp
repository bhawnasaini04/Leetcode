class Solution {
public:

    int countPalindrome(string s, int left, int right) {

        int count = 0;

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            count++;

            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {

        int answer = 0;

        for (int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            answer += countPalindrome(s, i, i);

            // Even length palindrome
            answer += countPalindrome(s, i, i + 1);
        }

        return answer;
    }
};