class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int> radiant;
        queue<int> dire;

        int n = senate.size();

        // Store the positions of both parties
        for (int i = 0; i < n; i++) {

            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {

            int r = radiant.front();
            int d = dire.front();

            radiant.pop();
            dire.pop();

            // The senator with the smaller index
            // gets to act first.
            if (r < d) {
                // Radiant bans Dire
                radiant.push(r + n);
            }
            else {
                // Dire bans Radiant
                dire.push(d + n);
            }
        }

        if (!radiant.empty())
            return "Radiant";

        return "Dire";
    }
};