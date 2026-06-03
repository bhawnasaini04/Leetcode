// The rand7() API is already defined for you.
// int rand7();

class Solution {
public:
    int rand10() {

        while (true) {

            int num =
                (rand7() - 1) * 7 + rand7();

            if (num <= 40)
                return 1 + (num - 1) % 10;
        }
    }
};