class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> answer(n, 0);

        stack<int> functionStack;

        int previousTime = 0;

        for (string log : logs) {

            // Find the first ':'
            int firstColon = log.find(':');

            // Find the second ':'
            int secondColon = log.find(':', firstColon + 1);

            // Get function ID
            int functionId = stoi(
                log.substr(0, firstColon)
            );

            // Get start or end
            string type = log.substr(
                firstColon + 1,
                secondColon - firstColon - 1
            );

            // Get time
            int currentTime = stoi(
                log.substr(secondColon + 1)
            );

            if (type == "start") {

                // Current function was running
                // until currentTime - 1
                if (!functionStack.empty()) {
                    answer[functionStack.top()] +=
                        currentTime - previousTime;
                }

                functionStack.push(functionId);

                previousTime = currentTime;
            }
            else {

                // Current function runs until currentTime
                answer[functionStack.top()] +=
                    currentTime - previousTime + 1;

                functionStack.pop();

                previousTime = currentTime + 1;
            }
        }

        return answer;
    }
};