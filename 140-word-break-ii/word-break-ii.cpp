class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, vector<string>> memo;

    vector<string> solve(string s) {
        if (memo.count(s)) return memo[s];

        vector<string> res;

        if (s.empty()) {
            res.push_back("");
            return res;
        }

        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);

            if (st.count(word)) {
                vector<string> temp = solve(s.substr(i));

                for (string x : temp) {
                    res.push_back(word + (x.empty() ? "" : " " + x));
                }
            }
        }

        return memo[s] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        return solve(s);
    }
};