class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;

        for (string op : operations) {

            if (op == "C") {
                scores.pop_back();
            }
            else if (op == "D") {
                scores.push_back(2 * scores.back());
            }
            else if (op == "+") {
                int n = scores.size();

                scores.push_back(scores[n - 1] + scores[n - 2]);
            }
            else {
                // Convert string to integer
                scores.push_back(stoi(op));
            }
        }

        int answer = 0;

        for (int score : scores) {
            answer += score;
        }

        return answer;
    }
};