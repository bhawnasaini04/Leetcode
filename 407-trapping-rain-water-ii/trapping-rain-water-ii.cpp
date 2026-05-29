class Solution {
public:
    int trapRainWater(
        vector<vector<int>>& heightMap) {

        int m = heightMap.size();

        if(m == 0)
            return 0;

        int n = heightMap[0].size();

        priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>> pq;

        vector<vector<bool>> visited(
            m,
            vector<bool>(n,false)
        );

        for(int i=0;i<m;i++) {

            pq.push({
                heightMap[i][0],i,0
            });

            pq.push({
                heightMap[i][n-1],i,n-1
            });

            visited[i][0]=true;
            visited[i][n-1]=true;
        }

        for(int j=1;j<n-1;j++) {

            pq.push({
                heightMap[0][j],0,j
            });

            pq.push({
                heightMap[m-1][j],
                m-1,j
            });

            visited[0][j]=true;
            visited[m-1][j]=true;
        }

        int water = 0;

        int dir[4][2] = {
            {1,0},{-1,0},
            {0,1},{0,-1}
        };

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int h = curr[0];
            int x = curr[1];
            int y = curr[2];

            for(auto &d : dir) {

                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && ny>=0 &&
                   nx<m && ny<n &&
                   !visited[nx][ny]) {

                    visited[nx][ny]=true;

                    water += max(
                        0,
                        h-heightMap[nx][ny]
                    );

                    pq.push({
                        max(h,
                        heightMap[nx][ny]),
                        nx,ny
                    });
                }
            }
        }

        return water;
    }
};