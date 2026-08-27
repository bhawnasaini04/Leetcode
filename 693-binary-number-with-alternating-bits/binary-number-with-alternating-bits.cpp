class Solution {
public:
    bool hasAlternatingBits(int n) {

        int previous = n % 2;
        n = n / 2;

        while (n > 0) {

            int current = n % 2;

            // Two consecutive bits are same
            if (current == previous)
                return false;

            previous = current;
            n = n / 2;
        }

        return true;
    }
};