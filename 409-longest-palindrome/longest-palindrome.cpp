class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> freq;

        for(char ch:s)
            freq[ch]++;

        int length = 0;
        bool odd = false;

        for(auto &p:freq) {

            length +=
            (p.second/2)*2;

            if(p.second%2)
                odd = true;
        }

        return odd ? length+1 : length;
    }
};