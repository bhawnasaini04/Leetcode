class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        
        q.push(start);

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            if (arr[index] == 0)
                return true;

            // Already visited
            if (arr[index] < 0)
                continue;

            int jump = arr[index];

            // Mark visited
            arr[index] = -arr[index];

            int forward = index + jump;
            int backward = index - jump;

            if (forward < n)
                q.push(forward);

            if (backward >= 0)
                q.push(backward);
        }

        return false;
    }
};