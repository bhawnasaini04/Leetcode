class Solution {
public:
    int numberOfBoomerangs(
        vector<vector<int>>& points) {

        int result = 0;

        for (auto& p1 : points) {

            unordered_map<int,int> freq;

            for (auto& p2 : points) {

                int dx =
                    p1[0] - p2[0];

                int dy =
                    p1[1] - p2[1];

                int dist =
                    dx * dx + dy * dy;

                freq[dist]++;
            }

            for (auto& p : freq) {

                int cnt = p.second;

                result +=
                    cnt * (cnt - 1);
            }
        }

        return result;
    }
};