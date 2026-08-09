class Solution {
public:
    long long dist(vector<int>& a, vector<int>& b) {

        long long dx = a[0] - b[0];
        long long dy = a[1] - b[1];

        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1,
                     vector<int>& p2,
                     vector<int>& p3,
                     vector<int>& p4) {

        vector<vector<int>> p = {p1, p2, p3, p4};

        vector<long long> d;

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                d.push_back(dist(p[i], p[j]));
            }
        }

        sort(d.begin(), d.end());

        // Four equal sides
        if (d[0] == 0)
            return false;

        if (d[0] != d[1] ||
            d[1] != d[2] ||
            d[2] != d[3])
            return false;

        // Two equal diagonals
        if (d[4] != d[5])
            return false;

        // Diagonal² = 2 * side²
        return d[4] == 2 * d[0];
    }
};