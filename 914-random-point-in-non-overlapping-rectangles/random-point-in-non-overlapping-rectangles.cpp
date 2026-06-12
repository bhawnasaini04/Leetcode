class Solution {
public:
    vector<vector<int>> rects;
    vector<int> prefix;
    int total = 0;

    Solution(vector<vector<int>>& rects) {

        this->rects = rects;

        for (auto &r : rects) {

            total +=
                (r[2] - r[0] + 1) *
                (r[3] - r[1] + 1);

            prefix.push_back(total);
        }
    }

    vector<int> pick() {

        int k = rand() % total;

        int idx =
            upper_bound(prefix.begin(),
                        prefix.end(),
                        k)
            - prefix.begin();

        auto &r = rects[idx];

        int width =
            r[2] - r[0] + 1;

        int base =
            idx == 0 ? 0 :
            prefix[idx - 1];

        int offset = k - base;

        int x =
            r[0] + offset % width;

        int y =
            r[1] + offset / width;

        return {x, y};
    }
};