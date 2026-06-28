class Solution {
public:
    string nearestPalindromic(string n) {

        long long num = stoll(n);
        int len = n.size();

        vector<long long> cand;

        cand.push_back((long long)pow(10, len) + 1);
        cand.push_back((long long)pow(10, len - 1) - 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        for (long long i = prefix - 1; i <= prefix + 1; i++) {

            string left = to_string(i);
            string right = left;

            if (len % 2)
                right.pop_back();

            reverse(right.begin(), right.end());

            cand.push_back(stoll(left + right));
        }

        long long ans = -1;

        for (long long x : cand) {

            if (x == num)
                continue;

            if (ans == -1 ||
                abs(x - num) < abs(ans - num) ||
                (abs(x - num) == abs(ans - num) && x < ans))
                ans = x;
        }

        return to_string(ans);
    }
};