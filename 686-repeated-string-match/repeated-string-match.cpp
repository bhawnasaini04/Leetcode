class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string s = "";
        int count = 0;

        // Keep adding a until s is at least as long as b
        while (s.size() < b.size()) {
            s += a;
            count++;
        }

        // Check if b is present
        if (s.find(b) != string::npos)
            return count;

        // One extra repetition may be enough
        s += a;
        count++;

        if (s.find(b) != string::npos)
            return count;

        return -1;
    }
};