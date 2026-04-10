class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX; // overflow case

        bool sign = (dividend < 0) ^ (divisor < 0);

        long long a = labs(dividend);
        long long b = labs(divisor);

        long long result = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        return sign ? -result : result;
    }
};