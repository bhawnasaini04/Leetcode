class Solution {
public:
    vector<vector<char>> updateBoard(
        vector<vector<char>>& board,
        vector<int>& click) {

        int m = board.size();
        int n = board[0].size();

        int r = click[0];
        int c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        vector<pair<int,int>> dirs = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},         {0,1},
            {1,-1},{1,0},{1,1}
        };

        queue<pair<int,int>> q;
        q.push({r,c});

        while (!q.empty()) {

            auto [x,y] = q.front();
            q.pop();

            if (board[x][y] != 'E')
                continue;

            int mines = 0;

            for (auto &[dx,dy] : dirs) {

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    board[nx][ny] == 'M')
                    mines++;
            }

            if (mines > 0) {

                board[x][y] =
                    mines + '0';
            }
            else {

                board[x][y] = 'B';

                for (auto &[dx,dy] : dirs) {

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < m &&
                        ny >= 0 && ny < n &&
                        board[nx][ny] == 'E') {

                        q.push({nx, ny});
                    }
                }
            }
        }

        return board;
    }
};