class Solution {
    struct Event {
        long long y, x1, x2;
        int type;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    struct Node {
        int cnt = 0;
        long long len = 0;
    };

    vector<Node> seg;
    vector<long long> xs;

    void pushUp(int idx, int l, int r) {
        if (seg[idx].cnt > 0) {
            seg[idx].len = xs[r + 1] - xs[l];
        } else if (l == r) {
            seg[idx].len = 0;
        } else {
            seg[idx].len = seg[idx * 2].len + seg[idx * 2 + 1].len;
        }
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            seg[idx].cnt += val;
            pushUp(idx, l, r);
            return;
        }

        int mid = (l + r) >> 1;

        if (ql <= mid) update(idx * 2, l, mid, ql, qr, val);
        if (qr > mid) update(idx * 2 + 1, mid + 1, r, ql, qr, val);

        pushUp(idx, l, r);
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        xs.clear();

        for (auto& s : squares) {
            long long x = s[0];
            long long y = s[1];
            long long l = s[2];

            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});

            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end());

        int m = xs.size() - 1;
        seg.assign(4 * max(1, m), {});

        vector<tuple<long long,long long,long long>> strips;

        long long prevY = events[0].y;
        long long totalArea = 0;

        for (int i = 0; i < events.size();) {
            long long y = events[i].y;

            long long covered = (m > 0 ? seg[1].len : 0);

            if (y > prevY) {
                long long area = covered * (y - prevY);
                totalArea += area;
                strips.push_back({prevY, y, covered});
            }

            while (i < events.size() && events[i].y == y) {
                auto [yy, x1, x2, tp] = events[i];

                int l = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), x2) - xs.begin() - 1;

                if (l <= r)
                    update(1, 0, m - 1, l, r, tp);

                i++;
            }

            prevY = y;
        }

        long double target = (long double)totalArea / 2.0;
        long double acc = 0;

        for (auto& [y1, y2, width] : strips) {
            long double area = (long double)width * (y2 - y1);

            if (acc + area >= target) {
                return (double)(y1 + (target - acc) / width);
            }

            acc += area;
        }

        return 0.0;
    }
};