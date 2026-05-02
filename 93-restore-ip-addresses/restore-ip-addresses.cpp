class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(s, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(string& s, int index, int parts, string path, vector<string>& result) {
        if (parts == 4 && index == s.size()) {
            result.push_back(path.substr(0, path.size() - 1)); // remove last dot
            return;
        }

        if (parts >= 4) return;

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string segment = s.substr(index, len);

            if ((segment[0] == '0' && segment.length() > 1) || stoi(segment) > 255)
                continue;

            backtrack(s, index + len, parts + 1, path + segment + ".", result);
        }
    }
};