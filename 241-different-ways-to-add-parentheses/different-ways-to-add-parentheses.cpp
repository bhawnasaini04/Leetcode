class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.size(); i++) {

            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                vector<int> left =
                    diffWaysToCompute(expression.substr(0, i));

                vector<int> right =
                    diffWaysToCompute(expression.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {

                        if (ch == '+')
                            result.push_back(l + r);

                        else if (ch == '-')
                            result.push_back(l - r);

                        else
                            result.push_back(l * r);
                    }
                }
            }
        }

        if (result.empty())
            result.push_back(stoi(expression));

        return result;
    }
};