class Solution {
public:
    pair<int, int> getValues(string part) {

        int xCount = 0;
        int numberSum = 0;

        int i = 0;
        int sign = 1;

        while (i < part.size()) {

            // Handle sign
            if (part[i] == '+') {
                sign = 1;
                i++;
            }
            else if (part[i] == '-') {
                sign = -1;
                i++;
            }

            int number = 0;
            bool hasNumber = false;

            while (i < part.size() && isdigit(part[i])) {
                number = number * 10 + (part[i] - '0');
                i++;
                hasNumber = true;
            }

            // Variable x
            if (i < part.size() && part[i] == 'x') {

                if (!hasNumber)
                    number = 1;

                xCount += sign * number;
                i++;
            }
            else {
                numberSum += sign * number;
            }
        }

        return {xCount, numberSum};
    }

    string solveEquation(string equation) {

        int equalSign = equation.find('=');

        string left = equation.substr(0, equalSign);
        string right = equation.substr(equalSign + 1);

        auto leftValue = getValues(left);
        auto rightValue = getValues(right);

        int xCount = leftValue.first - rightValue.first;
        int numberSum = rightValue.second - leftValue.second;

        if (xCount == 0 && numberSum == 0)
            return "Infinite solutions";

        if (xCount == 0)
            return "No solution";

        int x = numberSum / xCount;

        return "x=" + to_string(x);
    }
};