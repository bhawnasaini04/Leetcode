class NumArray {
public:
    vector<int> bit;
    vector<int> nums;
    int n;

    NumArray(vector<int>& arr) {
        nums = arr;
        n = arr.size();

        bit.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
            updateBIT(i + 1, nums[i]);
    }

    void updateBIT(int index,
                   int val) {

        while (index <= n) {
            bit[index] += val;
            index += index & (-index);
        }
    }

    void update(int index,
                int val) {

        int diff =
            val - nums[index];

        nums[index] = val;

        updateBIT(
            index + 1,
            diff
        );
    }

    int query(int index) {
        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }

        return sum;
    }

    int sumRange(int left,
                 int right) {

        return query(right+1)
             - query(left);
    }
};