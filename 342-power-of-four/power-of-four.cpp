class Solution {
public:
    bool isPowerOfFour(int n) {
        // Must be positive
        // Power of 2: only one set bit
        // Set bit must be at odd position
        return n > 0 &&
               (n & (n - 1)) == 0 &&
               (n & 0x55555555);
    }
};