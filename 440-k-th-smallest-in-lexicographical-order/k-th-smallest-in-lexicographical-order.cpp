class Solution {
public:
    long countSteps(long n, long prefix, long nextPrefix) {
        long steps = 0;

        while (prefix <= n) {
            steps += min(n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {

        long curr = 1;
        k--;

        while (k > 0) {

            long steps =
                countSteps(n, curr, curr + 1);

            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};