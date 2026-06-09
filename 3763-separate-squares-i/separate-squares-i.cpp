class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double total = 0;
        long double hi = 0;

        for (auto &s : squares) {
            long double y = s[1];
            long double l = s[2];

            total += l * l;
            hi = max(hi, y + l);
        }

        long double target = total / 2.0;
        long double lo = 0;

        auto areaBelow = [&](long double line) {
            long double area = 0;

            for (auto &s : squares) {
                long double y = s[1];
                long double l = s[2];

                if (line <= y) continue;
                else if (line >= y + l)
                    area += l * l;
                else
                    area += l * (line - y);
            }

            return area;
        };

        for (int i = 0; i < 100; i++) {
            long double mid = (lo + hi) / 2.0;

            if (areaBelow(mid) >= target)
                hi = mid;
            else
                lo = mid;
        }

        return (double)hi;
    }
};