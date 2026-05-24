class Solution {
public:
    int dfs(vector<vector<int>>& matrix,
            int i, int j,
            vector<vector<int>>& dp) {

        if(dp[i][j] != 0)
            return dp[i][j];

        int m = matrix.size();
        int n = matrix[0].size();

        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        int ans = 1;

        for(auto &d : dir){
            int x=i+d[0];
            int y=j+d[1];

            if(x>=0 && y>=0 &&
               x<m && y<n &&
               matrix[x][y] > matrix[i][j]) {

                ans=max(ans,
                        1+dfs(matrix,x,y,dp));
            }
        }

        return dp[i][j]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(
            m,
            vector<int>(n,0)
        );

        int result=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result=max(
                    result,
                    dfs(matrix,i,j,dp)
                );
            }
        }

        return result;
    }
};