class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> dir = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},{0,1},
            {1,-1},{1,0},{1,1}
        };

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int live=0;

                for(auto d:dir){
                    int x=i+d[0];
                    int y=j+d[1];

                    if(x>=0 && y>=0 &&
                       x<m && y<n &&
                       abs(board[x][y])==1)
                        live++;
                }

                if(board[i][j]==1 &&
                   (live<2 || live>3))
                    board[i][j]=-1;

                if(board[i][j]==0 &&
                   live==3)
                    board[i][j]=2;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=(board[i][j]>0)?1:0;
            }
        }
    }
};