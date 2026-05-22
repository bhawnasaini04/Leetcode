class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            int balance = 0;
            bool valid = true;

            for (char ch : curr) {
                if (ch == '(')
                    balance++;
                else if (ch == ')') {
                    balance--;

                    if (balance < 0) {
                        valid = false;
                        break;
                    }
                }
            }

            if (balance != 0)
                valid = false;

            if (valid) {
                result.push_back(curr);
                found = true;
            }

            if (found)
                continue;

            for (int i = 0; i < curr.size(); i++) {

                if (curr[i] != '(' &&
                    curr[i] != ')')
                    continue;

                string next =
                    curr.substr(0, i) +
                    curr.substr(i + 1);

                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return result;
    }
};