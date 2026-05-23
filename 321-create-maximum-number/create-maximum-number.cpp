class Solution {
public:
    
    // Get maximum subsequence of length k
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int num : nums) {
            while (!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }

            st.push_back(num);
        }

        st.resize(k);
        return st;
    }

    // Merge two arrays into maximum number
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        int i = 0, j = 0;

        while (i < nums1.size() || j < nums2.size()) {

            if (lexicographical_compare(
                    nums1.begin() + i, nums1.end(),
                    nums2.begin() + j, nums2.end()))
                result.push_back(nums2[j++]);
            else
                result.push_back(nums1[i++]);
        }

        return result;
    }

    vector<int> maxNumber(vector<int>& nums1,
                          vector<int>& nums2,
                          int k) {

        vector<int> answer;

        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());

        for (int i = start; i <= end; i++) {

            vector<int> part1 = maxSubsequence(nums1, i);
            vector<int> part2 = maxSubsequence(nums2, k - i);

            vector<int> candidate = merge(part1, part2);

            if (candidate > answer)
                answer = candidate;
        }

        return answer;
    }
};