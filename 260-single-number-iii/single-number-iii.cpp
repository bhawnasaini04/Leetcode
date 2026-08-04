class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xorr = 0;

        for (int num : nums)
            xorr ^= num;

        unsigned int diffBit = (unsigned int)xorr & (-(unsigned int)xorr);

        int num1 = 0, num2 = 0;

        for (int num : nums) {
            if (num & diffBit)
                num1 ^= num;
            else
                num2 ^= num;
        }

        return {num1, num2};
    }
};