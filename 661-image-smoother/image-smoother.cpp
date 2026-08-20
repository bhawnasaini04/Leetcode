class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int>> answer(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                int sum = 0;
                int count = 0;

                // Check surrounding 3 x 3 area
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {

                        // Check if the position is inside the image
                        if (x >= 0 && x < rows &&
                            y >= 0 && y < cols) {

                            sum += img[x][y];
                            count++;
                        }
                    }
                }

                answer[i][j] = sum / count;
            }
        }

        return answer;
    }
};