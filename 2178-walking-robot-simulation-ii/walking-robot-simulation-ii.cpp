class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0=East, 1=North, 2=West, 3=South
    int perimeter;

    vector<string> directions = {"East", "North", "West", "South"};
    vector<pair<int,int>> moveDir = {
        {1,0}, {0,1}, {-1,0}, {0,-1}
    };

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h - 2);
    }

    void step(int num) {
        if (perimeter == 0) return;

        num %= perimeter;

        // Special case: if at start and full cycle
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }

        while (num--) {
            int nx = x + moveDir[dir].first;
            int ny = y + moveDir[dir].second;

            // Check boundary
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; // turn counterclockwise
                nx = x + moveDir[dir].first;
                ny = y + moveDir[dir].second;
            }

            x = nx;
            y = ny;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return directions[dir];
    }
};