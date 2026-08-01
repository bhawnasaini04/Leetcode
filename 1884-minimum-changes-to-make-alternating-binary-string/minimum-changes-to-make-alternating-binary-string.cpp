class Solution {
public:
    int minOperations(string s) {

        int startWith0 = 0;
        int startWith1 = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != (i % 2 == 0 ? '0' : '1'))
                startWith0++;

            if (s[i] != (i % 2 == 0 ? '1' : '0'))
                startWith1++;
        }

        return min(startWith0, startWith1);
    }
};