class Solution {
public:
    int magicalString(int n) {

        if (n <= 0) return 0;
        if (n <= 3) return 1;

        vector<int> magic(n + 2);

        magic[0] = 1;
        magic[1] = 2;
        magic[2] = 2;

        int head = 2;
        int tail = 3;
        int num = 1;
        int ones = 1;

        while (tail < n) {

            for (int i = 0;
                 i < magic[head];
                 i++) {

                magic[tail] = num;

                if (num == 1 &&
                    tail < n)
                    ones++;

                tail++;
            }

            num = 3 - num;
            head++;
        }

        return ones;
    }
};